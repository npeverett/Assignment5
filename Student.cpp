#include <iostream>
#include "Student.h"

using namespace std;

//Empty Class Constructor
Student::Student()
{

}

//Overloaded Student Constructor
Student::Student(Person p, string major, double gpa, int advisorID)
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
