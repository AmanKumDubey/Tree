#include<bits/stdc++.h>
using namespace std;
 
        // { Count the leaf Node for the given tree };

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
node* buildtree(node* root){

    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;

    root=new node(data);
    if(data==-1){
        return NULL;
    }

    cout<<"Enter the left node data for "<<data<<endl;
    root->left=buildtree(root->left);

    cout<<"Enter the right node data for "<<data<<endl;
    root->right=buildtree(root->right);

    return root;
}

void inOrderTraversal(node* root,int &count){

    if(root==NULL){
        return;
    }
     inOrderTraversal(root->left,count);
     cout<<root->data<<" ";
     if(root->left==NULL && root->right==NULL){
        count++;
     }
     inOrderTraversal(root->right,count);

//      return count;
}
int main(){

    node* root=NULL;
    int count=0;
    root=buildtree(root);

    // 1 7 5 -1 -1 11 -1 -1 8 17 -1 -1 -1

    inOrderTraversal(root,count);
    cout<<endl;
    cout<<count;

     

     return 0;
}