#include <iostream>
using namespace std;

int main(){

  int n;
  double num;
  cin >> n;

  double *numList;
  numList = new double[n];

  for (int i=0; i<n; ++i){
    cin >> num;
    numList[i] = num;
  }

  for (int i=n-1; i>=0; --i){
    cout << numList[i] << endl;
  }
}
