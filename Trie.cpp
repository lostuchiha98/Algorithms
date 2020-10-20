//Queries --->search  --->insert --->same prefix

#include<bits/stdc++.h>
using namespace std;

class Trie{
    public:
        map<char,Trie*> child;
        bool isEnd;
        int prefix;

        Trie(){
            isEnd=false;
            prefix=0;
        }
};

Trie* root=new Trie();

void insert(string word){

    Trie* currNode=root;
    for(int i=0;i<word.size();i++){
        char letter=word[i];
        Trie* node=currNode->child[letter];
        if(node==NULL){
            node=new Trie();
            currNode->child[letter]=node;
        }
        currNode=node;
        currNode->prefix++;
    }
    currNode->isEnd=true;

}

bool search(string word){
    Trie* currNode=root;
    for(int i=0;i<word.size();i++){
        char letter=word[i];
        if(currNode->child[letter]==NULL)
            return false;
        currNode=currNode->child[letter];
    }
    if(currNode->isEnd) return true;
    return false;
}

int totalPrefix(string word){
    Trie* currNode=root;
    for(int i=0;i<word.size();i++){
        char letter=word[i];
        if(currNode->child[letter]==NULL)
            return 0;
        currNode=currNode->child[letter];
    }
    return currNode->prefix; 
}


int main(){
    int n;
    cin>>n;

    vector<string> allWord;

    for(int i=0;i<n;i++){
        string x;
        cin>>x;
        allWord.push_back(x);
    }

    for(int i=0;i<allWord.size();i++){
        insert(allWord[i]);
    }
    string s;
    cin>>s;
    cout<<search(s)<<endl;

    string prefixC;

    cin>>prefixC;

    cout<<totalPrefix(prefixC)<<endl;
}