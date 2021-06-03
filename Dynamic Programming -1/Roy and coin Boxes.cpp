/*****
Roy and Coin Boxes
Send Feedback
Roy has N coin boxes numbered from 1 to N.
Every day he selects two indices [L,R] and adds 1 coin to each coin box starting from L to R (both inclusive).
He does this for M number of days.

After M days, Roy has a query: How many coin boxes have atleast X coins.
He has Q such queries.
Input
First line contains N - number of coin boxes.
Second line contains M - number of days. Each of the next M lines consists of two space separated integers L and R. Followed by integer Q - number of queries.
Each of next Q lines contain a single integer X.a
Output
For each query output the result in a new line.
Constraints
1 ≤ N ≤ 1000000

1 ≤ M ≤ 1000000

1 ≤ L ≤ R ≤ N

1 ≤ Q ≤ 1000000

1 ≤ X ≤ N
Sample Input
7
4
1 3
2 5
1 2
5 6
4
1
7
4
2
Sample Output
6
0
0
4
*******/

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define vll vector<ll>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    //cin>>t;
    while(t-->0)
    {
        ll n,m;
        cin>>n>>m;
        vll dp(n+2);
        for(int i=0;i<m;i++)
        {
            ll l,r;
            cin>>l>>r;
            dp[l]++;
            dp[r+1]--;
        }
        for(int i=1;i<=n;i++)
        {
            dp[i]+=dp[i-1];
        }
        
        
        vll ans(n+1);
        for(int i=1;i<=n;i++)
        {
            ll coins=dp[i];
            ans[coins]++;
        }
        
        
        for(ll i=n-1;i>=1;i--)
        {
            ans[i]+=ans[i+1];
        }
        ll q;
        cin>>q;
        for(int i=0;i<q;i++)
        {
            ll x;
            cin>>x;
            cout<<ans[x]<<"\n";
        }
    }
    return 0;
}
 
