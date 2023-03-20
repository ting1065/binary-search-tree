// You must submit this test file with your code implementation. 
// include all tests that you used to test your binary search tree implementation
// Compile this assignment with: gcc -Wall -g bst_tests.c -o tests
// This is a great assignment to practice debugging.
// Run with: gdb ./tests --tui
// Then type 'start'
// Then type 'next' or 'n' and enter
// See the GDB debugging video for more information

#include <stdio.h>  
#include <stdlib.h> 

#include "my_bst.h"

// Write more tests here to test your implementation. 
// We will use our own test suite (i.e. replacing this file)
// in order to test your implementation from my_bst.

// Testing allocation
int unitTest1(){
    int result;
    tree_t * testBST = bst_create();
    if (testBST!=NULL){
        result = 1;
    }else{
        result = 0;
    }
    bst_free(testBST);
    return result;    
}

// Add and find a node
int unitTest2(){
    int result;
    tree_t * testBST = bst_create();
    bst_add(testBST,78);
    result = bst_find(testBST,78);
    bst_free(testBST);    
    return result;
}

// Sums the nodes in a BST
int unitTest3(){
    int result;
    tree_t * testBST = bst_create();
    bst_add(testBST, 5);
    result = bst_sum(testBST);
    bst_free(testBST);   

    if(result==5){ 
        return 1;
    }
    return 0;
}

//Fill a Binary Search Tree with values 1-100 and searching for nodes.
int unitTest4() {

    tree_t* testBST = bst_create();

    int i;
    for (i=1; i<101; i++) {
        bst_add(testBST, i);
    }

    int result1 = bst_find(testBST, -5);
    int result2 = bst_find(testBST, 1);
    int result3 = bst_find(testBST, 25);
    int result4 = bst_find(testBST, 75);
    int result5 = bst_find(testBST, 100);
    int result6 = bst_find(testBST, 105);
    bst_free(testBST);

    if (result1 == 0 &&
        result2 == 1 &&
        result3 == 1 &&
        result4 == 1 &&
        result5 == 1 &&
        result6 == 0) {
        return 1;
    }
    return 0;   
}

//Add 100 nodes and then check that the size is 100.
int unitTest5() {
    
    tree_t* testBST = bst_create();

    int i;
    for (i=50; i<150; i++) {
        bst_add(testBST, i);
    } 

    int result = (bst_size(testBST) == 100);
    bst_free(testBST);

    if (result) {
        return 1;
    }

    return 0;
}

//Add 100 nodes with the value of '2' and check that the sum is 200.
int unitTest6() {

    tree_t* testBST = bst_create();

    int i;
    for (i=1; i<101; i++) {
        bst_add(testBST, 2);
    }

    int result1 = (bst_sum(testBST)==200);
    int result2 = (testBST->source->leftChild==NULL);
    bst_free(testBST);

    if (result1 && result2) {
        return 1;
    }

    return 0;
}

//add nodes that create a highly unbalanced tree (basically a linked list) and make sure the sum is correct, print works, tree is the correct shape
int unitTest7() {

    tree_t* testBST = bst_create();

    int i;
    for (i=10; i>=0; i-=2) {
        bst_add(testBST, i);
    }
    
    printf("ascending expected:\n");
    bst_print(testBST, 0);
    printf("descending expected:\n");
    bst_print(testBST, 1);

    int result1 = (bst_sum(testBST)==30);
    int result2 = (testBST->source->rightChild==NULL);
    bst_free(testBST);

    if (result1 && result2) {
        return 1;
    }

    return 0;
}

//Add nodes that create a "V"-shaped tree
//and make sure all functions still work. 
int unitTest8() {

    tree_t* testBST = bst_create();

    int i;
    for (i=5; i<10; i++) {
        bst_add(testBST, i);
    }
    for (i=4; i>0; i--) {
        bst_add(testBST, i);
    }

    printf("asending expected:\n");
    bst_print(testBST, 0);
    printf("descending expected:\n");
    bst_print(testBST, 1);

    int result1 = (bst_empty(testBST)==0);
    int result2 = (bst_sum(testBST)==45);
    int result3 = (bst_find(testBST, 0)==0);
    int result4 = (bst_find(testBST, 3)==1);
    int result5 = (bst_find(testBST, 7)==1);
    int result6 = (bst_find(testBST, 10)==0);
    int result7 = (bst_size(testBST) == 9);
    int result8 = (testBST->source->leftChild->rightChild==NULL);
    int result9 = (testBST->source->rightChild->leftChild==NULL);
    bst_free(testBST);

    if (result1 && result2 && result3 && result4 && result5 &&
        result6 && result7 && result8 && result9) {
        return 1;
    }

    return 0;  
}

//Test all NULLs, empty trees.
int unitTest9() {

    tree_t* nullTree = NULL;
    int result1 = (bst_add(nullTree, 8) == -1);
    printf("two NULL expected:\n");
    bst_print(nullTree, 0);
    bst_print(nullTree, 1);    
    int result2 = (bst_sum(nullTree)==-1);
    
    tree_t* emptyTree = bst_create();
    int result3 = (bst_empty(emptyTree)==1);
    printf("two NULL expected:\n");
    bst_print(emptyTree, 0);
    bst_print(emptyTree, 1);
    int result4 = (bst_sum(emptyTree)==0);
    int result5 = (bst_find(emptyTree, 1)==0);
    int result6 = (bst_size(emptyTree)==0);
    bst_free(emptyTree);

    if (result1 && result2 && result3 &&
        result4 && result5 && result6) {
        return 1;
    }
    return 0;

}

// TODO: Add more tests here at your discretion
int (*unitTests[])(int) = {
    unitTest1,
    unitTest2,
    unitTest3,
    unitTest4,
    unitTest5,
    unitTest6,
    unitTest7,
    unitTest8,
    unitTest9,
    NULL
};

// ====================================================
// ================== Program Entry ===================
// ====================================================
int main(){
	
	unsigned int testsPassed = 0;
    // List of Unit Tests to test your data structure
    int counter =0;
    while(unitTests[counter] != NULL){
		printf("========unitTest %d========\n",counter);
		if(1==unitTests[counter](1)){
			printf("passed test\n");
			testsPassed++;	
		}else{
			printf("failed test, missing functionality, or incorrect test\n");
		}
        counter++;
    }

    printf("%d of %d tests passed\n",testsPassed,counter);

    return 0;
}
