#include<bits/stdc++.h>
using namespace std;

    // Zig- Zag Traversal --> { levelOrder traversal -> R_to_L and L_to_R };
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

    cout<<"Enter the left node data for: "<<data<<endl;
    root->left=buildTree(root->left);

    cout<<"Enter the right node data for: "<<data<<endl;
    root->right=buildTree(root->right);

    return root;
}
vector<int>ZigZagTraversal(node* root){

    vector<int>result;
    if(root==NULL){
        return result;
    }

    queue<node*>q;
    q.push(root);

    bool leftToRight=true;
    while (!q.empty())
    {
        int size=q.size();
        vector<int>ans(size);

        // LevelProcess 
        for(int i=0;i<size;i++){
            node* frontNode=q.front();
            q.pop();

            //normal inser or reversal insert
            int index=leftToRight?i:size-i-1;
            ans[index]=frontNode->data;

            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
        leftToRight=!leftToRight;
    
    for(auto i: ans){
        result.push_back(i);
        
    }
    }
    for(int i=0;i<result.size();i++){
        cout<<result[i]<< " ";
    }
    return result;
}
int main(){

    return 0;
    node* root=NULL;
    root=buildTree(root);
    ZigZagTraversal(root);


}