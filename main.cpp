#include "BST10.h"
#include <iostream>

// Test driver
#include <stdlib.h>
#include <random>
#include <time.h>

using namespace std;
 
int main() {
    // Binary tree instance
    binaryTree<int> tree;
    cout << "----------------------------------------------" << endl;
    cout << "NO DUPLICATE DATA ARE INSERTED INTO THE TREE" << endl;
    cout << "IF YOU TRY TO INSERT DUPLICATE DATA, THEY ARE" << endl;
    cout << "SIMPLY IGNORED AND NOT ADDED INTO THE TREE." << endl;
    cout << "----------------------------------------------" << endl;
    cout << endl;
    
    // --------------------------------------------------------------- TESING THE TREE BEGINS -----------------------------------------------------------------------------------------------
    int ran_num;
    srand(time(NULL));
    for (int i = 0; i < 200; i++)
    {
        ran_num = rand() % 100;
        root = tree.insert(root,ran_num);
    }

    tree.getAllAscending(root);
    cout << endl;
   cout << "The size of the tree is " << tree.size(root) << endl;

   //----------------------------------------------------------------- TEST ENDS -------------------------------------------------------------------------------------------------------
    return 0;
}
