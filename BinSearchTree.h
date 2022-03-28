
#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H

#include <iostream>

// the tree node struct
struct TreeNode {
    int info {};
    TreeNode * left = nullptr;
    TreeNode * right = nullptr;
};


// the binary search tree class
class BinSearchTree {

public:
    // constructor
    BinSearchTree() {
        root = nullptr;
    }

    //------------------------------ methods --------------------------------
    TreeNode * getRoot();

    bool insert(int newInt);
    bool remove(int key);

    // recursive inorder traversal
    void inTrav();
    void inTrav(TreeNode* root);


    void printLessThanK(TreeNode* root, int k);


    //recursive preorder traversal
    void preTrav(TreeNode* root);

    // recursive postorder traversal
    void postTrav(TreeNode* root);

    // Recursively count the nodes in the tree
    int count(TreeNode* rt);

    // Exercise 1: recursive method to find sum of values of all nodes
    int sumOfValues(TreeNode* rt);


    // Exercise 2: recursive function to find the height of the binary tree pointed at by "root".
    // empty tree has a height of 0, a tree with one node (root) has a height of 1,
    int height(TreeNode* rt);


private:
    TreeNode* root;
};


#endif
