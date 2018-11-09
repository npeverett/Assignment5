#pragma once
#include <iostream>
#include "DoubleLL.h"
#include "Person.h"

using namespace std;

class Faculty : Person
{
public:
  Faculty();
  Faculty(Person p, string Department, DoubleLL<int> AdviseeIDs);
  ~Faculty();

protected:
  Person person;
  string Department;
  DoubleLL<int> AdviseeIDs;
};
