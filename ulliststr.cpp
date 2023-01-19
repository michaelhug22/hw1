#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"
#include <iostream>
#define ARRSIZE 10

ULListStr::ULListStr()
{
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
    }

ULListStr::~ULListStr()
{
    clear();
}

bool ULListStr::empty() const
{
    return size_ == 0;
}

size_t ULListStr::size() const
{
    return size_;
}


// WRITE YOUR CODE HERE

std::string const & ULListStr::back() const
{
  return tail_->val[tail_->last-1];//return last element
}
std::string const & ULListStr::front() const{// same thing as^^ but backwards
  return head_->val[head_->first];
}
//get the value at a location and return NULL if it doesnt exist
std::string* ULListStr::getValAtLoc(size_t loc) const{
if (loc >= size_) {//check if i is valid
         return nullptr;
          }
  Item* current = head_;
  while (current != nullptr) {
      if (loc < current->last - current->first) {//make sure i is less than num elements
          return &(current->val[current->first + loc]);
      }
      loc -= (current->last - current->first);// shuffle through arrays until i is in the correct array
      current = current->next;
  }
  return nullptr;
  }


void ULListStr::print() {// print all elements of the list
    Item* currItem = head_;
    while(currItem) {
        for(size_t i = 0; i < currItem->last; i++) {// make i size_t to avoid warning comparing signed-unsigned int
            if(currItem->val[i] != "")
                std::cout << currItem->val[i] << " ";
        }
        currItem = currItem->next;
    }
    std::cout << std::endl;
  }

void ULListStr::add_first_element(const std::string& value) {
    if (head_ == nullptr) {
        Item* newItem = new Item;
        newItem->first = 0;
        newItem->val[0] = value;
        newItem->last = 1;
        head_ = newItem;
        tail_ = newItem;
        size_ = 1;
        //std::cout<< "added";
    }
}


void ULListStr::push_back(const std::string& val)
{
if (head_ == nullptr) {// check if list is empty
  Item* newItem = new Item;
  newItem->first = 0;
  newItem->val[0] = val;
  newItem->last = 1;
  head_ = newItem;
  tail_ = newItem;
  size_ = 1;
} else {// check if the last array is full
  if (tail_->last == ARRSIZE) {
      // last node is full
      Item* newItem = new Item;
      newItem->prev = tail_;
      tail_->next = newItem;
      tail_ = newItem;
      tail_->val[tail_->first] = val;
      tail_->last = 1;
  } else {
      // last node has room
      tail_->val[tail_->last] = val;
      tail_->last++;
  }
}
size_++;
}

void ULListStr::push_front(const std::string& val) {
  if(head_ == nullptr){// check if the list is empty
        ULListStr::add_first_element(val);// use helper function above to add first value
    }
    else {
      if (head_->first == 0) { // check if first node is full
            Item* newItem = new Item;
            newItem->next = head_;
            head_->prev = newItem;
            head_ = newItem;
            head_->last = 1;
            head_->val[0] = val;
            head_->first = 0;
        } else {// first node has room in front of first val
            head_->first--;
            head_->val[head_->first] = val;
        }
    }
    size_++;
    return;
}

void ULListStr::pop_back() {
if (tail_ != nullptr) {// make sure tail isnt empty
        tail_->last--;//decrement last and size
        size_--;
        if (tail_->last == tail_->first && tail_->prev != nullptr) {//if tail is empty and there is a prev list
            ULListStr::Item* new_tail = tail_->prev;
            new_tail->next = nullptr;
            delete tail_;
            tail_ = new_tail;// set tail to new tail
        }
    }
}
// repeat ^ for front
void ULListStr::pop_front() {
if (head_ != nullptr) {// make sure head isnt empty
        head_->first++;//decrement last and size
        size_--;
        if (head_->last == head_->first && head_->next != nullptr) {//if head is empty and there is a prev list
            ULListStr::Item* new_head = head_->next;
            new_head->prev = nullptr;
            delete head_;
            head_ = new_head;// set head to new tail
        }
    }
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}



void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
