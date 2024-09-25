/* 
 * unit_tests.h
 * 
 * CS 15 homework 3
 * by Asli Kocak 
 * This file is used to test the binary search tree data structure 
 * It contains various tests and attempts to test edge cases
 *
 * NOTE: I use bst as a shorthant for binary search tree
 * 
 */


#include <cassert>
#include "BinarySearchTree.h"
#include <iostream>
#include <cstring>


using namespace std;

// Function:    Test Function for default constructor
// Parameters:  none
void bst_constructor () {
    //creates a new tree to ensure there are no memory leaks
    BinarySearchTree new_tree;
        new_tree.print_tree();

}


// // Function:    Test Function for insert function for bst
// // Parameters:  none
// void bst_insert () {
//     //create a new tree, and insert various values, and multiples of some. 
//     //check if values are printing correctly, and the * is showing up for 
//     //duplicates
//     BinarySearchTree new_tree;
//     new_tree.insert(4);
//     new_tree.insert(5);
//     new_tree.insert(2);
//     new_tree.insert(6);
//     new_tree.insert(6);
//     new_tree.insert(6);
//     new_tree.insert(6);
//     new_tree.print_tree();

// }




// // Function:    Test Function for height function for bst
// // Parameters:  none
// void bst_height () {

//     //test if a new empty tree height is -1
//     BinarySearchTree new_tree;
//     assert(new_tree.tree_height()== -1);

//     //test if only the root has height 1
//     new_tree.insert(4);
//     assert(new_tree.tree_height()== 0);

//     //add random values to the tree, and check if the height is adding up
//     new_tree.insert(5);
//     new_tree.insert(6);
//     new_tree.insert(6);
//     new_tree.insert(6);

//     assert(new_tree.tree_height()==2);
    

// }


// // Function:    Test Function for minimum function for bst
// // Parameters:  none
// void bst_min () {
//     BinarySearchTree new_tree;

//     //add random values to the tree
//     new_tree.insert(14);
//     new_tree.insert(-9);
//     new_tree.insert(0);
//     new_tree.insert(99);

//     //print tree, and check if the smallest value is on the left side, and
//     //if minimum value is -9
//     new_tree.print_tree();
//     assert(new_tree.find_min() == -9);
    
// }



// // Function:    Test Function for max function for bst
// // Parameters:  none
// void bst_max () {
//     BinarySearchTree new_tree;
    
//     //add random values to the tree
//     new_tree.insert(14);
//     new_tree.insert(-9);
//     new_tree.insert(0);
//     new_tree.insert(99);


//     //print tree, and check if the largest value is on the right side, and
//     //if maximum value is 99
//     new_tree.print_tree();
//     assert(new_tree.find_max() == 99);
    
// }

// // Function:    Test Function contains function for bst, that checks if a 
// //              value is in the tree
// // Parameters:  none
// void bst_contains () {
//     BinarySearchTree new_tree;
//     //check if an empty tree contains a random data (this should return false
//     //as it doesn't)
//     assert(new_tree.contains(5) == false);


//     //check if the root contains a the inserted value
//     new_tree.insert(14);
//     assert(new_tree.contains(14) == true);
//     new_tree.insert(-9);
//     new_tree.insert(0);
//     new_tree.insert(99);
//     //check if the tree contains a the inserted value, and the function 
//     //works for the branches
//     assert(new_tree.contains(13) == false);


//     //print tree to ensure that the insertions and the assertions were true
//     new_tree.print_tree();

    
// }


// // Function:    Test Function contains function for remove, that checks if a 
// //              value is removed from the tree
// // Parameters:  none
// void bst_remove () {
//     BinarySearchTree new_tree;
//     //insert random values to the tree
//     new_tree.insert(35);
//     new_tree.insert(17);
//     new_tree.insert(15);
//     new_tree.insert(12);
//     new_tree.insert(28);
//     new_tree.insert(57);
//     new_tree.insert(40);
//     new_tree.insert(30);
    
//     new_tree.insert(6);
//     new_tree.insert(12);


//     //for practicality, in this function, I printed before and after trees for
//     //removal. To not break the tree structure, I just changed the value in
//     //the remove function with values in the leaves, values with single and 
//     //2 children, and checked each part individually. I  tried removing 
//     //every number above (35,17,15...) and checked if remove worked
//     new_tree.print_tree();
//     new_tree.remove(17);
//     new_tree.print_tree();
// }



// // Function:    Test Function contains function for count, that counts if a 
// //              the number of nodes without duplicates
// // Parameters:  none
// void bst_count () {

//     BinarySearchTree new_tree;
//     //add numbers into the tree using for loop, so that I know exactly 
//     //how many I'm adding
//     for (int i = 0; i < 10; i++) {
//         new_tree.insert(i);
//     }

//     //check if the count is right
//     assert(new_tree.node_count() == 10);

//     new_tree.insert(2);
//     //check if count stays correct after adding a duplicate
//     assert(new_tree.node_count() == 10);
// }


// // Function:    Test Function contains function for total count, that adds
// //              all of the numbers in the tree, including duplicates
// // Parameters:  none
// void bst_count_total () {
//     BinarySearchTree new_tree;
//     //check if the total is 0 for an empty tree
//     assert(new_tree.count_total() == 0);

//     //add numbers into the tree using for loop, so that I know exactly 
//     //how many I'm adding
//     for (int i = 0; i < 10; i++) {
//         new_tree.insert(i);
//         new_tree.insert(i);

//     }
//     //check if the total is right
//     assert(new_tree.count_total() == 90);

//     //check if the total is right after inserting a duplicate
//     new_tree.insert(2);
//     assert(new_tree.count_total() == 92);
// }