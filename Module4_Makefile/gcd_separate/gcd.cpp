#include <iostream>
#include "gcd.h" // header file
using namespace std;

int gcd(int a, int b){
  while(a != b) {
    if (a > b){
      a -= b;} else {
      b -= a; }
  }
  return a;
}
