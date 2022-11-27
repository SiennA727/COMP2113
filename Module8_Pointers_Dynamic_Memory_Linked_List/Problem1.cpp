#include <iostream>
using namespace std;

int main(){
  int i1, i2;
  int *p1 = &i1, *p2 = &i2;
  *p1 = 10;
  *p2 = 20;
  cout << *p1 << " " << *p2 << endl;
  p1 = p2;
  cout << *p1 << " " << *p2 << endl;
  *p1 = 30;
  cout << *p1 << " " << *p2 << endl;
}
