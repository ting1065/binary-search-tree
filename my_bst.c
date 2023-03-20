// VFS23S
// Include our header file for our my_bst.c
//
#include "my_bst.h"

#include <stdio.h>
#include <stdlib.h>

// Complete all the following functions
// Do not change the function signatures or the header file
// You may include helper functions as needed
// make sure to include your tests in bst_tests.c

// Creates a BST
// Returns a pointer to a newly created BST.
// The BST should be initialized with data on the heap.
// The BST fields should also be initialized to default values(i.e. size=0).
tree_t *bst_create() {

    tree_t* newTree = malloc(tree_t*)(sizeof(tree_t));

    if (newTree == NULL) {
        return NULL;
    }
    
    newTree->size = 0;
    newTree->source = NULL;

    return newTree;
}

// BST Empty
// Check if the BST is empty
// Returns 1 if true (The BST is completely empty)
// Returns 0 if false (the BST has at least one element)
int bst_empty(tree_t *t) {

    if ()

    return -1;
}


// Adds a new node containing item to the BST
// The item is added in the correct position in the BST.
//  - If the data is less than or equal to the current node we traverse left
//  - otherwise we traverse right.
// The bst_function returns '1' upon success
//  - bst_add should increment the 'size' of our BST.
// Returns a -1 if the operation fails.
//      (i.e. the memory allocation for a new node failed).
// Your implementation should should run in O(log(n)) time.
//  - A recursive implementation is suggested.
int bst_add(tree_t *t, int item) {

    return 1;
}


// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// For NULL tree (i.e., when t == NULL) -- print "(NULL)".
// It should run in O(n) time.
void bst_print(tree_t *t, int order) {
 
}

// Returns the sum of all the nodes in the bst.
// exits the program for a NULL tree. 
// It should run in O(n) time.
int bst_sum(tree_t *t) {

    return -1;
}



// Returns 1 if value is found in the tree, 0 otherwise. 
// For NULL tree it exists the program. 
// It should run in O(log(n)) time.
int bst_find(tree_t *t, int value) {

}

// Returns the size of the BST
// A BST that is NULL exits the program.
// (i.e. A NULL BST cannot return the size)
unsigned int bst_size(tree_t *t) {

}


// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the program terminates.
void bst_free(tree_t *t) {

}
