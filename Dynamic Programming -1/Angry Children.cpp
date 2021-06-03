/*********
Angry Children
Send Feedback
Bill Gates is on one of his philanthropic journeys to a village in Utopia. He has N packets of candies and would like to distribute one packet to each of the K children in the village (each packet may contain different number of candies). To avoid a fight between the children, he would like to pick K out of N packets such that the unfairness is minimized.
Suppose the K packets have (x1, x2, x3,....xk) candies in them, where xi denotes the number of candies in the ith packet, then we define unfairness as
unfairness=0;
for(i=0;i<n;i++)
  for(j=i;j<n;j++)
    unfairness+=abs(xi-xj)
abs(x) denotes absolute value of x.
Input Format
The first line contains an integer N.
The second line contains an integer K.
N lines follow each integer containing the candy in the ith packet.
Output Format
A single integer which will be minimum unfairness.
Constraints
2<=N<=10^5

2<=K<=N

0<= number of candies in each packet <=10^9
Sample Input
7
3
10
100
300
200
1000
20
30
Sample Output
40
Explanation
Bill Gates will choose packets having 10, 20 and 30 candies.So unfairness will be |10-20| + |20-30| + |10-30| = 40. We can verify that it will be minimum in this way.
*******/

#include <bits/stdc++.h>
using namespace std;


//long long 
int main()
{
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    sort(arr,arr+n);
    
    long sum[n];
   for(int i=0;i<n;i++)
	{
		if(i>=1)
		{
			sum[i]=sum[i-1]+arr[i];
		}
		else 
		{
			sum[i]=arr[i];
		}
	}
	long cost=0;

	for(int i=1;i<k;i++)
		{
			cost=cost+(i*arr[i])-sum[i-1];
	
		}
	long ans=cost;
	for(int i=1;i<n-k;i++)
	{
		cost=cost-2*(sum[k+i-2]-sum[i-1])+(k-1)*(arr[i-1])+(k-1)*(arr[k+i-1]);
		if(ans>cost)
		{
			ans=cost;
		}
	}
    cout<<ans<<endl;
    return 0;
}

