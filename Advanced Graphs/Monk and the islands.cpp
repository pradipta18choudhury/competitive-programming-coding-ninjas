/******
Monk and the Islands
Send Feedback
MONK AND THE ISLAND
Monk visits the land of Islands. There are a total of N islands numbered from 1 to N. Some pairs of islands are connected to each other by Bidirectional bridges running over water.
Monk hates to cross these bridges as they require a lot of efforts. He is standing at Island #1 and wants to reach the Island #N. Find the minimum the number of bridges that he shall have to cross, if he takes the optimal route.
Input:
First line contains T. T testcases follow.
First line of each test case contains two space-separated integers N, M.
Each of the next M lines contains two space-separated integers X and Y , denoting that there is a bridge between Island X and Island Y.
Output:
Print the answer to each test case in a new line.
Constraints:
1 ≤ T ≤ 10
1 ≤ N ≤ 10000
1 ≤ M ≤ 100000
1 ≤ X, Y ≤ N
SAMPLE INPUT
2
3 2
1 2
2 3
4 4
1 2
2 3
3 4
4 2
SAMPLE OUTPUT
2
2
******/


#include <bits/stdc++.h>

using namespace std;

bool visited[10002];

int level[100002];

int ans=0;

// int n;

int dfs(int root,vector<int> v[],int n){

    queue<int> q;

    q.push(root);

    visited[root]=true;

    level[root]=0;

    while(!q.empty()){

        int r=q.front();

     

        q.pop();

        for(int i=0;i<(int)v[r].size();i++){

            if(!visited[v[r][i]]){

                level[v[r][i]]=level[r]+1;

                ans=level[v[r][i]];

                q.push(v[r][i]);

                if(v[r][i]==n)return ans;

                visited[v[r][i]]=true;

            }

        }

    }

    return ans;

}

int main(){

    int t;

    cin>>t;

    while(t-->0){

        memset(visited,0,sizeof(visited));

        ans=0;

        int n,m;

        // int root;

        cin>>n>>m;

        vector<int> v[n+1];


        for(int i=0;i<m;i++){

            int a,b;

            cin>>a>>b;

            // if(i==0)root = a;

            v[a].push_back(b);

            v[b].push_back(a);

        }

        cout<<dfs(1,v,n)<<endl;

    }

}
