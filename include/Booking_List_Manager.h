#pragma 
#include <iostream>
#include <fstream>
#include <vector>

#include "Lector.h"
#include "Escritor.h"

class Booking_List_Manager {
    private:
    Booking_List_Manager(std::string &source_f);

    std::string _source_f;
    std::vector<std::string> _content;

    Lector * _lector;
    Escritor * _escritor;
    
    public:
    Booking_List_Manager()=delete;
    Booking_List_Manager(const Booking_List_Manager&) = delete;
    Booking_List_Manager & operator=(const Booking_List_Manager &) = delete; 
    Booking_List_Manager(Booking_List_Manager&&) = delete;
    Booking_List_Manager & operator=(Booking_List_Manager &&) = delete;
    ~Booking_List_Manager(){}
    
    static Booking_List_Manager * instance(std::string &source){
        static Booking_List_Manager * l = new Booking_List_Manager(source);
        return l;
    }

    void run();


    std::vector<std::string> get_content(){
        return _content;
    }

};