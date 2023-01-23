#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<functional>
#include "Node.h"


class LinkedList{
    private:
        Node* head = nullptr;
        Node* tail = nullptr;
        size_t len = 0;

        Node* getNodeAtIndex(unsigned int index);

    public:
        LinkedList() = default;
        ~LinkedList();
        void add(int value); // Adds element to the end
        void add(int value, unsigned int index); // Adds element to an specific position
        void remove(); // Removes element from que end (tail)
        void remove(unsigned int index); // removes element at specific index
        //void removeIf(std::function<bool(int)>& predicate);
        void print();
        int get(unsigned int index);
        int length();
        
};

#endif