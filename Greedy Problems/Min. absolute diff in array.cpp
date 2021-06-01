/******

*******/
// arr - input array
// n - size of array
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int minAbsoluteDiff(int arr[], int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	sort(arr,arr+n);
    int min=arr[1]-arr[0];
    for(int i=2;i<n;i++)
    {
        if(abs(arr[i]-arr[i-1]) < min)
            min=abs(arr[i]-arr[i-1]);
    }
    return min;
}
int main() {

	int size;
	cin >> size;
	int *input = new int[1 + size];
	
	for(int i = 0; i < size; i++)
		cin >> input[i];
	
	cout<< minAbsoluteDiff(input,size) << endl;
	
	return 0;

}
