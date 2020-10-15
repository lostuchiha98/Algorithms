#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

node* root=NULL;

void bfs(node* start){

    queue<node*> que;
    que.push(start);

    while (!que.empty()){  
        node* x=que.front();
        que.pop();
        if(x!=NULL){
            cout<<x->data<<" ";
            que.push(x->left);
            que.push(x->right);
        }
    }   
}

void SearchAndInsert(node* Node,node*& root){

    if(root==NULL){
        root=Node;
        return ;
    }

    if(root->data > Node->data)
        SearchAndInsert(Node,root->left);
    
    else if(root->data < Node->data)
        SearchAndInsert(Node,root->right);

    else
        return ;   //if there is duplicate element no need to insert!
    
}

void insert(int d){
    node* Node=new node(d);
    if(root==NULL)  root=Node;
    else{
        SearchAndInsert(Node,root);
    }

}

int main(){
    insert(4);
    insert(1);
    insert(5);
    insert(9);
    insert(7);
    insert(11);
    insert(12);
    insert(15);
    insert(1);

    bfs(root);
}
