#include<bits/stdc++.h>
using namespace std;


    // Cheak sum tree or not --> { x==L+R ?True: False };
class node{

    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->left=NULL;
        this->right=NULL;
        this->data=data;
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
    cout<<"Enter the left node data for: "<<data<<endl;
    root->left=buildTree(root->left);

    cout<<"Enter the right node data for : "<<data<<endl;
    root->right=buildTree(root->right);

    return root;
}
pair<bool ,int> isSumTree(node* root){

    if(root==NULL){
        pair<bool,int>p=make_pair(true,0);
    }
    if(root->left==NULL && root->right==NULL){
        pair<bool,int>p=make_pair(true,root->data);
        return p;
    }
    pair<bool,int>leftAns=isSumTree(root->left);
    pair<bool,int>rightAns=isSumTree(root->right);

    bool left=leftAns.first;
    bool right=rightAns.first;

    bool coudn=root->data==leftAns.second+rightAns.second;

    pair<bool,int>ans;
    if(left && right &&coudn){
        ans.first=true;
        ans.second=2* root->data;

    }
    else{
        ans.first=false;
    }
    return ans;
}
int main(){

    node* root=NULL;
    root=buildTree(root);

    

    return 0;
}