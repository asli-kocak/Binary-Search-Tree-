/*
 * BinarySearchTree.h
 * COMP15
 * Spring 2021
 *
 * Implemented by Tufts CS department
 * Edited by Asli Kocak
 *
 * Interface of the Binary Search Tree class.
 * Behaves like a standard BST except that it handles multiplicity
 * If you insert twice a number and then remove it once, then it will
 * still be in the data structure
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_


class BinarySearchTree {
public:
        // constructor
        BinarySearchTree();

        // destructor
        ~BinarySearchTree();

        // copy constructor 
        BinarySearchTree(const BinarySearchTree &source);

        // assignment overload 
        BinarySearchTree &operator=(const BinarySearchTree &source);

        // find_min() returns the minimum value in the tree
        // returns INT_MAX if the tree is empty 
        int find_min() const;

        // find_max() returns the maximum value in the tree
        // returns INT_MIN if tree is empty 
        int find_max() const;

        // contains() returns true if the value is in the tree,
        // false if it is not in the tree 
        bool contains(int value) const;

        // insert() inserts the value into the Binary Search Tree.
        // If the value is already in the tree, the node's count
        // is incremented by 1
        void insert(int value);

        // remove() does a full removal from the tree (NOT lazy removal)
        // If a node's count is greater than one, the count is
        // decremented, and the node is not removed.
        bool remove(int value);

        // returns the maximum distance from the root to it's farthest
        // leaf.
        int tree_height() const; 

        // returns the total number of nodes (NOT including duplicates)
        int node_count() const; 

        // return the sum of all the node values (including duplicates)
        int count_total() const;

        // print the tree
        void print_tree() const;

private:
        // Binary Search Tree Node:
        // - data is the value
        // - count is the number of times the data has been inserted
        //   into the tree (minus removals)
        //
        struct Node {
                int   data;
                int   count;
                Node *left;
                Node *right;
        };
        // the root of the tree (starts as NULL)
        Node *root;

        // Allocates heap memory and creates a new node with inputted 
        // parameters
        Node *new_node(int value, int count, Node *left, Node *right) const;


        // the following functions are private helper functions
        // for the public functions. We do not want to expose the
        // internals of the tree publicly, so we pass the root (and
        // other information in some cases) to the functions below
        // from the public functions.

        Node *find_min(Node *node) const;
        Node *find_max(Node *node) const;
        bool  contains(Node *node, int value) const;
        void  insert(Node *node, Node *parent, int value);

        
        bool remove(Node *node, Node *parent, int value);
        // the following 3 are helper functions for the helper function remove
        // removes leaf (when node is not pointing to any other values)
        void remove_leaf(Node *node, Node *parent);
        // removes parent with single child 
        // (when the node is only pointing to one child)
        void remove_single_child(Node *node, Node *parent);
        // removes a parent with 2 children
        void remove_node_with_siblings(Node *node);


        int   tree_height(Node *node) const;
        int   node_count(Node *node) const;
        int   count_total(Node *node) const;
        Node *pre_order_copy(Node *node) const;

        // used by the destructor to delete nodes recursively
        void post_order_delete(Node *node);
        
        // find_parent (written by the cs department) is necessary for removing
        // the right_min of a node when removing a node that has
        // two children
        Node *find_parent(Node *node, Node *child) const;

        // Pretty print
        void print_tree(Node *node, char *const currPos,
                        const char *const fullLine,
                        const char *const branch) const;
};

#endif /* BINARYSEARCHTREE_H_ */
