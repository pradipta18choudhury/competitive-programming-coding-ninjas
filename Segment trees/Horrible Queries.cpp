/*******
Horrible Queries
Send Feedback
World is getting more evil and it's getting tougher to get into the Evil League of Evil. Since the legendary Bad Horse has retired, now you have to correctly answer the evil questions of Dr. Horrible, who has a PhD in horribleness (but not in Computer Science). You are given an array of N elements, which are initially all 0. After that you will be given C commands. They are -
0 p q v - you have to add v to all numbers in the range of p to q (inclusive), where p and q are two indexes of the array.

1 p q - output a line containing a single integer which is the sum of all the array elements between p and q (inclusive)
Input
In the first line you'll be given T, number of test cases.

Each test case will start with N (N <= 100 000) and C (C <= 100 000). After that you'll be given C commands in the format as mentioned above. 1 <= p, q <= N and 1 <= v <= 10^7.
Output
Print the answers of the queries.
Input:
1
8 6
0 2 4 26
0 4 8 80
0 4 5 20
1 8 8 
0 5 7 14
1 4 8
Output:
80  
508
******/

/*******
#include <bits/stdc++.h>
#include <cstring>
#include <algorithm>

using namespace std;

long long sum[4 * 100000],childSum[4 * 100000];

void built(int TreeNode,int start,int end)
{
    if(start==end)
    {
        childSum[TreeNode]=sum[start];
        return;
    }
    int mid=(start+end)/2;
    built(2*TreeNode+1,start,mid);
    built(2*TreeNode+2,mid+1,end);
    childSum[TreeNode]=(childSum[2*TreeNode+1] + childSum[2*TreeNode+2]);
}

long long query(int node, int l, int r, int a, int b){
    if(l > b || r < a) return 0;
    
    long long ret = (min(b,r) - max(a,l) + 1) * sum[node];
    
    if(a <= l && r <= b) ret += childSum[node];
    else{
        int mi = (l + r) >> 1;
        
        ret += query(2 * node + 1,l,mi,a,b) + query(2 * node + 2,mi + 1,r,a,b);
    }
    
    return ret;
}

void update(int node, int l, int r, int a, int b, int x){
    if(l > b || r < a) return;
    
    if(a <= l && r <= b) sum[node] += x;
    else{
        int mi = (l + r) >> 1;
        
        update(2 * node + 1,l,mi,a,b,x);
        update(2 * node + 2,mi + 1,r,a,b,x);
        
        childSum[node] = childSum[2 * node + 1] + childSum[2 * node + 2] + (mi - l + 1) * sum[2 * node + 1] + (r - mi) * sum[2 * node + 2];
    }
}

int main(){
    int TC,N,C;
    int op,p,q,v;
    
    cin>>TC;
    
    while(TC--){
        cin>>N>>C;
        
        memset(sum,0,sizeof sum);
        memset(childSum,0,sizeof childSum);
        built(1,0,N-1);
        
        for(int i = 0;i < C;++i){
            cin>>op;
            
            if(op == 0){
                cin>>p>>q>>v;
                
                update(0,1,N,p,q,v);
            }else{
                cin>>p>>q;
                
                cout<<query(0,1,N,p,q)<<endl;
            }
        }
    }
    
    return 0;
}
*****/



#include<bits/stdc++.h>
#define ll long long
using namespace std;

void build(ll *tree,ll *arr,ll si,ll ei,ll node){
    ll mid = (si+ei)/2;
    if(si == ei){
        tree[node] = arr[si];
        return ;
    }
    
    build(tree,arr,si,mid,2*node);
    build(tree,arr,mid+1,ei,2*node+1);
    
    tree[node] = tree[2*node] + tree[2*node + 1];
        
}


void inc(ll *tree,ll *lazy,ll si,ll ei,ll node,ll l,ll r,ll value){
    if(si>ei)
        return;
    
    ll mid = (si+ei)/2;
    if(lazy[node] != 0){
        tree[node] += lazy[node]*(ei-si+1);

        if(si != ei){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }

        lazy[node] = 0;
    }
    if(l>ei || r <si)
        return;
    else if(l <= si && ei <= r){
        tree[node] += value*(ei-si+1);
        if(si != ei){
            lazy[2*node] += value;
            lazy[2*node+1] += value;
        }
        return;
    }
    inc(tree,lazy,si,mid,2*node,l,r,value);
    inc(tree,lazy,mid+1,ei,2*node+1,l,r,value);
    
    tree[node] = tree[2*node] + tree[2*node + 1];       
}


ll query(ll *tree,ll *lazy,ll si,ll ei,ll node,ll left ,ll right){
    //lazy work
    if(si>ei)
        return 0;
    if(lazy[node] != 0){
        tree[node] += lazy[node]*(ei-si+1);
        if(si!=ei){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node]; 
        }
        lazy[node] = 0;
    }
    
    if(si>right || ei <left){
        return 0;
    }
    //Completely inside
	if (si>=left && ei<=right)
	{
		return tree[node];
	}

	//Partially inside
	
	ll mid = (si+ei)/2;

	if(left>mid){
		return query(tree,lazy, mid+1, ei, 2*node+1, left, right);
	}

	if(right<=mid){
		return query(tree,lazy, si, mid, 2*node, left, right);
	}


	ll l = query(tree,lazy, si, mid, 2*node, left, right);
	ll r = query(tree,lazy, mid+1, ei, 2*node+1, left, right);
    
    return l+r;
}
int main() {
    ll t;
    cin>>t;
    while(t--){
        ll n ,c;
        cin>>n>>c;
        ll *arr =  new ll[n];
        for(ll i=0;i<n;i++)
            arr[i] = 0;
        ll *tree = new ll[4*n];
        ll *lazy = new ll[4*n];
        for(ll i=1;i<4*n;i++){
            lazy[i] = 0;
            tree[i] = 0;
        }
        
        //build(tree,arr,0,n-1,1);
        
        while(c--){
            
            ll type,l,r,x;
            cin>>type;
            if(type == 1){
                cin>>l>>r;
                cout<<query(tree,lazy,0,n-1,1,l-1,r-1)<<endl;
            }
            else if(type == 0){
                cin>>l>>r>>x;
                inc(tree,lazy,0,n-1,1,l-1,r-1,x);
        
            }
                
        }  
    }
}
