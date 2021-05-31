/*******
Code : Get Path - BFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2 (as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using BFS and print the shortest path available.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
The following line contain two integers, that denote the value of v1 and v2.
Output Format :
Print the path from v1 to v2 in reverse order.
Constraints :
2 <= V <= 1000
1 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
0 <= v1 <= 2^31 - 1
0 <= v2 <= 2^31 - 1
Time Limit: 1 second
Sample Input 1 :
4 4
0 1
0 3
1 2
2 3
1 3
Sample Output 1 :
3 0 1
Sample Input 2 :
6 3
5 3
0 1
3 4
0 3
Sample Output 2 :
*******/

#include <bits/stdc++.h>
using namespace std;

void pathBfs(int **edge,int V,int start,int end)
{
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
    {
        visited[i]=false;
    }
   	 
   	queue<int> visitingnodes;
    map<int,int> m;
    visitingnodes.push(start);
    visited[start]=true;
    
    while(!visitingnodes.empty())
    {
        int curr_node=visitingnodes.front();
        visitingnodes.pop();
        //we need to check first for every vertex,that current vertex matches with end vertex or not
        if(curr_node==end)
        {
            cout<<curr_node<<" ";
            while(m[curr_node]!=start)
            {
                cout<<m[curr_node]<<" ";
                curr_node=m[curr_node];
            }
            cout<<start;
        }
        for(int i=0;i<V;i++)
        {
            if(curr_node==i)
            {
                continue;
            }
            if(edge[curr_node][i] && !visited[i])
            {
                m[i]=curr_node;
                visitingnodes.push(i);
                visited[i]=true;
            }
        }
    }
}

int main()
{
  	int V, E, tempX, tempY;
  	cin >> V >> E;
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
    
    int v1,v2;
    cin>>v1>>v2;
    pathBfs(edge,V,v1,v2);
    
  	return 0;
}
