/*******
Boredom
Send Feedback
Gary is bored and wants to play an interesting but tough game . So he figured out a new board game called "destroy the neighbours" .

In this game there are N integers on a board. In one move, he can pick any integer x from the board and then all the integers with
value x+1 or x-1 gets destroyed .This move will give him x points.
He plays the game until the board becomes empty . But as he want show this game to his friend Steven, he wants to learn techniques 
to maximise the points to show off . Can you help Gary in finding out the maximum points he receive grab from the game ?
Note: The element to be picked is also removed from the list.
Input Format :
Line 1 : Integer N 
Line 2 : A list of N integers
Output Format :
Maximum points Gary can recieve from the Game setup
Constraints :
1<=N<=10^5
1<=A[i]<=1000
Sample Input :
2
1 2
Sample Output :
2
********/
#include <bits/stdc++.h>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
/**********
int solve(int n,vector<int>A){
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  
	int dp[n+1];
    dp[0]=0;
    dp[1]=A[1];
    //int n1=dp.size();
    
    for(int i=2;i<n;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+i*A[i]);
    }
    return dp[n];
}

********/


int solve(int n,vector<int>v){
  /* Don't write main().
     Don't read input, it is passed as function argument.
     Return output and don't print it.
     Taking input and printing output is handled automatically.
  */

     int * arr= new int [1001];
     int * sum= new int [1001];

    for(int i=0;i<1001;i++)
    {
        arr[i]=0;
    }
    
      for(int i=0;i<n;i++)
      {
          ++arr[v[i]];
      }

    sum[0]=0;
    sum[1]=1*arr[1];
    
    
    for(int i=2;i<=1000;i++)
    {
        int a=i*arr[i] + sum[i-2];
        int b= sum[i-1];
        
        sum[i]=max(a,b);
    }

    return sum[1000];
    
}
int n;
vector<int>A;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		A.push_back(x);
	}
	cout<<solve(n,A)<<endl;
}
