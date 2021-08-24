/*****
Vasya vs Rhezo
Send Feedback
Queen Vasya is preparing for a war against Rhezo. She has N warriors in total arranged in a line. Let us number the warriors by numbers from 1 to N. She will fight Rhezo's army for Q days, and each day she can choose only one warrior.
For each warrior, we know 2 values associated with him, let us call these A and B. Each day Vasya can choose her warrior from a range Li to Ri, she must choose the warrior with maximum A value. If there is more than 1 warrior having the same maximum A value, she chooses the warrior with minimum B value. If still there is more than 1 warrior with same maximum A value and same minimum B value, she chooses the one with lower index in line.
You being the hand of Queen Vasya, need to help her in choosing the warrior for each day.
Input:
First line contains a single integer N, denoting the number of warriors Queen Vasya has. 
Second line contains N space separated integers Ai. Third line contains N space separated integers Bi.
Next line contains a single integer Q, denoting the number of days Queen Vasya chooses a warrior. 
Each of the next Q lines contains 2 integers Li and Ri.
Output:
For each Li and Ri, print the index of the warrior that Queen Vasya should choose.
Constraints:
1≤ N,Q ≤10^6
1≤ Ai,Bi ≤10^9
1≤Li≤Ri
Sample Input
5
1 8 4 6 8
4 8 6 3 7
4
1 4
2 4
3 4
1 5
Sample Output
2
2
4
5
*****/

#include <bits/stdc++.h>
using namespace std;

int v[4000002];
int arr[1000002],brr[1000002];
//map<int,int>m;

void build(int node,int start,int end)
{
        if(start==end)
        {
                v[node]=start;
        }
        else{
        int mid=(start+end)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,end);
        if(arr[v[2*node]]>=arr[v[2*node+1]]){
         if(arr[v[2*node]]>arr[v[2*node+1]])
         v[node]=v[2*node];
         else{
                if(brr[v[2*node]]<=brr[v[2*node+1]])
                {
                        v[node]=v[2*node];
                }
                else v[node]=v[2*node+1];
         }
        }
        else
        {
                v[node]=v[2*node+1];
        }
        }
}

int query(int node,int start,int end,int l,int r)
{
        if(l>end || r<start)
        {
                return -1;
        }
        if(l<=start && r>=end) return v[node];
        else
        {
                int mid=(start+end)/2;
                int v1 = query(2*node,start,mid,l,r);
                int v2 = query(2*node+1,mid+1,end,l,r);
                if(v1==-1 && v2==-1) return -1;
                if(v1==-1 && v2!=-1) return v2;
                if(v2==-1 && v1!=-1) return v1;

                if(arr[v1]>=arr[v2]){
                 if(arr[v1]>arr[v2])
                        return v1;
                 else{
                        if(brr[v1]<=brr[v2])
                        {
                                return v1;
                        }
                        else return v2;
                 }
                }
                else
                {
                        return v2;
                }
        }
}

int main() {
        int a,b,l,r;
        scanf("%d",&a);
        for(int i=0;i<a;i++)
        {
               scanf("%d",&arr[i]);
        }
        for(int i=0;i<a;i++)
        {
                scanf("%d",&brr[i]);
        }
        build(1,0,a-1);
        cin>>b;
        while(b--)
        {
                scanf("%d %d",&l,&r);
                printf("%d\n",query(1,0,a-1,l-1,r-1)+1);
        }
        return 0;
}
