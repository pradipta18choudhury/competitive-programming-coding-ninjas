/*******
Dominos
Send Feedback
Domino
Dominos are lots of fun. Children like to stand the tiles on their side in long lines. When one domino falls, it knocks down the next one, which knocks down the one after that, all the way down the line.
However, sometimes a domino fails to knock the next one down. In that case, we have to knock it down by hand to get the dominos falling again.
Your task is to determine, given the layout of some domino tiles, the minimum number of dominos that must be knocked down by hand in order for all of the dominos to fall.
Input
The first line of input contains one integer specifying the number of test cases to follow.Each test case begins with a line containing two integers,each no larger than 100 000. The first integer n is the number of domino tiles and the second integer m is the number of lines to follow in the test case. The domino tiles are numbered from 1 to n.
Each of the following lines contains two integers x and y indicating that if domino number x falls, it will cause domino number y to fall as well.
Output
For each test case, output a line containing one integer, the minimum number of dominos that must be knocked over by hand in order for all the dominos to fall.
Sample Input
1
3 2
1 2
2 3
Sample Output
1
*******/

#include<bits/stdc++.h>

using namespace std;

bool vis[100005];

void dfs2(vector<int>list[],int sv)

{

   vis[sv]=1;

   for(int i=0;i<list[sv].size();i++)

   {

       if(!vis[list[sv][i]])

       {

           dfs2(list,list[sv][i]);

       }

   }

}

void dfs(vector<int>list[],int sv,stack<int>&st)

{

   vis[sv]=1;

   for(int i=0;i<list[sv].size();i++)

   {

       if(!vis[list[sv][i]])

       {

           dfs(list,list[sv][i],st);

       }

   }

  st.push(sv);

}

int scc(vector<int>list[],int n)

{

   stack<int>st;

    int count=0;

   for(int i=0;i<n;i++)

   {

       if(!vis[i])

       {

           dfs(list,i,st);

           

       }

   }

   memset(vis,0,sizeof(vis));

   

   while(!st.empty())

   {

       int el=st.top();

       st.pop();        

       if(!vis[el])

       {            

           dfs2(list,el);

           count++;

       }

   }

   return count;

}

int main()

{

//code

   int t;

   cin>>t;

   while(t--)

   {

       int n,m;

       cin>>n>>m;

       vector<int>list[n+1];

       for(int i=0;i<m;i++)

       {

           int x,y;

           cin>>x>>y;

           list[x-1].push_back(y-1);

       }

       memset(vis,0,sizeof(vis));

       int ans=scc(list,n);

       cout<<ans<<endl;

   }

return 0;

}
