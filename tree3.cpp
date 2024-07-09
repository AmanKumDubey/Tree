#include<bits/stdc++.h>
using namespace std;

// Inorder Traversal --> { LNR /};
class node{

    public:
    int data;
    node*left;
    node* right;

    node(int d){
         this->data=d;
         this->left=NULL;
         this->right=NULL;
    }
};
node* buildTree(node* root){
    cout<<"Enter the data for Node: "<<endl;
    int data;
    cin>>data;

    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter the left node data for "<<data<<endl;
    root->left=buildTree(root->left);

    cout<<"Enter the right node data for "<<data<<endl;
    root->right=buildTree(root->right);

    return root;

}


void inOrder(node * root){

    if(root==NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}
int main(){

    // 1 7 5 -1 -1 11 -1 -1 8 17 -1 -1 90 -1 -1
    node* root= NULL;
    root=buildTree(root);
    inOrder(root);


    return 0;
}
