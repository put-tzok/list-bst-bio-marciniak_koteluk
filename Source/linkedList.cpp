#include <linkedList.h>

Node::Node()
    : key(NULL), next(new Node(NULL)) {
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

Node* LinkedList::insertElement(int value) { 
    Node* createdNode = new Node(value, this->head->next);
    this->head->next = createdNode;

    this->size++;
    return createdNode;
}

Node* LinkedList::searchElementWithValue(int value) { 
    for(Node* i = this->head->next; i != NULL; i = i->next) {
        if(i->key == value) return i;
    }
    return NULL;
}

void LinkedList::deleteElementWithValue(int value) { 
    if(this->size == 1) {
        delete this->head->next;

        this->size--;
        this->head = NULL;
        return;
    }

    Node* temp = this->head->next->next;
    delete this->head->next;
    this->head->next = temp;
    this->size--;
}
    
LinkedList::LinkedList()
: size(0), head(new Node()) {
    // std::cout << "Linked list successfully initialized" << std::endl;
}
    
LinkedList::~LinkedList() {
    // std::cout << "Linked list successfully deleted" << std::endl;
}
