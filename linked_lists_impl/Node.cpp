#include<iostream>
#include "Node.h"

template <typename T>
Node<T>::Node(T value){
    this->value = value;
}

template <typename T>
Node<T>* Node<T>::getNext(){
    return this->next;
}

template <typename T>
void Node<T>::setNext(Node<T>* next){
    this->next = next;
}

template <typename T>
T Node<T>::getValue(){
    return this->value;
}

template <typename T>
Node<T>::~Node(){
    std::cout << "Deleting Node w value: " << this->value << std::endl;
}