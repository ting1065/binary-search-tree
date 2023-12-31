#include "my_bst.h"
#include <stdio.h>
#include <stdlib.h>

// Creates a BST
// Returns a pointer to a newly created BST.
tree_t *bst_create() {

    tree_t* newTree = (tree_t*)malloc(sizeof(tree_t));

    if (newTree == NULL) {
        return NULL;
    }
    
    newTree->size = 0;
    newTree->source = NULL;

    return newTree;
}


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


//a helper function that adds a new node(the first parameter) to 
//a tree that has the second parameter as its root node. 
void add_helper(treenode_t* newNode, treenode_t* oldNode) {

    if (newNode->data >= oldNode->data &&
        oldNode->rightChild == NULL) {
        newNode->rightChild = oldNode->rightChild;       
        oldNode->rightChild = newNode;
        return;
    }
    else if (newNode->data < oldNode->data &&
             oldNode->leftChild == NULL) {
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

// Adds a new node containing item to the BST
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

    if (bst_empty(t)) {
        t->source = newNode;
    } else {
        add_helper(newNode, t->source);
    }

    t->size++;
    return 1;
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
    *startIndex += 1;
    append_ascending_helper(rootNode->rightChild, dataAscendingArray, startIndex);
    
}

// Prints the tree in ascending order if order = 0, otherwise prints in descending order.
void bst_print(tree_t *t, int order) {

    if (t == NULL || t->source == NULL) {
        printf("(NULL)\n");
        return;
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


// Returns the sum of all the nodes in the bst.
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


//helper function for seaching node by node using binary search.
int bst_find_helper(treenode_t* start, int target) {

    if (start == NULL) {
        return 0;
    } else if (start->data == target){
        return 1;
    } else if (start->data > target) {
        return bst_find_helper(start->leftChild, target);
    } else {
        return bst_find_helper(start->rightChild, target);
    }
    
}

// Searches the BST for a value
// Returns 1 if value is found in the tree, 0 otherwise. 
int bst_find(tree_t *t, int value) {

    if (t == NULL) {
        exit(1);
    }

    return bst_find_helper(t->source, value);
    
}


// Returns the size of the BST
unsigned int bst_size(tree_t *t) {

    if (t == NULL) {
        exit(1);
    } else if (t->size >= 0) {
        return t->size;
    } else {
        exit(1);
    }
}


//a helper function to free nodes using dfs.
void node_free_helper(treenode_t* n) {
    
    if (n == NULL) {
        return;
    }

    if (n->leftChild == NULL && n->rightChild == NULL) {
        free(n);
        return;
    }

    if (n->leftChild != NULL) {
        node_free_helper(n->leftChild);
    }

    if (n->rightChild != NULL) {
        node_free_helper(n->rightChild);
    }

    free(n);
}

// Free BST
// Removes a BST and ALL of its elements from memory.
void bst_free(tree_t *t) {

    if (t == NULL) {
        return;
    }

    node_free_helper(t->source);
    free(t);

}
