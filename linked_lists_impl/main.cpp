#include<iostream>
#include<string_view>
#include "LinkedList.h"

// main file for testing 

void printWithLen(const LinkedList<int>& a, const LinkedList<int>& b){
    a.print();
    std::cout << " len: " << a.length() << std::endl;
    
    b.print();
    std::cout << " len: " << b.length() << std::endl;
}

int main(){

    auto isEven = [](int a) -> bool {
        if(a%2 == 0){
            return true;
        } else {
            return false;
        }
    };

    auto isOdd = [](int a) -> bool {
        if(a%2 == 0){
            return false;
        } else {
            return true;
        }
    };


    LinkedList<int> a;
    LinkedList<int> b;

    for(size_t i = 1; i <= 10; i++){
        a.add(i);
        b.add(i);
    }

    printWithLen(a,b);

    a.removeIf(isEven); // Removing evens
    b.removeIf(isOdd); // Removing odds

    std::cout << "================" << std::endl;
    printWithLen(a,b);
    
    a.add(15, 3);

    printWithLen(a,b);

    // Examples with cities

    LinkedList<std::string_view> cities;
    cities.add("Bogota");
    cities.add("Ibague");
    cities.add("Los Angeles");
    cities.add("New York");
    
    cities.print();
    std::cout << std::endl;

    cities.remove(2);
    cities.add("Paris", 1);

    cities.print();
    std::cout << std::endl; 



       
    return 0;
}