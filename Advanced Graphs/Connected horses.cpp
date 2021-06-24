/********
Connected horses
Send Feedback
You all must be familiar with the chess-board having 
8*8 squares of alternate black and white cells. Well, here 
we have for you a similar 
N*M size board with similar arrangement of black and white 
cells.
A few of these cells have Horses placed over them. 
Each horse is unique. Now these horses are not the 
usual horses which could jump to any of the 
8 positions they usually jump in. They can move only if there is another horse on one of the 8-positions that it can     go to usually and then both the horses will swap their positions. This swapping can happen infinitely times.
A photographer was assigned to take a picture of all the different ways that the horses occupy the board! Given the state of the board, calculate answer. Sincethis answer may be quite large, calculate in modulo 
10^9+7
Input:
First line contains 
T which is the number of test cases.
T test cases follow first line of each containing three integers 
N, M and Q where 
N,M is the size of the board and 
Q is the number of horses on it.

Q lines follow each containing the 2 integers 
X and Y which are the coordinates of the Horses.
Output:
For each test case, output the number of photographs taken by photographer.
Constraints:
 1<=T<=10
 1<=N,M<=1000
 1<=Q<=N*M
SAMPLE INPUT
2
4 4 4
1 1
1 2
3 1
3 2
4 4 4
1 1
1 2
3 1
4 4
SAMPLE OUTPUT
4
2
********/

#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
int horse[8][2]={ {2 , 1}, {2 , -1}, {-2 , 1}, {-2, -1}, {1 , 2}, {1 , -2}, {-1, 2}, {-1, -2} };
long long int factorial[1000003];
int n,m;
long long int count(int **edge,int x,int y,bool **visited)
{
    int count1=1;
    visited[x][y]=true;
    edge[x][y]=1;
    for(int i=0;i<8;i++)
    {
        int a=x+horse[i][0];
        int b=y+horse[i][1];
        
        if(a<0 || a>=n || b<0 || b>=m)//invalid indexes
            continue;
        
        if(edge[a][b] && !visited[a][b])
        {
            
            visited[a][b]=true;
            count1+=count(edge,a,b,visited);
        }
    }
    return count1;
}
int main()
{
	//code
    int t;
    cin>>t;
    
    factorial[0] = 1;
    for(long long i = 1; i <= 1e6; i++){
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }
    while(t--)
    {
        int q;
        long long ans=1;
        cin>>n>>m>>q;
        //int arr[n][m];
        int **edge=new int*[n];
        for(int i=0;i<n;i++)
        {
            edge[i]=new int[m];
            for(int j=0;j<m;j++)
                edge[i][j]=0;
        }
        
        while(q--)
        {
            int i,j;
            cin>>i>>j;
            edge[i-1][j-1]=1;
        }
        
        bool **visited=new bool*[n];
    	for(int i=0;i<n;i++)
    	{
        	visited[i]=new bool[m];
        	for(int j=0;j<m;j++)
            visited[i][j]=false;
    	}
    
    	for(int i=0;i<n;i++)
    	{
        	for(int j=0;j<m;j++)
        	{
            	if(edge[i][j] && !visited[i][j])
            	{
                	int c=count(edge,i,j,visited);
                	ans = (ans*factorial[c])%MOD;
                    ans=(ans+MOD)%MOD;
            	}
        	}
   		 }
    	cout<<ans%MOD<<endl;
    }
    
    
	return 0;
}
