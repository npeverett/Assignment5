#pragma once
#ifndef BST_H
#define BST_H
#define MARKER -1
#include <iostream>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <stdio.h>
#include "Student.h"
#include "Faculty.h"

using namespace std;

//TreeNode CLASS
template <class T>
class TreeNode
{
public:

  TreeNode();
  TreeNode(T v);
  ~TreeNode();

  T value;
  TreeNode<T>* left;
  TreeNode<T>* right;
};

//Empty Class Constructor
template <class T>
TreeNode<T>::TreeNode()
{
  left = NULL;
  right = NULL;
}

//Overloaded TreeNode Constructor
template <class T>
TreeNode<T>::TreeNode(T v)
{
  left = NULL;
  right = NULL;
  value = v;
}

//TreeNode Destructor
template <class T>
TreeNode<T>::~TreeNode()
{

}


//Binary Search Tree CLASS
template <class T>
class BST
{
public:

  BST();

  virtual ~BST();
  void deleteTree(TreeNode<T>* node);

  void insert(T value);
  bool deleteNode(T value);
  bool contains(T value);
  bool contains(int v);
  bool isEmpty();

  T find(int v);
  TreeNode<T>* getSuccessor(TreeNode<T>* d);
  T getRoot();

  void printTree();
  void recPrint(TreeNode<T>* node);

  void serialize(TreeNode<T>* node);
  void deserialize(string data);
private:
  TreeNode<T>* root;
};

//BST Constructor
template <class T>
BST<T>::BST()
{
  root = NULL;
}

//BST Destructor
template <class T>
BST<T>::~BST()
{
  if (isEmpty())
  {
    return;
  }

  deleteTree(root);
}

//Method to delete all nodes of Tree
template <class T>
void BST<T>::deleteTree(TreeNode<T>* node)
{
  if (node != NULL)
  {
    if (node -> left != NULL)
    {
      deleteTree(node -> left);
    }

    if (node -> right != NULL)
    {
      deleteTree(node -> right);
    }

    delete node;
  }
}


//Method to check if Tree is empty
template <class T>
bool BST<T>::isEmpty()
{
  return (root == NULL);
}


//Method to insert new node into the Tree
template <class T>
void BST<T>::insert(T v)
{
  TreeNode<T>* node = new TreeNode<T>(v);

  if (isEmpty())
  {
    root = node;
  }

  else
  {
    TreeNode<T>* current = root;
    TreeNode<T>* parent = NULL;

    while (true)
    {
      parent = current;

      if (*v < current -> value)
      {
        current = current -> left;
        if (current == NULL)
        {
          parent -> left = node;
          break;
        }
      }

      else
      {
        current = current -> right;
        if (current == NULL)
        {
          parent -> right = node;
          break;
        }
      }
    }
  }
}


//Method to delete a node given its value
template <class T>
bool BST<T>::deleteNode(T v)
{

  //If tree does not contain the value
  if (!contains(v))
  {
    return false;
  }

  //If the tree is empty
  if (isEmpty())
  {
    return false;
  }

  TreeNode<T>* curr = root;
  TreeNode<T>* parent = NULL;
  bool isLeft;

  while (curr -> value != v)
  {

    parent = curr;

    //If less than... go left
    if (v < curr -> value)
    {
      isLeft = true;
      curr = curr -> left;
      continue;
    }

    //If greater than... go right
    if (v > curr -> value)
    {
      isLeft = false;
      curr = curr -> right;
      continue;
    }

    //Otherwise... must be null, node doesn't exist
    if (curr == NULL)
    {
      return false;
    }
  }

  //Case 1: Node is a leaf
  if (curr -> left == NULL && curr -> right == NULL)
  {
    if (curr == root)
    {
      root = NULL;
    }

    else if (isLeft)
    {
      parent -> left = NULL;
    }

    else
    {
      parent -> right = NULL;
    }
  }


  //Case 2: Node has one left child
  else if (curr -> right == NULL)
  {
    if (curr == root)
    {
      root = curr -> left;
    }

    else if (isLeft)
    {
      parent -> left = curr -> left;
    }

    else
    {
      parent -> right = curr -> left;
    }
  }

  //Case 3: Node has one right child
  else if (curr -> left == NULL)
  {
    if (curr == root)
    {
      root = curr -> right;
    }

    else if (isLeft)
    {
      parent -> left = curr -> right;
    }

    else
    {
      parent -> right = curr -> right;
    }
  }

  //Case 4: Node has two children
  else
  {
    TreeNode<T>* successor = getSuccessor(curr);
    if (curr == root)
    {
      root = successor;
    }

    else if (isLeft)
    {
      parent -> left = successor;
    }

    else
    {
      parent -> right = successor;
    }

    successor -> left = curr -> left;
  }

  return true;
}


//Method to get the successor of a node (left most node of right child)
template <class T>
TreeNode<T>* BST<T>::getSuccessor(TreeNode<T>* d)
{
  TreeNode<T>* sp = d;
  TreeNode<T>* successor = d;
  TreeNode<T>* curr = d -> right;

  while (curr != NULL)
  {
    sp = successor;
    successor = curr;
    curr = curr -> left;
  }

  if (successor != d -> right)
  {
    sp -> left = successor -> right;
    successor -> right = d -> right;
  }

  return successor;
}

template <class T>
T BST<T>::getRoot()
{
  return root -> value;
}

//Method to see if a value is in the Tree
template <class T>
bool BST<T>::contains(T v)
{
  if (isEmpty())
  {
    return false;
  }

  else
  {
    TreeNode<T>* curr = root;
    while (*curr -> value != v)
    {

      if (isEmpty())
      {
        return false;
      }

      if (v < curr -> value)
      {
        curr = curr -> left;
      }

      else
      {
        curr = curr -> right;
      }

      if (curr == NULL)
      {
        return false;
      }
    }
  }

  return true;
}

//Overloaded 'contains' to check for ID instead instead of T object
template <class T>
bool BST<T>::contains(int v)
{
  if (isEmpty())
  {
    return false;
  }

  else
  {
    TreeNode<T>* curr = root;
    while (curr -> value -> person -> getID() != v)
    {

      if (isEmpty())
      {
        return false;
      }

      if (v < curr -> value -> person -> getID())
      {
        curr = curr -> left;
      }

      else
      {
        curr = curr -> right;
      }

      if (curr == NULL)
      {
        return false;
      }
    }
  }

  return true;
}

template <class T>
T BST<T>::find(int v)
{
  if (isEmpty())
  {
    cout << "Tree is empty" << endl;
  }
  else
  {
    TreeNode<T>* curr = root;
    while (curr -> value -> person -> getID() != v)
    {
      if (v < curr -> value -> person -> getID())
      {
        curr = curr -> left;
      }

      else
      {
        curr = curr -> right;
      }

      if (curr == NULL)
      {
        break;
      }
    }
    return curr -> value;
  }
}

//Method to print nodes in tree (inOrder)
template <class T>
void BST<T>::recPrint(TreeNode<T>* node)
{
  if (isEmpty())
  {
    cout << "Tree is empty" << endl;
    return;
  }

  if (node == NULL)
  {
    return;
  }

  //If node value is a student, print respective student info
  if (typeid(node -> value).name() == typeid(Student*).name())
  {
    recPrint(node -> left);
    node -> value -> printStudentInfo(node -> value);
    cout << endl;
    recPrint(node -> right);
  }

  //If node value is a faculty member, print respective faculty info
  else if (typeid(node -> value).name() == typeid(Faculty*).name())
  {
    recPrint(node -> left);
    node -> value -> printFacultyInfo(node -> value);
    cout << endl;
    recPrint(node -> right);
  }

  //For all other types, print normal value
  else
  {
    recPrint(node -> left);
    cout << node -> value << endl;
    recPrint(node -> right);
  }
}


//Method to print all nodes in tree
template <class T>
void BST<T>::printTree()
{
  if (isEmpty())
  {
    cout << "Database is empty" << endl;
    return;
  }

  recPrint(root);
}











template <class T>
void BST<T>::serialize(TreeNode<T>* node)
{
}


template <class T>
void BST<T>::deserialize(string data)
{
}


#endif
