#include<bits/stdc++.h>
using namespace std;

// cheak for balance tree --> { height[left] - height[right] <=1 };
// Time complexity- { O(n^2) };

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
    cout<<"Enter the left node data : "<<data<<endl;
    root->left=buildTree(root->left);

    cout<<"Enter the right node data : "<<data<<endl;
    root->right=buildTree(root->right);

    return root;
}

int height(node* root){

    if(root==NULL){
        return 0;
    }

    int left=height(root->left);
    int right=height(root->right);

    int ans=max(left,right)+1;

    return ans;
}
bool isBalanced(node* root){

    //base case
    if(root==NULL){
        return true;
    }
    bool left=isBalanced(root->left);
    bool right=isBalanced(root->right);
    bool diff=abs(height(root->left)-height(root->right))<=1;
    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }
}
int main(){

    node* root=NULL;
    root=buildTree(root);
    cout<<endl;
    cout<<"This is balance tree: "<<isBalanced(root);


    return 0;
}