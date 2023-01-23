#ifndef NODE_H
#define NODE_H

class Node{
    private:
        int value;
        Node* next = nullptr;
    
    public:
        Node(int value);
        ~Node();
        Node* getNext();
        void setNext(Node* next);
        int getValue();
    
};

#endif