#include <iostream>
#include "BinarySearchTree.cpp"

int main(){
BinarySearchTree new_tree;

    new_tree.insert(35);
    new_tree.insert(17);
    new_tree.insert(12);
    new_tree.insert(28);
    new_tree.insert(57);
    new_tree.insert(40);
    new_tree.insert(30);
    new_tree.insert(1);
    new_tree.insert(6);


    
    new_tree.print_tree();
    new_tree.remove(17);
    new_tree.print_tree();
 return 0;
}



