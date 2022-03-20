
#include "BinSearchTree.h"



//------------------------------ methods --------------------------------

// return root of the tree
TreeNode * BinSearchTree::getRoot() {
    return root;
}

// insert into the BST following the logic to go left or right
bool BinSearchTree::insert(int newInt){
    TreeNode* p = root;
    TreeNode* q = nullptr;

    while (p != nullptr) {
        if (p->info == newInt) {
            return false;
        }
        q = p;
        if (newInt < p->info) {
            p = p->left;
        }
        else {
            p = p->right;
        }
    }
    // new node
    TreeNode* v = new TreeNode;
    v->info = newInt;
    if (q == nullptr) {
        std::cout << "Insert at root " << v->info << std::endl;
        root = v;
    }
    else if (newInt < q->info) {
        std::cout << "Insert " << v->info << " left to " << q->info << std::endl;
        q->left = v;
    }
    else{
        std::cout << "Insert " << v->info << " right to " << q->info << std::endl;
        q->right = v;
    }
    return true;
}

// this is a BST delete function
bool BinSearchTree::remove(int key){
    TreeNode* p = root;
    TreeNode* q = nullptr;

    while (p != nullptr && p->info != key) {
        q = p;
        if (key < p->info) {
            p = p->left;
        }
        else {
            p = p->right;
        }
    }

    if (p == nullptr) {
        return false;
    }

    TreeNode* rp;
    if (p->left == nullptr) {
        rp = p->right;
    }
    else if (p->right == nullptr) {
        rp = p->left;
    }
    else {
        TreeNode* f = p;
        rp = p->right;
        TreeNode* s = rp->left;

        while (s != nullptr) {
            f = rp;
            rp = s;
            s = rp->left;
        }

        if (f != p) {
            f->left = rp->right;
            rp->right = p->right;
        }

        rp->left = p->left;
    }

    if (q == nullptr) {
        root = rp;
    }
    else if (p == q->left) {
        q->left = rp;
    }
    else {
        q->right = rp;
    }

    delete p;
    return rp != nullptr;

}


// traversal
void BinSearchTree::traverseNodes() {
    traverseNodes(root); // call the traversal with the root, which is private
}

void BinSearchTree::traverseNodes(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    traverseNodes(root->left);
    std::cout << root->info << " ";
    traverseNodes(root->right);
}

// Recursively count the nodes in the tree
int BinSearchTree::count(TreeNode *rt) {
    if (rt == nullptr) {
        return 0;  // Nothing to count
    }
    return 1 + count( rt->left) + count(rt->right);
}

// Exercise 1: recursive method to find sum of values of all nodes
int BinSearchTree::sumOfValues(TreeNode* rt) {
    if (rt == nullptr) {
        return 0;  // no values
    }
    return rt->info + sumOfValues( rt->left) + sumOfValues(rt->right);
}


// Exercise 2: recursive function to find the height of the binary tree pointed at by "root".
// empty tree has a height of 0, a tree with one node (root) has a height of 1,
int BinSearchTree::height(TreeNode* rt) {
    if (rt == nullptr) {
        return 0;  // no values
    }
    // return largest height of left and rigtht subtree
    return std::max(1 + height(rt->left), 1 + height(rt->right));

}