#include "Booking_List_Manager.h"



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