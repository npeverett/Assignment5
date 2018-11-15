#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Student.h"

using namespace std;

//Empty Class Constructor
Student::Student()
{

}

//Overloaded Student Constructor
Student::Student(Person* p, string major, double gpa, int advisorID)
{
  person = p;
  Major = major;
  GPA = gpa;
  AdvisorID = advisorID;
}

//Student Destructor
Student::~Student()
{

}

bool Student::operator!= (const Student& st) const
{
  return ID != st.ID;
}

bool Student::operator== (const Student& st) const
{
  return ID == st.ID;
}

bool Student::operator< (const Student& st) const
{
  return ID < st.ID;
}

bool Student::operator> (const Student& st) const
{
  return ID > st.ID;
}

void Student::printStudentInfo(const Student* st)
{
  cout << "ID: " << st -> person -> getID()<< endl;
  cout << "Name: " << st -> person -> getName() << endl;
  cout << "Level: " << st -> person -> getLevel() << endl;
  cout << "Major: " << st -> Major << endl;
  cout << "GPA: " << st -> GPA << endl;
  cout << "Advisor ID: " << st -> AdvisorID << endl;
}

//Compiler does not recognize Type during compile time, so BST must have
//printFacultyInfo method in Student class, and vice versa in Faculty class (NEVER CALLED)
void Student::printFacultyInfo(const Student* st)
{

}

int Student::createRandomID()
{
  //Generate random seed
  srand(time(NULL));

  //Generate random ID number
  int id =  500000 + rand() % 49999 + 1;

  return id;
}
