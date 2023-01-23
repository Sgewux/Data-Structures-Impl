#ifndef HASHMAP_H
#define HASHMAP_H

#include<string_view>
#include "BucketNode.h"

class HashMap{
    private:
        size_t bucketSize;
        BucketNode** bucket = nullptr;
        BucketNode* getNode(std::string_view key) const;
        size_t getIndexForKey(std::string_view key) const;
    
    public:
        HashMap();
        HashMap(size_t bucketSize);
        ~HashMap();
        void put(std::string_view key, int value);
        int get (std::string_view key) const;
        void remove(std::string_view key);
        void xd();
};

#endif