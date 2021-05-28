/*
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


long long _mergeSort(long long arr[],long long temp[],
                    long long left,long long mid,long long right)
{
    long long i,j,k,sum;
    i=left;
    j=mid;
    k=left;
    sort(arr,arr+mid);
    sort(arr+mid+1,arr+right);
    while((i <= mid-1) && (j <= right))
    {
        if(arr[i]<arr[j])
        {
            sum+=arr[i]*(right-mid+1);
            temp[k++]=arr[i++];
        }
        else if(arr[i]>arr[j])
        {
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid-1)
        temp[k++]=arr[i++];
    while(j<=right)
        temp[k++]=arr[j++];
    for(int i=left;i<right;i++)
      arr[i]=temp[i];
    
    return sum;
}

long long _merge(long long arr[],long long temp[],long long left,long long right)
{
    long long mid,sum1,sum2,sum3;
    while(left<right)
    {
        mid=left+(right-left)/2;
    	sum1 += _merge(arr,temp,left,mid);
        sum2 += _merge(arr,temp,mid+1,right);
        sum3 += _mergeSort(arr,temp,left,mid+1,right);
    }
    return (sum1+sum2+sum3);
}

int main() {
	int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        long long temp[n];
        cout<<_merge(arr,temp,0,n-1);
        cout<<endl;
    }
	// Write your code here
    return 0;
}
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


long long _mergeSort(long long arr[],long long temp[],
                    long long left,long long mid,long long right)
{
    long long i,j,k,sum=0;
    i=left;
    j=mid + 1;
    k=left;
    while((i <= mid) && (j <= right))
    {
        if(arr[i]<arr[j])
        {
            sum+=arr[i]*(right-j+1);
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid)
        temp[k++]=arr[i++];
    while(j<=right)
        temp[k++]=arr[j++];
    for(int i=left;i<right+1;i++)
      arr[i]=temp[i];
    
    return sum;
}

long long _merge(long long arr[],long long temp[],long long left,long long right)
{
    long long mid,sum1=0,sum2=0,sum3=0;
    if(left<right)
    {
        mid=left+(right-left)/2;
    	sum1 = _merge(arr,temp,left,mid);
        sum2 += _merge(arr,temp,mid+1,right);
        sum3 += _mergeSort(arr,temp,left,mid,right);
    }
    return (sum1+sum2+sum3);
}

int main() {
	int t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        long long temp[n];
        cout<<_merge(arr,temp,0,n-1);
        cout<<endl;
    }
	// Write your code here
    return 0;
}

/******
Murder
Send Feedback
Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a
number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till
now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each
number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than 
the present number. Calculate the sum of all the numbers written on his notes diary.
Answer may not fit in integer . You have to take long.
Input
First line gives T, number of test cases.

2T lines follow.

First line gives you the number of stairs N

Next line gives you N numbers written on the stairs.
Output
For each test case output one line giving the final sum for each test case.
Constraints
T<=10

1<=N<=10^5

All numbers will be between 0 and 10^6.
Sample Input:
1
5
1 5 3 6 4
Sample Output:
15
Explanation:
For the first number, the contribution to the sum is 0.
For the second number, the contribution to the sum is 1.
For the third number, the contribution to the sum is 1.
For the fourth number, the contribution to the sum is 9 (1+5+3).
For the fifth number, the contribution to the sum is 4 (1+3).
Hence the sum is 15 (0+1+1+9+4).
******/
