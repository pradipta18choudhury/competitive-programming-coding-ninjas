/*******
Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his
auto - correct more times than the auto - correct corrects him. Pradyumn is thinking to make
his own app for mobile which will restrict auto - correct feature, instead it will provide 
auto - completion. Whenever Pradyumn types factorial, auto - correct changes it to fact.
Pradyumn's App will show options such as fact, factorial, factory. Now, he can chose from 
any of these options. As Pradyumn is busy with his front - end work of his App. He asks you
to help him. He said "You will be given set of words(words may repeat too but counted as one only).
Now, as user starts the app, he will make queries(in lowercase letters only). So, you have to print
all the words of dictionary which have the prefix same as given by user as input. And if no such
words are available, add this word to your dictionary." As you know, Pradyumn want this app to be
as smart as him :P So, implement a program for him such that he can release it on Fun Store.
INPUT CONSTRAINTS
1≤N≤30000
sum(len(string[i]))≤2∗10^5
1≤Q≤10^3
INPUT FORMAT
Single integer N which denotes the size of words which are input as dictionary
N lines of input, where each line is a string of consisting lowercase letter
Single integer Q which denotes the number of queries.
Q number of lines describing the query string on each line given by user
OUTPUT FORMAT
If auto - completions exists, output all of them in lexicographical order else output "No suggestions" without quotes

NOTE: All strings are lowercase
SAMPLE INPUT
3
fact
factorial
factory
2
fact
pradyumn
SAMPLE OUTPUT
fact
factorial
factory
No suggestions
********/

#include <bits/stdc++.h>
using namespace std;

class trieNode
{
    public:
    	int wordEnd;
        int child_count;
    	trieNode *children[26];
    	trieNode()
    	{
            wordEnd=0;
            child_count = 0;
        	for(int i=0;i<26;i++)
            	children[i]=NULL;
    }
};
struct trie {
    int cnt;
    //to keep a count of number of words in the tree 
    trieNode *root;
    //stores the root of the tree 
};
trie *T;
void initialize() { 
    int i; 
    T=new trie; 
    T->cnt=0; 
    T->root=new trieNode; 
}
trieNode *create_node() { 
    trieNode *newnode=new trieNode; 
    return newnode; 
}

void insert(string &s)
{
    (T->cnt)++; 
    trieNode *node=T->root;
    if(s.empty())
        return;
    
    for(int i=0;i<s.length();i++)
    {
        int index=s[i]-'a';
        if(node->children[index]==NULL){
            (node->child_count)++; 
             node->children[index]=create_node();
    	}
        node=node->children[index];
    }
    node->wordEnd=T->cnt;
       // else
       // {
        //    child=new trieNode();
        //    root->children[index]=child;
       // }
      //  child->wordEnd=true;
        //mark last node as end or leaf
   // }
}
void solve(trieNode *node, string &A, int k) { 
    int n=node->child_count, i; 
    if(node->wordEnd!=0) { 
        for(i=0;i<k;i++) 
            cout<<A[i];
        printf("\n");
    }
    for(i=0;i<26;i++) { 
        if(node->children[i]!=NULL) { 
            A[k]=(char)(i+97); 
            solve(node->children[i], A, k+1);
        }
    }
}

bool querry(string s)
{
    int length=s.size(); 
    trieNode *node=T->root; 
    for(int i=0;i<length;i++) { 
        int index=s[i]-'a'; 
        if(node->children[index]==NULL) 
            return false; 
        node=node->children[index]; 
    }
    solve(node, s, length); 
    return true;
    /*
	if(root==NULL)
        return 0;
    trieNode *curr=root;
    for(int i=0;i<s.length();i++)
    {
        int index=s[i]-'a';
        
        if(!curr->children[index])
            return 0;
        
        curr=curr->children[index];
    }
    if(curr->wordEnd==true)
    {
        cout<<s<<endl;
        return -1;
    }
    */
}


int main()
{
    int n;
    cin>>n;
    trieNode *root=new trieNode();
    initialize();
    while(n--)
    {
        string s;
        cin>>s;
        insert(s);
    }
    
    int q;
    cin>>q;
    while(q--)
    {
        string s1;
        cin>>s1;
        int b=querry(s1); 
        if(b==0) { 
            printf("No suggestions\n"); 
            insert(s1); 
        }
    }
    return 0;
}
