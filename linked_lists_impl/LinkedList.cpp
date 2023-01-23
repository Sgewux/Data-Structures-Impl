#include<iostream>
#include "LinkedList.h"

LinkedList::~LinkedList(){
    Node* current = this->head;

    while(current){
        Node* former = current;
        current = current->getNext();
        delete former;
    }
}

void LinkedList::add(int value){ // Ads node to the end
    
    Node* newNode = new Node(value);

    if(!this->head){ // First time adding element
        this->head = newNode;
        this->tail = newNode;
    
    } else {
        Node* formerTail = this->tail;
        this->tail = newNode;
        formerTail->setNext(newNode); // Putting it as former tail's next node
        
    }

    this->len++; // increasing length attr
}

Node* LinkedList::getNodeAtIndex(unsigned int index){
    Node* toReturn = this->head;
    
    if(index < this->len){

        for(size_t i = 0; i < index; i++){
            toReturn = toReturn->getNext();
        }

        return toReturn;

    } else {
        throw "Index out of range";
    }
    
}


int LinkedList::get(unsigned int index){
    Node* nodeAtIndex = getNodeAtIndex(index);

    return nodeAtIndex ? nodeAtIndex->getValue() : -1;
}

void LinkedList::add(int value, unsigned int index){

  
    if(index == 0){ // Corner case: adding at the beggining
        if(!this->head){
            add(value); // First time adding element
        
        } else { 
            Node* newNode = new Node(value);
            Node* formerHead = this->head;
            
            newNode->setNext(formerHead);
            this->head = newNode;

            this->len++;
        }   
        
    } else if(index == this->len-1){ // Corner case: adding at the end.
        add(value);

    } else { // Adding at the middle
        Node* newNode = new Node(value);
        Node* nodeBefore = this->getNodeAtIndex(index - 1);
        Node* actualNode = nodeBefore->getNext();

        nodeBefore->setNext(newNode);
        newNode->setNext(actualNode);

        this->len++;
    }

}

void LinkedList::print(){
    Node* current = this->head;
    while (current)
    {
        std::cout << current->getValue() << ", ";
        current = current->getNext();   
    }
    
}

void LinkedList::remove(){
    if(this->tail){ // List not empty

        if(this->len == 1){ // Single element list
            delete this->head; // Head and tail are the same
            this->head = nullptr;
            this->tail = nullptr;
            this->len--;
            
        } else {
            Node* nodeBeforeTail = this->getNodeAtIndex(this->len-2);
            Node* formerTail = this->tail;
            nodeBeforeTail->setNext(nullptr);
            this->tail = nodeBeforeTail;

            delete formerTail; // freeing memory

            this->len--;
        }
    }
}

void LinkedList::remove(unsigned int index){

    if(index == 0){ // Corner case: deleteing at beggining
        if(this->len == 1){ // Single element list
            remove();
            
        } else {
            Node* formerHead = this->head;
            Node* newHead = this->head->getNext();
            this->head = newHead;

            delete formerHead;

            this->len--;
        }
        
    
    } else if (index == this->len - 1){ // Corner case: deleting at the end
        remove();
    
    } else { // Normal case: deleting somewhere in the middle
        Node* nodeBefore = getNodeAtIndex(index - 1);
        Node* formerNode = nodeBefore->getNext();
        Node* nodeAfter = formerNode->getNext();

        nodeBefore->setNext(nodeAfter);
        
        delete formerNode;

        this->len--;
    }
        
    
}

// void LinkedList::removeIf(std::function<bool(int)>& predicate){
//     for (size_t i = 0; i < this->len; i++)
//     {
//         if(predicate(get(i))){
//             remove(i);
//         }
//     }
    
// }

int LinkedList::length(){
    return this->len;
}