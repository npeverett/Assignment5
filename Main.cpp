#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "BST.h"
#include "DoubleLL.h"
#include "Person.h"
#include "Student.h"
#include "Faculty.h"
#include "Error.h"

using namespace std;


int main()
{
  BST<Student*> studentTable;
  BST<Faculty*> facultyTable;


  Student s;
  Faculty f;
  Person p;
  Error e;

  int timer = 0;
  while (true)
  {
    //Timer used so that screen isn't cleared during first run
    if (timer > 0){
      //cout << string( 50, '\n');
    }
    timer++;

    //Option for user input
    int option = 0;
    p.displayMenu();
    cin >> option;

    if (option == 1)
    {
      studentTable.printTree();
      continue;
    }

    if (option == 2)
    {
      facultyTable.printTree();
      continue;
    }

    if (option == 3)
    {
      int id = 0;
      cout << endl;
      cout << "Please enter student ID number: ";
      cin >> id;
      cout << endl;

      continue;
    }
    if (option == 4)
    {
      int id = 0;
      cout << endl;
      cout << "Please enter faculty ID number: ";
      cin >> id;
      cout << endl;

      continue;
    }

    if (option == 5)
    {
      int id = 0;
      cout << endl;
      cout << "Please enter student ID number: ";
      cin >> id;
      cout << endl;

      continue;
    }

    if (option == 6)
    {
      int id = 0;
      cout << "Please enter faculty ID number: ";
      cin >> id;
      cout << endl;

      continue;
    }

    if (option == 7)
    {
      string nameStu;
      string fname;
      string lname;
      string levelStu;
      string majorStu;
      int idStu;
      double gpaStu;
      int facAdvisorStu;

      cout << endl;
      cout << "Please enter student first name: ";
      cin >> fname;

      cout << "Please enter student last name: ";
      cin >> lname;

      nameStu = fname + " " + lname;

      cout << "Please enter student level: ";
      cin >> levelStu;

      Person* personStu = new Person(s.createRandomID(), nameStu, levelStu);

      cout << "Please enter student major (NO WHITESPACE) : ";
      cin >> majorStu;


      cout << "Please enter student GPA: ";
      cin >> gpaStu;


      cout << "Please enter faculty advisor ID: ";
      cin >> facAdvisorStu;
      cout << endl;

      Student* newStudent =  new Student(personStu, majorStu, gpaStu, facAdvisorStu);
      studentTable.insert(newStudent);

      cout << nameStu << " has successfully been added." << endl;
      sleep(2);
      continue;
    }

    if (option == 8)
    {
      int id = 0;
      cout << endl;
      cout << "Please enter student ID number: ";
      cin >> id;
      cout << endl;

      studentTable.find(id);
      continue;
    }

    if (option == 9)
    {
      string nameFac;
      string fname;
      string lname;
      string levelFac;
      string deptFac;
      DoubleLL<int> adviseeList;

      cout << endl;
      cout << "Please enter faculty first name: ";
      cin >> fname;
      cout << endl;

      cout << "Please enter faculty last name: ";
      cin >> lname;

      nameFac = fname + " " + lname;

      cout << "Please enter faculty level: ";
      cin >> levelFac;
      cout << endl;

      //Create new person with random ID
      Person* personFac = new Person(f.createRandomID(), nameFac, levelFac);

      cout << "Please enter faculty department: ";
      cin >> deptFac;
      cout << endl;


      Faculty* newFaculty = new Faculty(personFac, deptFac, adviseeList);
      facultyTable.insert(newFaculty);

      cout << nameFac << " has successfully been added." << endl;
      sleep(2);
      continue;
    }

    if (option == 10)
    {
      int id = 0;
      cout << "Please enter faculty ID number: ";
      cin >> id;
      cout << endl;

      continue;
    }

    if (option == 11)
    {
      int idS = 0;
      int idF = 0;

      cout << endl;
      cout << "Please enter student ID number: ";
      cin >> idS;
      cout << endl;

      cout << "Please enter NEW faculty ID number: ";
      cin >> idF;
      cout << endl;

      continue;
    }

    if (option == 12)
    {
      int idS = 0;
      int idF = 0;

      cout << endl;
      cout << "Please enter student ID number: ";
      cin >> idS;
      cout << endl;

      cout << "Please enter faculty ID number: ";
      cin >> idF;
      cout << endl;

      continue;
    }

    if (option == 13)
    {


      continue;
    }

    if (option == 14)
    {
      cout << endl;
      cout << "Exiting... " << endl;
      break;
    }

    else
    {
      cout << "Please enter a valid choice" << endl;
      continue;
    }
  }
  return 1;
}
