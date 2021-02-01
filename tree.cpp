//tree.cpp: Define member functions of Tree ADT
//Github: sioni322, Email: sioni322@naver.com

#include "tree.h"

using namespace std;

/* "Tree" constructor function: Make a new binary tree */
Tree::Tree(int v) {
    Node* newnode = new Node(v, 1);

    root = newnode;
    total = 1;
}

/*"~Tree" destructor function: Delete a binary tree */
Tree::~Tree() {
    delete root;
}



/* "rootnode" function: Return the address of the root node */
Node* Tree::rootnode() {
    return root;
}

/* "totalnode" function: Return the total number of nodes in this tree */
int Tree::totalnode() {
    return total;
}

/* "depth" function: Return the depth of this tree */
int Tree::depth() {
    return ceil(log2(total));
}



/* "insert" function: Insert new node into the tree and return the status(0: complete, 1: failed) */
int Tree::insert(int n, int v, bool leftright) {
    Node* child = new Node(v, ++total);
    Node* parent = find(n);

    if(child == NULL || parent == NULL)
        return 1;

    if(parent->node_left() != NULL && parent->node_right() != NULL)
        return 1;
    
    parent->modify_addr(child, leftright);

    return 0;
}

/* "find" function: Find out the node which number is "n" and return its address */
Node* Tree::find(int n) {
    if(n > total || n < 0)
        return NULL;

    Node* node = root;
    queue<Node*> queue;
    int count = 1;

    while(count < total) {
        if(node->node_number() == n) {
            return node;
        }
        else {
            queue.push(node->node_left());
            queue.push(node->node_right());

            node = queue.front();
            queue.pop();

            count += 1;
        }
    }

    return NULL;
}

/* "print" function: Print out the tree */
void Tree::print() {
    Node* node = root;
    queue<Node*> queue;
    int count = 0;

    while(count < total) {
        std::cout << node->node_number() << "# node's value: " << node->node_value() << "\t(";
        if(node->node_left() != NULL)
            std::cout << "left #: " << node->node_left()->node_number() << ", ";
        if(node->node_right() != NULL)
            std::cout << "right #: " << node->node_right()->node_number();
        std::cout << ")\n";


        if(node->node_left() != NULL)
            queue.push(node->node_left());

        if(node->node_right() != NULL)
        queue.push(node->node_right());

        node = queue.front();
        queue.pop();

        count += 1;
    }

    return;
}



/* "infix" function: Search the tree based on the infix notation */
void Tree::infix(Node* node, vector<int>& result) {
    if(node == NULL)
        return;

    infix(node->node_left(), result);
    result.push_back(node->node_value());
    infix(node->node_right(), result);

    return;
}

/* "postfix" function: Search the tree based on the postfix notation */
void Tree::postfix(Node* node, vector<int>& result) {
    if(node == NULL)
        return;

    postfix(node->node_left(), result);
    postfix(node->node_right(), result);
    result.push_back(node->node_value());

    return;
}

/* "prefix" function: Search the tree based on the prefix notation */
void Tree::prefix(Node* node, vector<int>& result) {
    if(node == NULL)
        return;

    result.push_back(node->node_value());
    prefix(node->node_left(), result);
    prefix(node->node_right(), result);

    return;
}