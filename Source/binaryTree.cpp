#include "../Headers/binaryTree.h"

Node::Node()
    : key(NULL), left(NULL), right(NULL) {
        // std::cout << "Node successfully created" << std::endl;
}
    
Node::Node(int value)
    : key(value), left(NULL), right(NULL) {
        // std::cout << "Node with value: " << value << " successfully created" << std::endl;
}
    
Node::~Node() {
    // std::cout << "Node successfully deleted" << std::endl;
}

// TODO
Node* BinarySearchTree::insertElement(int value) { return NULL; } 
Node** BinarySearchTree::searchElementWithValue(int value) { return NULL; }
Node* BinarySearchTree::deleteElementWithValue(int value) { return NULL; }
Node** BinarySearchTree::getMaximum(Node*) { return NULL; }
//

BinarySearchTree::BinarySearchTree()
    : size(0), root(NULL) {
        // std::cout << "Linked list successfully initialized" << std::endl;
}
    
BinarySearchTree::~BinarySearchTree() {
    // std::cout << "Linked list successfully deleted" << std::endl;
}
