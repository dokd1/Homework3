#include "BST10.h"
#include "LinearHashTable.h"
#include <iostream>
#include <stdlib.h>
#include <random>
#include <time.h>
using namespace std;



int main() {   
    srand(time(NULL));
    // Binary tree instance
    binaryTree<int> tree;
    // Hash table instance
    HashTable table;

    int Arrsize = 100;
    int ran_num;
    int num_holder[100] = {0};
    
    // input the random number on the array
    for (int i = 0; i < Arrsize; i++)
    {
        ran_num = rand() % 150 + 1;

        if ( i == 0)
        {
            num_holder[i] = ran_num;
        }
        else
        {
            bool double_checker = false;
            for (int k = 0; k < i; k++)
            {
                if (ran_num == num_holder[k])
                {
                    double_checker = true;
                    ran_num = rand() % 1000 + 1;
                }
            }

            if (!double_checker)
            {
                num_holder[i] = ran_num;
            }
            else
            {

            }
        }
    }

   
    return 0;
}
