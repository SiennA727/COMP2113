#include <iostream>
#include <fstream> // include file stream header file
#include <cstdlib>
#include <string>
using namespace std;

int main(){
  char filename[80] = "data.txt";
  string path = "/Users/shenao/Desktop/git/COMP2113/Module7";
  ifstream fin;
  fin.open(path+"/"+filename);

  if (fin.fail()) {
    cout << "Error in file opening!" << endl;
    exit(1); // force program terminate
  }

  string name;
  int age;
  double weight;

  fin >> name >> age >> weight;
  fin.close();

  cout << name << ", " << age << ", " << weight << endl;

  return 0;
}
