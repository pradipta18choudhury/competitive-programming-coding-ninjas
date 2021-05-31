/******
Code : Is Connected ?
Send Feedback
Given an undirected graph G(V,E), check if the graph G is connected graph or not.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two integers, that denote that there exists an edge between vertex a and b.
Output Format :
The first and only line of output contains "true" if the given graph is connected or "false", otherwise.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
true
Sample Input 2:
4 3
0 1
1 3 
0 3
Sample Output 2:
false 
Sample Output 2 Explanation
The graph is not connected, even though vertices 0,1 and 3 are connected to each other but there isn’t any path from vertices 0,1,3 to vertex 2. 
*****/
// #include <iostream>
// using namespace std;


// void IsConnected(int **edge,int V,int start,bool *visited)
// {
//     visited[start]=true;
   
//     for(int i=0;i<V;i++)
//     {
//         if(!visited[i] && edge[start][i]==1)
//             IsConnected(edge,V,i,visited);
//     }
// }


// int main() {
//     int V, E;
//     cin >> V >> E;

//   /*

//   	   Write Your Code Here
// 	   Complete the Rest of the Program
// 	   You have to take input and print the output yourself
	 
//   */
// 	int **edge=new int*[V];
//     for(int i=0;i<V;i++)
//     {
//         edge[i]=new int[V];
//         for(int j=0;j<V;j++)
//             edge[i][j]=0;
//     }
    
//     for(int i=0;i<E;i++)
//     {
//         int f,s;
//         cin>>f>>s;
//         edge[f][s]=1;
//         edge[s][f]=1;
//     }
    
//     bool *visited=new bool[V];
//     for(int i=0;i<V;i++)
//         visited[i]=false;
    
//    IsConnected(edge,V,0,visited);
//     for(int i=0;i<V;i++)
//     {
//         if(visited[i]==false)
//         {
//             cout<<"false";
//             return 0;
//         }
//     }
//     cout<<"true";
//   return 0;
// }




#include<iostream>
#include<queue>
#include<map>
using namespace std;
void visited_filler(int** arr, int v, int current_element, bool* visited)
{
	queue<int>q;
	visited[current_element] = true;
	q.push(current_element);
	while (!q.empty())
	{
		int current = q.front();
		for (int i = 0; i < v; i++)
		{
			if (!visited[i] && arr[current][i] == 1 && i != current)
			{
				q.push(i);
				visited[i] = true;
			}
		}
		q.pop();
	}
}
int main()
{
	int v, e;
	cin >> v >> e;
	int** arr = new int* [v];
	for (int i = 0; i < v; i++)
	{
		arr[i] = new int[v];
		for (int j = 0; j < v; j++)
		{
			arr[i][j] = 0;
		}
	}
	while (e--)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;
	}
	bool* visited = new bool[v];
	for (int i = 0; i < v; i++)
	{
		visited[i] = false;
	}
	visited_filler(arr, v, 0, visited);
	for (int i = 0; i < v; i++)
	{
		if (!visited[i])
		{
			cout << "false";
			return 0;
		}
	}
	cout << "true";
	return 0;
}
