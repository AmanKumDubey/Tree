#include<bits/stdc++.h>
using namespace std;

// cheak tree is balance or not 
// Time Complexity --> { O(n) };

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data=data;
        this->right=NULL;
        this->left=NULL;
    }
};

node* buildTre(node* root){

    cout<<"Enter data "<<endl;
    int data;
    cin>>data;

    if(data==-1){
        return NULL;
    }
    root=new node(data);

    cout<<"Enter the left node data for : "<<data<<endl;
    root->left=buildTre(root->left);

    cout<<"Enter the right node data for :"<<data<<endl;
    root->right=buildTre(root->right);

    return root;
}

pair<bool,int> iSBlance(node* root){

    if(root==NULL){
        pair<bool,int>p= make_pair(true,0);
        return p;
    }
    pair<int,int>left=iSBlance(root->left);
    pair<int,int>right=iSBlance(root->right);

    bool leftans=left.first;
    bool rightans=right.first;

    bool diff=abs(left.second-right.second)<=1;

    pair<bool,int>ans;
    ans.second=max(left.second,right.second)+1;

    if(leftans && rightans && diff){
        ans.first=true;
    }
}
int main(){

    node* root=NULL;
    root=buildTre(root);
    cout<<endl;
    cout<<"This is balance : "<<iSBlance(root).first;

    return 0;
}