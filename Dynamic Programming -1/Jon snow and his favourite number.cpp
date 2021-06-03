/******
Jon Snow and his favourite number
Send Feedback
Jon Snow now has to fight with White Walkers. He has n rangers, each of which has his own strength. Also Jon Snow has his favourite number x. Each ranger can fight with a white walker only if the strength of the white walker equals his strength. He however thinks that his rangers are weak and need to improve. Jon now thinks that if he takes the bitwise XOR of strengths of some of rangers with his favourite number x, he might get soldiers of high strength. So, he decided to do the following operation k times:
Arrange all the rangers in a straight line in the order of increasing strengths.
Take the bitwise XOR of the strength of each alternate ranger with x and update it's strength.
Suppose, Jon has 5 rangers with strengths [9, 7, 11, 15, 5] and he performs the operation 1 time with x = 2. He first arranges them in the order of their strengths, [5, 7, 9, 11, 15]. Then he does the following:
The strength of first ranger is updated to 5 xor 2, i.e. 7.
The strength of second ranger remains the same, i.e. 7.
The strength of third ranger is updated to 9 xor 2, i.e. 11.
The strength of fourth ranger remains the same, i.e. 11.
The strength of fifth ranger is updated to 15 xor 2, i.e. 13.
The new strengths of the 5 rangers are [7, 7, 11, 11, 13]
Now, Jon wants to know the maximum and minimum strength of the rangers after performing the above operations k times. He wants your help for this task. Can you help him?
Input
First line consists of three integers n, k, x (1 ≤ n ≤ 10^5, 0 ≤ k ≤ 10^5, 0 ≤ x ≤ 10^3) — number of rangers Jon has, the number of times Jon will carry out the operation and Jon's favourite number respectively.

Second line consists of n integers representing the strengths of the rangers a1, a2, ..., an (0 ≤ ai ≤ 10^3).
Output
Output two integers, the maximum and the minimum strength of the rangers after performing the operation k times.
Sample Input
5 1 2
9 7 11 15 5
Sample Output
13 7
******/
#include <bits/stdc++.h>
using namespace std;
/******
alternate elements ka xor lenge, then we need to sort again, and this xor lena then sort karna, we need to do this k times

normal way: k can be 10^5
			k time xor, then sort this will lead to 10^5, TLE
            
these array elements can be at max 10^3=1000
as we r sorting agaun and again
array has repeated elememts, 10^3 means 1000 that is less than 1024 size
xor lene k baad bhi numbers humare 1024 se bare nhi honge

approach:
array 1024 size ka rakh lenge, and jab bhi koi element ayga uske according jake count ko ek increase kar denge

instead of going to each number and doing ,
we know 1 number bohot baar repeat ho raha, 
lets figure out ki achha lets say 1 -> 100 times a raha, to 50 times hoga, 50 times nhi hoga
and accordingly change the count

maintain 2 array
1st mein count kar lenge ki kaun kitne baar a raha

*****/
int main()
{
  int *arr = new int[1026];
  int *mark = new int[1026];
  
  memset(arr,0,sizeof(arr));
  memset(mark,0,sizeof(mark));
    
  int n,k,x,index;
  cin>>n>>k>>x;
  
  for(int i=0;i<n;i++)
  {
  cin>>index;
  arr[index] = arr[index]+1;    
  }
  
  
  int collect=0;
  int range=0;
  int add;
  int xoro;
  for(int i=0;i<k;i++)
  {
    collect=0;
   for(int j=0;j<=1025;j++)
   {
   
     if(arr[j]>0)
     {
     range=arr[j];  
     add = range/2;

       
     if((collect+1)%2==1 && range%2==1)
     add++;
    
    //   cout<<add<<endl;
       
     collect=collect+range;
     xoro = j^x;  
  
     mark[xoro] = mark[xoro]+add;
      mark[j] = mark[j]+arr[j]-add;
     }
     
     }
   for(int j=0;j<=1025;j++)
   {
     
     arr[j]=mark[j];
     mark[j]=0;
   }
  
 
  }
  
 int low,high;
  //=1000;
  int r=1;
  for(int i=0;i<=1025;i++)
  {
    if(arr[i]>0 && r==1)
    {
      low=i;
     r=0;
    }
    if(arr[i]>0)
      high=i;
    
  }
 
  
  cout<<high<<" "<<low;
  
    return 0;
}
