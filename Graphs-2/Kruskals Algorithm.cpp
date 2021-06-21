/**********
Kruskal's Algorithm
Send Feedback
Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.
For printing MST follow the steps -
1. In one line, print an edge which is part of MST in the format - 
v1 v2 w
where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1  <= v2 i.e. print the smaller vertex first while printing an edge.
2. Print V-1 edges in above format in different lines.
Note : Order of different edges doesn't matter.
Input Format :
Line 1: Two Integers V and E (separated by space)
Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)
Output Format :
Print the MST, as described in the task.
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
1 2 1
0 1 3
0 3 5
**********/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Edge
{
    public:
    int src;
    int dest;
    int weight;
};

bool compare(Edge e1,Edge e2)
{
    return e1.weight<e2.weight;
}

int getParent(int v,int *parent)
{
    if(parent[v]==v)
        return v;
    return getParent(parent[v],parent);
}

Edge *Kruskal(Edge *edge,int n,int E)
{
	sort(edge,edge+E,compare);
    
    Edge *output=new Edge[n-1];
    int *parent=new int[n];
    for(int i=0;i<n;i++)
    {
    	parent[i]=i;
    }
    int i=0;
    int count=0;
    while(count<(n-1))
    {
        Edge current=edge[i];
        int source=getParent(current.src,parent);
        int destination=getParent(current.dest,parent);
        if(source!=destination)
        {
            output[count]=current;
            count++;
            parent[source]=destination;
        }
        i++;
    }
    return output;
}


int main()
{
  int V, E, tempX, tempY;
  cin >> V >> E;
    Edge *edge=new Edge[E];

  /*

  	   Write Your Code Here
	   Complete the Rest of the Program
	   You have to Print the output yourself
	 
  */
	for(int i=0;i<E;i++)
    {
        int s,d,w;
        cin>>s>>d>>w;
        edge[i].src=s;
        edge[i].dest=d;
        edge[i].weight=w;
    }
    Edge* output=Kruskal(edge,V,E);
    for(int i=0;i<V-1;i++)
    {
        if(output[i].src<output[i].dest)
        {
            cout<<output[i].src<<" "<<output[i].dest<<" "<<output[i].weight<<endl;
        }else
            cout<<output[i].dest<<" "<<output[i].src<<" "<<output[i].weight<<endl;
    }
  return 0;
}
