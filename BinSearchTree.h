
#ifndef BINSEARCHTREE_H
#define BINSEARCHTREE_H

#include <iostream>

// the tree node struct
struct TreeNode {
    int info {};
    TreeNode *left = nullptr;
    TreeNode *right = nullptr;
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
    void traverseNodes();
    void traverseNodes(TreeNode* root);

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


#endif //DSA_NOTES_BINSEARCHTREE_H
