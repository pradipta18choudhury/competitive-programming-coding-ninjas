#include <bits/stdc++.h>
using namespace std;

void _mergesort(int arr[],int temp[],int left,int mid,int right)
{
    int i,j,k;
    i=left;
    k=left;
    j=mid;
    while(i<=mid-1 && j<=right)
    {
        if(arr[i]<=arr[j])
        {
            temp[k++]=arr[i++];
        }
        else
        {
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid-1)
        temp[k++]=arr[i++];
    while(j<=right)
        temp[k++]=arr[j++];
    for(int i=left;i<=right;i++)
    {
        arr[i]=temp[i];
    }
    return;
}

void _merge(int arr[],int temp[],int left,int right)
{
	  int mid;
    if(left>=right)
        return;
    if(left<right)
    {
        int mid=(left+right)/2;
        _merge(arr,temp,left,mid);
        _merge(arr,temp,mid+1,right);
        _mergesort(arr,temp,left,mid+1,right);
    }
}

void mergeSort(int input[], int size){
	// Write your code here
    int temp[size];
      _merge(input,temp,0,size-1);  
}
int main() {
  int length;
  cin >> length;
  int* input = new int[length];
  for(int i=0; i < length; i++)
    cin >> input[i];
  mergeSort(input, length);
  for(int i = 0; i < length; i++) {
    cout << input[i] << " ";
  }
}

/******
Merge Sort Code
Send Feedback
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)
Output format :
Array elements in increasing order (separated by space)
Constraints :
1 <= n <= 10^3
Sample Input 1 :
6 
2 6 8 5 4 3
Sample Output 1 :
2 3 4 5 6 8
Sample Input 2 :
5
2 1 5 2 3
Sample Output 2 :
1 2 2 3 5 
*****/
