#include<bits/stdc++.h>
using namespace std;


// Find Diameter of the given tree
// Diameter--> { longest path b/w any two node };

// Opp2 --> { Time Complexity(O)};
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

pair<int,int> diameterfast(node* root){
    if(root==NULL){
        pair<int,int>p=make_pair(0,0);
        return p;
    }

    pair<int,int>left=diameterfast(root->left);
    pair<int,int>right=diameterfast(root->right);

    int op1=left.first;
    int op2=right.first;
    int op3=left.second+right.second+1;


    pair<int,int> ans;
    ans.first=max(op1,max(op2,op3));
    ans.second=max(left.second,right.second)+1;

    return ans;

}
int diameter(node* root){
    return diameterfast(root).first;
}
int main(){

    node* root=NULL;
    root=buildTree(root);
    cout<<endl;
    cout<<diameter(root);
    return 0;
}