/********
String Maker
Send Feedback
According to Ancient Ninjas , string making is an art form . There are various methods of string making , 
one of them uses previously generated strings to make the new one . Suppose you have two strings A and B ,
to generate a new string C , you can pick a subsequence of characters from A and a subsequence of characters
from B and then merge these two subsequences to form the new string.
Though while merging the two subsequences you can not change the relative order of individual subsequences. 
What this means is - suppose there two characters Ai and Aj in the subsequence chosen from A , where i < j , 
then after merging if i acquires position k and j acquires p then k<p should be true and the same apply for subsequence from C.
Given string A , B , C can you count the number of ways to form string C from the two strings A and B by the 
method described above. Two ways are different if any of the chosen subsequence is different .
As the answer could be large so return it after modulo 10^9+7 .
Input Format :
Line 1 : String A
Line 2 : String B
Line 3 : String C
Output Format :
The number of ways to form string C
Constraints :
1 <= |A|, |B|, |C| <= 50
Sample Input :
abc
abc 
abc
Sample Output :
8
*******/

#include <cstring>
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int dp[52][52][52];
 //------------------------------------------------------------- APPROACH 1 ---------------------------------------------------------------------------
int solve(string a,string b,string c)
{
	// Write your code here .
    int dp[a.length()][b.length()][c.length()];
    memset(dp,-1,sizeof(dp));
    
    
    int ways=0;
    if(a.length()<0 || b.length()<0)
        return 0;
    if(c.length()==0)
        return 1;
   // if(dp[a.size()][b.size()][c.size()]!=-1)
        //return dp[a.size()][b.size()][c.size()];
    

    
    for(int i=0;i<a.length();i++)
    {
        if(a[i]==c[0])
          ways +=  solve(a.substr(i+1),b,c.substr(1));
    }
    
    for(int j=0;j<b.length();j++)
    {
        if(b[j]==c[0])
            ways += solve(a,b.substr(j+1),c.substr(1));
    }
    //dp[a.size()][b.size()][c.size()]=ways;
    return ways;
}

// -------------------------------------------------------------------------- APPROACH_2 ------------------------------------------------------------------------------

int helper(string a,string b,string c,int x,int y,int z)
{
    if(z==0)
        return 1;
    if(x<=0 && y<=0)
        return 0;
    if(dp[x][y][z]!=-1)
        return dp[x][y][z];
    
	int ways=0;
    for(int i=x-1;i>=0;i--)
    {
        if(a[i]==c[z-1])
        {
            ways+=helper(a,b,c,i,y,z-1);
            ways=ways%mod;
        }
    }
    
    for(int j=y-1;j>=0;j--)
    {
        if(b[j]==c[z-1])
        {
            ways+=helper(a,b,c,x,j,z-1);
            ways=ways%mod;
        }
    }
    
    return dp[x][y][z]=ways;
}

int solve(string a,string b,string c)
{
    memset(dp,-1,sizeof(dp));
    return helper(a,b,c,a.size(),b.size(),c.size());
}

int main()
{
	string a,b,c;
	cin>>a>>b>>c;
	cout<<solve(a,b,c)<<endl;
}
