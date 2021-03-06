/**********
Ghost Type
Send Feedback
Gengar has got an integer N. Now using his ghostly powers, he can create the permutation from 1 to N of this given number.
Since, he's a special kind of Poke'mon, so he thinks he deserves special permutations. He wants to find the total number of special permutations of length N, consisting of the integers from 1 to N
.

A permutation is called special if it satisfies following condition:
If Ap & Aq == Ap, then p < q, where p and q are two distinct indices of permutation and A is the permutation itself. "&" denotes the bitwise and operation.
Help Gengar in finding the number of such permutations.
Input format:
The only line of input will consist of a single integer N denoting the length of the permutation.
Output format:
Output the total number of special permutations of length N
.

Constraints:
1 ≤ N ≤ 20

SAMPLE INPUT
4

SAMPLE OUTPUT
8

Explanation
All the special permutations of length 4 are: 1 2 3 4

1 2 4 3

1 4 2 3

2 1 3 4

2 1 4 3

2 4 1 3

4 1 2 3

4 2 1 3
**********/

#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<long long> dp((1<<n)+2);
	dp[0]=1;
	for(int mask=0;mask<(1<<n);mask++)
	{
		for(int i=0;i<n;i++)
		{
			if((mask&(1<<i))==0)
			{
				int fl=0;
				for(int j=0;j<n;j++)
				{
					if(mask&(1<<j) && ((i+1)&(j+1))==(j+1))
					{
						fl=1;
					}
 
				}
				if(fl==0)
				{
					dp[mask|(1<<i)]+=dp[mask];
				}
			}
			
		}
	}
	cout<<dp[(1<<n)-1]<<'\n';
}
int main()
{
	int n;
	cin>>n;
	vector<long long> dp((1<<n)+2);
	dp[0]=1;
	for(int mask=0;mask<(1<<n);mask++)
	{
		for(int i=0;i<n;i++)
		{
			if((mask&(1<<i))==0)
			{
				int fl=0;
				for(int j=0;j<n;j++)
				{
					if(mask&(1<<j) && ((i+1)&(j+1))==(j+1))
					{
						fl=1;
					}
 
				}
				if(fl==0)
				{
					dp[mask|(1<<i)]+=dp[mask];
				}
			}
			
		}
	}
	cout<<dp[(1<<n)-1]<<'\n';
}
