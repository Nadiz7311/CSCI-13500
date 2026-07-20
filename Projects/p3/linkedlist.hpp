#ifndef LINKEDLIST_HPP_
#define LINKEDLIST_HPP_

#include <iostream>
#include <stdexcept>

// Node struct declaration
struct Node {
  int value;
  Node* next;

  explicit Node(int passed_value) : value(passed_value), next(nullptr) {}
};

class LinkedList {
 public:
  // Default constructor
  LinkedList();

  // Destructor
  ~LinkedList();

  // Inserts a new node at the end
  void InsertNode(const int value);

  // Inserts a new node at the front
  void InsertNodeFront(const int value);

  bool Contains(const int value) const;

  bool Remove(const int position);

  void PrintValues() const;

  void PrintAddresses() const;

  // Gets value at 1 based position.
  int GetValueAtPosition(const int position) const;

  // Reverses current list in place, transfers ownership to new heap allocated list and leaves this list empty.
  LinkedList* ReverseList();

  void InsertNodeAt(const int value, const int position);

  // Getter for current size
  int GetSize() const;

  // Creates new list that alternates nodes from this list and second list.
  LinkedList* MergeIntertwine(const LinkedList& second_list) const;

 private:
  int size_;
  Node* head_;
};

#endif