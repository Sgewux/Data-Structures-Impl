#include "BucketNode.h"

#include<string_view>
#include<iostream>

BucketNode::BucketNode(std::string_view key, int value){
    this->key = key;
    this->value = value;
}

std::string_view BucketNode::getKey(){
    return this->key;
}

BucketNode* BucketNode::getNext(){
    return this->next;
}

BucketNode* BucketNode::getPrev(){
    return this->prev;
}

void BucketNode::setNext(BucketNode* next){
    this->next = next;
}

void BucketNode::setPrev(BucketNode* prev){
    this->prev = prev;
}

void BucketNode::setValue(int value){
    this->value = value;
}
int BucketNode::getValue(){
    return this->value;
}

BucketNode::~BucketNode(){
    std::cout << "Deleting node w key: " << this->key << std::endl;
}