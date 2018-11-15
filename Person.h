#pragma once
#include <iostream>

using namespace std;

class Person
{
public:

  Person();
  Person(int ID, string Name, string Level);
  ~Person();


  int getID();
  string getName();
  string getLevel();
  void displayMenu();


protected:
  int ID;
  string Name;
  string Level;

};
