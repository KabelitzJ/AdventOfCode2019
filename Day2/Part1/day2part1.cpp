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

  std::vector<int> vec;
  std::stringstream ss(line);

  for(int i; ss >> i;) {
    vec.push_back(i);    
    if (ss.peek() == ',') {
        ss.ignore();
    }
  }

  int index = 0;
  int operation = vec[index];
  int firstInputPosition = 0;
  int firstInput = 0;
  int secondInputPosition = 0;
  int secondInput = 0;
  int outputPosition = 0;
  int output = 0;
  bool shouldRun = (operation == 1 || operation == 2);

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

  std::cout << vec[0];

  return 0;
}
