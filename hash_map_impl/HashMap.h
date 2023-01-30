#ifndef HASHMAP_H
#define HASHMAP_H

#include<string_view>
#include "BucketNode.h"

template <typename K, typename V>
class HashMap{
    private:
        size_t bucketSize;
        BucketNode<K,V>** bucket = nullptr;
        BucketNode<K,V>* getNode(K key) const;
        size_t getIndexForKey(K key) const;
    
    public:
        HashMap();
        HashMap(size_t bucketSize);
        ~HashMap();
        void put(K key, V value);
        V get (K key) const;
        void remove(K key);
};


template class HashMap<std::string_view, std::string_view>;
template class HashMap<std::string_view, int>;
template class HashMap<std::string_view, float>;
template class HashMap<std::string_view, double>;
template class HashMap<std::string_view, bool>;


#endif