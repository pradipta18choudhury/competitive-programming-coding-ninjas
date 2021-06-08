/********
Given an array of n integers, find subarray whose xor is maximum.
Input Format
First line contains single integer n (1<=n<=1000000).
Next line contains n space separated integers.
Output Format
Print xor of the subarray whose xor of all elements in subarray is maximum over all subarrays.
Constraints
1 <= n <= 1000000
1 <= A[i] <=100000 
Sample Input
4
1 2 3 4
Sample Output
7
********/

/********                           EXPLATION TO THIS PROBLEM

for a given subarray, find max xor possible of that subarray.

1 way to ki take xor of every possible subarray.
run 2 loops, compare elements take xor
for(i=0;i<n;i++)
{											1 2 3 4 5
											first xor of 12 then 123 then 1234 then 12345
                                            then 23 234 2345
                                            34 345
                                            45											this will take O(n^2)
for(j=1;j<n;j++)
{
xor_max=arr[i]^arr[j];
}
}

take a array|1|8|2|5|
insert xor of 1, 18 into the trie
-> if we take 18 xor 1 = 8
-> 18 xor 2 = 182
now, 5 comes, subarrays ending with 5 are:
											1825
                                            825
                                            25
                                            5                      in our trie, xor values stored are: 1, 18, 182
now, if we do: 1825 xor 182 = 5
				1825 xor 18=25
                1825 xor 1 = 825

********/



#include<bits/stdc++.h>
using namespace std;
class trieNode
{
public:
	trieNode *left;
	trieNode *right;
};

void insert(trieNode* head,int value)
{
	trieNode* curr=head;
	for(int i=31;i>=0;i--)// 31 for 31st bit
	{
		int b=(1<<i)&value;
		if(b==0)
		{
			if(!curr->left)
				curr->left=new trieNode();
			curr=curr->left;
		}
		else
		{
			if(!curr->right)
				curr->right=new trieNode();
			curr=curr->right;
		}
	}
}
int xorMaximumPair(trieNode* head,int *arr,int n)
{
	int max_xor=INT_MIN;
	for(int i=0;i<n;i++)
	{
		int value=arr[i];
		trieNode* curr=head;
		int current_xor=0;
		for(int j=31;j>=0;j--)
		{
            
			int b=(1<<j)&value;
			if(b==0)
			{
				if(curr->right)
				{
					current_xor+=(1<<j);// 1<<j == pow(2,j)
					curr=curr->right;// xor pair will be max if we get more no. of 1 so check right side and add accordingly
				}
				else
					curr=curr->left;
			}
			else
			{
				if(curr->left)
			 	{
					current_xor+=(1<<j);
					curr=curr->left;
				}
				else
					curr=curr->right;

			}
		}
		if(current_xor>max_xor)
			max_xor=current_xor;
	}
	return max_xor;
}
int main()
{ 
	
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int Xor=0;
	for(int i=0;i<n;i++)
	{
		Xor=Xor^arr[i];
		arr[i]=Xor;
	}
	trieNode *head=new trieNode();
	for(int i=0;i<n;i++)
	{
		insert(head,arr[i]);
	}
	cout<<xorMaximumPair(head,arr,n);
	return 0;
}	
