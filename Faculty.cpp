#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <time.h>
#include "Faculty.h"
#include "DoubleLL.h"

using namespace std;

//Empty Class Constructor
Faculty::Faculty()
{

}

//Overloaded Faculty Constructor
Faculty::Faculty(Person* p, string department, DoubleLL<int> adviseeIDs)
{
  person = p;
  Department = department;
  AdviseeIDs = adviseeIDs;
}

//Faculty Destructor
Faculty::~Faculty()
{

}

// Does not equal operator overload
bool Faculty::operator!= (Faculty* fc)
{
  return person -> getID() != fc -> person -> getID();
}

bool Faculty::operator!= (int value)
{
  return person -> getID() != value;
}

// Equals operator overload
bool Faculty::operator== (Faculty* fc)
{
  return person -> getID() == fc -> person -> getID();
}


// Less than operator overload
bool Faculty::operator< (Faculty* fc)
{
  return person -> getID() < fc -> person -> getID();
}

// Greater than operator overload
bool Faculty::operator> (Faculty* fc)
{
  return person -> getID() > fc -> person -> getID();
}


void Faculty::printFacultyInfo(Faculty* fc)
{
  cout << "ID: " << fc -> person -> getID() << endl;
  cout << "Name: " << fc -> person -> getName() << endl;
  cout << "Level: " << fc -> person -> getLevel() << endl;
  cout << "Department: " << fc -> Department << endl;
  cout << "Students: " << endl;
  fc -> AdviseeIDs.printList();
}

//Compiler does not recognize Type during compile time, so BST must have
//printStudentInfo method in Faculty class, and vice versa in Student class (NEVER CALLED)
string Faculty::printStudentInfo(const Faculty* fc)
{
  return "";
}

int Faculty::createRandomID()
{
  //Generate random seed
  srand(time(NULL));

  //Generate random ID number
  int id = 10000 + rand() % 9999 + 1;

  return id;
}
