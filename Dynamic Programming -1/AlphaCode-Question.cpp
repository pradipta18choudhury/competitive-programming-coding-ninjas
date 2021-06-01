/******
Alice and Bob need to send secret messages to each other and are discussing ways to encode their messages:
Alice: “Let’s just use a very simple code: We’ll assign ‘A’ the code word 1, ‘B’ will be 2, and so on down to ‘Z’ being assigned 26.”

Bob: “That’s a stupid code, Alice. Suppose I send you the word ‘BEAN’ encoded as 25114. You could decode that in many different ways!”

Alice: “Sure you could, but what words would you get? Other than ‘BEAN’, you’d get ‘BEAAD’, ‘YAAD’, ‘YAN’, ‘YKD’ and ‘BEKD’.
I think you would be able to figure out the correct decoding. And why would you send me the word ‘BEAN’ anyway?”

Bob: “OK, maybe that’s a bad example, but I bet you that if you got a string of length 5000 there would be tons of different
decodings and with that many you would find at least two different ones that would make sense.”

Alice: “How many different decodings?”

Bob: “Jillions!”
For some reason, Alice is still unconvinced by Bob’s argument, so she requires a program that will determine how many decodings
there can be for a given string using her code.
Input
Input will consist of multiple input sets. Each set will consist of a single line of at most 5000 digits representing a valid 
encryption (for example, no line will begin with a 0). There will be no spaces between the digits. An input line of ‘0’ will terminate the input and should not be processed.
Output
For each input set, output the number of possible decodings for the input string. Print your answer taking modulo "10^9+7"
Sample Input:
25114
1111111111
3333333333
0
Sample Output:
6
89
1
*******/
#include <bits/stdc++.h>
using namespace std;
#define m 1000000007


/******
int num_codes(int *input,int size)
{
	int *output=new int[size+1];
    output[0]=1;
    output[1]=1;
    
    for(int i=2;i<=size;i++)
    {
        output[i]=0;
        if(input[i-1] > 0)
            output[i] += output[i-1]%m;
        if((input[i-1] <= 6 && input[i-2] == 2)||(input[i-2] == 1))
            output[i] += output[i-2]%m;
    }
    int ans=output[size];
    delete [] output;
    return ans;
}

int main()
{
    string s;
    cin>>s;
    int *arr=new int[s.length()];
    //int n=arr.length();
    //for(int i=0;i<s.length())
    cout<<num_codes(arr,s.length())<<endl;
    return 0;
}
****/

void alphacodes(int*arr,int len){
    int*output=new int[len+1];
    output[0]=1;
    output[1]=1;
    for(int i=2;i<=len;i++){
        output[i]=0;
        if(arr[i-1]==0&&(arr[i-2]*10+arr[i-1]>26||arr[i-2]*10+arr[i-1]<10)){
            output[len]=0;
            break;
        }
        if(arr[i-1]!=0)
        output[i]=output[i-1];
        if(arr[i-2]*10+arr[i-1]<=26&&arr[i-2]*10+arr[i-1]>=10)
            output[i]=(output[i-2]+output[i])%1000000007;
    }
    int ans=output[len];
    delete[]output;
    cout<<ans<<endl;
}
int main()
{
    string s;
    while(cin>>s&&s[0]!='0'){
        int *arr=new int[s.length()];
        for(int i=0;i<s.length();i++){
            arr[i]=s[i]-'0';
        }
        alphacodes(arr,s.length());
        delete []arr;
    }
    return 0;
}
