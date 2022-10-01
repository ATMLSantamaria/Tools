#include "Booking_List_Manager.h"


int main(){

    std::string file("../data/.booking_list.txt");
    Booking_List_Manager * list = Booking_List_Manager::instance(file);
 

    list->run();

    std::vector<std::string> a = list->get_content();




}