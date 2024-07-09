#include<bits/stdc++.h>
using namespace std;


    // PreOrder Traversal --> { NLR };
class node{
    public:
    int data;
    node* left;
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

void PreOrder(node* root){

    if(root==NULL){
        return ;
    }

    cout<<root->data<<" ";
    PreOrder(root->left);
    
    PreOrder(root->right);
}
int main(){

     node* root= NULL;
    root=buildTree(root);
    PreOrder(root);

    return 0;
}