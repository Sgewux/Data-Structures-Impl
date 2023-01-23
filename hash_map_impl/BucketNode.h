#ifndef BUCKETNODE_H
#define BUCKETNODE_H

#include<string_view>

class BucketNode{
    private:
        std::string_view key;
        int value;
        BucketNode* prev = nullptr;
        BucketNode* next = nullptr;
    public:
        BucketNode(std::string_view key, int value);
        ~BucketNode();
        std::string_view getKey();
        int getValue();
        void setValue(int value);
        BucketNode* getPrev();
        void setPrev(BucketNode* prev);
        BucketNode* getNext();
        void setNext(BucketNode* next);
};

#endif