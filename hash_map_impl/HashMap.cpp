#include "HashMap.h"
#include "BucketNode.h"

#include<iostream>
#include<functional>
#include<string_view>

HashMap::HashMap(){
    this->bucketSize = 16;
    this->bucket = new BucketNode*[this->bucketSize];

    for(size_t i = 0; i < bucketSize; i++){
        *(this->bucket + i) = nullptr;
    }
}

HashMap::HashMap(size_t bucketSize){
    this->bucketSize = bucketSize;
    this->bucket = new BucketNode*[this->bucketSize];

    for(size_t i = 0; i < bucketSize; i++){
        *(this->bucket + i) = nullptr;
    }
}


HashMap::~HashMap(){
    for(size_t i = 0; i < this->bucketSize; i++){
        BucketNode* current = *(this->bucket + i);
        while(current){
            BucketNode* next = current->getNext();
            delete current,
            current = next;
        }
    }
    
    delete[] this->bucket;
}

size_t HashMap::getIndexForKey(std::string_view key) const{
    size_t hash = std::hash<std::string_view>{}(key);
    size_t bucketIndex = hash & (this->bucketSize - 1);

    return bucketIndex;
}

BucketNode* HashMap::getNode(std::string_view key) const{
    size_t bucketIndex = getIndexForKey(key);

    BucketNode* head = *(this->bucket + bucketIndex);

    if(!head){ // no node with that hash
        throw "No such elment";
        
    } else {
        do{
            if(head->getKey() == key){
                return head;
            }

        } while ( (head = head->getNext()) );
        
        throw "No such element";
        
    }
}

void HashMap::put(std::string_view key, int value){
    size_t bucketIndex = getIndexForKey(key);

    if(!*(this->bucket + bucketIndex)){ // First element in bucket
        BucketNode* newNode = new BucketNode(key, value);

        *(this->bucket + bucketIndex) = newNode;
    } else {
        try
        {
            BucketNode* node = getNode(key); // Already a node whose key is key
            node->setValue(value);
        }
        catch(const char * message)
        {
            BucketNode* newNode = new BucketNode(key, value);

            BucketNode* formerHead =  *(this->bucket + bucketIndex);
            formerHead->setPrev(newNode);
            newNode->setNext(formerHead);
            *(this->bucket + bucketIndex) = newNode; // Seting it as new head
        }
        
        
    }

}

int HashMap::get(std::string_view key) const{
    return getNode(key)->getValue();
}

void HashMap::remove(std::string_view key){
    BucketNode* toDelete = getNode(key);
    BucketNode* formerPrev = toDelete->getPrev();
    BucketNode* formerNext = toDelete->getNext();
    size_t bucketIndex = getIndexForKey(key);

    if(!formerPrev && !formerNext){ //Deleting a single node, so the list is empty after deleting


        *(this->bucket + bucketIndex) = nullptr;
    
    } else {

        if(!formerPrev){ // Deleting head
            formerNext->setPrev(nullptr);
            *(this->bucket + bucketIndex) = formerNext; // new head
        
        } else if(!formerNext){ // Deleting tail
            formerPrev->setNext(nullptr);
        
        } else { // Deleting middle
            formerPrev->setNext(formerNext);
            formerNext->setPrev(formerPrev);
        }

    }


    delete toDelete;
}

void HashMap::xd(){
    for(size_t i = 0; i < bucketSize; i++){
        BucketNode* uwu = *(this->bucket + i);
        std::cout << "Content index " << i << " " << (uwu == nullptr)  << std::endl;
    }
}