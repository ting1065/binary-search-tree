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

    if (t == NULL) {
        return -1;
    }

    if (t->size > 0) {
        return 0;
    } else if (t->size == 0) {
        return 1;
    } else {
        return -1;
    }

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
    
    if (t == NULL) {
        return -1;
    }

    treenode_t* newNode = (treenode_t*)malloc(sizeof(treenode_t));
    if (newNode == NULL) {
        return -1;
    }
    newNode->data = item;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    if (bs_empty(t)) {
        t->source = newNode;
    } else {
        add_helper(newNode, t->source);
    }

    t->size++;
    return 1;
}

//a helper function that adds a new node(the first parameter) to 
//a tree that has the second parameter as its root node. 
void add_helper(treenode_t* newNode, treenode_t* oldNode) {

    if (newNode->data >= oldNode->data &&
        (oldNode->rightChild == NULL || oldNode->rightChild->data >= newNode->data)) {
        newNode->rightChild = oldNode->rightChild;       
        oldNode->rightChild = newNode;
        return;
    }
    else if (newNode->data < oldNode->data &&
             (oldNode->leftChild == NULL || oldNode->leftChild->data < newNode->data)) {
        newNode->leftChild = oldNode->leftChild;
        oldNode->leftChild = newNode;
        return;
    }

    if (newNode->data >= oldNode->data) {
        add_helper(newNode, oldNode->rightChild);
    } else {
        add_helper(newNode, oldNode->leftChild);
    }

}

// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
// For NULL tree (i.e., when t == NULL) -- print "(NULL)".
// It should run in O(n) time.
void bst_print(tree_t *t, int order) {

    if (t == NULL || t->source == NULL) {
        printf("(NULL)");
    } 
    
    int dataAscendingArray[t->size];
    int startIndex = 0;

    append_ascending_helper(t->source, dataAscendingArray, &startIndex);
    
    int i;
    if (order == 0) {
        for (i = 0; i < t->size; i++) {
            printf("%d\n", dataAscendingArray[i]);
        }
    } else {
        for (i = t->size - 1; i >= 0; i--) {
            printf("%d\n", dataAscendingArray[i]);
        }
    }
}


//a helper function to append all the data into an array in ascending order using dfs.
void append_ascending_helper(treenode_t* rootNode,
                             int* dataAscendingArray,
                             int* startIndex) {

    if (rootNode == NULL) {
        return;
    }

    append_ascending_helper(rootNode->leftChild, dataAscendingArray, startIndex);
    dataAscendingArray[*startIndex] = rootNode->data;
    *startIndex++;
    append_ascending_helper(rootNode->rightChild, dataAscendingArray, startIndex);
    
}

// Returns the sum of all the nodes in the bst.
// exits the program for a NULL tree. 
// It should run in O(n) time.
int bst_sum(tree_t *t) {

    if (t == NULL) {
        return -1;
    }

    if (t->source == NULL) {
        return 0;
    }

    int dataAscendingArray[t->size];
    int startIndex = 0;
    append_ascending_helper(t->source, dataAscendingArray, &startIndex);

    int i;
    int sum = 0;
    for (i = 0; i < t->size; i++) {
        sum += dataAscendingArray[i];
    }
      
    return sum;
}



// Returns 1 if value is found in the tree, 0 otherwise. 
// For NULL tree it exists the program. 
// It should run in O(log(n)) time.
int bst_find(tree_t *t, int value) {

    if (t == NULL) {
        exit(1);
    }

    return bst_find_helper(t->source, value);
    
}

//helper function for seaching node by node using binary search.
int bst_find_helper(tree_node_t* start, int target) {

    if (start == NULL) {
        return 0;
    } else if (start->data == target){
        return 1
    } else if (start->data > target) {
        return bst_find_helper(start->leftChild);
    } else {
        return bst_find_helper(start->rightChild);
    }
    
}

// Returns the size of the BST
// A BST that is NULL exits the program.
// (i.e. A NULL BST cannot return the size)
unsigned int bst_size(tree_t *t) {

    if (t == NULL) {
        exit(1);
    } else if (t->size >= 0) {
        return t->size;
    } else {
        exit(1);
    }
}


// Free BST
// Removes a BST and ALL of its elements from memory.
// This should be called before the program terminates.
void bst_free(tree_t *t) {

}

//a helper function to free nodes using dfs.
void node_free_helper(treennode_t* t) {
    
    if (t == NULL) {
        return;
    }

    if (t->leftChild == NULL && t->right == NULL) {
        free(t);
        return;
    }

    if (t->leftChild != NULL) {
        node_free_helper(t->leftChild);
    }

    if (t->rightChild != NULL) {
        node_free_helper(t->rightChild);
    }

    free(t);

}
