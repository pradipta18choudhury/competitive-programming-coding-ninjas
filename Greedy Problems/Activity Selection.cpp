/*******
Activity Selection
Send Feedback
You are given n activities with their start and finish times. Select the maximum number of activities that can be
performed by a single person, assuming that a person can only work on a single activity at a time.
Input
The first line of input contains one integer denoting N.
Next N lines contains two space separated integers denoting the start time and finish time for the ith activity.

Output
Output one integer, the maximum number of activities that can be performed
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di ≤ 10^9
Sample Input
6
1 2
3 4
0 6
5 7
8 9
5 9
Sample Output
4
*******/
#include <bits/stdc++.h>
using namespace std; 


struct Activity 
{ 
    int start, finish; 
}; 


bool Sort_activity(Activity s1, Activity s2) 
{ 
    return (s1.finish< s2.finish); 
} 


void print_Max_Activities(Activity arr[], int n) 
{  
	sort(arr, arr+n, Sort_activity); 
    int i = 0; 
	int count=1;
    for (int j = 1; j < n; j++) 
    { 
      	if (arr[j].start>= arr[i].finish) 
      	{	 
			count++;
			i = j; 
      	} 
    } 
    cout<<count<<endl;
} 


int main() 
{ 
    int N;
    cin>>N;
    Activity arr[N];
	for(int i=0; i<=N-1; i++)
	{
		cin>>arr[i].start>>arr[i].finish;
    }

	print_Max_Activities(arr, N); 
    return 0; 
}
