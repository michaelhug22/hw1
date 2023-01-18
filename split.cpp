/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
/* Add a prototype for a helper function here if you need */

void split(Node*& in, Node*& odds, Node*& evens)
{
  if(in != nullptr) // recursive function proceeds until in == nullptr
  {
    if (in->value % 2 == 1) { // check if odd
        odds = in; // set current odd node to in node
        Node* next = in->next;
        in->next = nullptr; // set in next to nullptr because the data was just transfered to the odds
        split(next, odds->next, evens);
    } else { // repeat above steps for even numbers
        evens = in;
        Node* next = in->next;
        in->next = nullptr;
        split(next, odds, evens->next);
    }
  }
  in = nullptr;
  return;
}

/* If you needed a helper function, write it here */
