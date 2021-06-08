/********
A straightforward question. Given an array of positive integers you have to print the number
of subarrays whose XOR is less than K. Subarrays are defined as a sequence of continuous elements Ai, Ai+1, ...,
Aj . XOR of a subarray is defined as Ai ^ Ai+1 ^ ... ^ Aj. Symbol ^ is Exclusive Or.
Input Format
First line contains T, the number of test cases. 
Each of the test case consists of N and K in one line, followed by N space separated integers in next line.
Output Format
For each test case, print the required answer.
Constraints:
1 ≤ T ≤ 5
1 ≤ N ≤ 10^5
1 ≤ A[i] ≤ 10^5
1 ≤ K ≤ 10^6
Sample Input
1
5 2
4 1 3 2 7   
Sample Output
3
********/

/**********

return the count ki kitne chhote/leaf node hain less than k
1
12
123
1234
.........
if p=1,k=1, then all right elements will be small
calculate all leaf elements in right

if p=1,k=0, then xor will give 1, don't move to left, it will only maximise the result
move right

if p=0,k=1 all elements in left give less xor value
move left

if p=0,k=0 xor with left will only produce less valu
move left, moving right will only maximise the result

********/
#include <bits/stdc++.h>
using namespace std;
class trienode{
    public:
    trienode* left;
    trienode* right;
    trienode* parent;
    long long leaf=0;
};

void updateleaf(trienode* temp){
    temp=temp->parent;
    while(temp!=NULL){
        temp->leaf+=1;
        temp=temp->parent;
    }
}

void insert(trienode* head,int num){
    trienode* temp=head;
    
    for(int j=31;j>=0;j--){
            int b=(num>>j)&1;
            if(b==0){
                if(temp->left==NULL){
                    temp->left=new trienode();
                }
                trienode* parent=temp;
                temp=temp->left;
                temp->parent=parent;
                
            }
            else{
                if(temp->right==NULL){
                    temp->right=new trienode;
                }
                trienode* parent=temp;
                temp=temp->right;
                temp->parent=parent;
            }
            if(j==0){
                temp->leaf+=1;
                updateleaf(temp);
            }
            
        }
}

long long buildtrie(trienode* head,int arr[],int n,int k){
    int curxor=0;
    long long count=0;
    insert(head,curxor);
    
    for(int i=0;i<n;i++){
        trienode* temp=head;
        curxor=curxor^arr[i];
        
        for(int j=31;j>=0;j--){
            if(temp!=NULL){
                int b1=(curxor>>j)&1;
                int b2=(k>>j)&1;
                
                if(b1==0&&b2==0){
                    temp=temp->left;
                }
                
                else if(b1==0&&b2==1){
                    if(temp->left!=NULL){
                        count+=temp->left->leaf;
                    }
                    temp=temp->right;
                }
                else if(b1==1&&b2==0){
                    temp=temp->right;
                }
                else{
                    if(temp->right!=NULL){
                        count+=temp->right->leaf;
                    }
                    temp=temp->left;
                }
                
                
            }
            else{
                break;
            }
        }
        
        
        
        
        
        
        insert(head,curxor);
        
    }
    
    return count;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        trienode* head=new trienode();
        
        cout<<buildtrie(head,arr,n,k)<<endl;
        
        
        
    }
    return 0;
}

