#include "linkedlist.hpp"

int main() {
  LinkedList list;

  list.InsertNode(10);
  list.InsertNode(23);
  list.InsertNodeFront(4);

  list.PrintValues();       // 4 - 10 - 23 - nullptr
  list.PrintAddresses();    // positions and addresses

  std::cout << "Contains 10? "
            << (list.Contains(10) ? "yes" : "no") << std::endl;
  std::cout << "Size: " << list.GetSize() << std::endl;

  // Gets value at position
  try {
    int value = list.GetValueAtPosition(2);
    std::cout << "Value at position 2: " << value << std::endl;
  } catch (const std::out_of_range& e) {
    std::cout << "Exception: " << e.what() << std::endl;
  }

  // Removes element
  list.Remove(2);
  list.PrintValues();

  // Reverses list
  LinkedList* reversed = list.ReverseList();
  std::cout << "Original after reverse (should be empty): ";
  list.PrintValues();
  std::cout << "Reversed: ";
  reversed->PrintValues();

  // Another list for merge
  LinkedList other;
  other.InsertNode(100);
  other.InsertNode(200);

  LinkedList* merged = reversed->MergeIntertwine(other);
  std::cout << "Merged intertwine: ";
  merged->PrintValues();

  // Clean up heap allocated lists
  delete reversed;
  delete merged;

  return 0;
}