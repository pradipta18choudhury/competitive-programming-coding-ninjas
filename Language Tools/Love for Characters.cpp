#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char p[n];
    for(int i=0;i<n;i++)
    {
        cin>>p[i];
    }
    cout<<count(p,p+n,'a')<<" "<<count(p,p+n,'s')<<" "<<count(p,p+n,'p')<<endl;
	return 0;
}
/******
Love for Characters
Send Feedback
Ayush loves the characters ‘a’, ‘s’, and ‘p’. He got a string of lowercase letters and he wants to find out how many
times characters ‘a’, ‘s’, and ‘p’ occurs in the string respectively. Help him find it out.
Input:
First line contains an integer denoting length of the string.
Next line contains the string.
Constraints:
1<=n<=10^5
‘a’<= each character of string <= ‘z’
Output:
Three space separated integers denoting the occurrence of letters ‘a’, ‘s’ and ‘p’ respectively.
Sample Input:
6
aabsas
Sample output:
3 2 0
****/
