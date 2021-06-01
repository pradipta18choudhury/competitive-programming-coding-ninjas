/******
Winning Lottery
Send Feedback
Harshit knows by his resources that this time the winning lottery number is the smallest number whose sum of the digits is S and the number of digits is D. You have to help Harshit and print the winning lottery number.
Input Format
The Input line contains two space-separated integers: S,D
Output Format
The output contains a single integer denoting the winning lottery number
Constraints
1 <= D <= 1000
1 <= S <= 9*D
Time Limit: 1 second
Sample Input1:
9 2
Sample Output1:
18
Explanation
There are many other possible numbers like 45, 54, 90, etc with the sum of digits as 9 and number of digits as 2. The smallest of them is 18.
******/

#include<bits/stdc++.h>
#include<bits/stdc++.h>
using namespace std;
int main() {

	// Write your code here
    int sum,digit;
    cin>>sum>>digit;
    int arr[digit];
    arr[0]=1;
    int rsum=sum-1;
    for(int i=digit-1;i>=1;i--)
    {
        int d=9;
        if(d<=rsum)
        {
            arr[i]=d;
            rsum-=d;
        }
        else
        {
            arr[i]=rsum;
            rsum=0;
        }
    }
    
    for(int i=0;i<digit;i++)
        cout<<arr[i];
    
}
