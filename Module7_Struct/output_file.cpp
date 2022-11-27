#include <iostream>
#include <fstream> // include file stream header file
#include <cstdlib>
#include <string>
using namespace std;

int main(){
  ofstream fout; // create an ofstream object
  string path = "/Users/shenao/Desktop/git/COMP2113/Module7";
  string filename = "data.txt";
  fout.open(path + "/" + filename); // connect to an external file
  // or replace above by ofstream fout ("data.txt")

  if (fout.fail()) {
    cout << "Error in file opening!" << endl;
    exit(1); // force program terminate
  }

  string name = "Peter";
  int age  = 30;
  double weight = 130.5;

  fout << name << " " << age << " " << weight << endl;
  fout.close(); // disconnect

  return 0;
}
