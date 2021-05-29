/******
Return Keypad Code
Send Feedback
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
********/

#include <string>
using namespace std;

string numtostr (int n)
{
    string s1="";
    if(n==2)
    {
        s1="abc";
        return s1;
    }
    else if(n==3)
    {
        s1="def";
        return s1;
    }
    else if(n==4)
    {
        s1="ghi";
        return s1;
    }
    else if(n==5)
    {
        s1="jkl";
        return s1;
    }
    else if(n==6)
    {
        s1="mno";
        return s1;
    }
    else if(n==7)
    {
        s1="pqrs";
        return s1;
    }
    else if(n==8)
    {
        s1="tuv";
        return s1;
    }
    else if(n==9)
    {
        s1="wxyz";
        return s1;
    }
    else
    {
        return s1;
    }
}



int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    
    int a=num%10,i,j;
    int b=num/10;
    string s1=numtostr(a);
    if(num==0)
    {
        output[0]="";
        return 1;
    }
    int small=keypad(b,output);
    int k=0;
    for(i=0;i<s1.size();i++)
    {
        for(j=0;j<small;j++)
        {
          output[j+(i+1)*small]=output[j];
        }
    }
    for(i=0;i<s1.size();i++)
    {
        for(j=0;j<small;j++)
        {
            output[k]=output[k]+s1[i];
            k++;
        }
    }
    return k;
}
int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}

//-----------------------------------------------------------ANother Way  --------------------------------------------------------------------------

#include <string>
#include <vector>
using namespace std;
const vector<string>v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int keypad(int num, string output[]){

if(num==0 || num==1)
{
output[0]="";
return 1;
}

int x=num%10;
int small_answer= keypad(num/10,output);
int k=0;
static int starting_index=small_answer;
while(k<v[x].size())
{
int i=0;
for(;i<small_answer;i++)
{
//output[starting_index]=output[i]+v[x][k];
//starting_index++;
output[i+(k+1)*small_answer]=output[i];

}
k++;
}
// return small_answer*v[x].size();
    int h=0;
    for(int i=0;i<v.size();i++)
    {
        for(int j=0;j<small_answer;j++)
        {
            output[h]=output[h]+v[i];h++;
        }
    }
return h;
}

int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
