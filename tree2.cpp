#include<bits/stdc++.h>
using namespace std;

//level order traversal of tree (DFS)

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

node*  buildTree(node* root){

    cout<<"Enter your data :"<<endl;
    int data;
    cin>>data;

    root=new node(data);

    if(root->data==-1){
        return NULL;
    }

    cout<<"Enter the left tree data for : "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter the right tree data for : "<<data<<endl;
    root->right=buildTree(root->right);


    return root;

}
void levelOrder_Traversal(node* root){
     queue<node*>q;
     q.push(root);
     q.push(NULL);

     while(!q.empty()){
        node* temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
     }
}

int main(){

    node* root=NULL;
    root=buildTree(root);
    cout<<endl;
    levelOrder_Traversal(root);

    return 0;
}