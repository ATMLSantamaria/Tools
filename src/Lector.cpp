#include "Lector.h"


Lector::Lector(std::string & source){
    l.open(source,std::fstream::in);
}

std::vector<std::string> Lector::readBookingList(){
    std::string line;
    std::vector<std::string> _load_text;
    for (line;std::getline(l,line);){
        _load_text.push_back(line);
    }



    return std::move(_load_text);
}

Lector::~Lector(){l.close();}