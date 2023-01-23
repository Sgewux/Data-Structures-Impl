#include<iostream>
#include "LinkedList.h"


void removeEven(LinkedList& list){
    for (size_t i = 0; i < list.length(); i++)
    {
        if(list.get(i) % 2 == 0){
            list.remove(i);
        }
    }
    
}

void removeOdd(LinkedList& list){
    for (size_t i = 0; i < list.length(); i++)
    {
        if(list.get(i) % 2 != 0){
            list.remove(i);
        }
    }
}

void printWithLen(LinkedList& a, LinkedList& b){
    a.print();
    std::cout << " len: " << a.length() << std::endl;
    
    b.print();
    std::cout << " len: " << b.length() << std::endl;
}

int main(){


    // auto func = [](int a)->bool{
    //      return a > ;
    // };

    // LinkedList a;
    // LinkedList b;

    // for(size_t i = 1; i <= 10; i++){
    //     a.add(i);
    //     b.add(i);
    // }

    // printWithLen(a,b);

    // removeEven(a);
    // removeOdd(b);

    // std::cout << "================" << std::endl;
    // printWithLen(a,b);
    
    // a.add(15, 3);

    // printWithLen(a,b);


    LinkedList a;
    for(size_t i = 1; i <= 10; i++){
        a.add(i,0);
    }



    a.print();
    std::cout << " len: " << a.length() << std::endl;

    removeOdd(a);

    a.print();
    std::cout << " len: " << a.length() << std::endl;

    a.add(-1, 3);

    a.print();
    std::cout << " len: " << a.length() << std::endl;


       
    return 0;
}