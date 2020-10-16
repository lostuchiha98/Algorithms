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

//Breadth First Search ===========> NOT REQUIRED ONLY FOR VISUALISATION
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

void Inorder(node* start){
    node* Node=start;

    if(Node==NULL)
        return;

    Inorder(Node->left);
    cout<<Node->data<<" ";
    Inorder(Node->right);
}

node* maxLeftSubTree(node*&subRoot){
    node* currNode;
    if(subRoot->right==NULL){
        currNode=subRoot;
        subRoot=NULL;

        return currNode;
    }

    maxLeftSubTree(subRoot->right);
    
}



void Delete(int d,node* &root){

    if(root->data>d)  Delete(d,root->left);
    else if(root->data<d) Delete(d,root->right);
    else{

        if(root->left == NULL && root->right == NULL){
            root=NULL;      //deleting a leaf node 
        }

        else if(root->left == NULL || root->right == NULL){
            if(root->left!=NULL){
                root=root->left;   //deleting a parent node with one child
            }
            else{
                root=root->right;
            }
        }

        else{
            node* maxSubNode = maxLeftSubTree(root->left);  //parent node with two child
            maxSubNode->left=root->left;
            maxSubNode->right=root->right;
            root=maxSubNode;
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
        return ;
    
}

void insert(int d){
    node* Node=new node(d);
    if(root==NULL)  root=Node;
    else{
        SearchAndInsert(Node,root);
    }

}

int main(){
    insert(16);
    insert(12);
    insert(18);
    insert(8);
    insert(14);
    insert(17);
    insert(19);
    insert(7);
    insert(10);
    insert(20);
    insert(9);
    insert(11);
    insert(21);
    insert(22);
    Delete(8,root);
    Delete(16,root);
    Delete(19,root);
    Inorder(root);  //is used to get the element from the tree in sorted order
    // bfs(root);
}
