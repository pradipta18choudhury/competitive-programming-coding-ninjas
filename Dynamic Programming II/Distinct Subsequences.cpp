/*******
Given a string, count the number of distinct subsequences of it ( including empty subsequence ). 
For the uninformed, A subsequence of a string is a new string which is formed from the original 
string by deleting some of the characters without disturbing the relative positions of the remaining characters.
For example, "AGH" is a subsequence of "ABCDEFGH" while "AHG" is not.
Input
First line of input contains an integer T which is equal to the number of test cases. You are required to process 
all test cases. Each of next T lines contains a string s.
Output
Output consists of T lines. Ith line in the output corresponds to the number of distinct subsequences of ith input string.
Since, this number could be very large, you need to output ans%1000000007 where ans is the number of distinct subsequences. 
Constraints and Limits
T ≤ 100, length(S) ≤ 100000

All input strings shall contain only uppercase letters.
Sample Input
3
AAA
ABCDEFG
CODECRAFT
Sample Output
4
128
496
*******/
/*****
Now for example lets take mod = 5
 lets suppose dp[i-1] = 4 &  dp[i] = 6
 now since dp[i] is more than 5, we have to take mod. Now it will become 1
 
 now since I was doing a subtraction
 dp[i]-=dp[i-1]  // dp[i] will become -3
dp[i] has become negative, so I am adding mod, because technically it changes nothing in the answer! // now dp[i] will become -3+5 =2
And because of that dp[i] has again become positive!
we dont want dp[i] to be negative, so remember whenever there is a substraction involved in the question and a mod is involved,
adding a mod becomes mandatory for us!
*****/

#include <bits/stdc++.h>
using namespace std;
#include <vector>
int MAX=256;
long mod=1000000007;

int subsequence(string s)
{
    int n=s.length();
    int dp[n+1];
    vector<int> last_occur(MAX,-1);
    
    dp[0]=1;//base case
    //we r considering empty string also
    for(int i=1;i<=n;i++)
    {
        dp[i]=(2*dp[i-1])%mod;// we need to twice everytime
        if(last_occur[s[i-1]]!=-1)// whether thae character has already arrived
            dp[i]=(dp[i]%mod-dp[last_occur[s[i-1]]]%mod+mod)%mod;
        
        last_occur[s[i-1]]=(i-1);
    }
    
    int ans=dp[n]%mod;
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
       // int n=strlen(s);
        int ans=subsequence(s);
        cout<<ans<<endl;
    }
    return 0;
}
