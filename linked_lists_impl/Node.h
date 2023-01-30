#ifndef NODE_H
#define NODE_H

template <typename T>
class Node{
    private:
        T value;
        Node<T>* next = nullptr;
    
    public:
        Node(T value);
        ~Node();
        Node<T>* getNext();
        void setNext(Node<T>* next);
        T getValue();
    
};

template class Node<int>;
template class Node<float>;
template class Node<double>;
template class Node<std::string_view>;

#endif