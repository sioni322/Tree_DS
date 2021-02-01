//tree.h: Include Tree class definition
//Github: sioni322, Email: sioni322@naver.com

#ifndef __TREE__
#define __TREE__

#include <iostream>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

class Node {
    private:
    int value;          //Current node's value
    int number;         //Current node's number

    Node* leftchild;    //Left child node's pointer
    Node* rightchild;   //Right child node's pointer

    public:
    /* "Node" instructor function: Make a new node */
    Node(int v, int n) {
        value = v;
        number = n;

        leftchild = NULL;
        rightchild = NULL;
    }

    /* "~Node" destructor function: Delete the node */
    ~Node() {
        delete leftchild;
        delete rightchild;
    }

    /* "node_value" function: Return the value of this node */
    int node_value() {
        return value;
    }

    /* "node_number" function: Return the number of this node */
    int node_number() {
        return number;
    }

    /* "node_left" function: Return the left child node's address */
    Node* node_left() {
        return leftchild;
    }

    /* "node_right" function: Return the right child node's address */
    Node* node_right() {
        return rightchild;
    }

    /* "modify_left" function: Modify the left child node's address */
    void modify_addr(Node* node, bool child) {
        if(!child) {
            leftchild = node;
        }
        else {
            rightchild = node;
        }
    }
};

//Tree class can express a binary tree only
class Tree {
    private:
    Node* root;         //Point out the root node
    int total;          //Total number of nodes in this tree

    public:
    //Constructor and destructor functions
    /* "Tree" constructor function: Make a new binary tree */
    Tree(int v);

    /*"~Tree" destructor function: Delete a binary tree */
    ~Tree();



    //Tree Parameter functions
    /* "rootnode" function: Return the address of the root node */
    Node* rootnode();

    /* "totalnode" function: Return the total number of nodes in this tree */
    int totalnode();

    /* "depth" function: Return the depth of this tree */
    int depth();



    //Basic functions
    /* "insert" function: Insert new node into the tree and return the status(0: complete, 1: failed) */
    int insert(int n, int v, bool leftright);

    /* "find" function: Find out the node which number is "n" and return its address */
    Node* find(int n);

    /* "print" function: Print out the tree */
    void print();



    //Infix, postfix, prefix search functions
    /* "infix" function: Search the tree based on the infix notation */
    void infix(Node* node, vector<int>& result);

    /* "postfix" function: Search the tree based on the postfix notation */
    void postfix(Node* node, vector<int>& result);

    /* "prefix" function: Search the tree based on the prefix notation */
    void prefix(Node* node, vector<int>& result);
};



#endif