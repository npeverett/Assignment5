#include <iostream>
#include "Person.h"

using namespace std;

//Empty Class Constructor
Person::Person()
{

}

//Overloaded Person Constructor
Person::Person(int id, string name, string level)
{
  ID = id;
  Name = name;
  Level = level;
}

//Person Destructor
Person::~Person()
{

}


void Person::displayMenu()
{
  cout << endl;
  cout << "UNIVERSITY DATABASE SYSTEM" << endl;
  cout << "==========================" << endl;
  cout << endl;

  cout << "1. Print all students and their information" << endl;
  cout << "2. Print all faculty and their information" << endl;
  cout << "3. Find and display student information given student id" << endl;
  cout << "4. Find and display faculty information given faculty id" << endl;
  cout << "5. Given a student's ID, print the name and info of their faculty advisor" << endl;
  cout << "6. Given a faculty's ID, print ALL the names and info of their advisees" << endl;
  cout << endl;
  cout << "7. Add new student" << endl;
  cout << "8. Delete a student given ID" << endl;
  cout << "9. Add a new faculty member" << endl;
  cout << "10. Delete a faculty member given ID" << endl;
  cout << endl;
  cout << "11. Change a student's advisor" << endl;
  cout << "12. Remove an advisee from a faculty advisor given ID" << endl;
  cout << endl;
  cout << "13. Rollback (Undo)" << endl;
  cout << "14. Exit" << endl;
  cout << endl;
}
