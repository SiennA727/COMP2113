# Structs

## Basics

Structure: a collection of one or more member variables

```c++
struct Point {
  double x;
  double y;
}; // end with ;
```

```c++
struct Student{
  int id;
  string name;
  char sex;
};
```

Members of different structures can have the same name.

## Declaration and Initialization

```c++
Point p1;
Student s1,s2;
```
Order of initialization should be same as the structure has been defined:

```c++
Point p1 = {1.0, 2.0};
Student s1 = { 3035123456, “Sze Ka Ka", 'F' };
Student s2 = s1;
```

Cannot initialize with more members, but can do with less:

```c++
Point p2 = {1.0} // x = 1.0 y = 0.0
```

Input from user:

```c++
Point input_point(){
  double x,y;
  cin >> x >> y;
  Point p = {x,y};
  return p;
}
```

## Access member variables

```c++
// dot operator
p1.x *= 2.0;
p2.y++;
// string variable
int l = s1.name.length()
```

## Operator (Assignment = only)

The following expressions are invalid:

```c++
Point pt1 = {1.0, 2.0}, pt2 = {3.0, 5.0};
Point pt3 = pt1 + pt2;
bool b = pt1 > pt2;
bool c = pt1 == pt2;
bool d = pt1 && pt2;
```

Assignment:

```c++
Point p1 = {1.0, 2.0}, p2;
p2.y = p1.x;
p1 = p2;
```

## Nested Structures

```c++
struct Triangle {
  Point p1, p2, p3;
};
Triangle tr1 = {{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}};
Triangle tr2 = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0}; // same!
tr2.p1.x += tr1.p2.x;
tr2.p2 = tr1.p3;
```

## Arrays of Structures

Compare parallel arrays and structure arrays:

Parallel:

A record refers to name[i], subclass[i], ...

```c++
string name[5];
int subclass[5];
int year[5]; int month[5];
int day[5];
double mark[5];
```

Structure:

A record refers to student[i].name, student[i].subclass, ...

```c++
const int MAX = 200;

struct Student_record {
  string name;
  int subclass;
  int year;
  int month;
  int day;
  double mark;
};

Student_record student[MAX];
```

Here, `student` is an array of multiple Student_record structures, `student[2]` is a struct, `student[4].year` accesses value.

To copy student records:

```c++
student[10] = student[5]
```

## Structs and Functions

pass-by-value:

```c++
double point_distance(Point p, Point q) {
  double dx = p.x - q.x;
  double dy = p.y - q.y;
  return sqrt( dx*dx + dy*dy);
}
```

pass-by-reference:

```c++
void swap(Point &p, Point &q){
  Point temp = p;
  p = q;
  q = temp;
}
```

Example: struct Circle

```c++
struct Circle {
  double x, y;
  double r;
};

/// compute area of a circle
double Area ( Circle c ){
  const double PI = 3.14159265;
  return PI * c.r * c.r;
}

/// enlarge a circle (increase radius)
void enlargeCircle ( Circle &c, double increment ){
  c.r += increment;
}

/// check whether a circle overlaps with another
bool overlapCircle( Circle c1, Circle c2 ){
  double dx = c1.x - c2.x;
  double dy = c1.y - c2.y;
  double distance = sqrt(dx*dx + dy*dy);
  return ( distance <= (c1.r + c2.r) );
}
```

## Struct with member Functions

Define function inside structure:

```c++
struct Circle {
  double x, y;
  double r;
  double Area() {
    const double PI = 3.14159265358979323846;
    return PI * r * r;
  }
};
```

Define function outside structure:

```c++
struct Circle {
  double x, y;
  double r;
  double Area();
};

double Circle::Area(){ // scope resolution operator ::
  const double PI = 3.14159265358979323846;
  return PI * r * r;
}
```

When member function is called, the function automaticlly use member variables as arguments. (They should be defined with same name in the structure)

# Classes

## Abstract Data Type (ADT)

ADT: encapsulates both data and methods into a package, so that users can only perform certain operations against the data inside. Implementation details are hidden. (information hiding)

For example:

```c++
string s = "I am mysterious";
cout << s.length() << endl;
cout << s.substr(0, 5) << endl;
cout << s.find("am") << endl;
```

We don't know how the `length`, `substr()`, and `find` methods are defined and implemented.

ADTs are implemented using classes in C++. A class contains data(member variables) and methods(member functions).

```c++
class Point { // keyword for defining a class
  public: // access specifier
    double getX() { return x; } // have access to private variables
    double getY(); { return y; }
    void setCoord(double s, double t){
      x = s;
      y = t;
    }

    double distance(Point &p); // not yet defined
    void translate(Point &p);

private: // can only be accessed by member functions in the same class
  double x;
  double y;
};
```

Member functions can be defined outside the class body:

```c++
double Point::distance(Point &p){
  double dx = p.x - x; // private variables
  double dy = p.y - y;
  return sqrt(dx*dx + dy*dy);
}

void Point::translate(Point &p){
  x += p.x;
  y += p.y;
}
```

# File I/O

## Streams

Two classes: ofstream ifstream

```c++
#include <fstream>  
```

## Write to file

*output_file.cpp:*

```c++
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
```

### Append to file

`fout.open("data.txt",ios::app)`

## Read from file

*input_file.cpp:*

```c++
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
```

### Reading until End Of File (EOF)

Using `while (fin >> x)` which returns false when EOF is reached and there is nothing to read anymore

example:

```c++
while (fin >> x){ sum += x; }
```

### Reading lines from a file

`getline(fin, str)` reads a line and store as string object

example:

```c++
string line;
while (getline(fin, line)){
  cout << line << endl;
}
```

## Input String Stream

### Declaration

`#include <sstream>`: extract a stream of characters from string

```c++
string str;
istringstream iss(str);
```

*input_string_stream*

```c++
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
  string line  = " apple orange banana ", word;

  istringstream line_in(line);

  while ( line_in >> word ) {
    cout << "\"" << word << "\"" << endl;
  }

  return 0;
}
```

## Stream Output Formatting

`endl`: move the insertion point to next lines

### Default floating point notation

default to 6 significant digits

```c++
double a = 1.2345678; // 1.23456
double b = 0.00012345678; // 0.000123457
double c = 1234567.8; // 1.23456e+06
double d = 0.000012345678; // 1.23457e-05
```

### `showpoint` Manipulator

```c++
double e = 12.0;
cout << e << endl; // 12
cout << showpoint << e << endl; // 12.0000
```

### `fixed` and `scientific` Manipulators

```c++
double f = 0.135;
cout << f << endl; // 0.135
cout << fixed << f << endl; // 0.135000
cout << scientific << f << endl; // 1.350000e-01

cout.unsetf(ios_base::floatfield);
cout << f << endl; // 0.135
```

### `setprecision` Manipulator

Set maximum meaningful digits **before and after** the decimal point

```c++
#include <iomanip>
double a = 1.2345678
cout << setprecision(2);
cout << a << endl; // 1.2
```

### `setw`, `setfill` and `left` / `right`

```c++
#include <iomanip>
int x = 12;
string a = "Hello";
double b = 34.567;

cout << fixed << setprecision(2);
cout << setfill('-');

cout << left;
cout << setw(5) << x << setw(8) << a;
cout << setw(6) << b << endl;

cout << right;
cout << setw(5) << x << setw(8) << a;
cout << setw(6) << b << endl;

// output:
// 12345678901234567890
// 12---Hello---34.57-
// ---12---Hello-34.57
```

# Recursion

0! = 1
iterative: n! = n * (n-1) * (n-2) * ... * 2 * 1, if n > 0
recursive: n! = n * (n-1)!, if n > 0

A recursive function:

```c++
int factorial(int num) {
  if (num == 0)
    return 1;
  else
    return num * factorial(num – 1);
}
```
