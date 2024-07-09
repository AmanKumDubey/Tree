#include<bits/stdc++.h>
using namespace std;

// Post Order Traversal --> { LRN };

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node * root){

    cout<<"Enter the data "<<endl;
    int data;
    cin>>data;

    root=new node(data);

    if(data==-1){
        return NULL;
    }
    cout<<"Enter the left node data for: "<<data<<endl;
    root->left=buildTree(root->left);

    cout<<"Enter the right node data for: "<<data<<endl;
    root->right=buildTree(root->right);
    
    return root;
}
// Post Order --

void postorderTraversal(node* root){

    if(root==NULL){
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->data<<" ";
}
int main(){

    node* root=NULL;
    root= buildTree(root);
    postorderTraversal(root);


    return 0;
}