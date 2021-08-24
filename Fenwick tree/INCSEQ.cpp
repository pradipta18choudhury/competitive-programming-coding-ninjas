/********
INCSEQ
Send Feedback
Given a sequence of N (1 ≤ N ≤ 10,000) integers S1, ..., SN (0 ≤ Si < 100,000), 
compute the number of increasing subsequences of S with length K (1 ≤ K ≤ 50 and K ≤ N); that is, 
the number of K-tuples i1, ..., iK such that 1 ≤ i1 < ... < iK ≤ N and Si1 < ... < SiK.
Input
The first line contains the two integers N and K. The following N lines contain the integers of the sequence in order.
Output
Print a single integer representing the number of increasing subsequences of S of length K, modulo 5,000,000.
Sample Input
4 3
1
2
2
10
Output:
2
*******/


#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define memo(a,b) memset(a,b,sizeof(a))
#define INF 1e9
#define EPS 1e-8
#define PI 3.14159265358979323846

typedef long long ll ;
typedef unsigned long long ull ;


int n , k , ans = 0 , mod = 5000000 ;
ll tree[51][100000+10] ;

void update(int idx,int j ,ll V)
{
    while(idx<=100005)
    {
        tree[j][idx]=(tree[j][idx]+V)%mod;
        idx+=idx&(-idx);
    }
}

ll query(int idx,int j)
{
    ll sum=0;
    while(idx>0)
    {
        sum=(sum+tree[j][idx])%mod;
        idx-=idx&(-idx);
    }
    return sum;
}

int main()
{
    
    scanf("%d%d",&n,&k);
    for(int j=1;j<=n;j++)
    {
        int a ;
        scanf("%d",&a);
        a++;
        for(int i=1;i<=k;i++)
        {
            ll p =  i == 1 ? 1 : query(a-1,i-1);
            update(a,i,p);
            if(i==k) ans=(ans+p)%mod;
        }
    }
    cout << ans << endl ;
    return 0;
}
