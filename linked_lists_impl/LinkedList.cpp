#include<iostream>
#include<functional>
#include "LinkedList.h"

template<typename T>
LinkedList<T>::~LinkedList(){
    Node<T>* current = this->head;

    while(current){
        Node<T>* former = current;
        current = current->getNext();
        delete former;
    }
}

template<typename T>
void LinkedList<T>::add(T value){ // Ads node to the end
    
    Node<T>* newNode = new Node<T>(value);

    if(!this->head){ // First time adding element
        this->head = newNode;
        this->tail = newNode;
    
    } else {
        Node<T>* formerTail = this->tail;
        this->tail = newNode;
        formerTail->setNext(newNode); // Putting it as former tail's next node
        
    }

    this->len++; // increasing length attr
}

template<typename T>
Node<T>* LinkedList<T>::getNodeAtIndex(unsigned int index) const{
    Node<T>* toReturn = this->head;
    
    if(index < this->len){

        for(size_t i = 0; i < index; i++){
            toReturn = toReturn->getNext();
        }

        return toReturn;

    } else {
        throw "Index out of range";
    }
    
}

template<typename T>
T LinkedList<T>::get(unsigned int index) const{
    Node<T>* nodeAtIndex = getNodeAtIndex(index);

    return nodeAtIndex->getValue();
}

template<typename T>
void LinkedList<T>::add(T value, unsigned int index){

  
    if(index == 0){ // Corner case: adding at the beggining
        if(!this->head){
            add(value); // First time adding element
        
        } else { 
            Node<T>* newNode = new Node<T>(value);
            Node<T>* formerHead = this->head;
            
            newNode->setNext(formerHead);
            this->head = newNode;

            this->len++;
        }   
        
    } else if(index == this->len-1){ // Corner case: adding at the end.
        add(value);

    } else { // Adding at the middle
        Node<T>* newNode = new Node<T>(value);
        Node<T>* nodeBefore = this->getNodeAtIndex(index - 1);
        Node<T>* actualNode = nodeBefore->getNext();

        nodeBefore->setNext(newNode);
        newNode->setNext(actualNode);

        this->len++;
    }

}

template<typename T>
void LinkedList<T>::print() const{
    Node<T>* current = this->head;
    while (current)
    {
        std::cout << current->getValue() << ", ";
        current = current->getNext();   
    }
    
}

template<typename T>
void LinkedList<T>::remove(){
    if(this->tail){ // List not empty

        if(this->len == 1){ // Single element list
            delete this->head; // Head and tail are the same
            this->head = nullptr;
            this->tail = nullptr;
            this->len--;
            
        } else {
            Node<T>* nodeBeforeTail = this->getNodeAtIndex(this->len-2);
            Node<T>* formerTail = this->tail;
            nodeBeforeTail->setNext(nullptr);
            this->tail = nodeBeforeTail;

            delete formerTail; // freeing memory

            this->len--;
        }
    }
}

template<typename T>
void LinkedList<T>::remove(unsigned int index){

    if(index == 0){ // Corner case: deleteing at beggining
        if(this->len == 1){ // Single element list
            remove();
            
        } else {
            Node<T>* formerHead = this->head;
            Node<T>* newHead = this->head->getNext();
            this->head = newHead;

            delete formerHead;

            this->len--;
        }
        
    
    } else if (index == this->len - 1){ // Corner case: deleting at the end
        remove();
    
    } else { // Normal case: deleting somewhere in the middle
        Node<T>* nodeBefore = getNodeAtIndex(index - 1);
        Node<T>* formerNode = nodeBefore->getNext();
        Node<T>* nodeAfter = formerNode->getNext();

        nodeBefore->setNext(nodeAfter);
        
        delete formerNode;

        this->len--;
    }
        
    
}

template<typename T>
void LinkedList<T>::removeIf(const std::function<bool (T) >& predicate){
    Node<T>* current = this->head;
    size_t idx = 0;

    while (current)
    {
        Node<T>* currentsNex = current->getNext(); // Storing next in a variable to preserve it

        if(predicate(current->getValue())){ // if predicate returns true
            remove(idx);
        
        } else {
            idx++; // idx increases only if we have not deleted anything, if we did index remains the same because list's size decreased
        }

        current = currentsNex; // We always update the current pointer
    }
    
}

template<typename T>
size_t LinkedList<T>::length() const{
    return this->len;
}