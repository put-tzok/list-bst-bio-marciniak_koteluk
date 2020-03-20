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
    : key(-1), next(new Node(NULL)) {
        // std::cout << "Node successfully created" << std::endl;
}

Node::Node(Node* node) 
    : next(node) {
        // std::cout << "Node successfully created" << std::endl;
    }
    
Node::Node(int value, Node* node)
    : key(value), next(node) {
        // std::cout << "Node with value: " << value << " successfully created" << std::endl;
}
    
Node::~Node() {
    // std::cout << "Node successfully deleted" << std::endl;
}

int LinkedList::getSize() { return this->size; }
int LinkedList::setSize(int val) { 
    this->size = val;
    return this->size;
}

Node* LinkedList::getHead() { return this->head; }
Node* LinkedList::setHead(Node* node) {
    this->head = node;
    return this->head;
}

Node* LinkedList::insertElement(int value) { 
    Node* createdNode = new Node(value, this->getHead()->getNextNode());
    this->getHead()->setNextNode(createdNode);

    int size = this->getSize();
    this->setSize(++size);
    return createdNode;
}

Node* LinkedList::searchElementWithValue(int value) { 
    for(Node* i = this->getHead()->getNextNode(); i != NULL; i = i->getNextNode()) {
        if(i->getValue() == value) return i;
    }
    return NULL;
}

void LinkedList::deleteElementWithValue(int value) { 
    if(this->getSize() == 1) {
        delete this->getHead()->getNextNode();

        int size = this->getSize();
        this->setSize(--size);
        this->setHead(NULL);
        return;
    }

    Node* temp = this->getHead()->getNextNode()->getNextNode();
    delete this->getHead()->getNextNode();
    this->getHead()->setNextNode(temp);
    
    int size = getSize();
    this->setSize(--size);
}
    
LinkedList::LinkedList()
: size(0), head(new Node()) {
    // std::cout << "Linked list successfully initialized" << std::endl;
}
    
LinkedList::~LinkedList() {
    // std::cout << "Linked list successfully deleted" << std::endl;
}
