#include <iostream>
#include <regex>
#include <string>

// input: 178416-676461

bool checkPass(int a) {
    int pass[6];
    bool isDesc = false;
    bool hasPair = false;
    int pairValue = -1;

    for(int i = 0, j = 100000; i < 6; i++, j /= 10) {
        pass[i] = (a / j) % 10;
    }

    for(int i = 0; i < 5; i++) {
        if(pass[i] > pass[i + 1]) {
            isDesc = true;
            break;
        }

        if(pass[i] == pass[i + 1]) {
            if(pass[i] != pairValue) {
                hasPair = true;
                pairValue = pass[i];
            } else {
                hasPair = false;
            }
        }
    }

    return (!isDesc && hasPair);
}

int main(void) {

    int count = 0;

    for(int i = 178416; i <= 676461; i++) {
        if(checkPass(i)) {
            count++;
        }
    }

    std::cout << count << std::endl;

    return 0;
}