/********
Largest Bitonic Subarray
Send Feedback
You are given an array of positive integers as input. Write a code to return the length of the largest such subsequence in which
the values are arranged first in strictly ascending order and then in strictly descending order.
Such a subsequence is known as bitonic subsequence. A purely increasing or purely decreasing subsequence will also be considered
as a bitonic sequence with the other part empty.
Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.
Input Format:
Line 1 : A positive Integer N, i.e., the size of array
Line 2 : N space-separated integers as elements of the array 
Output Format:
Length of Largest Bitonic subsequence
Input Constraints:
1<= N <= 10000
Sample Input 1:
6
15 20 20 6 4 2
Sample Output 1:
5
Sample Output 1 Explanation:
Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5.
Sample Input 2:
2
1 5
Sample Output 2:
2
Sample Input 3:
2
5 1
Sample Output 3:
2
*******/

#include <bits/stdc++.h>
using namespace std;

/******
int longestBitonicSubarray(int *input, int n) {
		
	/* Don't write main().
     	* the input is already passed as function argument.
     	* Taking input and printing output is handled automatically.
     	
    int *out1=new int[n];
    for(int i=0;i<n;i++)
        out1[i]=1;
    
    for(int i=1;i<n;i++)
        for(int j=i-1;j>=0;j--)
        {
            if(input[i]<input[j])
                continue;
            out1[i]=out1[j]+1;
        }
            
            
    int *out2=new int[n];
    for(int i=0;i<n;i++)
        out2[i]=1;
    
    for(int i=n-2;i>=0;i--)
        for(int j=n-1;j>i;j--)
            if(input[i]>input[j] && out2[i]<out2[j]+1)
                out2[i]=out2[j]+1;
    
    int max=out1[0]+out2[0]-1;
    for(int i=1;i<n;i++)
        if(max<out1[i]+out2[i]-1)
            max=out1[i]+out2[i]-1;
    
    return max;
    
}
****/


int longestBitonicSubarray(int *input, int n) {
		
	/* Don't write main().
     	* the input is already passed as function argument.
     	* Taking input and printing output is handled automatically.
     	*/
    int *out1=new int[n];
    for(int i=0;i<n;i++)
        out1[i]=0;
    out1[0] = 1;
    for(int i=1;i<n;i++)
    {
        int t=0;
        for(int j=i-1;j>=0;j--)
        {
            if(input[i]>input[j])
                t = max(t , out1[j]);
                
            //     continue;
            // out1[i]=out1[j]+1;
        }
        out1[i] = t+1;
    }
            
    int *out2=new int[n];
    for(int i=0;i<n;i++)
        out2[i]=1;
    
    for(int i=n-2;i>=0;i--)
    {
        int t=0;
        for(int j=n-1;j>i;j--)
            if(input[i]>input[j])
                t = max(t,out2[j]);
                // out2[i]=out2[j]+1;
        out2[i] = t+1;
    }
    
    int max=out1[0]+out2[0]-1;
    for(int i=1;i<n;i++)
        if(max<out1[i]+out2[i]-1)
            max=out1[i]+out2[i]-1;
    
    return max;
    
}
