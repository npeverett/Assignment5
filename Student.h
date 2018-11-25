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

  bool operator!=(Student* st);
  bool operator!= (int value);
  bool operator==(Student* st);
  bool operator>(Student* st);
  bool operator<(Student* st);
  bool operator< (int v);


  void printStudentInfo(const Student* st);
  string printFacultyInfo(const Student* st);
  int createRandomID();
  int getFacultyID();
  void setFacultyID(Student* st, int newID);

  Person* person;
protected:

  //Person* person;
  string Major;
  double GPA;
  int AdvisorID;
};
