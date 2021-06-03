/*****
Adjacent Bit Counts
Send Feedback
For a string of n bits x1,x2,x3,...,Xn the adjacent bit count of the string (AdjBC(x)) is given by
X1*X2 + X2*X3 + X3*X4 + ... + Xn-1 * Xn
which counts the number of times a 1 bit is adjacent to another 1 bit. For example:
AdjBC(011101101) = 3
AdjBC(111101101) = 4
AdjBC(010101010) = 0
Write a program which takes as input integers n and k and returns the number of bit strings x of n bits (out of 2ⁿ) that satisfy AdjBC(x) = k. For example, for 5 bit strings, there are 6 ways of getting AdjBC(x) = 2:
11100, 01110, 00111, 10111, 11101, 11011
Input
The first line of input contains a single integer P, (1 ≤ P ≤ 1000), which is the number of data sets that follow. Each data set is a single line that contains the data set number, followed by a space, followed by a decimal integer giving the number (n) of bits in the bit strings, followed by a single space, followed by a decimal integer (k) giving the desired adjacent bit count. The number of bits (n) will not be greater than 100.
Output
For each data set there is one line of output. It contains the data set number followed by a single space, followed by the number of n-bit strings with adjacent bit count equal to k. As answer can be very large print your answer modulo 10^9+7.
Sample Input
10
1 5 2
2 20 8
3 30 17
4 40 24
5 50 37
6 60 52
7 70 59
8 80 73
9 90 84
10 100 90
Sample Output
1 6
2 63426
3 1861225
4 168212501
5 44874764
6 160916
7 22937308
8 99167
9 15476
10 23076518
*****/
#include <bits/stdc++.h>
using namespace std;
/*****
    long long dp[101][101][2]; 
void bit_count()
{
  
    // If n = 1 and k = 0. 
    dp[1][0][0] = 1; 
    dp[1][0][1] = 1; 
  	for(int i=2;i<=100;i++){
        dp[i][i-1][0]=0;
        dp[i][i-1][1]=1;
        dp[i][0][0]= (dp[i-1][0][0]+ dp[i-1][0][1])%1000000007;
         dp[i][0][1]= dp[i-1][0][0];
    }
    for (int i = 2; i <= 100; i++) { 
  
        // number of adjacent 1's can not exceed i-1 
        for (int j = 1; j < i; j++) { 
            dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1])%1000000007; 
            dp[i][j][1] = (dp[i - 1][j][0] + dp[i - 1][j-1][1])%1000000007;
  
        } 
    }
 //   return (dp[n][k][1]+dp[n][k][0]) % 1000000007;
}

int main()
{
    int P;
    cin>>P;
    bit_count();
   for(int i=1;i<=P;i++)
   {
       int n,k;
       cin>>n>>k;
       if(n==0 && k==0){
           cout<<i<<' '<<1<<endl;
           continue;
       }
       cout<<i<<" "<<(dp[n][k][0]+dp[n][k][1])%1000000007<<endl;
   }
    return 0;
}

****/







#include<iostream>
#define mod 1000000007
#define fon(i,n) for(int i=0 ; i<n ; i++)
#define cn currentBitCount
#define st start
using namespace std;
int dp[101][101][2];
int len,bitCount;
void init(){
  fon(i,101)
    fon(j,101)
      fon(k,2)  dp[i][j][k]=-1;
}


int solve(int st , int cn ,int preBit)
{
  if(st==len)
    return (bitCount==cn);
  int &ans=dp[st][cn][preBit];
  if(ans!=-1)  
      return ans;
  ans=solve(st+1 , cn+preBit , 1);
  ans+=solve(st+1 , cn , 0);
  ans%=mod;
  return ans;
}


int main()
{
  int t,sn;
  cin>>t;
  while (t--) {
    cin>>sn>>len>>bitCount;
    init();
    int ans=solve(0,0,0);
    cout<<sn<<" "<<ans<<endl;
  }
}


