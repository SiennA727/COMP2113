#include <iostream>
#include <cstdlib>
#include "d2boh.h"
using namespace std;

int main(int argc, char* argv[]){

  int type = atoi(argv[1]), input_num = atoi(argv[2]);

  int digit;

  if (type == 1){
    int output[10];
    digit = decimal_to_binary(input_num, output);
    for (int i=0; i<digit; ++i)
      cout << output[i];
  }

  else if (type == 2){
    int output[10];
    digit = decimal_to_octal(input_num, output);
    for (int i=0; i<digit; ++i)
      cout << output[i];
  }

  else if (type == 3){
    char output[10];
    digit = decimal_to_hexadecimal(input_num, output);
    for (int i=0; i<digit; ++i)
      cout << output[i];
  }

  cout << endl;

  return 0;
}
