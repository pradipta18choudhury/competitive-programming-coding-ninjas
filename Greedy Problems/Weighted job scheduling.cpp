/*******
Weighted Job Scheduling
Send Feedback
You are given N jobs where every job is represented as:
1.Start Time
2.Finish Time
3.Profit Associated
Find the maximum profit subset of jobs such that no two jobs in the subset overlap.
Input
The first line of input contains one integer denoting N.
Next N lines contains three space separated integers denoting the start time, finish time and the profit associated with the ith job. 
Output
Output one integer, the maximum profit that can be achieved.
Constraints
1 ≤ N ≤ 10^6
1 ≤ ai, di, p ≤ 10^6
Sample Input
4
3 10 20
1 2 50
6 19 100
2 100 200
Sample Output
250
******/

#include<bits/stdc++.h>
using namespace std;

struct job{
    int start,finish,profit;
};

bool compare(job s1,job s2)
{
    return (s1.finish < s2.finish);
}


int binarySearch(job arr[],int n)
{
	int start=0;
    int end=n-1;
    while(start<=end)
    {
        int mid=(start+end)/2;
        if (arr[mid].finish <= arr[n].start) 
        { 
            if (arr[mid + 1].finish <= arr[n].start) 
                start = mid + 1; 
            else
                return mid; 
        } 
        else
            end = mid - 1; 
    } 
  
    return -1; 
}

int findMaxProfit(job arr[], int n) 
{ 
    // Sort jobs according to finish time 
    sort(arr, arr+n, compare); 
    int *table = new int[n]; 
    table[0] = arr[0].profit; 
    for (int i=1; i<n; i++) 
    { 
        int inclProf = arr[i].profit; 
        int l = binarySearch(arr, i); 
        if (l != -1) 
            inclProf += table[l]; 
        table[i] = max(inclProf, table[i-1]); 
    } 
    int result = table[n-1]; 
    delete[] table; 
  
    return result; 
} 




int main()
{
    //Write your code here
    int n;
    cin>>n;
    job arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i].start>>arr[i].finish>>arr[i].profit;
    }
    cout<<findMaxProfit(arr,n);
    return 0;
}
