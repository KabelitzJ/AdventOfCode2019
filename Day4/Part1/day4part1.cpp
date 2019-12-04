#include <iostream>

// input: 178416-676461

int* makePass(int a) {
    int* pass = new int[6];

    for(int i = 0, j = 100000; i < 6; i++, j /= 10) {
        pass[i] = (a / j) % 10;
    }

    return pass;
}

bool checkPass(int pass[6]) {
    int last = -1;
    bool twoSame = false;
    bool desc = false;

    for(int i = 0; i < 6; i++) {
        if(pass[i] == last && !twoSame) {
            twoSame = true;
        }

        if(pass[i] < last) {
            desc = true;
            break;
        }

        last = pass[i];
    }
    delete[] pass;

    return (!desc && twoSame);
}

int main(void) {

    int count = 0;

    for(int i = 178416; i <= 676461; i++) {
        if(checkPass(makePass(i))) {
            count++;
        }
    }

    std:: cout << count << std::endl;

    return 0;
}