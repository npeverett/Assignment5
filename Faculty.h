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

  bool operator!=(const Faculty& fc) const;
  bool operator==(const Faculty& fc) const;
  bool operator>(const Faculty& fc) const;
  bool operator<(const Faculty& fc) const;

  void printFacultyInfo(Faculty* fc);
  void printStudentInfo(const Faculty* fc);

  int createRandomID();

protected:
  Person* person;
  string Department;
  DoubleLL<int> AdviseeIDs;
};
