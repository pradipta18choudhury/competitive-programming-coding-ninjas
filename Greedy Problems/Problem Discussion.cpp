/******
Problem discussion
Send Feedback
Harshit gave Aahad an array of size N and asked to minimize the difference between the maximum value and minimum value by
modifying the array under the condition that each array element either increase or decrease by k(only once).
It seems difficult for Aahad so he asked for your help
Input Format
The First line contains two space-separated integers: N,K
Next lines contain N space-separated integers denoting elements of the array
Output Format
The output contains a single integer denoting the minimum difference between maximum value and the minimum value in the array
Constraints
1 =< N <= 10^5 
1 <= Ai,K <= 10^9
Sample Input1:
3 6
1 15 10
Sample Output1:
5
Explaination
We change from 1 to 6, 15 to  9 and 10 to 4. Maximum difference is 5 (between 4 and 9). We can't get a lower difference.
******/
#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int n;
    int k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i]; 
    }
	sort(arr,arr+n);
    int ans=arr[n-1]-arr[0];
    int small=arr[0]+k;
    int big=arr[n-1]-k;
    if(small>big)
    swap(small,big);
    
    for(int i=1;i<=n;i++)
    {
        int subtract=arr[i]-k;
        int add=arr[i]+k;
        
        if(subtract>=small || add<=big)
            continue;
        else if(big-subtract<=add-small)
            small=subtract;
        else
            big=add;
    }
    cout<<min(ans,(big-small));
    return 0;
}
