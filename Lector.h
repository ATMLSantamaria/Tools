#include <iostream>
#include <fstream>
#include <vector>

class Lector {
    private:
    std::fstream l;
    public:
    Lector(std::string &source);
    std::vector<std::string> readBookingList();
    ~Lector();


};
