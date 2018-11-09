#include <iostream>
#include "Faculty.h"
#include "DoubleLL.h"

using namespace std;

//Empty Class Constructor
Faculty::Faculty()
{

}

//Overloaded Faculty Constructor
Faculty::Faculty(Person p, string department, DoubleLL<int> adviseeIDs)
{
  person = p;
  Department = department;
  AdviseeIDs = adviseeIDs;
}

//Faculty Destructor
Faculty::~Faculty()
{

}
