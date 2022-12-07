#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<iomanip>
using namespace std;
// Define the classes and member functions here

struct Student {
	int id;
	string name;
	Student() {
		id = 0;
		name = "invalid";
	};
	Student(int inputid, string inputname) {
		id = inputid;
		name = inputname;
	};
};

class Table {
public:
	void InsertStudent(Student x, int y);
	void SearchbyID(int x);
	void SearchbyGrade(int y);
	void Statistics();
	void PrintAll();
	// You can add more member functions to help your implementation.
private:
	/* The data type is decided by you records; */ 
	map<Student, int> Record;
	map<Student, int>::iterator itr;
	vector<Student> unsorted;
	vector<int> grades;
	int maxGrade;
	int minGrade;
	double medianGrade;
};

bool operator<(const Student&a, const Student&b) {
	return (a.id < b.id);
}

//insert one record in to the map
void Table::InsertStudent(Student x, int y) {
	if (Record.count(x) > 0)
		cout << "Student exists." << endl;
	else {
		Record[x] = y;
	}
}

//return the name and grade of the student with id x
void Table::SearchbyID(int x) {
	for (itr = Record.begin(); itr != Record.end(); itr++){
		if ( (*itr).first.id == x ) {
			cout << (*itr).first.name << endl;
			cout << (*itr).second << endl;
			break;
		}
	}
	if (itr == Record.end())
		cout << "No such student." << endl;
}

//return the id and name of the student with grade y
void Table::SearchbyGrade(int y) {
	for (itr = Record.begin(); itr != Record.end(); itr++){
		if ( (*itr).second == y ){
			unsorted.push_back((*itr).first);
		}
	}
	if (unsorted.size() == 0)
		cout << "No such record." << endl;
	else {
		sort(unsorted.begin(), unsorted.end());
		for (int i=0; i < unsorted.size(); i++)
			cout << unsorted[i].id << " " << unsorted[i].name << endl;
	}
	unsorted.clear();
}

void Table::Statistics() {
	// To be implemented
	for (itr = Record.begin(); itr != Record.end(); itr++){
		grades.push_back((*itr).second);
	}
	sort(grades.begin(), grades.end());
	maxGrade = grades[grades.size()-1];
	minGrade = grades[0];
	if (grades.size() % 2 == 0)
		medianGrade = (double) (grades[grades.size()/2] + grades[grades.size()/2-1]) / 2;
	else
		medianGrade = grades[(grades.size()-1)/2];
	cout << "Maximum " << maxGrade << endl;
	cout << "Median " << medianGrade << endl;
	cout << "Minimum " << minGrade << endl;
	grades.clear();
}

//Print all records in the accending order of id
void Table::PrintAll() {
	for (itr = Record.begin(); itr != Record.end(); itr++)
		cout << (*itr).first.id << ' ' << (*itr).first.name << ' ' << (*itr).second << endl;
}


int main() {
	Table t;
	string command;
	int id;
	string name;
	int grade;
	
	while (cin >> command) {
		if (command == "InsertStudent") {
			cin >> id >> name >> grade;
			Student s = {id, name};
			t.InsertStudent(s, grade);
		}
		else if (command == "SearchbyID") {
			cin >> id;
			t.SearchbyID(id);
		}
		else if (command == "SearchbyGrade") {
			cin >> grade;
			t.SearchbyGrade(grade);
		}
		else if (command == "PrintAll") {
			t.PrintAll();
		}
		else if (command == "Statistics") {
			t.Statistics();
		}
		else if (command == "exit") {
			break;
		}
	}

	return 0;
}