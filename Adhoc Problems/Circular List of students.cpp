/****
Circular List of Students
Send Feedback
You are given a circular list of students as follows:
0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 -> 11
This list is circular, means that 11 will follow 0 again. You will be given the student number ‘i’ and some position ‘p’. You will have to tell that if the list will start from (i+1)th student, then which student will be at pth position.
Input Format:
First line will have an integer ‘t’, denoting the number of test cases.
Next line will have two space separated integers denoting the value of ‘i’ and ‘p’ respectively.
Output Format:
Print ‘t’ lines containing single integer denoting the student number.
Constraints:
1 <= t <= 10^5
0 <= i <= 11
1 <= p <= 12
Sample Input:
2
2 3
5 8
Sample Output:
5
1
Explanation:
First, list will start at 3. 3 -> 4 -> 5. Hence, 5 will be at third position.
Second, list will start at 6. 6 -> 7 -> 8 -> 9 -> 10 -> 11 -> 0 -> 1. Hence, 1 will be at 8th position.
*****/
#include<bits/stdc++.h>
using namespace std;
/***
struct Node
{
	int data;
    struct Node *next;
}*head;

void insert(int data)
{
	struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    struct Node *p=head;
    newNode->data=data;
    newNode->next=head;
    if(head!=NULL)
    {
        while(p->next!=head)
            p=p->next;
        p->next=newNode;
    }
    else
    {
        newNode->next=newNode;
        head=newNode;
    }
}


int traversal(int i,int p)
{
	struct Node *q=head->next;
    struct Node *temp;
    int a=0,s=0;
    while(q!=head)
    {
        a++;
        if(q->data==i)
        {
            while(p>0)
            {
                temp=q;
                temp=temp->next;
                p--;
            }
            s=temp->data;
            break;
        }
        q=q->next;
    }
    return s;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int i,p;
        cin>>i>>p;
        insert(0);
        insert(1);
        insert(2);
        insert(3);
        insert(4);
        insert(5);
        insert(6);
        insert(7);
        insert(8);
        insert(9);
        insert(10);
        insert(11);
        
        cout<<traversal(i,p)<<endl;
    }
	return 0;
    
    
    ***/

int main()
{
     int arr[12] = {0,1,2,3,4,5,6,7,8,9,10,11};
    int t;
    cin >> t;
    while(t--)
    {
        int i,p;
        int ans;
        cin >> i >> p;
        
        ans = i+p;
        if(ans > 11)
        {
            ans = ans-11;
            ans = arr[ans-1];
        }

        cout << ans << endl;
    }
    
	return 0;
}


