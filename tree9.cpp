#include<bits/stdc++.h>
using namespace std;


// Find Diameter of the given tree
// Diameter--> { longest path b/w any two node };

// Opp1 --> { Time Complexity(O^2)};
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

    if(data==-1)
    {
        return NULL;
    }
    root=new node(data);
    cout<<"Enter left node data for "<<data<<endl;
    root->left=buildTree(root->left);

    cout<<"Enter right node data for "<<data<<endl;
    root->right=buildTree(root->right);

    return root;
}

int Height(node* root){

    if(root==NULL){
        return 0;
    }

    int left=Height(root->left);
    int right=Height(root->right);

    int ans=max(left,right)+1;
    return ans;

}
int diameter(node* root){
    if(root==NULL){
        return 0;
    }
    int op1=diameter(root->left);
    int op2=diameter(root->right);
    int op3=Height(root->left)+Height(root->right)+1;

    int ans=max(op1,max(op2,op3));

    return ans;
}
int main(){

    node* root=NULL;
    root=buildTree(root);
    cout<<endl;
    cout<<diameter(root);
    return 0;
}