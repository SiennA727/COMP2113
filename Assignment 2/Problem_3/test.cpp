#include <iostream>
#include <cstdlib>
#include "d2boh.h"
using namespace std;

int main(){
  for (int j=1; j<101; ++j){
    int digit, output[10];
    digit = decimal_to_binary(j, output);
    for (int i=0; i<digit; ++i)
      cout << output[i];
    cout << endl;
  }
  for (int j=1; j<101; ++j){
    int digit, output[10];
    digit = decimal_to_octal(j, output);
    for (int i=0; i<digit; ++i)
      cout << output[i];
    cout << endl;
  }
  for (int j=1; j<101; ++j){
    int digit;
    char output[10];
    digit = decimal_to_hexadecimal(j, output);
    for (int i=0; i<digit; ++i)
      cout << output[i];
    cout << endl;
  }
}
