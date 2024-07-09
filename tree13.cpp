#include<bits/stdc++.h>
using namespace std;

// Determine if two nodes are identical:

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

    cout<<"Enter the data "<<endl;
    int data;
    cin>>data;

    if(data==-1){
        return NULL;
    }

    root= new node(data);
    
    cout<<"Enter the left node1 data for: "<<data<<endl;
    root->left=buildtree(root->left);

    cout<<"Enter the right node1 data for: "<<data<<endl;
    root->right=buildtree(root->right);

    
    return root;
}

bool isIdentical(node* r1,node* r2){

    if(r1==NULL && r2==NULL){
        return true;
    }
    if(r1==NULL && r2!=NULL){
        return false;
    }
    if(r1!=NULL && r2==NULL){
        return false;
    }
    bool left=isIdentical(r1->left,r2->left);
    bool right=isIdentical(r1->right,r2->right);

    bool value=r1->data==r2->data;

    if(left && right && value){
        return true;
    }
    else{
        return false;
    }
}
int main(){

    node* rootx=NULL;
    node* rooty=NULL;
    cout<<"Enter data for first node "<<endl;
    rootx=buildtree(rootx);
    cout<<"Enter data for second node "<<endl;
    rooty=buildtree(rooty);

    cout<<endl;
    cout<<"These nodes are identical.. : "<<isIdentical(rootx,rooty);

    return 0;
}