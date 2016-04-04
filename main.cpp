#include <iostream>
#include "stack_template.hpp"

using namespace std;

main()
{
  Stack<int> first_stack;

  first_stack<<1<<2<<3;

  while(!first_stack.empty())
  {
    int g;
    first_stack>>g;
    cout<< g << endl;
  }


  Stack<char> second_stack;

  second_stack<<'a'<<'b'<<'c';

  while(!second_stack.empty())
  {
    char g;
    second_stack>>g;
    cout<< g << endl;
  }

}