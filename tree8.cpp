#include<bits/stdc++.h>

using namespace std;

// Count the Height of the given tree
// height--> { longest path b/w root node and leaf node };

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
node* buildTree(node* root){

    cout<<"Enter the data "<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root=new node(data);
    cout<<"Enter the left node data for : "<<data<<endl;
    root->left=buildTree(root->left);

    cout<<"Enter the right data for : "<<data<<endl;
    root->right=buildTree(root->right);

    return root;
}
int Height(node* root){

    if(root==NULL){
        return 0;
    }
    int left=Height(root->left);
    int right=Height(root->right);

    int ans=max(left, right)+1;

    return ans;
}
int main(){
    node* root=NULL;
    root=buildTree(root);

    cout<<Height(root);

    return 0;
}