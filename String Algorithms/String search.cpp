/********
String Search
Send Feedback
Given two strings S and T, write a function to find if T is present as a substring inside S or not. If yes, return the starting index otherwise return -1.
Input format :

Line 1 : String S

Line 2 : String T

Sample Input 1:
WelcomeBack
come 
Sample Output 1:
3
Sample Input 2:
WelcomeBack
code
Sample Output 2:
-1
********/

#include<bits/stdc++.h>
using namespace std;
#include <cstring>


int *getKMP(string arr)
{
    int size=sizeof(arr);
    int *c=new int[size];
    int i=1,j=0;
    c[0]=0;
    
    while(i<size)
    {
        if(arr[i]==arr[j])
        {
            c[i]=j+1;
            i++;j++;
        }
        else
        {
            if(j!=0)
                j=c[j-1];
            else
            {
                c[i]=0;
                i++;
            }
        }
    }
    return c;
}


int findString(char S[], char T[]) {
    // Write your code here
    int lenS=strlen(S);
    int lenT=strlen(T);
    
    int i=0,j=0;
    int isMatch=-1;
    int *arr=getKMP(T);
    while(i<lenS && j<lenT)
    {
     	if(S[i]==T[j])
        {
            //isMatch=i;
            i++;j++;
        }
        else
        {
            if(j!=0)
                j=arr[j-1];
            else
                i++;
        }
        if(j==lenT)
        {
            isMatch=(i-j);
            j=arr[j-1];
        }
    }
    if(isMatch>0)
        return isMatch;
    else
        return -1;
//return isMatch;
}
