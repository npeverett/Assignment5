#include <iostream>
#include "Error.h"
#include "Queue.h"
#include "BST.h"

using namespace std;

//Empty Class Constructor
Error::Error()
{

}

//Overloaded Error Constructor
Error::Error(ErrorType error, int prevID)
{
  type = error;
  lastID = prevID;
}

//Class Destructor
Error::~Error()
{

}

void Error::addError(Error error)
{
  errorQueue -> enque(error);
}

void Error::Undo()
{
  Error temp = errorQueue -> front();
  if (temp.type == Insertion)
  {
    errorQueue -> deque();
    //Need to remove from BST
  }

  if (temp.type == Deletion)
  {
    errorQueue -> deque();
    //Need to add to BST
  }
}
