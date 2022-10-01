#include "Escritor.h"

void Escritor::formatHours(){
    std::string booking_id;
    std::string hours;
    char tmp;
    double h;
    for (std::string i : _local_content){
        std::istringstream ss(i);
        ss >> booking_id >> tmp >> hours;
        h=std::stod(hours);
        content_2_save.push_back(std::make_pair(booking_id,h));
    }

    //printFormatHours();

}

/// @brief 
void Escritor::readHours(){
    std::cout << "\n\n Proceed to read hours \n\n";
    std::string added_hours;
    //int n=0;
    
    addNewBookingNumber();

    for (auto &i : content_2_save){
        //std::cout << "Iteracion: " << n++;
        std::cout << "\nEnter number of hours to add";
        std::cout << " to the booking number: " ;
        std::cout << i.first << "      \n";

        std::cin >> added_hours;

        i.second = i.second + std::stod(added_hours);
    }

    std::cout << "\n\n Finish reading \n\n";

    //printFormatHours();


}

void Escritor::printCurrentBookingNumbers(){
    for (auto i : content_2_save){
        std::cout << "Current Booking Numbers ";
        std::cout << i.first << "=" << i.second << std::endl;
    }
}

void Escritor::writeFormatHours(){
    //addNewBookingNumber();
    f.open(destination_f,std::fstream::out);
    for (auto i : content_2_save){
        std::string t;
        t=i.first+" = "+std::to_string(i.second);
        f << t << std::endl;

    }
    f.close();
}

void Escritor::addNewBookingNumber(){
    std::string answer,new_booking;
    printCurrentBookingNumbers();
    std::cout << "\n\nDo you want to add a new booking number? [y/n]\n";
    std::cin >> answer;
    if (answer=="yes"||answer=="y"||answer=="Y"||answer=="Yes"||answer=="YES"){
        std::cout << "Write the new Booking Number\n";
        std::cin >> new_booking;
        content_2_save.push_back(std::make_pair(new_booking,0));
        return;
    } else {
        return;
        }

}