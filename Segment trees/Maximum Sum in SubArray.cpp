/********
Maximum Sum In Subarray
Send Feedback
You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
Given M queries, your program must output the results of these queries.
Input
The first line of the input file contains the integer N.
In the second line, N numbers follow.
The third line contains the integer M.
M lines follow, where line i contains 2 numbers xi and yi.
Output
Your program should output the results of the M queries, one 
query per line.
Sample Input:
3 
-1 2 3 
1
1 2
Sample Output:
2
********/


#include<bits/stdc++.h>
using namespace std;

struct node
{
  	int sum;
    int maxSum;
    int prefix;
    int suffix;
};

void BuiltTree(int *arr,node *tree,int TreeNode,int start,int end)
{
	if(start==end)
    {
        tree[TreeNode].sum=arr[start];
        tree[TreeNode].maxSum=arr[start];
        tree[TreeNode].prefix=arr[start];
        tree[TreeNode].suffix=arr[start];
        return;
    }
    
    int mid=(start+end)/2;
    BuiltTree(arr,tree,2*TreeNode,start,mid);
    BuiltTree(arr,tree,2*TreeNode+1,mid+1,end);
    
    node left=tree[2*TreeNode];
    node right=tree[2*TreeNode+1];
    
    tree[TreeNode].sum=(left.sum+right.sum);
    
    tree[TreeNode].prefix=max(left.prefix,left.sum+right.prefix);
    
    tree[TreeNode].suffix=max(right.suffix,right.sum+left.suffix);
    
    tree[TreeNode].maxSum=max(left.sum+right.prefix, 
                    max(right.sum+left.suffix, 
                    max(left.maxSum, 
                    max(right.maxSum, left.suffix + right.prefix))));
    return;
}


/*void update(int *arr,node *tree,int TreeNode,int start,int end,int idx,int value)
{
    if(start==end)
    {
        tree[TreeNode].sum=value;
        tree[TreeNode].maxSum=value;
        tree[TreeNode].prefix=value;
        tree[TreeNode].suffix=value;
        return;
    }
    
    int mid=(start+end)/2;
    if(value>mid)
        update(arr,tree,2*TreeNode+1,mid+1,end,idx,value);
    else
        update(arr,tree,2*TreeNode,start,mid,idx,value);
    
    
    node left=tree[2*TreeNode];
    node right=tree[2*TreeNode+1];
    
    tree[TreeNode].sum=(left.sum+right.sum);
    
    tree[TreeNode].prefix=max(left.prefix,left.sum+right.prefix);
    
    tree[TreeNode].suffix=max(right.suffix,right.sum+left.suffix);
    
    tree[TreeNode].maxSum=max(tree[TreeNode].prefix, 
                    max(tree[TreeNode].suffix, 
                    max(left.maxSum, 
                    max(right.maxSum, left.suffix + right.prefix))));
    
    
}
*/

node querry(int *arr,node *tree,int TreeNode,int start,int end,int l,int r)
{
    
    
    if(r<start||end<l)
      { /*node ans;
    ans.sum=ans.maxSum=ans.prefix=ans.suffix=-100000;
        return ans;*/
        node zero = {-100000,-100000,-100000,-100000};
        return zero;
    }
    if(start>=l && end<=r){
        return tree[TreeNode];
    }
    
    int mid=(start+end)/2;
    /*if(l>mid)
        return querry(arr,tree,2*TreeNode+1,mid+1,end,l,r);
    else if(l<=mid)
        return querry(arr,tree,2*TreeNode,start,mid,l,r);*/
    
    node left=querry(arr,tree,2*TreeNode,start,mid,l,r);
    node right=querry(arr,tree,2*TreeNode+1,mid+1,end,l,r);
    node ans;
    ans.sum=(left.sum+right.sum);
    
    ans.prefix=max(left.prefix,left.sum+right.prefix);
    
    ans.suffix=max(right.suffix,right.sum+left.suffix);
    
    ans.maxSum=max(left.sum+right.prefix, 
                    max(right.sum+left.suffix, 
                    max(left.maxSum, 
                    max(right.maxSum, left.suffix + right.prefix))));
    return ans;
}
int main() {

	// Write your code here
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    node *tree=new node[4*n];
    BuiltTree(arr,tree,1,0,n-1);
    int t;
    cin>>t;
    while(t--)
    {
        int start,end;
        cin>>start>>end;
        
        //update(arr,tree,1,0,n-1,start,end);
        cout<<querry(arr,tree,1,0,n-1,start-1,end-1).maxSum;
        cout<<endl;
    }
    return 0;
}



/******
#include<bits/stdc++.h>
using namespace std;

struct node{
    int maximum;
    int sum;
    int bpsum;
    int bssum;
};

void buildTree(int *arr,node *tree,int start,int end,int treeNode){
    if(start==end){
      
    tree[treeNode].maximum=arr[start];
    tree[treeNode].bpsum=arr[start];
    tree[treeNode].bssum=arr[start];
    tree[treeNode].sum=arr[start];
     return;
    }
    
    int mid=(start+end)/2;
    buildTree(arr,tree,start,mid,2*treeNode);
    buildTree(arr,tree,mid+1,end,2*treeNode+1);
    
    node left=tree[treeNode*2];
    node right=tree[2*treeNode+1];
    
    tree[treeNode].maximum=max(left.maximum,max(right.maximum,max(left.sum+right.bpsum,max(right.sum+left.bssum,left.bssum+right.bpsum))));
    tree[treeNode].sum=left.sum+right.sum;
    tree[treeNode].bpsum=max(left.bpsum,left.sum+right.bpsum);
    tree[treeNode].bssum=max(right.bssum,right.sum+left.bssum);
    return;
    
}


node query(node *tree,int start,int end,int treeNode,int left,int right){
  
    if(start>right || end<left){
       node zero = {-100000,-100000,-100000,-100000};
        return zero;
    }  
    
    if(start>=left && end<=right){
        return tree[treeNode];
    }
    
    int mid=(start+end)/2;
    
    node ans1=query(tree,start,mid,2*treeNode,left,right);
    node ans2=query(tree,mid+1,end,2*treeNode+1,left,right);
    
    node ans;
    ans.maximum=max(ans1.maximum,max(ans2.maximum,max(ans1.sum+ans2.bpsum,max(ans2.sum+ans1.bssum,ans1.bssum+ans2.bpsum))));
    ans.sum=ans1.sum+ans2.sum;
    ans.bpsum=max(ans1.bpsum,ans1.sum+ans2.bpsum);
    ans.bssum=max(ans2.bssum,ans2.sum+ans1.bssum);
    
    return ans;
    
}
int main() {
     int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    
    node *tree=new node[4*n];
    buildTree(arr,tree,0,n-1,1);
    
    int q;
    cin>>q;
    while(q--){
    int l,r;
    cin>>l>>r;
        node ans=query(tree,0,n-1,1,l-1,r-1);
        cout<<ans.maximum<<endl;
        
    }
    return 0;
	// Write your code here
}*****/
