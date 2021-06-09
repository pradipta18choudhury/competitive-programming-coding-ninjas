/********
Charlie acquired airline transport company and to stay in business he needs to lower the expenses by any means possible.
There are N pilots working for his company (N is even) and N/2 plane crews needs to be made. A plane crew consists of two 
pilots - a captain and his assistant. A captain must be older than his assistant. Each pilot has a contract granting him two 
possible salaries - one as a captain and the other as an assistant. A captain's salary is larger than assistant's for the same pilot.
However, it is possible that an assistant has larger salary than his captain. Write a program that will compute the minimal amount of
money Charlie needs to give for the pilots' salaries if he decides to spend some time to make the optimal (i.e. the cheapest) arrangement of pilots in crews.
Input
The first line of input contains integer N, 2 ≤ N ≤ 10,000, N is even, the number of pilots working for the Charlie's company. 
The next N lines of input contain pilots' salaries. The lines are sorted by pilot's age, the salaries of the youngest pilot are given the first. Each of those N lines contains two integers separated by a space character, X i Y, 1 ≤ Y < X ≤ 100,000, a salary as a captain (X) and a salary as an assistant (Y).
Output
The first and only line of output should contain the minimal amount of money Charlie needs to give for the pilots' salaries. 
Sample Input
4 
5000 3000 
6000 2000 
8000 1000 
9000 6000 
Sample Output
19000 
********/
#include <bits/stdc++.h>
using namespace std;


int airline(int **person,int n,int c,int ass,int **dp)
{
	int ans=0,ans1=0,ans2=0,ans3=0;
    
    //a[n][2]  stores both salaries if each member
    //c is number of captains 
    //ass is number of assistants
    
    if(n==0 ){
        return 0;
    }
    
    if(dp[n][abs(c-ass)]>-1)
        return dp[n][abs(c-ass)];
        
    if(abs(c-ass)==0) //case when we are at  first member
    {
        ans=airline(person+1,n-1,c,ass-1,dp)+person[0][1];//adding his assitant sallary
    }
    else if(abs(c-ass)==n){//case when we are at  last member
        ans=airline(person+1,n-1,c-1,ass,dp)+person[0][0];//adding his pilot's sallary
    }else{
        //this case is for ith member 
        ans1=airline(person+1,n-1,c,ass-1,dp)+person[0][1];//let say this member is assigned as assistant
        ans2=airline(person+1,n-1,c-1,ass,dp)+person[0][0];//let say this member is assigned as captain
        ans=min(ans1,ans2);//taking the minimum of two
    }

   
    dp[n][abs(c-ass)]=ans;
    return ans;
}


int main()
{
    int n;
    cin>>n;
    
// 2d array with size 2*n where a[i][0] stores the sallary of person as pilot and a[i][1] the sallary as assitant 
    int**person=new int*[n];
    for(int i=0;i<n;i++)
    person[i]=new int[2];
    
    for(int i=0;i<n;i++){
        cin>>person[i][0]>>person[i][1];
    }
    
    
    //efficient way to declare dp array
    int **dp=new int *[n+1];
        for(int i=0;i<=n;i++)
            dp[i]=new int[n];
            
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++)
            {
                dp[i][j]=-1;
            }
    }
    
    int ans=airline(person,n,n/2,n/2,dp); // (array of sallaries , total n, no. of captains to take , no of assitant to take, dp)
    cout<<ans<<endl;
    return 0;
}





