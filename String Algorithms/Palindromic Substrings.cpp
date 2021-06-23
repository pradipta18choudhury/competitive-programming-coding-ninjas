/******
Palindromic Substrings
Send Feedback
Given a string S, count and return the number of substrings of S that are palindrome.
Single length substrings are also palindromes. You just need to calculate the count, not the substrings.
Input Format :
String S
Output Format :
count of palindrome substrings
Constraints :
1 <= Length of S <= 1000
Sample Input :
aba
Sample Output :
4
**Note : Here 4 corresponds to ("a","b","a","aba").
******/
#include  <cstring>
#include<bits/stdc++.h>
using namespace std;


int countPalindromeSubstrings(char s[]) {
	// Write your code here
    int n=strlen(s);
    int max1=0,max2=0;
    
    for(int i=0;i<n;i++)
    {
        //odd place
        int l=i;
        int r=i;
        while(l>=0 && r<n && s[l]==s[r])
        {
            max1++;
            l--;r++;
        }
        
        //even place
        l=i;
        r=i+1;
        while(l>=0 && r<n && s[l]==s[r])
        {
            max2++;
            l--;r++;
        }
        
    }
    return max1+max2;
	
}

//------------------------------------------------------------------  ANOTHER APPROACH   ----------------------------------------------------------------------------------
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int countPalindromeSubstrings(string s) {
	// Write your code here
    // unordered_set<string> ps;
    int max1=0,max2=0;
     int n=s.length();
     for(int i=0;i<n;i++){
         //Odd
         int l=i;
         int r=i;
         while(l>=0 and r<n and s[l]==s[r]){
            // ps.insert(s.substr(l,r));
             l--;
             //rthe++;
             max1++;
             r++;
         }
        //Even
        l=i;
        r=i+1;
          while(l>=0 and r<n and s[l]==s[r]){
             //ps.insert(s.substr(l,r));
             l--;max2++;
             r++;
         }
             
         }
     
     return max1+max2;
        
}
