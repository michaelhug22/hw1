/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/
#include "split.h"
#include <iostream>
using namespace std;


int main(int argc, char* argv[])
{
Node* in = new Node(1, new Node(3, new Node(5,new Node(7, new Node(9, nullptr))))); //Create list to test
  
  Node* odds = nullptr;
  Node* evens = nullptr;
  
  split(in, odds, evens);
  
  // Print the linked lists
  Node* curr = odds;
  cout << "Odds:";
  while (curr != nullptr) {
    cout << curr->value << " ";
    curr = curr->next;
  }
  cout << endl;
  
  cout << "Evens:";
  curr = evens;
  while (curr != nullptr) {
    cout << curr->value << " ";
    curr = curr->next;
  }
  cout << endl;
  
  Node* current = in; // delete in to prevent memory leaks
while (current != nullptr) {
    Node* next = current->next;
    delete current;
    cout << "1";
    current = next;
}
  return 0;
}

