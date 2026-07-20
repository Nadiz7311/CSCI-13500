#include "linkedlist.hpp"

LinkedList::LinkedList() : size_(0), head_(nullptr) {}

LinkedList::~LinkedList() {
  Node* current = head_;
  while (current != nullptr) {
    Node* to_delete = current;
    current = current->next;
    delete to_delete;
  }
  head_ = nullptr;
  size_ = 0;
}

void LinkedList::InsertNode(const int value) {
  Node* new_node = new Node(value);

  if (head_ == nullptr) {
    head_ = new_node;
  } else {
    Node* current = head_;
    while (current->next != nullptr) {
      current = current->next;
    }
    current->next = new_node;
  }

  ++size_;
}

void LinkedList::InsertNodeFront(const int value) {
  Node* new_node = new Node(value);
  new_node->next = head_;
  head_ = new_node;
  ++size_;
}

bool LinkedList::Contains(const int value) const {
  Node* current = head_;
  while (current != nullptr) {
    if (current->value == value) {
      return true;
    }
    current = current->next;
  }
  return false;
}

bool LinkedList::Remove(const int position) {
  if (position < 1 || position > size_) {
    return false;
  }

  // Remove head
  if (position == 1) {
    Node* to_delete = head_;
    head_ = head_->next;
    delete to_delete;
    --size_;
    return true;
  }

  // Find node before the one to remove
  Node* current = head_;
  for (int i = 1; i < position - 1; ++i) {
    current = current->next;
  }

  Node* to_delete = current->next;
  current->next = to_delete->next;
  delete to_delete;
  --size_;
  return true;
}

void LinkedList::PrintValues() const {
  Node* current = head_;
  while (current != nullptr) {
    std::cout << current->value << " - ";
    current = current->next;
  }
  std::cout << "nullptr" << std::endl;
}

void LinkedList::PrintAddresses() const {
  Node* current = head_;
  int position = 1;
  while (current != nullptr) {
    std::cout << position << " " << current << std::endl;
    current = current->next;
    ++position;
  }
}

int LinkedList::GetValueAtPosition(const int position) const {
  if (position < 1 || position > size_) {
    throw std::out_of_range("Position out of range");
  }

  Node* current = head_;
  for (int i = 1; i < position; ++i) {
    current = current->next;
  }
  return current->value;
}

LinkedList* LinkedList::ReverseList() {
  // Reverse the chain of nodes owned by this list
  Node* prev = nullptr;
  Node* current = head_;
  while (current != nullptr) {
    Node* next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  LinkedList* reversed_list = new LinkedList();
  reversed_list->head_ = prev;
  reversed_list->size_ = size_;

  // Original list becomes empty
  head_ = nullptr;
  size_ = 0;

  return reversed_list;
}

void LinkedList::InsertNodeAt(const int value, const int position) {
  if (position < 1 || position > size_ + 1) {
    throw std::out_of_range("Position out of range");
  }

  if (position == 1) {
    InsertNodeFront(value);
    return;
  }

  if (position == size_ + 1) {
    InsertNode(value);
    return;
  }

  Node* new_node = new Node(value);

  // Find node before insertion position
  Node* current = head_;
  for (int i = 1; i < position - 1; ++i) {
    current = current->next;
  }

  new_node->next = current->next;
  current->next = new_node;
  ++size_;
}

int LinkedList::GetSize() const {
  return size_;
}

LinkedList* LinkedList::MergeIntertwine(const LinkedList& second_list) const {
  LinkedList* merged = new LinkedList();

  Node* current1 = head_;
  Node* current2 = second_list.head_;

  // Alternate nodes from this list and second list
  while (current1 != nullptr || current2 != nullptr) {
    if (current1 != nullptr) {
      merged->InsertNode(current1->value);
      current1 = current1->next;
    }
    if (current2 != nullptr) {
      merged->InsertNode(current2->value);
      current2 = current2->next;
    }
  }

  return merged;
}