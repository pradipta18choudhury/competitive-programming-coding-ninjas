/********
Code : Get Path - DFS
Send Feedback
Given an undirected graph G(V, E) and two vertices v1 and v2(as integers), find and print the path from v1 to v2 (if exists). Print nothing if there is no path between v1 and v2.
Find the path using DFS and print the first path that you encountered.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. Print the path in reverse order. That is, print v2 first, then intermediate vertices and v1 at last.
4. Save the input graph in Adjacency Matrix.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex 'a' and 'b'.
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
********/

#include <iostream>
#include <vector>
using namespace std;

vector<int> getPath(int **edge,bool *visited,int V,int start,int end)
{
    visited[start]=true;
    if(start==end)
    {
        vector<int> p;
        p.push_back(start);
        return p;
    }
    
   else
    {
        for(int i=0;i<V;i++)
            if(edge[start][i] == 1 && !visited[i])
            {
                vector<int> temp = getPath(edge,visited, V,i,end);
                // If i doesnot belong to the path then it will return empty vector
                // as there will be no way to reach end from i
                
                if(temp.size() > 0)
                {
                	temp.push_back(start);
                    return temp;
                }
                
            }
        vector<int> temp;
        return temp;
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
    int v1,v2;
    cin>>v1>>v2;
    
    bool *visited=new bool[V];
    for(int i=0;i<V;i++)
        visited[i]=false;
    
    vector<int> result=getPath(edge,visited,V,v1,v2);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";
    
  return 0;
}

