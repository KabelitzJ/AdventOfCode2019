#include <iostream>
#include <fstream>
#include <string>

int main(void) {

    int mass = 0;
    int sum = 0;
    std::string line;
    std::ifstream ifs("input.txt");

    if(ifs.is_open()) {
        while(getline(ifs, line)) {
            mass = std::stoi(line);
            sum += mass / 3 - 2;
        }
        ifs.close();
    }

    std::cout << sum;


    return 0;
}