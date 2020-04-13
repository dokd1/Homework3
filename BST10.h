#ifndef BST10_H
#define BST10_H
#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;      //Value in node
    Node* left;     //Pointer to left child node
    Node* right;    //Pointer to right child node
};
Node* root;         //Pointer to root node

template<typename T>
class binaryTree {
    int insert_checked,remove_checked,find_checked;
public:

    binaryTree();   //Constructor
    ~binaryTree();  //Destructor

    int height(Node*);
    int difference(Node*);

    Node* rotateRR(Node*);
    Node* rotateLL(Node*);
    Node* rotateLR(Node*);
    Node* rotateRL(Node*);
    Node* balance(Node*);
    Node* insert(Node*, T);
    Node* find(Node*, T);       
    T size(Node*);
    void getAllAscending(Node* t);
    void getAllDescending(Node* t);
    Node* emptyTree(Node*);
    Node* FindMin(Node*);
    Node* remove(T, Node*);       
    int get_insert_check() { return insert_checked; }
    int get_remove_check() { return remove_checked; }
    int get_find_check() { return find_checked; }




};
//-------------------------------------------------------------------------------------------------------------------------------
//Constructor
//-------------------------------------------------------------------------------------------------------------------------------
template<typename T>
binaryTree<T>::binaryTree() {
    root = NULL;
    insert_checked = remove_checked = find_checked = 0;
}

//-------------------------------------------------------------------------------------------------------------------------------
//EmptyTree
//-------------------------------------------------------------------------------------------------------------------------------
template<typename T>
Node* binaryTree<T>::emptyTree(Node* t) {
    if (t == NULL) {
        return NULL;
        emptyTree(t->left);
        emptyTree(t->right);
        delete t;
    }
    return NULL;
}

//-------------------------------------------------------------------------------------------------------------------------------
//Destructor
//-------------------------------------------------------------------------------------------------------------------------------
template<typename T>
binaryTree<T>::~binaryTree() {
    root = emptyTree(root);
}

//-------------------------------------------------------------------------------------------------------------------------------
//Calculate the height of the binary tree
//-------------------------------------------------------------------------------------------------------------------------------
template<typename T>
int binaryTree<T>::height(Node* t) {
    int heightt = 0;
    if (t != NULL) {
        int left_height = height(t->left);
        int right_height = height(t->right);
        int max_height = max(left_height, right_height);
        heightt = max_height + 1;
    }
    return heightt;
}

//-------------------------------------------------------------------------------------------------------------------------------
//Difference - calculutes the differnce between the left and right subtrees
//-------------------------------------------------------------------------------------------------------------------------------
template<typename T>
int binaryTree<T>::difference(Node* t) {
    int left_height = height(t->left);
    int right_height = height(t->right);
    int balance_factor = left_height - right_height;

    return balance_factor;
}

//-------------------------------------------------------------------------------------------------------------------------------
//Right right rotation
//-------------------------------------------------------------------------------------------------------------------------------
template<typename T>
Node* binaryTree<T>::rotateRR(Node* parent) {
    Node* t;
    t = parent->right;
    parent->right = t->left;
    t->left = parent;
    return t;

}
//-------------------------------------------------------------------------------------------------------------------------------
//Left left rotation
//-------------------------------------------------------------------------------------------------------------------------------
template<typename T>
Node* binaryTree<T>::rotateLL(Node* parent) {
    Node* t;
    t = parent->left;
    parent->left = t->right;
    t->right = parent;

    return t;
}
//-------------------------------------------------------------------------------------------------------------------------------
//Left Right Rotation
//-------------------------------------------------------------------------------------------------------------------------------
template<typename T>
Node* binaryTree<T>::rotateLR(Node* parent) {
    Node* t;
    t = parent->left;
    parent->left = rotateRR(t);
    return rotateLL(parent);
}

//-------------------------------------------------------------------------------------------------------------------------------
//Right Left Rotation
//-------------------------------------------------------------------------------------------------------------------------------
template<typename T>
Node* binaryTree<T>::rotateRL(Node* parent) {
    Node* t;
    t = parent->right;
    parent->right = rotateLL(t);
    return rotateRR(parent);

}
//-------------------------------------------------------------------------------------------------------------------------------
//Balance
//-------------------------------------------------------------------------------------------------------------------------------
template<typename T>
Node* binaryTree<T>::balance(Node* t) {
    int bal_factor = difference(t);
    if (bal_factor > 1) {
        if (difference(t->left) > 0) {
            t = rotateLL(t);
        }
        else {
            t = rotateLR(t);
        }
    }
    else if (bal_factor < -1) {
        if (difference(t->right) > 0) {
            t = rotateRL(t);
        }
        else {
            t = rotateRR(t);
        }
    }
    return t;
}


//-------------------------------------------------------------------------------------------------------------------------------
//Insert - accepts a value, creates a node and inserts the node into the tree in the appropriate location.
//This should rebalance the tree as necessary, so the tree remains balanced at all times.  If the value already exists in the tree, this should throw an error.
//-------------------------------------------------------------------------------------------------------------------------------
template<typename T>
Node* binaryTree<T>::insert(Node* r, T v) {
    if (r == NULL) {
        r = new Node;
        r->data = v;
        r->left = NULL;
        r->right = NULL;
        return r;
    }
    else if (v < r->data) {
        insert_checked++;
        r->left = insert(r->left, v);
        r = balance(r);
    }
    else if (v > r->data) {
        insert_checked++;
        r->right = insert(r->right, v);
        r = balance(r);
    }
    return r;


}

//-------------------------------------------------------------------------------------------------------------------------------
//Find - accepts a value, locates the value in the tree and returns a pointer to the node.
//If the value isn’t in the tree, it will return a null pointer.
//-------------------------------------------------------------------------------------------------------------------------------
template<typename T>
Node* binaryTree<T>::find(Node* t, T v) {
    if (t == NULL) {
        cout << "VALUE NOT FOUND" << endl;
        return NULL;
    }
    else if (v < t->data) {
        find_checked++;
        return find(t->left, v);

    }
    else if (v > t->data) {
        find_checked++;
        return find(t->right, v);
    }
    else {
        return t;
    }

}

//-------------------------------------------------------------------------------------------------------------------------------
//Size - returns the number of elements in the tree as an integer.
//-------------------------------------------------------------------------------------------------------------------------------
template<typename T>
T binaryTree<T>::size(Node* t) {
    if (t == NULL) {
        return 0;
    }
    else {
        return size(t->left) + size(t->right) + 1;
    }

}

//-------------------------------------------------------------------------------------------------------------------------------
//GetAllAscending - returns an array with each node stored in order from smallest to largest (based on the sorting value, not the other data in the node).
//-------------------------------------------------------------------------------------------------------------------------------
template <typename T>
void binaryTree<T>::getAllAscending(Node* t) {
    if (t == NULL)
        return;
    cout << t->data << " ";
    getAllAscending(t->left);
    getAllAscending(t->right);
}

//-------------------------------------------------------------------------------------------------------------------------------
//GetAllDescending -  returns an array with each node stored in order from largest to smallest (based on the sorting value, not the other data in the node).
//-------------------------------------------------------------------------------------------------------------------------------
template <typename T>
void binaryTree<T>::getAllDescending(Node* t) {
    if (t == NULL)
        return;
    getAllDescending(t->left);
    getAllDescending(t->right);
    cout << t->data << " ";

}

//-------------------------------------------------------------------------------------------------------------------------------
//Find Min
//-------------------------------------------------------------------------------------------------------------------------------
template <typename T>
Node* binaryTree<T>::FindMin(Node* t) {
    if (t == NULL) {
        return NULL;
    }
    Node* temp = t;
    while (temp->left != NULL) {
        temp = temp->left;
    }
    return temp;
}
//-------------------------------------------------------------------------------------------------------------------------------
//Remove - accepts a value, finds the value and removes it from the tree.  A pointer to the removed node is returned.
//This should rebalance the tree as necessary, so the tree remains balanced at all times.
//-------------------------------------------------------------------------------------------------------------------------------
template <typename T>
Node* binaryTree<T>::remove(T v, Node* t) {       //NEEDS TO BE WORKED ON
    if (t == NULL) {
        return NULL;
    }
    if (v < t->data) {
        remove_checked++;
        t->left = remove(v, t->left);
    }
    else if (v > t->data) {
        remove_checked++;
        t->right = remove(v, t->right);
    }
    else {
        if (t->left == NULL && t->right == NULL) {
            delete(t);
            t = NULL;
        }
        else if (t->left == NULL) {
            Node* temp = t;
            t = t->right;
            delete temp;
        }
        else if (t->right == NULL) {
            Node* temp = t;
            t = t->left;
            delete temp;
        }
        else {
            Node* temp = FindMin(t->right);
            t->data = temp->data;
            t->right = remove(temp->data, t->right);
        }
    }
    return t;

}
#endif // BST10_H
