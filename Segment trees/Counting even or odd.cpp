/******
Counting Even/Odd
Send Feedback
Ashu and Shanu are best buddies. One day Shanu gives Ashu a problem to test his intelligence.He gives him an array of N natural numbers and asks him to solve the following queries:-
Query 0 :- modify the element present at index i to x.
Query 1:- count the number of even numbers in range l to r inclusive.
Query 2:- count the number of odd numbers in range l to r inclusive.
Input:
First line of the input contains the number N. Next line contains N natural numbers. 
Next line contains an integer Q followed by Q queries.

0 x y - modify the number at index x to y. 

1 x y - count the number of even numbers in range l to r inclusive.

2 x y - count the number of odd numbers in range l to r inclusive.
Constraints:
1<=N,Q<=10^5

1<=l<=r<=N 

0<=Ai<=10^9

1<=x<=N

0<=y<=10^9
Note:-
indexing starts from 1.
Sample Input
6
1 2 3 4 5 6
4
1 2 5
2 1 4
0 5 4
1 1 6
Sample Output
2
2
4
********/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll tree[300000];
ll arr[200000];

void build(ll i,ll s, ll e)
{
  if(s==e)
  {
    tree[i]=arr[s];
    return;
  }
  else
  {
    ll mid=(s+e)/2;
    build(2*i,s,mid);
    build(2*i+1,mid+1,e);
    tree[i]=tree[2*i]+tree[2*i+1];
  }
}

void update(ll i,ll s,ll e,ll idx,ll val)
{
  if(s==e)
  {
    tree[i]=tree[i]-arr[idx]+val;
    arr[idx]=val;
  }
  else
  {
    ll mid=(s+e)/2;
    if(s<=idx && idx<=mid)
    {
      update(2*i,s,mid,idx,val);
    }
    else
    {
      update(2*i+1,mid+1,e,idx,val);
    }
    tree[i]=tree[2*i]+tree[2*i+1];
  }
}


ll query(ll i, ll s,ll e,ll l,ll r)
{
  if(r<s || l>e)
    return 0;
  if(l<=s && e<=r)
    return tree[i];
  
  ll mid=(s+e)/2;
  ll ans1=query(2*i,s,mid,l,r);
  ll ans2=query(2*i+1,mid+1,e,l,r);
  return ans2+ans1;
}
int main()
{
  ll n;
  cin>>n;
  for(ll i=1;i<=n;i++)
  {
    ll g;
    cin>>g;
    arr[i]=g%2==0?1:0;
  }
  build(1,1,n);
  ll t;
  cin>>t;
  while(t--)
  {
    int c;
    cin>>c;
    if(c==1)
    {
      ll a,b;
      cin>>a>>b;
      cout<<query(1,1,n,a,b)<<"\n";
    }
    else if(c==0)
    {
      ll idx,val;
      cin>>idx>>val;
      update(1,1,n,idx,val%2==0?1:0);
    }
    else
    {
      ll a,b;
      cin>>a>>b;
      cout<<b-a+(b!=a?1:0)-query(1,1,n,a,b)<<"\n";
    }
  }
  return 0;
}
