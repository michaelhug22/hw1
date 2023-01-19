#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

void push_front_test(ULListStr *test_list){// test the push front funciton
  test_list->push_front("a");
  test_list->push_front("s");
  test_list->push_front("f");
  test_list->push_front("h");
  test_list->push_front("q");
  test_list->push_front("m");
  test_list->push_front("a");
  test_list->push_front("g");
  test_list->push_front("y");
}


int main(int argc, char* argv[])
{
  ULListStr *test_list = new ULListStr();

  push_front_test(test_list);

  test_list->print();

  for (int i = 0; i < 4; i++) {
      test_list->push_back("Value " + std::to_string(i));
      //test_list->print();
  }
  for (int i = 4; i < 8; i++) {
      test_list->push_back("Value " + std::to_string(i));
  }
  for (int i = 8; i < 12; i++) {
      test_list->push_back("Value" + std::to_string(i));
  }
  test_list->print();//print the list

  std::cout << "pop_back test:\n";
  for (int i = 0; i < 8; i++) {
      test_list->pop_back();
      std::cout << " result "<< std::endl;
      test_list->print();
  }

//repeat above test for pop_front
  std::cout << "\npop_front test:" << std::endl;
  for (int i = 0; i < 5; i++) {
      test_list->pop_front();
      std::cout << " result "<< std::endl;
      test_list->print();
  }
std::cout << std::endl << "testing front() and back()";
  //test front and back
  std::cout << " front: " << test_list->front() << " back: "
   << test_list->back() << std::endl;

  return 0;
}