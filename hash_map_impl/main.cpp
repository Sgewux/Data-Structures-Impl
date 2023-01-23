#include<iostream>
#include<functional>
#include<string_view>

#include "HashMap.h"

void printAges(const HashMap& ages){
    std::string_view names[] = {"Carlos", "Jose", "Luis", "Luisa", "Nelson"};
    for (size_t i = 0; i < std::size(names); i++)
    {
        try
        {
            std::cout << names[i] << " : " << ages.get(names[i]) << std::endl;
        }
        catch(const char * messsage)
        {
            std::cout << names[i] << " : " << messsage << std::endl;
        }
        
    }

    std::cout << "============================" << std::endl;
    
}

int main(){

    try{
        HashMap ages;
        
        ages.put("Carlos", 12);
        ages.put("Jose", 19);
        ages.put("Luis", 14);
        ages.put("Luisa", 23);
        ages.put("Nelson", 15);

        printAges(ages);

        ages.put("Jose",45);

        printAges(ages);

        ages.remove("Luis");
        ages.remove("Luisa");

        printAges(ages);


    }
    catch(const char * message){
       std::cout << message;
    }
    

    return 0;
}