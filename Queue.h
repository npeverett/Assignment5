#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

using namespace std;

template <class T>
class Queue{
public:
  Queue();
  Queue(int maxSize);
  ~Queue();

  void enque(T);
  void deque();
  T front();
  int size();

  bool isFull();
  bool isEmpty();

private:
  T* myQueue;
  int frontM;
  int rearM;
  int QSize;
  int numElements;
};

template <class T>
Queue<T>::Queue()
{}

template <class T>
Queue<T>::~Queue()
{
  while (!isEmpty())
  {
    deque();
  }

  delete[] myQueue;
  cout << "Queue Destroyed" << endl;
}

template <class T>
Queue<T>::Queue(int maxSize)
{
  myQueue = new T[maxSize];
  frontM = 0;
  rearM = -1;
  QSize = maxSize;
  numElements = 0;
}

template <class T>
void Queue<T>::enque(T data)
{
  if (isFull())
  {
    frontM = 0;
  }

  if (rearM == QSize - 1)
  {
    rearM = -1;
  }

  myQueue[++rearM] = data;
  numElements++;
}

template <class T>
void Queue<T>::deque()
{
  if (isEmpty())
  {
    cout << "Queue is empty" << endl;
    exit(0);
  }

  if (frontM == QSize - 1)
  {
    frontM = 0;
  }

  frontM++;
  numElements--;
}

template <class T>
T Queue<T>::front()
{
  if (isEmpty())
  {
    cout << "Queue is empty" << endl;
    exit(0);
  }

  return (myQueue[frontM]);
}

template <class T>
int Queue<T>::size()
{
  return numElements;
}

template <class T>
bool Queue<T>::isFull()
{
  return (numElements == QSize);
}

template <class T>
bool Queue<T>::isEmpty()
{
  return (numElements == 0);
}

#endif
