/*************
Maximum Sum In Subarray
Send Feedback
You are given a sequence A[1], A[2], ..., A[N].
A query is defined as follows:
Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }. 
Given M queries, write a program that outputs the results of these queries.
Input Format:
The first line of input contains an integer N.
In the second line contains N space separated integers.
The third line contains the integer M.
Next M lines contains 2 integers x and y.
Output Format:
For each query, print the answer in a new line.
Constraints:
1 <= N <= 10^5
1 < = Q <= 10^5
-10^4 <= arr[i] <= 10^4
Sample Input 1:
3 
-1 2 3 
1
1 2
Sample Output 1:
2
*************/

#include <iostream>
#include <queue>
using namespace std;

void print(int **edge,int n,int sv,bool *visited){
   // bool * visited=new bool[n];
   // for(int i=0;i<n;i++)
    //{
    //    visited[i]=false;
   // }
    queue<int> q;
    q.push(sv);
    visited[sv]=true;
    while(!q.empty())
    {
        int curr=q.front();
         q.pop();
        cout<<curr<<" ";
        for(int i=0;i<n;i++)
        {
            if(i==curr)
                continue;
            if(edge[curr][i]==1 && !visited[i])
            {
                q.push(i);
                visited[i]=true;
            }
        }
    }
   // delete [] visited;
}

void bfs(int **edge,int n,int sv)
{
    bool *visited=new bool[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=false;
    }
    //visited[sv]=true;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
            print(edge,n,i,visited);
    }
    
}

int main() {
    int V, E;
    cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to take input and print the output yourself
	 
  */
    int **edge=new int*[V];
    for(int i=0;i<V;i++){
        edge[i]=new int[V];
        for(int j=0;j<V;j++){
            edge[i][j]=0;
        }
    }
    for(int i=0;i<E;i++)
    {
        int f,s;
        cin>>f>>s;
        edge[f][s]=1;
        edge[s][f]=1;
    }
    
    bfs(edge,V,0);
    
    for(int i=0;i<V;i++)
        delete[] edge[i];
    delete[] edge;
  return 0;
}
