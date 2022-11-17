// This program finds the GCD of two numbers as one entire program
#include <iostream>
#include "gcd.h"
using namespace std;

int main() {
  int a, b, c;
  cout << "Please input two positive numbers: "; cin >> a >> b;
  c = gcd(a, b);
  cout << "GCD is " << c << endl;
}
