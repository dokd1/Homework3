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
    int total_table = 0;
    int total_remove = 0;
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
                num_holder[i] = ran_num;
            }
        }
    }

    for (int i = 0; i < 50; i++)
    {
        root = tree.insert(root, num_holder[i]);
       total_table = total_table + table.insert(num_holder[i]);
    }

    cout << "----------------------List of the numbers---------------------------------------------------" << endl;
    cout << " List of the numbers" << endl;
    for (int i = 0; i < 50; i++)
    {
        cout << i + 1 << "." << num_holder[i] << " " ;
    }
    cout << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;

    cout << "----------------------Items on the tree-------------------------------------------------------" << endl;
    tree.getAllAscending(root);
    cout << endl;
    cout << "The size of the tree is " << tree.size(root) << endl;
    cout << "The total number of check tree performed is " << tree.get_insert_check() << endl;

    cout << "-----------------------------------------------------------------------------------------------" << endl;

    cout << "----------------------Items on the Table-------------------------------------------------------" << endl;
    table.print();
    cout << "The total check table performed while inserting is " << total_table << endl;
    cout << "-----------------------------------------------------------------------------------------------" << endl;

    cout << "----------------------Performing deletion------------------------------------------------------" << endl;
    for (int i = 0; i < 50; i++)
    {
        root = tree.remove(num_holder[i], root);
        total_remove = total_remove + table.remove(num_holder[i]);
    }

    cout << "The total number check for remove function for the tree is " << tree.get_remove_check() << endl;
    cout << "The total number check for the remove function for the table is " << total_remove << endl;

    cout << "----------------------Performing deletion------------------------------------------------------" << endl;
    cout << "----------------------Tree print start---------------------------------------------------------" << endl;
    tree.getAllAscending(root);
    cout << "----------------------Tree print finish------------------------------------------------------" << endl;
    cout << "----------------------Table print start------------------------------------------------------" << endl;
    table.print();
    cout << "----------------------Table print finish------------------------------------------------------" << endl;
    int find_table = 0;

    for (int i = 50; i < Arrsize; i++)
    {
        root = tree.insert(root, num_holder[i]);
        total_table = total_table + table.insert(num_holder[i]);
    }
    cout << "The 2nd total check table performed while inserting is " << total_table << endl;
    cout << "The 2nd total number of check tree performed is " << tree.get_insert_check() << endl;
    for (int i = 50; i < Arrsize; i++)
    {
        find_table = find_table + table.find(num_holder[i]);
        tree.find(root, num_holder[i]);
    }

    cout << "The total number of spot it checked for find function for the tree is " << tree.get_find_check() << endl;
    cout << "The total number of spot it checked for find function for the table is " << find_table << endl;
    return 0;
}
