#include <iostream>
using namespace std;

string* addEntry(string *array, int &size, string newEntry){
  string *temp;
  temp = new string[size];
  for (int i=0; i<size; ++i)
    temp[i] = array[i];
  delete [] array;

  array = new string[size+1];
  for (int i=0; i<size; ++i){
    array[i] = temp[i];
  }
  delete [] temp;

  array[size] = newEntry;
  size++;
  return array;
}

string* deleteEntry(string *array, int &size, string entryToDelete){
  for (int i=0; i<size; ++i){

    if (array[i] == entryToDelete){

      string *temp;
      temp = new string[size];
      for (int j=0; j<size; ++j){
        temp[j] = array[j];
      }
      delete [] array;

      array = new string[size-1];
      for (int j=0; j<i; ++j){
        array[j] = temp[j];
      }
      for (int j=i; j<size-1; ++j){
        array[j] = temp[j+1];
      }
      delete [] temp;

      size--;
      return array;
    }
  }

  return array;
}

int main() {
  string *array;
  int size = 5;
  array = new string[size];
  array[0] = "a";
  for (int i=1; i<size; ++i){
    array[i] = array[i-1]+"a";
  }

  *array = addEntry(array, &size, "add");
  for (int i=0; i<size; ++i)
    cout << array[i] << " ";

  *array = deleteEntry(array, &size, "aaa");
  for (int i=0; i<size; ++i)
    cout << array[i] << " ";

  return 0;
}
