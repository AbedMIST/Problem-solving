#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int key;
    Node *left, *right, *parent;
    Node(){}
    Node(int val)
    {
        key = val;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};



Node* insert(Node *root,int val){
    ///Creates a node in the binary tree
    if(root==NULL){
        Node *newNode = new Node(val);
        root = newNode;
        return root;
    }
    else{

        queue<Node*> q;
        q.push(root);
     
        while (!q.empty()) {
            Node* temp = q.front();
            q.pop();
     
            if (temp->left != NULL)
                q.push(temp->left);
            else {
                Node *newNode = new Node(val);
                temp->left = newNode;
                return root;
            }
     
            if (temp->right != NULL)
                q.push(temp->right);
            else {
                Node *newNode = new Node(val);
                temp->right = newNode;
                return root;
            }
        }
    }
    
}



bool sameTree(Node *a,Node *b){

    if (a == NULL && b == NULL)
        return true;
 
    if (a != NULL && b != NULL && a->key==b->key)   //compare
    {
        return (sameTree(a->left, b->left) && sameTree(a->right, b->right)) ;
    }
     
    return false;
}

bool isSubtree(Node* root, Node* subroot){

    if(subroot == NULL)    return true;
    if(root == NULL && subroot != NULL)    return false;
    
    // both are not NULL
    if( sameTree(root,subroot))   return true;  //will get ans

    return (isSubtree(root->left,subroot) || isSubtree(root->right,subroot));
}


int main()
{

    int x,i,j,n,m;
    Node *root1 = NULL;
    Node *root2 = NULL;

    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>x;
        root1 = insert(root1,x);
    }
    for(i=0;i<m;i++){
        cin>>x;
        root2 = insert(root2,x);
    }


    bool ans = isSubtree(root1,root2);
    cout<<ans<<endl;

}