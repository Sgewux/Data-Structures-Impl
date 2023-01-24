#ifndef BUCKETNODE_H
#define BUCKETNODE_H

#include<string_view>

template<typename K, typename V>
class BucketNode{
    private:
        K key;
        V value;
        BucketNode<K,V>* prev = nullptr;
        BucketNode<K,V>* next = nullptr;
    public:
        BucketNode(K key, V value);
        ~BucketNode();
        K getKey();
        V getValue();
        void setValue(V value);
        BucketNode<K,V>* getPrev();
        void setPrev(BucketNode<K,V>* prev);
        BucketNode<K,V>* getNext();
        void setNext(BucketNode<K,V>* next);
};

template class BucketNode<std::string_view, std::string_view>;
template class BucketNode<std::string_view, int>;
template class BucketNode<std::string_view, float>;
template class BucketNode<std::string_view, double>;
template class BucketNode<std::string_view, bool>;

#endif