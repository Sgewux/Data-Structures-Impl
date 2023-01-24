#include<iostream>
#include<functional>
#include<string_view>

#include "HashMap.h"

//Main file to tet the functionality of HashMap data structure

void printAges(const HashMap<std::string_view, int>& ages){
    std::string_view names[] = {"Carlos", "Jose", "Luis", "Luisa", "Nelson"};
    for (size_t i = 0; i < std::size(names); i++)
    {
        try
        {
            std::cout << names[i] << " : " << ages.get(names[i]) << std::endl;
        }
        catch(const char * messsage)
        {
            std::cout <<  " : " << messsage << std::endl;
        }
        
    }

    std::cout << "============================" << std::endl;
    
}

void printCities(const HashMap<std::string_view, std::string_view>& cities){
    std::string_view countries[] = {"Colombia", "Venezuela", "France"};

    for (size_t i = 0; i < std::size(countries); i++)
    {
        try
        {
            std::cout << countries[i] << " : " << cities.get(countries[i]) << std::endl;
        }
        catch(const char * messsage)
        {
            std::cout << " : " << messsage << std::endl;
        }
        
    }

    std::cout << "============================" << std::endl;
}

int main(){

    try{
        HashMap<std::string_view, int> ages;
        
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

    
        HashMap<std::string_view, std::string_view> capitalCities;

        capitalCities.put("Colombia", "Bogota");
        capitalCities.put("Venezuela", "Caracas");
        capitalCities.put("France", "Paris");

        printCities(capitalCities);

        capitalCities.put("Colombia", "Ibague");
        capitalCities.remove("France");

        printCities(capitalCities);

    }
    catch(const char * message){
       std::cout << message;
    }
    

    return 0;
}