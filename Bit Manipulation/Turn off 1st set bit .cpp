/******
You are given an integer Ni. You need to make first set bit of binary representation of N to 0 and return the updated N.
Counting of bits start from 0 from right to left.
Input Format :
Integer N 
Output Format :
Updated N
Sample Input 1 :
4
Sample Output 1 :
0
Sample Input 2 :
12 
Sample Output 2 :
8
*******/

#include <bits/stdc++.h>
using namespace std;
/*******
Bitwise AND (&)
0&0 is 0
0&1 is 0
1&0 is 0
1&1 is 1

Bitwise OR ( | )
0|0 is 0
0|1 is 1
1|0 is 1
1|1 is 1

Bitwise XOR (^)
0^0 is 0
0^1 is 1
1^0 is 1
1^1 is 0
Bitwise NOT (~)
~0 is 1
~1 is 0
*******/
int turnOffFirstSetBit(int n){
    return (n & (n-1));
}

int main() {
	int n;

	cin >> n;
	
	cout<< turnOffFirstSetBit(n) <<endl;
		
	return 0;
}

