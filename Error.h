#include <iostream>
#include "Queue.h"

using namespace std;

;


class Error
{
public:
  enum ErrorType { Insertion, Deletion };

  Error();
  Error(ErrorType error, int prevID);
  ~Error();

  void addError(Error error);
  void Undo();

private:
  Queue<Error>* errorQueue;
  ErrorType type;
  int lastID;
};
