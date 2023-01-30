#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<functional>
#include<string_view>
#include "Node.h"

template<typename T>
class LinkedList{
    private:
        Node<T>* head = nullptr;
        Node<T>* tail = nullptr;
        size_t len = 0;

        Node<T>* getNodeAtIndex(unsigned int index) const;

    public:
        LinkedList() = default;
        ~LinkedList();
        void add(T value); // Adds element to the end
        void add(T value, unsigned int index); // Adds element to an specific position
        void remove(); // Removes element from que end (tail)
        void remove(unsigned int index); // removes element at specific index
        void removeIf(const std::function<bool(T)>& predicate); // Removes element according given predicate
        void print() const;
        T get(unsigned int index) const;
        size_t length() const;
        
};

template class LinkedList<int>;
template class LinkedList<float>;
template class LinkedList<double>;
template class LinkedList<std::string_view>;


#endif