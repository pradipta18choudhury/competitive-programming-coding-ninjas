/******
Hasan and Trip
Send Feedback
Hasan has finally finished his final exams and he decided to go in a trip among cities in Syria.
There are N cities in Syria and they are numbered from 1 to N, each city has coordinates on plane, i-th city is in (Xi, Yi).
Hasan is in first city and he wants to visit some cities by his car in the trip but the final destination should be N-th city and the sequence of cities he will visit should be increasing in index (i.e. if he is in city i he can move to city j if and only if i < j ).
Visiting i-th city will increase Hasan's happiness by Fi units (including first and last cities), also Hasan doesn't like traveling too much, so his happiness will decrease by total distance traveled by him.
Help Hasan by choosing a sequence of cities to visit which maximizes his happiness.
Input format:
First line contain integer N.
Next N lines contains three integers each, i-th line contains coordinates of i-th city Xi, Yi and Fi.
Output format:
Output one number rounded to 6 digits after floating point, the maximum possible happiness Hasan can get. Note: If answer is 2 print 2.000000
Constraints:
1 <= N <= 3,000
0 <= Xi, Yi, Fi <= 100,000
Sample Input
3
0 0 1
3 1 1
6 0 9
Sample Output
4.675445
Explanation for the first test case:
According to the input, we have three coordinates: (0, 0), (3, 1) and (6, 0) and each of these coordinates have following happiness: 1, 1 and 9 respectively. 
Now, to get maximum happiness Hasan will start with (0, 0) and happiness of 1 units and he will travel from:
1. (0, 0) to (3, 1): This will increase its happiness by 1 and decrease it happiness by distance between these points, i.e. 3.162278 or square root of 10.
2. (3, 1) to (6, 0): This will increase its happiness by 9 and decrease it happiness by distance between these points, i.e. 3.162278 or square root of 10.

Hence, Hasan's happiness will be: 1 + 1 - 3.162278 + 9 - 3.162278 = 4.675445.
******/

#include <bits/stdc++.h>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    double * x=new double[n];
    double * y=new double[n];
    double * z=new double[n];
    double *dp=new double[n];
    for(long long i=0;i<n;i++)
    {
        cin>>x[i]>>y[i]>>z[i];
        dp[i]=-DBL_MAX;
    }
    dp[0]=z[0];
    for(long long i=1;i<n;i++)
    {
        for(long long j=0;j<i;j++)
            dp[i]=max(dp[i], dp[j] - sqrt((x[j]-x[i])*(x[j]-x[i]) + (y[j]-y[i])*(y[j]-y[i])));
        dp[i]+=z[i];
    }
	cout<<fixed<<setprecision(6)<<dp[n-1]<<endl;
    return 0;
}
