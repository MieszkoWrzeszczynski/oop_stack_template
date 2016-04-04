#include <iostream>

#ifndef stack_template_hpp
#define stack_template_hpp

using namespace std;

template <class T>
class Stack
{

protected:
  struct Node
  {
     T data;
     Node* prev;
  };

  Node* top;

public:
  Stack();
  ~Stack();   

  void push(T e);
  T pop() ;      
  T empty() const;  

  void size_i();
  void size_r();
  int size_recursion(Node * tmp);

  Stack<T>& operator<<(T e);
  Stack<T>& operator>>(T & f);

};

template <class T>
Stack<T>::Stack()
{ 
  top = NULL;
}

template <class T>
Stack<T>::~Stack() 
{
  while(top!=NULL) 
  {
     Node* old_node=top;
     top=top->prev;
     delete old_node;
  } 
}

template <class T>
void Stack<T>::push(T e)
{
    Node* new_item = new Node;
    new_item->data = e;
    new_item->prev = top;
    top = new_item;
}

template <class T>
T Stack<T>::pop() 
{
    T ret=top->data;
    Node* old_node=top;
    top=top->prev; 
    delete old_node;
    return ret;
}

template <class T>
T Stack<T>::empty()  const 
{ 
  return top == NULL;
}

template <class T>
void Stack<T>::size_i() 
{ 
    int items = 0;
    Node* tmp = top;

    while(tmp!=NULL)
    {  
       tmp = tmp->prev;
       items++; 
    }   
     cout << items;
}

template <class T>
void Stack<T>::size_r()
{
  cout << size_recursion(top);
}

template <class T>
int Stack<T>::size_recursion(Node * tmp)
{
   if(!tmp) return 0;
   else
   return size_recursion(tmp->prev) +1;
}

template <class T>
Stack<T>& Stack<T>::operator<<(T e)
{
   push(e);
   return * this;
}


template <class T>
Stack<T>& Stack<T>::operator>>(T & f)
{
   f = pop();
   return * this;
}

#endif