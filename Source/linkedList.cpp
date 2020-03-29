#include <linkedList.h>

Node* Node::getNextNode() { return this->next; }
Node* Node::setNextNode(Node* node) {
    this->next = node;
    return this->next;
}

int Node::getValue() { return this->key; }
int Node::setValue(int val) { 
    this->key = val; 
    return this->key;
}

Node::Node()
    :next(NULL) {
        // std::cout << "Node successfully created" << std::endl;
}

Node::Node(int value, Node* node)
    : key(value), next(node) {
        // std::cout << "Node with value: " << value << " successfully created" << std::endl;
}
    
Node::~Node() {
    // std::cout << "Node successfully deleted" << std::endl;
}

unsigned int LinkedList::getSize() { return this->size; }
unsigned int LinkedList::setSize(int val) { 
    this->size = val;
    return this->size;
}

Node* LinkedList::getHead() { return this->head; }
Node* LinkedList::setHead(Node* node) {
    this->head = node;
    return this->head;
}

Node* LinkedList::insertElement(int value) { 
    Node* createdNode = new Node(value, this->getHead());
    this->setHead(createdNode);

    this->setSize(this->getSize() + 1);
    return this->getHead();
}

Node* LinkedList::searchElementWithValue(int value) { 
    for(Node* i = this->getHead(); i != NULL; i = i->getNextNode()) {
        if(i->getValue() == value) return i;
    }
    return NULL;
}

void LinkedList::deleteElementWithValue(int value) { 
    Node* prevNode = NULL;

    for(Node* i = this->getHead(); i != NULL; prevNode = i, i = i->getNextNode()) {
        if(i->getValue() == value) {
            if(prevNode == NULL) 
                this->setHead(i->getNextNode());
            else
                prevNode->setNextNode(i->getNextNode());
            this->setSize(this->getSize() - 1);
            return;
        }
    }
}
    
LinkedList::LinkedList()
: size(0), head(NULL) {
    // std::cout << "Linked list successfully initialized" << std::endl;
}
    
LinkedList::~LinkedList() {
    // std::cout << "Linked list successfully deleted" << std::endl;
}
