/*******
Let us see how search engines work. Consider the following simple auto complete feature. When you type some 
characters in the text bar, the engine automatically gives best matching options among it's database.
Your job is simple. Given an incomplete search text, output the best search result.
Each entry in engine's database has a priority factor attached to it. We consider a result / search 
suggestion best if it has maximum weight and completes the given incomplete search query. For each 
query in the input, print the maximum weight of the string in the database, that completes the given
incomplete search string. In case no such string exists, print -1.
INPUT
First line contains two integers n and q, which represent number of database entries and number of
search queries need to be completed. Next n lines contain a string s and an integer weight, which are the database entry and it's corresponding priority.

Next q lines follow, each line having a string t, which needs to be completed.
OUTPUT
Output q lines, each line containing the maximum possible weight of the match for given query, else -1, in case no valid result is obtained.
CONSTRAINTS
1 ≤ n, weight, len(s), len(t) ≤ 10^6
1 ≤ q ≤ 10^5
total length of all strings in database entries ≤ 10^6
total length of all query strings ≤ 10^6
SAMPLE INPUT
2 1
hackerearth 10
hackerrank 9
hacker
SAMPLE OUTPUT
10
********/
#include <bits/stdc++.h>
using namespace std;
/*****
every trie contain how many children it have, but in this q trie will also contain 
its no of children and some weight
for every insertion we need to take care of weight as well

for search purpose, first travel the whole prefix, if any of the node is not present then 
simply return -1

trienode** children  = **because we need to maintain a array of children of each node
and every children has some weight
*******/


class trieNode
{
    public:
    trieNode **children;
    int weight;
    
    trieNode()
    {
        children=new trieNode*[26];
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        weight=0;
    }
};

void insert(string s,int w,trieNode *root)
{
    if(s.empty())
        return;
    
    int index=s[0]-'a';
    trieNode *child;
    if(root->children[index])
        child=root->children[index];
    else
    {
        child=new trieNode();
        root->children[index]=child;
    }
    if(root->weight<w)
        root->weight=w;
    insert(s.substr(1),w,child);
}

int BestSearch(string s,trieNode *root)
{
    trieNode *current=root;
    int bestWeight=-1;
    
    for(int i=0;i<s.length();i++)
    {
        int index=s[i]-'a';
        trieNode *child=current->children[index];
        if(child)
        {
            current=child;
            bestWeight=child->weight;
        }
        else
            return -1;
    }
    return bestWeight;
}

int main()
{
    int n,q;
    cin>>n>>q;
    trieNode *root=new trieNode();
    
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        int weight;
        cin>>weight;
        insert(s,weight,root);
    }
    
    for(int i=0;i<q;i++)
    {
        string pre;
        cin>>pre;
        cout<<BestSearch(pre,root)<<endl;
    }
    return 0;
}
