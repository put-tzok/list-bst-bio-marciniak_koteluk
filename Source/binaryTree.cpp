#include "../Headers/binaryTree.h"

Node* Node::getLeftNode() { return this->left; }
Node* Node::getRightNode() { return this->right; }
int Node::getValue() { return this->key; }
int Node::setValue(int val) { 
    this->key = val; 
    return this->key;
}
    
Node::Node()
    : key(NULL), left(NULL), right(NULL) {
        std::cout << "Node successfully created" << std::endl;
}
    
Node::Node(int value)
    : key(value), left(NULL), right(NULL) {
        std::cout << "Node with value: " << value << " successfully created" << std::endl;
}
    
Node::~Node() {
    std::cout << "Node successfully deleted" << std::endl;
}

int BinarySearchTree::getSize() { return this->size; }
int BinarySearchTree::setSize(int val) {
    this->size = val;
    return this->size;
}
Node* BinarySearchTree::getRoot() { return this->root; }
Node* BinarySearchTree::setRoot(Node* node) {
    this->root = node;
    return this->root;
}

// TODO
Node* BinarySearchTree::insertElement(int value) { return NULL; } 
Node** BinarySearchTree::searchElementWithValue(int value) { return NULL; }
Node* BinarySearchTree::deleteElementWithValue(int value) { return NULL; }
Node** BinarySearchTree::getMaximum(Node*) { return NULL; }
//

BinarySearchTree::BinarySearchTree()
    : size(0), root(NULL) {
        std::cout << "Linked list successfully initialized" << std::endl;
}
    
BinarySearchTree::~BinarySearchTree() {
    std::cout << "Linked list successfully deleted" << std::endl;
}
