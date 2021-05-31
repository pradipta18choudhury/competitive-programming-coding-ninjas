/*********
Code : All connected components
Send Feedback
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). Order of different components doesn't matter.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two space separated integers, that denote that there exists an edge between vertex a and b.
Output Format :
Print different components in new line. And each component should be printed in increasing order of vertices (separated by space). Order of different components doesn't matter.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
0 1 3 
2
********/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <queue>
vector<vector<int>> components;

void PrintDfs(int **edge,int n,int e,bool *visited,vector<int> &vec)
{
    vec.push_back(e);
    visited[e]=true;
    for(int i=0;i<n;i++)
    {
        if(i==e)
            continue;
        if(!visited[i] && edge[e][i])
            PrintDfs(edge,n,i,visited,vec);
    }
}
int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */
	int **edge=new int*[V];
    for(int i=0;i<V;i++)
    {
        edge[i]=new int[V];
        for(int j=0;j<V;j++)
            edge[i][j]=0;
    }
    
    for(int i=0;i<E;i++)
    {
        int f,s;
        cin>>f>>s;
        edge[f][s]=1;
        edge[s][f]=1;
    }
    
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    
   for(int i=0;i<V;i++)
   {
       vector<int> vec;
       vector<int>();
       if(!visited[i])
       {
           PrintDfs(edge,V,i,visited,vec);
           sort(vec.begin(),vec.end());
           components.push_back(vec);
       }
   }
    
    for(int i=0;i<components.size();i++)
    {
        for(int j=0;j<components[i].size();j++)
        {
            cout<<components[i][j]<<" ";
        }
        cout<<endl;
    }
  return 0;
}
