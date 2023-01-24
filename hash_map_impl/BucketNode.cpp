#include "BucketNode.h"

#include<string_view>
#include<iostream>

template<typename K, typename V>
BucketNode<K,V>::BucketNode(K key, V value){
    this->key = key;
    this->value = value;
}

template<typename K, typename V>
K BucketNode<K,V>::getKey(){
    return this->key;
}

template<typename K, typename V>
BucketNode<K,V>* BucketNode<K,V>::getNext(){
    return this->next;
}

template<typename K, typename V>
BucketNode<K,V>* BucketNode<K,V>::getPrev(){
    return this->prev;
}

template<typename K, typename V>
void BucketNode<K,V>::setNext(BucketNode<K,V>* next){
    this->next = next;
}

template<typename K, typename V>
void BucketNode<K,V>::setPrev(BucketNode<K,V>* prev){
    this->prev = prev;
}

template<typename K, typename V>
void BucketNode<K,V>::setValue(V value){
    this->value = value;
}

template<typename K, typename V>
V BucketNode<K,V>::getValue(){
    return this->value;
}
template<typename K, typename V>
BucketNode<K,V>::~BucketNode(){
    std::cout << "Deleting node w key: " << this->key << std::endl;
}