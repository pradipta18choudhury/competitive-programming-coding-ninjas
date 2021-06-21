/*********
Dijkstra's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the shortest distance from the source vertex (i.e. Vertex 0) to all other vertices (including source vertex also) using Dijkstra's Algorithm.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
For each vertex, print its vertex number and its distance from source, in a separate line. The vertex number and its distance needs to be separated by a single space.
Note : Order of vertices in output doesn't matter.
Constraints :
2 <= V, E <= 10^5
Time Limit: 1 sec
Sample Input 1 :
4 4
0 1 3
0 3 5
1 2 1
2 3 8
Sample Output 1 :
0 0
1 3
2 4
3 5
*********/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int getMin(int *distance,bool *visited,int n)
{
    int minVertex=-1;
    for(int i=0;i<n;i++)
    {
        if((!visited[i] && (minVertex==-1 || distance[i] < distance[minVertex])))
            minVertex=i;
    }
    return minVertex;
}

void dijkstra(int **edge,int n)
{
	bool *visited=new bool[n]();
    int *distance=new int[n];
    
    for(int i=0;i<n;i++)
    {
        distance[i]=INT_MAX;
    }
    distance[0]=0;
    
    for(int i=0;i<n-1;i++)
    {
        int minVertex=getMin(distance,visited,n);
        visited[minVertex]=true;
        
        for(int j=0;j<n;j++)
        {
            if(edge[minVertex][j] && !visited[j])
            {
                int currD=distance[minVertex]+edge[minVertex][j];
                if(distance[j]>currD)
                    distance[j]=currD;
            }
        }
    }
    
    for(int i=0;i<n;i++)
    {
        cout<<i<<" "<<distance[i]<<endl;
    }
    delete [] visited;
    delete [] distance;
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
        int f,s,weight;
        cin>>f>>s>>weight;
        edge[f][s]=weight;
        edge[s][f]=weight;
    }
    cout<<endl;
    dijkstra(edge,V);
    
    for(int i=0;i<V;i++)
        delete [] edge[i];
    delete [] edge;
    
  return 0;
}
