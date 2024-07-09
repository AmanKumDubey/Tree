#include<bits/stdc++.h>
using namespace std;

        // Create Tree from Level Order Traversal ;

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

void buildTree_fromLevelOrder(node* root){

    cout<<"Enter the data "<<endl;
    int data;
    cin>>data;
    queue<node*>q;
    root=new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<"Enter the left node for : "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left=new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter the rifgt node for : "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right=new node(rightData);
            q.push(temp->right);
        }
    }
}
int main(){

    node* root= NULL;
    buildTree_fromLevelOrder(root);

    return 0;
}