#include "../Headers/binaryTree.h"

Node* Node::getLeftNode() { return this->left; }
Node* Node::setLeftNode(Node* node) {
    this->left = node;
    return this->left; 
}

Node* Node::getRightNode() { return this->right; }
Node* Node::setRightNode(Node* node) {
    this->right = node;
    return this->right;
}

int Node::getValue() { return this->key; }
int Node::setValue(int val) { 
    this->key = val; 
    return this->key;
}
    
Node::Node()
    : key(0), left(NULL), right(NULL) {
        std::cout << "Node successfully created" << std::endl;
}
    
Node::Node(int value)
    : key(value), left(NULL), right(NULL) {
        std::cout << "Node with value: " << value << " successfully created" << std::endl;
}
    
Node::~Node() {
    std::cout << "Node successfully deleted" << std::endl;
}

unsigned int BinarySearchTree::getSize() { return this->size; }
unsigned int BinarySearchTree::setSize(int val) {
    this->size = val;
    return this->size;
}
Node* BinarySearchTree::getRoot() { return this->root; }
Node* BinarySearchTree::setRoot(Node* node) {
    this->root = node;
    return this->root;
}

Node* BinarySearchTree::insertElement(int value) {
    if(this->getRoot() == NULL) {
        this->setRoot(new Node(value));
        return this->getRoot();
    }

    Node* node = this->searchElementWithValue(this->getRoot(), value);

    if(node->getValue() < value) {
        node->setRightNode(new Node(value));
    } else if(node->getValue() >= value) {
        node->setLeftNode(new Node(value));
    }

    return node;
}

Node* BinarySearchTree::searchElementWithValue(Node* node, int value) { 
    if(node == NULL || node->getValue() == value)
        return node;

    if(node->getValue() < value) {
        if(node->getRightNode() == NULL) return node;
        return this->searchElementWithValue(node->getRightNode(), value);
    }

    if(node->getLeftNode() == NULL) return node;
    return this->searchElementWithValue(node->getLeftNode(), value);
}
Node* BinarySearchTree::deleteElementWithValue(int value) { return NULL; }

Node* BinarySearchTree::getMaximum(Node*) { return NULL; }

BinarySearchTree::BinarySearchTree()
    : size(0), root(NULL) {
        std::cout << "Linked list successfully initialized" << std::endl;
}
    
BinarySearchTree::~BinarySearchTree() {
    std::cout << "Linked list successfully deleted" << std::endl;
}
