#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

class Escritor {
    private:
    std::fstream f;
    std::string destination_f;
    std::vector<std::string> _local_content;
    std::vector<std::pair<std::string,double>> content_2_save;

    void addNewBookingNumber();
    public:
    Escritor(std::string &source,std::vector<std::string> &content):destination_f(source),_local_content(content){};
    
    void formatHours();
    /// @brief 
    void readHours();
    void saveHours();

    void printCurrentBookingNumbers();

    void writeFormatHours();

    
    

};



