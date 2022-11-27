#include <iostream>
using namespace std;

int main(){

  int SIZE;
  cin >> SIZE;

  int *set = new int[SIZE], *temp = new int[SIZE], *count = new int[SIZE];

  for (int i=0; i<SIZE; i++){
    cin >> set[i];
    temp[i] = set[i];
    count[i] = 0;
  }

  for (int i=0; i<SIZE; i++){
    for (int j=0; j<SIZE; j++){
      if (set[j] == temp[i])
        count[i] += 1;
    }
  }

  int maxIndex = 0;
  for (int i=0; i<SIZE; i++){
    if (count[i] > count[maxIndex])
      maxIndex = i;
  }

  cout << "The mode of the set is " << set[maxIndex];

  delete[] set;
  delete[] temp;

}
