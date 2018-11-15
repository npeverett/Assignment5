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

bool Faculty::operator!= (const Faculty& fc) const
{
  return ID != fc.ID;
}

bool Faculty::operator== (const Faculty& fc) const
{
  return ID == fc.ID;
}

bool Faculty::operator< (const Faculty& fc) const
{
  return ID < fc.ID;
}

bool Faculty::operator> (const Faculty& fc) const
{
  return ID > fc.ID;
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
