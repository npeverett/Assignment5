#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include "BST.h"
#include "DoubleLL.h"
#include "Person.h"
#include "Student.h"
#include "Faculty.h"

using namespace std;


int main()
{
  BST<Student*> studentTable;
  BST<Faculty*> facultyTable;


  Student s;
  Faculty f;
  Person p;

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
      if (studentTable.isEmpty())
      {
        cout << "Student database is empty" << endl;
        continue;
      }

      int id = 0;
      cout << endl;
      cout << "Please enter student ID number: ";
      cin >> id;
      cout << endl;

      if (studentTable.contains(id))
      {
        Student* temp = studentTable.find(id);
        temp -> printStudentInfo(temp);
      }

      else
      {
        cout << "Could not find student with given ID" << endl;
      }
      continue;
    }
    if (option == 4)
    {
      if (facultyTable.isEmpty())
      {
        cout << "Faculty database is empty" << endl;
        continue;
      }

      int id = 0;
      cout << endl;
      cout << "Please enter faculty ID number: ";
      cin >> id;
      cout << endl;

      Faculty* temp = facultyTable.find(id);
      temp -> printFacultyInfo(temp);

      continue;
    }

    if (option == 5)
    {
      int id = 0;
      cout << endl;
      cout << "Please enter student ID number: ";
      cin >> id;
      cout << endl;

      if (studentTable.contains(id))
      {
        Student* tempS = studentTable.find(id);
        int idF = tempS -> getFacultyID();
        Faculty* tempF = facultyTable.find(idF);
        tempF -> printFacultyInfo(tempF);
      }
      else
      {
        cout << "No student found with given ID" << endl;
        sleep(2);
        continue;
      }

      continue;
    }

    if (option == 6)
    {
      int id = 0;
      cout << "Please enter faculty ID number: ";
      cin >> id;
      if (facultyTable.contains(id))
      {
        Faculty* temp = facultyTable.find(id);
        if (temp -> AdviseeIDs.size() == 0)
        {
          cout << "No students have been assigned to this faculty member" << endl;
          sleep(2);
          continue;
        }

        for (int i = 0; i < temp -> AdviseeIDs.size(); i++)
        {
          int currID = temp -> AdviseeIDs.getPositionData(i);
          Student* tempStudent = studentTable.find(currID);
          tempStudent -> printStudentInfo(tempStudent);
          cout << endl;
        }

      }
      else
      {
        cout << "No faculty found with given ID" << endl;
        sleep(2);
        continue;
      }

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

      if (facultyTable.contains(facAdvisorStu))
      {
        Faculty* temp = facultyTable.find(facAdvisorStu);
        temp -> AdviseeIDs.insertFront(personStu -> getID());
      }
      else
      {
        cout << "No faculty found with given ID, terminating current student..." << endl;
        sleep(2);
        continue;
      }

      Student* newStudent =  new Student(personStu, majorStu, gpaStu, facAdvisorStu);
      studentTable.insert(newStudent);

      cout << nameStu << " has successfully been added." << endl;
      sleep(2);
      continue;
    }

    if (option == 8)
    {
      int id = 0;
      string name = "";

      cout << endl;
      cout << "Please enter student ID number: ";
      cin >> id;
      cout << endl;

      if (studentTable.contains(id))
      {
        Student* temp = studentTable.find(id);
        Faculty* tempFac = facultyTable.find(temp -> getFacultyID());

        name = temp -> person -> getName();
        int tempID = temp -> person -> getID();

        cout << "5.0" << endl;
        tempFac -> AdviseeIDs.remove(tempID);
        cout << "5.1" << endl;
        studentTable.deleteNode(temp);
      }
      else
      {
        cout << "No student found with given ID" << endl;
        sleep(2);
        continue;
      }

      cout << name << " has successfully been removed." << endl;
      sleep(2);
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

      cout << "Please enter faculty last name: ";
      cin >> lname;

      nameFac = fname + " " + lname;

      cout << "Please enter faculty level: ";
      cin >> levelFac;

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
      string name = "";

      cout << "Please enter faculty ID number: ";
      cin >> id;
      cout << endl;

      if (facultyTable.contains(id))
      {
        Faculty* temp = facultyTable.find(id);
        name = temp -> person -> getName();
        facultyTable.deleteNode(temp);
      }
      else
      {
        cout << "No faculty found with given ID" << endl;
        sleep(2);
        continue;
      }

      cout << name << " has been successfully removed." << endl;
      sleep(2);
      continue;
    }

    if (option == 11)
    {
      Student* tempS;
      int idS = 0;
      int idF = 0;

      cout << endl;
      cout << "Please enter student ID number: ";
      cin >> idS;
      cout << endl;

      cout << "Please enter NEW faculty ID number: ";
      cin >> idF;
      cout << endl;

      if (studentTable.contains(idS))
      {
        tempS = studentTable.find(idS);
      }
      else
      {
        cout << "No student found with given ID" << endl;
        sleep(2);
        continue;
      }

      if (facultyTable.contains(idF))
      {
        Faculty* tempF = facultyTable.find(idF);
        tempS -> setFacultyID(tempS, tempF -> person -> getID());
      }
      else
      {
        cout << "No faculty found with given ID" << endl;
        sleep(2);
        continue;
      }

      cout << "Student advisor successfully updated." << endl;
      sleep(2);
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

      if (studentTable.contains(idS) == false)
      {
        cout << "No student found with given ID" << endl;
        sleep(2);
        continue;
      }

      if (facultyTable.contains(idF) == false)
      {
        cout << "No faculty found with given ID" << endl;
        sleep(2);
        continue;
      }

      else
      {
        Faculty* temp = facultyTable.find(idF);
        temp -> removeStudent(temp, idS);
      }


      cout << "Student successfully removed from advisor list." << endl;
      sleep(2);
      continue;
    }

    if (option == 13)
    {
      cout << "This method has not been implemented yet" << endl;
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
      sleep(2);
      continue;
    }
  }
  return 1;
}
