#include "HashMap.h"
#include "BucketNode.h"

#include<iostream>
#include<functional>

template<typename K, typename V>
HashMap<K,V>::HashMap(){
    this->bucketSize = 16;
    this->bucket = new BucketNode<K,V>*[this->bucketSize];

    for(size_t i = 0; i < bucketSize; i++){
        *(this->bucket + i) = nullptr;
    }
}

template<typename K, typename V>
HashMap<K,V>::HashMap(size_t bucketSize){
    this->bucketSize = bucketSize;
    this->bucket = new BucketNode<K,V>*[this->bucketSize];

    for(size_t i = 0; i < bucketSize; i++){
        *(this->bucket + i) = nullptr;
    }
}

template<typename K, typename V>
HashMap<K,V>::~HashMap(){
    for(size_t i = 0; i < this->bucketSize; i++){
        BucketNode<K,V>* current = *(this->bucket + i);
        while(current){
            BucketNode<K,V>* next = current->getNext();
            delete current,
            current = next;
        }
    }
    
    delete[] this->bucket;
}

template<typename K, typename V>
size_t HashMap<K,V>::getIndexForKey(K key) const{
    size_t hash = std::hash<K>{}(key);
    size_t bucketIndex = hash & (this->bucketSize - 1);

    return bucketIndex;
}

template<typename K, typename V>
BucketNode<K,V>* HashMap<K,V>::getNode(K key) const{
    size_t bucketIndex = getIndexForKey(key);

    BucketNode<K,V>* head = *(this->bucket + bucketIndex);

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

template<typename K, typename V>
void HashMap<K,V>::put(K key, V value){
    size_t bucketIndex = getIndexForKey(key);

    if(!*(this->bucket + bucketIndex)){ // First element in bucket
        BucketNode<K,V>* newNode = new BucketNode<K,V>(key, value);

        *(this->bucket + bucketIndex) = newNode;
    } else {
        try
        {
            BucketNode<K,V>* node = getNode(key); // Already a node whose key is key
            node->setValue(value);
        }
        catch(const char * message)
        {
            BucketNode<K,V>* newNode = new BucketNode<K,V>(key, value);

            BucketNode<K,V>* formerHead =  *(this->bucket + bucketIndex);
            formerHead->setPrev(newNode);
            newNode->setNext(formerHead);
            *(this->bucket + bucketIndex) = newNode; // Seting it as new head
        }
        
        
    }

}

template<typename K, typename V>
V HashMap<K,V>::get(K key) const{
    return getNode(key)->getValue();
}

template<typename K, typename V>
void HashMap<K,V>::remove(K key){
    BucketNode<K,V>* toDelete = getNode(key);
    BucketNode<K,V>* formerPrev = toDelete->getPrev();
    BucketNode<K,V>* formerNext = toDelete->getNext();
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