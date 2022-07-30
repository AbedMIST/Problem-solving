// Binary search tree --> left child< node <right child
// pre-order,in-drder,post-order traversal is easy in pointer recursion form
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int key, level;
    Node *left, *right, *parent;
    Node(){}
    Node(int val)
    {
        key = val;
        level = 0;
        left = NULL;
        right = NULL;
        parent = NULL;
    }
};


class BST{
public:
    Node *root;

public:
    BST(){
        root = NULL;
    }

    Node* getRoot() {return root;}

private:
    void insertRoot(int val){
        ///Creates a node in the bst as root
        Node *newNode = new Node(val);
        root = newNode;
    }

    void insertOther(int val){
        ///Creates a node in the bst which is not root
        Node *newNode = new Node(val);

        Node *curNode = root;
        Node *prevNode = NULL;

        while(curNode != NULL)
        {
            prevNode = curNode;
            if(val < curNode->key) curNode = curNode->left;
            else curNode = curNode->right;
        }

        newNode->parent = prevNode;

        if(val < prevNode->key) prevNode->left = newNode;
        else prevNode->right = newNode;
    }

public:
    void insert(int val){
        ///Creates a node in the bst
        if(root == NULL) insertRoot(val);
        else insertOther(val);
    }

    Node* findNode(int val){
        ///Returns the reference of a node in the bst that contains the parameter as key
        Node *curNode = root;
        while(curNode != NULL)
        {
            if(curNode->key == val) return curNode;
            else if(curNode->key < val) curNode = curNode->right;
            else curNode = curNode->left;
        }
        return NULL;
    }

    Node* findMaximum(Node *node){
        ///Returns the reference of the maximum node in the bst which contains the parameter as root
        Node *curNode = node;
        while(curNode->right != NULL) curNode = curNode->right;
        return curNode;
    }

    Node* findMinimum(Node *node){
        ///Returns the reference of the maximum node in the bst which contains the parameter as root
        Node *curNode = node;
        while(curNode->left != NULL) curNode = curNode->left;
        return curNode;
    }

    void dfs(Node *node){
        ///Prints the in order traversal containing the parameter as root
        if(node == NULL) return;
        dfs(node->left);
        cout << node->key << ' ';
        dfs(node->right);
    }

private:
    Node* findSuccessor(Node *node){
        ///Returns the reference of the in order successor of the parameter in the bst
        return findMinimum(node->right);
    }

    void delete0Child(Node *node){
        ///Removes the parameter from the bst if the parameter is a leaf node
        if(node == root) root = NULL;
        else
        {
            Node *curParent = node -> parent;
            if(curParent->left == node) curParent->left = NULL;
            else curParent->right = NULL;
        }
        delete node;
    }

    void delete1Child(Node *node){
        ///Removes the parameter from the bst if the parameter has only one child
        Node *child = NULL;
        if(node->left == NULL) child = node -> right;
        else child = node->left;

        if(node == root) root = child;
        else
        {
            Node *curParent = node -> parent;
            if(curParent->left == node) curParent->left = child;
            else curParent->right = child;
        }
        delete node;
    }

    void delete2Child(Node *node){
        ///Removes the parameter from the bst if the parameter has 2 children
        Node *successor = findSuccessor(node);
        node->key = successor->key;
        if(successor->right == NULL) delete1Child(successor);
        else delete0Child(successor);
    }

public:
    bool deleteNode(int val){
        ///Removes a node containing the parameter from the bst
        ///Returns true in case of successful deletion, otherwise returns false
        Node *targetNode = findNode(val);
        if(targetNode == NULL) return false;
        else
        {
            if(targetNode->left == NULL && targetNode->right == NULL) delete0Child(targetNode);
            else if(targetNode->left != NULL && targetNode->right != NULL) delete2Child(targetNode);
            else delete1Child(targetNode);
            return true;
        }
    }

    int height(Node *node){
        ///returns the height of the bst
        ///Must develop a recursive solution
        if(node == NULL) return 0;
        int ret = 1 + max(height(node->left), height(node->right));
        return ret;
    }

    void bfs(){
        queue<Node*> q;
        root->level = 0;
        int level = root->level;
        q.push(root);

        while(!q.empty()){
            Node *temp = q.front();
            q.pop();
            if(temp->level > level){
                cout<<endl;
                level++;
            }
            cout<<temp->key<<" ";
            if(temp->left!=NULL){
                if(temp->left!=root)  temp->left->level = temp->level + 1;
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                if(temp->right!=root)  temp->right->level = temp->level + 1;
                q.push(temp->right);
            }
        }
    }
};



int main()
{
    BST b;
    int x,i,j,n;

    cin>>n;
    for(i=0;i<n;i++){
        cin>>x;
        b.insert(x);
    }

    b.dfs( b.root);   //show nodes in order traversal

}

// 9
// 6 10 14 13 7 4 3 8 1