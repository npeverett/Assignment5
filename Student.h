#pragma once
#include <iostream>
#include "Person.h"

using namespace std;

class Student : Person
{
public:
  Student();
  Student(Person* p, string Major, double GPA, int AdvisorID);
  ~Student();

  bool operator!=(const Student& st) const;
  bool operator==(const Student& st) const;
  bool operator>(const Student& st) const;
  bool operator<(const Student& st) const;

  void printStudentInfo(const Student* st);
  string printFacultyInfo(const Student* st);
  int createRandomID();
  int getFacultyID();
  void setFacultyID(Student* st, int newID);
protected:

  Person* person;
  string Major;
  double GPA;
  int AdvisorID;
};
