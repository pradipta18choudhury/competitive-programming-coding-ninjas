/********
KQUERY
Send Feedback
Given a sequence of n numbers a1, a2, ..., an and a number of k- queries. A k-query is a triple (i, j, k) (1 ≤ i ≤ j ≤ n). For each k-query (i, j, k), you have to return the number of elements greater than k in the subsequence ai, ai+1, ..., aj.
Input Format
Line 1: n (1 ≤ n ≤ 30000).

Line 2: n numbers a1, a2, ..., an (1 ≤ ai ≤ 10^9).

Line 3: q (1 ≤ q ≤ 200000), the number of k- queries.

In the next q lines, each line contains 3 numbers i, j, k representing a k-query (1 ≤ i ≤ j ≤ n, 1 ≤ k ≤ 10^9).
Output Format
For each k-query (i, j, k), print the number of elements greater than k in the subsequence ai, ai+1, ..., aj in a single line.
Sample Input
5
5 1 2 3 4
3
2 4 1
4 4 4
1 5 2 
Sample Output
2
0
3 
******/

#include<bits/stdc++.h>
using namespace std;
class KQUERY{
	public:
    	int left;
    	int right;
    	int value;
    int index;
};


const int N=500000;
KQUERY dp[500000];
int arr[N],ans[N],n,q;


bool comparator(KQUERY a,KQUERY b)
{
    if(a.value==b.value)
        return a.left>b.left;
    
    return a.value>b.value;
}


void update(int y,int *BIT)
{
    for(;y<=500000;y+=(y&(-y)))
        BIT[y]++;
}


int querry(int index,int *BIT)
{
    int count=0;
    for(;index>0;index-=(index&(-index)))
        count+=BIT[index];
    return count;
}


int main()
{
    std::ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&arr[i]);
    }
    
    int q;
    scanf("%d",&q);
    KQUERY *dp=new KQUERY[q+n+1];
    for(int i=1;i<=n;i++){
        dp[i].value=arr[i];
        dp[i].left=0;
        dp[i].right=i;
        dp[i].index=0;
    }
    
    for(int i=n+1;i<=n+q;i++)
    {
        scanf("%d%d%d",&dp[i].left,&dp[i].right,&dp[i].value);
        dp[i].index=i-n-1;
    }
    
    int *bit=new int[500000]();
    sort(dp+1,dp+q+n+1,comparator);
    int *ans=new int[q]();
    
    for(int i=1;i<=n+q;i++){
        if(dp[i].left == 0){
            update(dp[i].right,bit);
        }
        else{
            ans[dp[i].index]=querry(dp[i].right,bit)-querry(dp[i].left-1,bit);
        }
    }
    for(int i=0;i<q;i++){
        printf("%d\n",ans[i]);
    }
    
    
	return 0;
}
