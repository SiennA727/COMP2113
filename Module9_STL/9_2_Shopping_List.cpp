#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(vector<string> v){
  vector<string>::iterator itr;
  if (v.size() != 0){
    cout << "Items: ";
    for (itr=v.begin(); itr<v.end()-1; ++itr)
      cout << *itr << ", ";
    cout << *(v.end()-1) << endl;
  }
  else
    cout << "Items: " << endl;
}

int main(){
  vector<string> shopping_list;
  vector<string>::iterator itr;

  // 1. Create an empty vector. Print it.
  print(shopping_list);

  // 2. Append the items, "eggs," "milk," "sugar," "chocolate," and "flour" to the list. Print it.
  shopping_list.push_back("eggs");
  shopping_list.push_back("milk");
  shopping_list.push_back("sugar");
  shopping_list.push_back("chocolate");
  shopping_list.push_back("flour");
  print(shopping_list);

  // 3. Remove the last element from the vector. Print it.
  shopping_list.pop_back();
  print(shopping_list);

  // 4. Append the item, "coffee" to the vector. Print it.
  shopping_list.push_back("coffee");
  print(shopping_list);

  // 5. Write a loop that searches for the item, "sugar" and replaces it with "honey." Print the vector.
  for (itr=shopping_list.begin(); itr!=shopping_list.end(); ++itr){
    if (*itr == "sugar"){
      *itr = "honey";
      break;
    }
  }
  print(shopping_list);

  // 6. Write a loop that searches for the item, "milk," and then remove it from the vector. Print the vector.
  for (itr=shopping_list.begin(); itr!=shopping_list.end();++itr){
    if (*itr == "milk"){
      *itr = *(itr+1);
      *(itr+1) = "milk";
    }
  }
  shopping_list.pop_back();
  print(shopping_list);
}
