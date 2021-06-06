/******
Dilemma
Send Feedback
Abhishek, a blind man recently bought N binary strings all of equal length .\
A binary string only contains '0's and '1's . The strings are numbered from 1 to N and
all are distinct, but Abhishek can only differentiate between these strings by touching them.
In one touch Abhishek can identify one character at a position of a string from the set. 
Find the minimum number of touches T Abhishek has to make so that he learn that all strings are different .
Constraints :
2<=N<=10
1<=|L|<=100 , L is length of the strings .
Input Format:
Line 1 : An Integer N, denoting the number of binary strings .
Next N lines : strings of equal length
Output Format:
Return the minimum number of touches
Sample Input :
2
111010
100100
Sample Output :
2
*****/
#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*****    ----------------------------------------------------------- APPROACH ---------------------------------------------------
given n strings of length L
0<=n<=10
0<=L<=100

we need to distinguish the strings in minimum touches
1010
0101     for distinguishing, in first string first character is 1
		 in the second string first chacracter is 0
         so minimum touches=2
         
1001
1100     minimum touches=3 as first characters are same

if only 1 string is left,
no need to distinguish it, touches=0;


******/
int find_touches(int pos,int mask,vector<string>&v,int **dp)
{
    if((mask&(mask-1)) ==0)
        return 0;
    
     if(pos<0)
        return 10000;
    
    if(dp[pos][mask]!=INT_MAX)
        return dp[pos][mask];
    
    
    int newMask1=0;
    int newMask2=0;
    //int ans=0;
    int touches=0;
    
    for(int i=0;i<v.size();i++)
    {
        if(mask&(1<<i))
        {
            touches++;
                if(v[i][pos]=='0')
                {
                    newMask1 |= 1<<i;
                }
       			 else{
            		newMask2 |= 1<<i;
                 }
            }
    }
    
    int ans1=find_touches(pos-1,newMask1,v,dp)+find_touches(pos-1,newMask2,v,dp)+touches;
    int ans2=find_touches(pos-1,mask,v,dp);
    int ans=min(ans1,ans2);
    dp[pos][mask]=ans;
    
    return ans;
}

int minimumTouchesRequired(int n, vector<string> v) {
    /* Don't write main().
     * Don't read input, they are passed as function arguments.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    
    int **dp=new int*[v[0].size()];
    for(int i=0;i<v[0].size();i++)
    {
        dp[i]=new int[(1<<(n+1))];
        for(int j=0;j<(1<<(n+1));j++)
            dp[i][j]=INT_MAX;
    }
    
    return find_touches(v[0].size()-1,(1<<n)-1,v,dp);
}

//---------------------------------------------------- ANOTHER APPROACH  -------------------------------------------------------------------------------------------------
#include<vector>
#include<algorithm>
#include<climits>
#include<string>
using namespace std;
int dp[105][1 << 12];
int find_touches(int pos, int mask, vector<string> &v)
{
    if (!(mask & (mask - 1)) && mask)
        // everything was recongnised successfully when mask contains only one bit set
        return 0;

    if (pos == -1 || mask == 0)
        return 100000;

    if (dp[pos][mask])
        return dp[pos][mask];

    int newmask1 = 0, newmask2 = 0, touches = 0;
    //if we touch the v[any][pos],mask will split.
    for (int i = 0; i < v.size(); i++)
    {
        if ((mask >> i) & 1)
        {
            touches++;
            if (v[i][pos] == '0')
            {
                newmask1 |= (1 << i);
            }
            else
            {
                newmask2 |= (1 << i);
            }
        }
    }
    return dp[pos][mask] = min(find_touches(pos - 1, newmask1, v) + 
                               find_touches(pos - 1, newmask2, v) +
                               touches, find_touches(pos - 1, mask, v));
}

int minimumTouchesRequired(int n, vector<string> v)
{
    return find_touches(v[0].size() - 1, (1 << n) - 1, v);
}

int main() {
    int n;
    
    vector<string> v;
    
	cin >> n;
	for(int i = 0; i < n; i++) {
		string a;
		cin >> a;
		v.push_back(a);
	}
	cout << minimumTouchesRequired(n, v) << endl;
}
