/*******
Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.
Note: The input data will be such that there will always be a solution.
Input Format :
The first line of input contains a string, that denotes the value of S. The following line contains a string, that denotes the value of V.
Output Format :
Length of shortest subsequence in S such that it is not a subsequence in V
Constraints:
1 <= N <= 1000
1 <= M <= 1000 
Time Limit: 1 second
Sample Input 1:
babab
babba
Sample Output 1:
3
Explanation:
"aab" is the shortest subsequence which is present in S and absent in V.
*******/

#include <bits/stdc++.h>
using namespace std;
int dp[1005][1005]={};

int helper(string S,string V,int m,int n)
{
    // int **dp=new int*[m+1];
    //for(int i=0;i<=m;i++)
      //  dp[i]=new int[n+1];
    
//     memset(dp,-1,sizeof(dp));
    
    if(m==0)
        return 1000000;
    if(n<=0)
        return 1;
    if(dp[m][n]!=0)
        return dp[m][n];
    
    int k;
    for( k=0;k<n;k++)
        if(S[0]==V[k])
            break;
    
     if(k==n)
        return 1;
    else
    {
        int option1=helper(S.substr(1),V,m-1,n);
        int option2=1+helper(S.substr(1),V.substr(k+1),m-1,n-k-1);
        dp[m][n]=min(option1,option2);
    }
    
    int ans=dp[m][n];
    // for(int i=0;i<=m;i++)
    //     delete [] dp[i];
    // delete [] dp;
    return ans;
}


int solve(string S,string V)
{
	// Write your code here.
    
   // for(int i=0;i<=m;i++)
     //   dp[i][0]=1;
    
    //for(int i=0;i<=n;i++)
      //  dp[0][i]=INT_MAX;
    //if character not found in V
    int m=S.length();
    int n=V.length();
    int ans=helper(S,V,m,n);
    if(ans>=INT_MAX)
        return -1;
    else
        return ans;
}
int main() {
    string s, v;
    cin >> s >> v;
    cout << solve(s, v);
}
