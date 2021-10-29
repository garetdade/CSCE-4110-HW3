/*
Source:
  https://gist.github.com/harish-r/a7df7ce576dda35c9660
*/

#include<iostream>
using namespace std;

class BST {

    node* root;

    node* makeEmpty(node* t) {
        if(t == NULL)
            return NULL;
        {
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }

    node* insert(int x, node* t)
    {
        if(t == NULL)
        {
            t = new node;
            t->data = x;
            t->left = t->right = NULL;
        }
        else if(x < t->data)
            t->left = insert(x, t->left);
        else if(x > t->data)
            t->right = insert(x, t->right);
        return t;
    }

    node* findMin(node* t)
    {
        if(t == NULL)
            return NULL;
        else if(t->left == NULL)
            return t;
        else
            return findMin(t->left);
    }

    node* findMax(node* t) {
        if(t == NULL)
            return NULL;
        else if(t->right == NULL)
            return t;
        else
            return findMax(t->right);
    }

    node* remove(int x, node* t) {
        node* temp;
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            t->left = remove(x, t->left);
        else if(x > t->data)
            t->right = remove(x, t->right);
        else if(t->left && t->right)
        {
            temp = findMin(t->right);
            t->data = temp->data;
            t->right = remove(t->data, t->right);
        }
        else
        {
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }

        return t;
    }

    void inorder(node* t) {
        if(t == NULL)
            return;
        inorder(t->left);
        cout << t->data << " ";
        inorder(t->right);
    }

    node* find(node* t, int x) {
        if(t == NULL)
            return NULL;
        else if(x < t->data)
            return find(t->left, x);
        else if(x > t->data)
            return find(t->right, x);
        else
            return t;
    }

    int findHight(node* t) {
      if (t == NULL)
        return 0;
      else
        return 1 + max(findHight(t->left), findHight(t->right));
    }

    int minDepth(node *t)
    {
        // Corner case. Should never be hit unless the code is
        // called on root = NULL
        if (t == NULL)
            return 0;

        // Base case : Leaf Node. This accounts for height = 1.
        if (t->left == NULL && t->right == NULL)
        return 1;

        int l = INT_MAX;
        int r = INT_MAX;
        // If left subtree is not NULL, recur for left subtree

        if (t->left)
        l = minDepth(t->left);

        // If right subtree is not NULL, recur for right subtree
        if (t->right)
        r =  minDepth(t->right);

      //height will be minimum of left and right height +1
        return min(l , r) + 1;
    }

public:
    BST() {
        root = NULL;
    }

    ~BST() {
        root = makeEmpty(root);
    }

    void insert(int x) {
        root = insert(x, root);
    }

    void remove(int x) {
        root = remove(x, root);
    }

    void display() {
        inorder(root);
        cout << endl;
    }

    void search(int x) {
        root = find(root, x);
    }

    int hight(){
      return findHight(root);
    }

    int minimumDepth(){
      return minDepth(root);
    }
};
