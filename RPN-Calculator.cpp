#include <cstdlib>
#include <iostream>
#include <string>

#include "dlist.h"

/*
  operations: + add
              - subtract
              * multiply 
              / divide
              n negate top item
              d duplicate top item
              r reverse top two items
              p print top item
              c clear entire stack
              a print all items
              q quit
*/

class divZero {};
class badInput {};

// EFFECTS: performs + operation
//
// PSEUDOCODE:
// algorithm DoAdd
//  double var1
//
//  if(stack is not empty)
//    Remove front of stack and set var1 = to popped value
//    if(stack is empty)
//      push var back to front of stack
//      thow an empty list
//  else throw an empty list
//
//  remove node from front of stack and set double var2 equal to its value
//  insert a new node to the top of the stack with a value of var1 + var2

void DoAdd(Dlist<double> &stack)
{
  double var1;
  
  //checks if list has at least 2 elements
  if(!stack.IsEmpty())
  {
    var1 = stack.RemoveFront();
    if(stack.IsEmpty())
    {
      stack.InsertFront(var1);
      throw emptyList();
    }
  }
  else
    throw emptyList();
  
  double var2 = stack.RemoveFront();
  stack.InsertFront(var1 + var2);
}

// EFFECTS: performs - operation
//
// PSEUDOCODE:
// algorithm DoSub
//  double var1
//
//  if(stack is not empty)
//    Remove front of stack and set var1 = to popped value
//    if(stack is empty)
//      push var back to front of stack
//      thow an empty list
//  else throw an empty list
//
//  remove node from front of stack and set double var2 equal to its value
//  insert a new node to the top of the stack with a value of var1 - var2

void DoSub(Dlist<double> &stack)
{
  //checks if list has at least 2 elements
  double var1;
  
  if(!stack.IsEmpty())
  {
    var1 = stack.RemoveFront();
    if(stack.IsEmpty())
    {
      stack.InsertFront(var1);
      throw emptyList();
    }
  }
  else
    throw emptyList();
  
  double var2 = stack.RemoveFront();
  stack.InsertFront(var2 - var1);
}

// EFFECTS: performs * operation
//
// PSEUDOCODE:
// algorithm DoMult
//  double var1
//
//  if(stack is not empty)
//    Remove front of stack and set var1 = to popped value
//    if(stack is empty)
//      push var back to front of stack
//      thow an empty list
//  else throw an empty list
//
//  remove node from front of stack and set double var2 equal to its value
//  insert a new node to the top of the stack with a value of var1 * var2

void DoMult(Dlist<double> &stack)
{
  //checks if list has at least 2 elements
  double var1;
  
  if(!stack.IsEmpty())
  {
    var1 = stack.RemoveFront();
    if(stack.IsEmpty())
    {
      stack.InsertFront(var1);
      throw emptyList();
    }
  }
  else
    throw emptyList();
  
  double var2 = stack.RemoveFront();
  stack.InsertFront(var1 * var2);
}

// EFFECTS: performs / operation
//
// PSEUDOCODE:
// algorithm DoDiv
//  double var1
//
//  if(stack is not empty)
//    Remove front of stack and set var1 = to popped value
//    if(stack is empty)
//      push var back to front of stack
//      thow an empty list
//  else throw an empty list
//
//  remove node from front of stack and set double var2 equal to its value
//  insert a new node to the top of the stack with a value of var1 / var2

void DoDiv(Dlist<double> &stack)
{
  //checks if list has at least 2 elements
  double var1;
  
  if(!stack.IsEmpty())
  {
    var1 = stack.RemoveFront();
    if(stack.IsEmpty())
    {
      stack.InsertFront(var1);
      throw emptyList();
    }
  }
  else
    throw emptyList();
  
  double var2 = stack.RemoveFront();
  stack.InsertFront(var1 / var2);
}

// EFFECTS: performs n operation
//
// PSEUDOCODE:
// algorithm DoNeg
//  double var
//
//  if(stack is not empty)
//    Remove front of stack and set var = to popped value
//  else throw an empty list
//
//  insert a new node to the top of the stack with a value of var * -1

void DoNeg(Dlist<double> &stack)
{
  double var;
  
  if(!stack.IsEmpty())
  {
    var = stack.RemoveFront();
  }
  else
    throw emptyList();
  
  stack.InsertFront(var * -1);
}

// EFFECTS: performs d operation
//
// PSEUDOCODE:
// algorithm DoDup
//  double var
//
//  if(stack is not empty)
//    Remove front of stack and set var = to popped value
//  else throw an empty list
//
//  insert a new node to the top of the stack with a value of var
//  insert another new node to the top of the stack with a value of var

void DoDup(Dlist<double> &stack) {
  //checks if list is empty
  double front;
  
  if(!stack.IsEmpty())
  {
    front = stack.RemoveFront();
  }
  else
    throw emptyList();
  
  stack.InsertFront(front);
  stack.InsertFront(front);
}

// EFFECTS: performs r operation
//
// PSEUDOCODE:
// algorithm DoRev
//  double front
//
//  if(stack is not empty)
//    Remove front of stack and set front = to popped value
//    if(stack is empty)
//      push front back to front of stack
//      thow an empty list
//  else throw an empty list
//
//  remove node from back of stack and set double back equal to its value
//
//  insert a new node to the top of the stack with a value of back
//  insert a new node to the bottom of the stack with a value of front

void DoRev(Dlist<double> &stack)
{
  //checks if list has at least 2 elements
  double front;
  
  if(!stack.IsEmpty())
  {
    front = stack.RemoveFront();
    if(stack.IsEmpty())
    {
      stack.InsertFront(front);
      throw emptyList();
    }
  }
  else
    throw emptyList();

  double back = stack.RemoveBack();
  stack.InsertFront(back);
  stack.InsertBack(front);
}

// EFFECTS: performs p operation
//
// PSEUDOCODE:
// algorithm DoPrint
//  remove node from top of stack and set double print val equal to its value
//  output printval followed by a newline

void DoPrint(Dlist<double> &stack)
{
  double printval = stack.RemoveFront();
  stack.InsertFront(printval);
  std::cout << printval << std::endl;
}

// EFFECTS: performs c operation
//
// PSEUDOCODE:
// algorithm DoClear
//  while(stack is not empty)
//  remove front of stack

void DoClear(Dlist<double> &stack)
{
  while(!stack.IsEmpty())
  {
    stack.RemoveFront();
  }
}

// EFFECTS: performs a operation
//
// PSEUDOCODE:
// algorithm DoPrintAll
//  create a copy of the stack named copyStack
//
//  while(copyStack is not empty)
//    remove front of copystack and output its value followed by a space
//  output and endline

void DoPrintAll(Dlist<double> &stack)
{
  Dlist<double> copyStack(stack);
  
  while(!copyStack.IsEmpty())
  {
    std::cout << copyStack.RemoveFront() << " ";
  }
  std::cout << std::endl;
}


bool DoOne(Dlist<double> &stack) {
  std::string s;
  double d;

  std::cin >> s;
  switch (s[0]) {
  case '+':
    DoAdd(stack);
    break;
  case '-':
    DoSub(stack);
    break;
  case '*':
    DoMult(stack);
    break;
  case '/':
    DoDiv(stack);
    break;
  case 'n':
    DoNeg(stack);
    break;
  case 'd':
	  DoDup(stack);
	  break;
  case 'r':
	  DoRev(stack);
	  break;
  case 'p':
	  DoPrint(stack);
	  break;
  case 'c':
	  DoClear(stack);
	  break;
  case 'a':
	  DoPrintAll(stack);
	  break;
  case 'q':
	  return true;
	  break;
  case '0':
  case '1':
  case '2':
  case '3':
  case '4':
  case '5':
  case '6':
  case '7':
  case '8':
  case '9':
	  d = std::atof(s.c_str());
    stack.InsertFront(d);
	  break;
  default:
	  badInput e;
	  throw e;
	  break;
  }
  return false;
}

int main() {
  Dlist<double> stack;

  bool done = false;
  while (!done) {
    try {
      done = DoOne(stack);
    } catch (emptyList e) {
      std::cout << "Not enough operands\n";
    } catch (divZero e) {
      std::cout << "Divide by zero\n";
    } catch (badInput e) {
      std::cout << "Bad input\n";
    }
  }
}
