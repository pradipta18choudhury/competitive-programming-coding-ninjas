/********
Maximum Sum Rectangle
Send Feedback
Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output
Output a single integer, maximum sum rectangle.
Constraints
1<=n,m<=100
Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29
********/

#include <bits/stdc++.h>
using namespace std;
int row;
int col;
int arr[1000][1000];

int kadaneAlgo(int *temp,int size)
{
    int sum=0,ans=0;
    for(int i=0;i<size;i++)
    {
        sum+=temp[i];
        if(sum<0)
            sum=0;
        else if(sum>0)
        {
            if(sum>ans)
                ans=sum;
        }
    }
    return ans;
}

void rectangle()
{
	int start,end,sum=0,i,k;
    int maxsum=INT_MIN;
    int temp[row];
    
    for(i=0;i<col;i++)
        for(int j=0;j<row;j++)
            temp[j]=0;
     for(k=i;k<col;k++)
    {
        for(int m=0;m<row;m++)
            temp[m]+=arr[m][k];
        sum=kadaneAlgo(temp,row);
        
        if(sum>maxsum)
            maxsum=sum;
    }
    
    cout<<maxsum<<endl;
}

int main()
{
    
    cin>>row>>col;
    //int arr[row][col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }
    
    rectangle();
    return 0;
}

--------------------------------------------------------------------------- ANOTHER WAY ------------------------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;
int row;
int col;
int arr[1000][1000];

int kadaneAlgo(int *temp,int size)
{
    int sum=0,ans=INT_MIN;
    for(int i=0;i<size;i++)
    {
        sum+=temp[i];
        if(sum>ans)
            ans=sum;
        if(sum<0)
            sum=0;
        }

    return ans;
}

void rectangle()
{
	int start,end,sum=0,i,k;
    int maxsum=INT_MIN;
    int temp[row];
    
    for(i=0;i<col;i++){
        for(int j=0;j<row;j++)
            temp[j]=0;
    
    for(k=i;k<col;k++)
    {
        for(int m=0;m<row;m++)
            temp[m]+=arr[m][k];
        sum=kadaneAlgo(temp,row);
        
        if(sum>maxsum)
            maxsum=sum;
    }
    }
    
    cout<<maxsum<<endl;
}

int main()
{
    
    cin>>row>>col;
    //int arr[row][col];
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cin>>arr[i][j];
        }
    }
    
    rectangle();
    return 0;
}

//--------------------------------------------------------------------------------   ANOTHER WAY    --------------------------------------------------------------------
    
#include <bits/stdc++.h>
using namespace std;
int calculate(int **arr,int n,int m)
{ 
    int res=INT_MIN;
    for(int l=0;l<m;l++)
    {
        int sum[n]={0};
        for(int r=l;r<m;r++)
        {
            for(int i=0;i<n;i++)               //sum of elements in each row b/w left and right
            {
                sum[i]+=arr[i][r];
            }
            
            int best=INT_MIN,current_best=0;   //kadane's algo
            for(int i=0;i<n;i++)
            {
                current_best+=sum[i];
                best=max(current_best,best);
                if(current_best<0)
                    current_best=0;
                
			}
            res=max(res,best);
		}
    }
    return res;
}
int main()
{
    int n,m;
    cin>>n>>m;
	int **arr=new int*[n];
    for(int i=0;i<n;i++)
        arr[i]=new int[m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>arr[i][j];
        }
	}
    
    cout<<calculate(arr,n,m);
    return 0;
}
