#pragma once
#include <iostream>
#include "DoubleLL.h"
#include "Person.h"

using namespace std;

class Faculty : Person
{
public:
  Faculty();
  Faculty(Person* p, string Department, DoubleLL<int> AdviseeIDs);
  ~Faculty();

  bool operator!=(Faculty* fc);
  bool operator==(Faculty* fc);
  bool operator>(Faculty* fc);
  bool operator<(Faculty* fc);

  void printFacultyInfo(Faculty* fc);
  string printStudentInfo(const Faculty* fc);

  int createRandomID();
  void removeStudent(Faculty* fc, int studentID);

  Person* person;
  DoubleLL<int> AdviseeIDs;
protected:
  string Department;
};
