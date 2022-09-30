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

Booking_List_Manager::Booking_List_Manager(std::string &source_f){
    _source_f=source_f;
    _lector = new Lector(source_f);
    _content = _lector->readBookingList();
    _escritor = new Escritor(source_f,_content);
}

void Booking_List_Manager::run(){
    std::cout << "Booking List Manager Started\n\n-----------------------------\n\n" << std::endl;

    //std::cout << "Lector Run started\n";
    //_content = _lector->readBookingList();
    //std::cout << "TMP Lector finished\n";

    _escritor->formatHours();

    std::cout << "aNTES DE READHOURS\n";
    _escritor->readHours();
    std::cout << "DESPUES DE READHOURS\n";
    _escritor->writeFormatHours();



}


int main(){
    //std::string aa;
    //std::cin >> aa;
    std::string file(".booking_list.txt");
    Booking_List_Manager * list = Booking_List_Manager::instance(file);
 

    list->run();

    std::vector<std::string> a = list->get_content();
    // for (std::string i : a){
    //     std::cout << i <<std::endl;
    // }




}