#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main() {

  std::string line;
  std::ifstream ifs("input.txt");

  if(ifs.is_open()) {
    getline(ifs, line);
    ifs.close();
  } else {
    return -1;
  }

  std::vector<int> orig;
  std::stringstream ss(line);

  for(int i; ss >> i;) {
    orig.push_back(i);    
    if (ss.peek() == ',') {
        ss.ignore();
    }
  }

  std::vector<int> vec = orig;
  int noun = 0;
  int verb = 0;
  int index = 0;
  int operation = vec[index];
  int firstInputPosition = 0;
  int firstInput = 0;
  int secondInputPosition = 0;
  int secondInput = 0;
  int outputPosition = 0;
  int output = 0;
  bool shouldRun = (operation == 1 || operation == 2);
  bool solutionFound = false;

  for(int j = 0; j <= 99 && !solutionFound; j++) {
    for(int i = 0; i <= 99 && !solutionFound; i++) {
      vec[1] = i; // noun
      vec[2] = j; //verb

      while(shouldRun) {
        firstInputPosition = vec[index + 1];
        secondInputPosition = vec[index + 2];
        outputPosition = vec[index + 3];

        firstInput = vec[firstInputPosition];
        secondInput = vec[secondInputPosition];

        if(operation == 1) {
          output = firstInput + secondInput;
        } else if(operation == 2) {
          output = firstInput * secondInput;
        }

        vec[outputPosition] = output;

        index += 4;
        operation = vec[index];
        shouldRun = (operation == 1 || operation == 2);
      }
      if(vec[0] == 19690720) {
        solutionFound = true;
        noun = i;
        verb = j;
      } else {
        vec = orig;
        index = 0;
        operation = vec[index];
        firstInputPosition = 0;
        firstInput = 0;
        secondInputPosition = 0;
        secondInput = 0;
        outputPosition = 0;
        output = 0;
        shouldRun = (operation == 1 || operation == 2);
      }
    }
  }

  std::cout << (100 * noun + verb) << "\n";

  return 0;
}
