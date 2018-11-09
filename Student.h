#pragma once
#include <iostream>
#include "Person.h"

using namespace std;

class Student : Person
{
public:
  Student();
  Student(Person p, string Major, double GPA, int AdvisorID);
  ~Student();

protected:

  Person person;
  string Major;
  double GPA;
  int AdvisorID;
};
