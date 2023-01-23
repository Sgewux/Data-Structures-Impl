#include<iostream>
#include "Node.h"

Node::Node(int value){
    this->value = value;
}

Node* Node::getNext(){
    return this->next;
}

void Node::setNext(Node* next){
    this->next = next;
}

int Node::getValue(){
    return this->value;
}


Node::~Node(){
    std::cout << "Deleting Node w value: " << this->value << std::endl;
}