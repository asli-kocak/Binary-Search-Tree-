/*
 * BinarySearchTree.cpp
 * COMP15
 * Spring 2021
 *
 * Implementation of the Binary Search Tree class.
 * Behaves like a standard BST except that it handles multiplicity
 * If you insert a number twice  and then remove it once, then it will
 * still be in the data structure
 */

#include <cstring>
#include <iostream>
#include <limits>

#include "BinarySearchTree.h"

using namespace std;

// Purpose:     Initializes the Binary Tree so that the 
//              root points to a null pointer.
// Parameters:  None
BinarySearchTree::BinarySearchTree()
{
       //Set root to a null node
       root = nullptr;
}



// Purpose:     Destructor that post order deletes the heap allocated memory 
//              for the tree
// Parameters:  None
BinarySearchTree::~BinarySearchTree()
{
        // walk tree in post-order traversal and delete
        post_order_delete(root);
        root = nullptr;  // not really necessary, since the tree is going
                         // away, but might want to guard against someone
                         // using a pointer after deleting
}



// Purpose:     Helper for destructor, uses recursion to use post order 
//              traversal and delete all the nodes
// Parameters:  Starting node for the deletion
void BinarySearchTree::post_order_delete(Node *node)
{

        // Recursively deletes all Nodes in the tree in a post-order fashion

        if (node != nullptr) {
                //recurses left then right first, then deletes the node
                post_order_delete(node->left);
                post_order_delete(node->right);
                delete node;
        }


}

// copy constructor
BinarySearchTree::BinarySearchTree(const BinarySearchTree &source)
{
        // use pre-order traversal to copy the tree
        root = pre_order_copy(source.root);
}

// assignment overload
// Purpose:     Overloads "=" so that it can copy trees
// Parameters:  source tree
BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &source)
{
        // check for self-assignment, do nothing if this is the case
        if (this == &source) {
                return *this;
        }
        
        // delete current tree if it exists and delete any memory it uses
        post_order_delete(root);

        // use pre-order traversal to copy the tree - deep copy
        root = pre_order_copy(source.root);
        return *this;
}

// Purpose:     Helper function that uses recursion to pre-order copy the tree
// Parameters:  initial node that the copying will start at

BinarySearchTree::Node *BinarySearchTree::pre_order_copy(Node *node) const
{
        // use a pre-order traversal to copy details from the
        // node to a new node)

        //create a node pointer to put the new node in
        Node *copy_node = nullptr;
        
        if (node != nullptr) {
                //create a new node with the given node's specifications
                //recurse to find its left and right pointers
                copy_node = new_node(node->data, node->count, 
                                     pre_order_copy(node->left), 
                                     pre_order_copy(node->right));

                //return the newly created node
                return copy_node;
        } 
        //if node is nullptr, return nullptr
        return nullptr;


}

// Find minimum value 
int BinarySearchTree::find_min() const
{
        if (root == nullptr)
                return numeric_limits<int>::max(); // INT_MAX

        return find_min(root)->data;
}


// Purpose:     Returns the address of the Node with the smallest data value.
// Parameters:  initial node that the searching for min will start at 
BinarySearchTree::Node *BinarySearchTree::find_min(Node *node) const
{

        // recurse through tree to find Node with smallest value and
        // return address of that Node.

        if (node->left == nullptr) {
                return node;
        } else {
                //go left as in bst's the leftmost element is the smallest
                return find_min(node->left);
        }
}

// Purpose:     Find maximum data in the tree
// Parameters:  none
int BinarySearchTree::find_max() const
{
        //return smallest possible value if root is a nullptr
        if (root == nullptr)
                return numeric_limits<int>::min(); // INT_MAX
        //return the data of the node found by the helper function
        return find_max(root)->data;
}

// Purpose:     Returns the address of the Node with the largest data value.
// Parameters:  initial node that the searching for max will start at 
BinarySearchTree::Node *BinarySearchTree::find_max(Node *node) const
{
        // recurse through tree to find Node with largest value and
        // return address of that Node.
        if (node->right == nullptr) {
                return node;
        } else {
                //go right as in bst's the leftmost element is the largest
                return find_max(node->right);
        }


}

// Purpose:     Returns true if a value is contained in the tree, false 
//              otherwise
// Parameters:  value that's being searched for
bool BinarySearchTree::contains(int value) const
{
        //The public function calls the recursive (private) function to do
        // the search

        return contains(root, value);
}

bool BinarySearchTree::contains(Node *node, int value) const
{       
        //return false if the value is nullptr, as it cannot have a value
        if (node == nullptr) {
                return false;
        } else {
                //if data contains value, return true, otherwise recurse
                //to both subtrees, until its either the end, or the value is
                //found
                if (node->data == value) {
                        return true;
                } else if (value < node->data) {
                        return contains(node->left, value);
                } else if (value > node->data) {
                        return contains(node->right, value);
                }
        }
        return false;
}
 

void BinarySearchTree::insert(int value)
{
        insert(root, nullptr, value);
}



// Purpose:     Inserts given value to tree recursively
// Parameters:  node where the insertion starts at, its parent, and the value
//              to be inserted
void BinarySearchTree::insert(Node *node, Node *parent, int value)
{
        //if the node is empty, insert new value to the appropriate branch
        if (node == nullptr) { 
                node = new_node(value, 1, nullptr, nullptr);  
                if (parent == nullptr) {
                        root = node;
                } else if(parent->data > node->data) {
                        parent->left = node;
                } else if (parent->data < node->data) {
                        parent->right = node;
                }
        //otherwise recurse until you find the empty node, available for insert  
        } else if (node->data > value) {
                insert(node->left, node, value);
        } else if (node->data < value) {
                insert(node->right, node, value);
        
        } else if (node->data == value) {
                //if data already exists, increase it's count
                node->count++;
        }
 
}


// Purpose:     Create new place for node in heap
// Parameters:  variables of the Node struct
BinarySearchTree::Node *BinarySearchTree::new_node (int value, int count, 
                                                   Node *left, Node *right) 
                                                const {
        //create heap place for new node
        Node *new_value = new Node();
        //set the new values
        new_value->data = value;
        new_value->count = count;
        new_value->left = left;
        new_value->right = right;

        return new_value;

}


// Purpose:     Removes given element from the tree
// Parameters:  value to be removed
bool BinarySearchTree::remove(int value)
{
        // use helper function and pass in the root
        return remove(root, nullptr, value);
}



// Purpose:     Removes the given element from the tree recursively
// Parameters:  node, its parent, and the value to be removed
bool BinarySearchTree::remove(Node *node, Node *parent, int value)
{
        //if contains value, start removal
        if (contains(value)){
                if (node->data == value) {
                        //go into specific cases when the value is found
                        if (node->count > 1) {
                                node->count--;
                        } else if (node->right == nullptr and 
                                   node->left == nullptr) {

                                remove_leaf(node, parent);

                        } else if (node->right == nullptr or 
                                   node->left == nullptr){
                                remove_single_child(node, parent);
                        } else if (node->right != nullptr and 
                                   node->left != nullptr) {
                                remove_node_with_siblings(node);
                        }
                        return true;
                //recurse if value is not found
                } if (node->data > value) {
                        
                        return remove(node->left, node, value);
                } if (node->data < value) {
                        return remove(node->right, node, value);
                }
        //otherwise return false
        } else {
                return false;
        }
        return false;
}



// Purpose:     Removes when value is a leaf
// Parameters:  node, its parent
void BinarySearchTree::remove_leaf(Node *node, Node *parent) {
        //set appropriate parent to nullptr
        if (node->data < parent->data){
                parent->left = nullptr;
        } else {
                parent->right = nullptr;
        }
        //delete node
        delete node;
}



// Purpose:     Removes when value has one child
// Parameters:  node, its parent
void BinarySearchTree::remove_single_child(Node *node, Node *parent){
        
        Node *replace_with = nullptr;
        //creates a nullptr to store the data in 
        if (node->right == nullptr) {
                replace_with = node->left;
        } else if (node->left == nullptr) {
                replace_with = node->right;
        }  
        
        //places the nullptr to appropriate child pointer of the parent
        if (parent == nullptr) {
                //if there is no parent, it means we need to replace the root
                root = replace_with;
        } else if (parent->data > node->data) {
                parent->left = replace_with;
        } else if (parent->data < node->data) {
                parent->right = replace_with;
        } 
        //delete the old node from memory
        delete node;

}

// Purpose:     Removes when value has two children
// Parameters:  node itself
void BinarySearchTree::remove_node_with_siblings(Node *node) { 

        //uses the minimum value in the right subtree for replacing
        Node *replace_with = find_min(node->right);    
        int replace_with_count = replace_with->count;
        int replace_with_data = replace_with->data;
        //sets count to 1 so that it does not decrease count instead of
        //removing the old minimum node.
        replace_with->count = 1;    
        remove(node->right, node, replace_with->data);
        //replaces the values of the node
        node->data = replace_with_data;
        node->count = replace_with_count;
}


int BinarySearchTree::tree_height() const
{
        return tree_height(root);
}


// Purpose:     Returns the height, the number of hops you need to do to
//              reach a leaf
// Parameters:  node itself
int BinarySearchTree::tree_height(Node *node) const
{

        //An empty tree (no root) is considered to have a height of -1
        //A tree with just a single Node has a height of 0.
        if (node == nullptr) {
                return -1;
        } else {
                //adds in heights of left and right subtrees by recursion.
                //every recursion adds +1
                int height_left = tree_height(node->left);
                int height_right = tree_height(node->right);
                //compares both subtrees and returns longest subtree's height
                if (height_left > height_right) {
                        return 1 + height_left;
                } else if (height_right >= height_left) {
                        return 1 + height_right;
                }

        }
        return 0;
}



//returns the total number of nodes
int BinarySearchTree::node_count() const
{
        return node_count(root);
}

// Purpose:     Returns the node count, the number of nods without duplicates
// Parameters:  node itself
int BinarySearchTree::node_count(Node *node) const
{

        if (node == nullptr) {
                return 0;
        } 

        //recursive call to left child and right child and
        // add the result of these with 1 ( 1 for counting the root)
        return 1 + node_count(node->left) + node_count(node->right);

}

// return the sum of all the node values (including duplicates)
int BinarySearchTree::count_total() const
{
        return count_total(root);
}

// Purpose:     Returns the total sum of all values in the tree including 
//              duplicates.s
// Parameters:  node itself
int BinarySearchTree::count_total(Node *node) const
{

        if (node == nullptr) {
                return 0;
        } 
        int add = node->count * node->data;
        
        //recursive call to left child and right child and
        // add the result of these with add(the value of the node times how
        // many times it exists)
        return add + count_total(node->left) + count_total(node->right);

}

BinarySearchTree::Node *BinarySearchTree::find_parent(Node *node,
                                                      Node *child) const
{
        if (node == nullptr)
                return nullptr;

        // if either the left or right is equal to the child,
        // we have found the parent
        if (node->left == child or node->right == child) {
                return node;
        }

        // Use the binary search tree invariant to walk the tree
        if (child->data > node->data) {
                return find_parent(node->right, child);
        } else {
                return find_parent(node->left, child);
        }
}

// use the printPretty helper to make the tree look nice
void BinarySearchTree::print_tree() const
{
        size_t      numLayers  = tree_height() + 1;
        size_t      levelWidth = 4;
        const char *rootPrefix = "-> ";

        // Need numLayers * levelWidth characters for each layer of tree.
        // Add an extra levelWidth characters at front to avoid if statement
        // 1 extra char for nul character at end
        char *start = new char[(numLayers + 1) * levelWidth + 1];

        print_tree(root, start + levelWidth, start + levelWidth, rootPrefix);
        delete[] start;
}

// Logic and Output Reference: 
// https://www.techiedelight.com/c-program-print-binary-tree/
void BinarySearchTree::print_tree(Node *node, char *const currPos,
                                  const char *const fullLine,
                                  const char *const branch) const
{
        if (node == nullptr)
                return;

        // 4 characters + 1 for nul terminator
        using TreeLevel                    = char[5];
        static const int       levelLength = sizeof(TreeLevel) - 1;
        static const TreeLevel UP = ".-- ", DOWN = "`-- ", EMPTY = "    ",
                               CONNECT = "   |";
        // Copies prev into dest and advances dest by strlen(prev)
        auto set = [](char *dest, const char *prev) {
                size_t p = strlen(prev);
                return (char *)memcpy(dest, prev, p) + p;
        };

        print_tree(node->right, set(currPos, EMPTY), fullLine, UP);

        // Clear any characters that would immediate precede the "branch"
        // Don't need to check for root (i.e start of array),fullLine is padded
        set(currPos - levelLength, EMPTY);

        // Terminate fullLine at current level
        *currPos = '\0';

        std::cerr << fullLine << branch << node->data
                  << (node->count > 1 ? "*" : "") << endl;

        // Connect upper branch to parent
        if (branch == UP)
                set(currPos - levelLength, CONNECT);

        // Connect lower branch to parent
        print_tree(node->left, set(currPos, CONNECT), fullLine, DOWN);
}
