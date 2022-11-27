#include <iostream>
#include <string>
#include <list>
using namespace std;

class Record{
public:
  string name;
  string major;
  int number;
};

int main(){
  list<Record> book;
  string command; Record r;

  while ( cin >> command){
    // Add
    if (command == "Add") {
      cin >> r.name >> r.major >> r.number;
      book.push_back(r);
      cout << "Added Successfully" << endl;
    }
    // Search
    else if (command == "Search") {
      cin >> r.name >> r.major;
      if (book.size() == 0)
        cout << "No Record found" << endl;
      else {
        for (int i=0; i<book.size(); ++i){
          if (book.front().name == r.name && book.front().major == r.major){
            cout << "Student Number:" << book.front().number << endl;
            break;
          }
          else if (i==book.size()-1)
            cout << "No Record found" << endl;
          else {
            book.push_back(book.front());
            book.pop_front();
          }
        }
      }
    }
    // Quit
    else
      cout << "Bye" << endl;
  }
}
