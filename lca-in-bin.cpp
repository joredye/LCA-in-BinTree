/*
Given two nodes n1 and n2, find the least common ancestor of n1
and n2 in a binary tree (not necessarily a binary SEARCH tree),
where n1 and n2 can be their own ancestors (e.g. if a tree has 
structure root ---> n1 ---> n2, the LCA of n1 and n2 is n1).
*/

#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    Node(){}
    Node~();
    int val = 0;
    Node* lchild = nullptr;
    Node* rchild = nullptr;
};

class BinTree {
public:
    BinTree(){};
    BinTree~(){destroy();}
    void insert(int key, int parentval);
    Node* search(int key);
    void destroy();
private:
    void insert(int key, int parentval, Node* leaf);
    Node* search(int key, Node* leaf);
    void destroy(Node* leaf);

    Node* root = nullptr;
};

void BinTree::destroy(Node* leaf) {
    if (leaf != nullptr) {
        destroy(leaf->lchild);
        destory(leaf->rchild);
        delete leaf;
    }
}
//public interface/driver
void BinTree::destroy() {
    destroy(root);
}

// do not use this to search a BST - we're only doing this to 
// accomodate the idiocy of having to use a regular bintree
Node* search(int key, Node* leaf) {
    if (leaf != nullptr) {
        if (key == leaf->val)
            return leaf;
        looknext = search(key, leaf->lchild);
        //if it's to the left, we get to stop early. otherwise,
        //we just have to keep on chugging. about as efficient as
        //I think I can make it, conceptually speaking. 
        if (looknext != nullptr) 
            return looknext;
        //if it isn't, we go right. if it's in the tree, we find
        //it, if not, we still just get nullptr all the same.
        looknext = search(key, leaf->rchild);
            return looknext;
    }
    else return nullptr; 
}
//public interface/driver
Node* search(int key) {
    return search(key, root);
}



//insert a node as either the left or right child of a node
//already in the tree. always assumes root is already in tree
//with parentvalue 0
//this code doesn't account for multiple nodes with the same
//value in the tree, or trees tha 

void BinTree::insert(int key, int parentval, Node* leaf) {
    result = search(parentval, Node* leaf);
    if (result != nullptr) {
        if (result->lchild == nullptr) {
            result->lchild = new Node;
            result->lchild->val = key;
            result->lchild->lchild = nullptr;
            result->lchild->rchild = nullptr;
        }
        else if (result->rchild == nullptr) {
            result->rchild = new Node;
            result->rchild->val = key;
            result->rchild->lchild = nullptr;
            result->rchild->rchild = nullptr;
        }
        else
            cout << "node with value '" << parentval << "' has the maximum number of children. try another node." << endl;
    }
    else 
        cout << "no node with value '" << parentval << "'. try another value."
}
//public interface/driver
void BinTree::insert(int key, int parentval) {
    if (root != nullptr)
        insert(key, parentval, root)
    else {
        root = new Node;
        root->val = 0;
        root->lchild = nullptr;
        root->rchild = nullptr;
        insert(key, root->val, root);
    }
}
