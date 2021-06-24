/*******
FILLMTR
Send Feedback
Fill The Matrix
A matrix B (consisting of integers) of dimension N × N is said to be good if there exists an array A (consisting of integers) such that B[i][j] = |A[i] - A[j]|, where |x| denotes absolute value of integer x.

You are given a partially filled matrix B of dimension N × N. Q of the entries of this matrix are filled by either 0 or 1. You have to identify whether it is possible to fill the remaining entries of matrix B (the entries can be filled by any integer, not necessarily by 0 or 1) such that the resulting fully filled matrix B is good.
Input
The first line of the input contains an integer T denoting the number of test cases.

The first line of each test case contains two space separated integers N, Q.

Each of the next Q lines contain three space separated integers i, j, val, which means that B[i][j] is filled with value val.
Output
For each test case, output "yes" or "no" (without quotes) in a single line corresponding to the answer of the problem.
Constraints
1 ≤ T ≤ 10^6
2 ≤ N ≤ 10^5
1 ≤ Q ≤ 10^6
1 ≤ i, j ≤ N
0 ≤ val ≤ 1
Sum of each of N, Q over all test cases doesn't exceed 106
Input
4
2 2
1 1 0
1 2 1
2 3
1 1 0
1 2 1
2 1 0
3 2
2 2 0
2 3 1
3 3
1 2 1
2 3 1
1 3 1
Output
yes
no
yes
no
*******/

#include<bits/stdc++.h>
using namespace std;
int parent[1000001];
vector<pair<int,int>> edges;
vector<int> graph[1000001];

int findparent(int parent[],int s){
    while(s!=parent[s]){
        s=parent[s];
    }
    return s;
}

void findparent(int parent[],int& s,int& e){
    while(s!=parent[s]){
        s=parent[s];
    }
    
    while(e!=parent[e]){
        e=parent[e];
    }
}

bool bipartite(int n,int parent[],int sv){
    if(n==0){
        return true;
    }
    unordered_set<int> set[2];
    vector<int> pending;
    int a=findparent(parent,sv);
    pending.push_back(a);
    set[0].insert(a);
    
    while(pending.size()!=0){
        int element=pending.back();
        pending.pop_back();
        
        int currentset=set[0].count(element)>0 ? 0:1;
        
        for(int i=0;i<graph[element].size();i++){
            int neighbour=graph[element][i];
            if(set[0].count(neighbour)==0&&set[1].count(neighbour)==0){
                pending.push_back(neighbour);
                set[1-currentset].insert(neighbour);
            }
            else if(set[currentset].count(neighbour)>0){
                return false;
            }
        }
        
    }
    return true;
}

bool ispossible(int parent[],int n){
    // vector<vector<int>> graph(n);
    for(int i=0;i<n;i++){
        graph[i].clear();
    }
    for(int i=0;i<edges.size();i++){
        int a=edges[i].first;
        int b=edges[i].second;
        
        findparent(parent,a,b);
        
        graph[a].push_back(b);
        graph[b].push_back(a);
        
        if(a==b){
            return false;
        }
        
    }
    
    unordered_set<int> set;
    for(int i=0;i<n;i++){
        set.insert(parent[i]);
    }
    
    unordered_set<int> :: iterator it=set.begin();
    
    while(it!=set.end()){
        if(!bipartite(n,parent,*it)){
        	return false;
        }
        it++;
    }
    
    
    
    
    
    return true;
}

void unionfind(int parent[],int n,int s,int e){
    while(s!=parent[s]){
        s=parent[s];
    }
    while(e!=parent[e]){
        e=parent[e];
    }
    
    parent[e]=parent[s];
    
}

int main()
{
	//code
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        bool flag=true;
        edges.clear();
        // int* parent=new int[n];
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        // vector<pair<int,int>> edges;
        for(int i=0;i<q;i++){
            int a,b,c;
            cin>>a>>b>>c;
            if(a==b&&c!=0){
                flag=false;
            }
            
            if(c==0){
                unionfind(parent,n,a-1,b-1);
            }
            if(c==1){
                edges.push_back((make_pair(a-1,b-1)));
            }
            
        }
        if(!flag){
            cout<<"no"<<endl;
            continue;
        }
        
        if(ispossible(parent,n)){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
        
        
    }
	return 0;
}
//----------------------------------------------------- 2nd way --------------------------------------------------------------------

#include <iostream>
#include <vector>
#include<utility>
using namespace std;
////////////////////////////////////////
const int N = 1e5 + 5;
bool error;
int col[N];
vector<pair<int, int>> adj[N];
////////////////////////////////////////
void dfs(int start)
{
    for (auto edge : adj[start])
    {
        int next = edge.first;
        if (col[next] == -1)
        {
            col[next] = col[start] ^ edge.second;
            dfs(next);
        }
        else if (col[next] != col[start] ^ edge.second)
        {
            error = true;
        }
    }
}
////////////////////////////////////////
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        error = false;
        for (int i = 1; i <= n; i++)
        {
            adj[i].clear();
            col[i] = -1;
        }
        while (m--)
        {
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back(make_pair(b, c));
            adj[b].push_back(make_pair(a, c));
        }
        for (int i = 1; i <= n; i++)
        {
            if (col[i] == -1)
            {
                col[i] = 0;
                dfs(i);
            }
        }
        if (error)
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }
}
