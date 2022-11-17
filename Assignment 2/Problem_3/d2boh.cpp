// d2boh.cpp

#include <iostream>
#include <cmath>
#include "d2boh.h"
using namespace std;

int decimal_to_binary(int input, int output[10]) {

  int digit = 1;

  while (pow(2, digit) < input)
    digit += 1;
  if (pow(2, digit) == input)
    digit += 1;

  for (int i = digit-1; i>=0; --i){
    output[i] = input % 2;
    input = (input - output[i]) / 2 ;
  }

  return digit;

}


int decimal_to_octal(int input, int output[10]) {

  int digit = 1;

  while (pow(8, digit) < input)
    digit += 1;
  if (pow(8, digit) == input)
    digit += 1;

  for (int i = digit-1; i>=0; --i){
    output[i] = input % 8;
    input = (input - output[i]) / 8 ;
  }

  return digit;

}

int decimal_to_hexadecimal(int input, char output[10]) {

  int digit = 1;

  while (pow(16, digit) < input)
    digit += 1;
  if (pow(16, digit) == input)
    digit += 1;

  for (int i = digit-1; i>=0; --i){
    int remainder = input % 16;
    if (remainder > 9)
      output[i] = (char) remainder + 55;
    else
      output[i] = remainder + '0';
    input = (input - remainder) / 16 ;
  }

  return digit;
}
