/*******
A thief is robbing a store and can carry a maximal weight of W into his knapsack. There are N items and ith 
item weighs wi and is of value vi. Considering the constraints of maximum weight that knapsack can carry,
you have to find and return the maximum value that thief can generate by stealing items.
Note
Space complexity should be O(W).
Input Format :
The first line contains an integers, that denote the value of N. The following line contains N space separated
integers, that denote the values of weight of items. The following line contains N space separated integers,
that denote the values associated with the items. The following line contains an integer that denote the value of W. W denotes maximum weight that thief can carry.
Output Format :
The first and only line of output contains the maximum value that thief can generate, as described in the task. 
Constraints
1 <= N <= 10^4
1<= wi <= 100
1 <= vi <= 100
Time Limit: 1 second
Sample Input 1 :
4
1 2 4 5
5 4 8 6
5
Sample Output 1 :
13
*******/

#include <bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
	return (a>b) ? a:b;    
}

int knapsack(int* weights, int* values, int n, int maxWeight){
  
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int i, wt;
   int K[n+1][2*maxWeight-1];
   for (i = 0; i <= n; i++) {
      for (wt = 0; wt <= maxWeight; wt++) {
         if (i == 0 || wt == 0)
         K[i][wt] = 0;
         else if (weights[i - 1] <= wt)
            K[i][wt] = max(values[i - 1] + K[i - 1][wt - weights[i - 1]], K[i - 1][wt]);
         else
        K[i][wt] = K[i - 1][wt];
      }
   }
   return K[n][maxWeight];
}

 //---------------------------------------------------------------- APPROACH - ii -----------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int max(int a,int b)
{
	return (a>b) ? a:b;    
}

int knapsack(int* weights, int* values, int n, int maxWeight){
	
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
	int i, wt;
   int K[2][maxWeight + 1];
    for(int i=0; i<=maxWeight; i++){
        K[0][i] = 0;
    }
   for (i = 1; i <= n; i++) {
       K[1][0] = 0;
      for (wt = 1; wt <= maxWeight; wt++) {
         if (weights[i - 1] <= wt)
            K[1][wt] = max(values[i - 1] + K[0][wt - weights[i - 1]], K[0][wt]);
         else
        	K[1][wt] = K[0][wt];
      }
       for(wt = 0; wt <= maxWeight; wt++){
           K[0][wt] = K[1][wt];
       }
   }
   return K[1][maxWeight];
}

int main() {
    int n;
    cin >> n;
    int* wt = new int[n];
    int* val = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    for (int j = 0; j < n; j++) {
        cin >> val[j];
    }

    int w;
    cin >> w;

    cout << knapsack(wt, val, n, w) << "\n";

    delete[] wt;
    delete[] val;
}
