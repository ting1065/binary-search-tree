// ==================================================
// Binary Search Tree ( BST )
// ==================================================
#ifndef MYBST_H
#define MYBST_H

// define a data struct for each node
typedef struct Treenode{
    int data;               // data each node holds
    struct Treenode* leftChild; // pointer to left child (if any)
    struct Treenode* rightChild;// pointer to right child (if any)
} treenode_t;

// define a data struct for the tree
typedef struct tree{
    unsigned int size;  // Size keeps track of how many items are in the BST.
    treenode_t* source;    // root node
} tree_t;

// Function declarations.
tree_t* bst_create();
int bst_empty(tree_t* t);
int bst_add(tree_t* t, int item);
void bst_print(tree_t* t, int order);
int bst_sum(tree_t *t);
int bst_find(tree_t * t, int value);
unsigned int bst_size(tree_t* t);
void bst_free(tree_t* t);

#endif
