// An empty list:
//
//  Node*
// +------+
// | head |-->nullptr
// +------+
//
//  Node*
// +------+
// | tail |-->nullptr
// +------+
//
//
//
// A list with two elements:
//
//  Node*      Node         Node
// +------+   +-----+      +-----+
// | head |-->|value|  +-->|value|
// +------+   +-----+  |   +-----+
//            |next |--+   |next |-->nullptr
//            +-----+      +-----+
//                           ^
// +------+                  |
// | tail |------------------+
// +------+
#include <iostream>

using namespace std;

class Node
{
public:
  Node(int val);
  int value;
  Node* next;
};

Node::Node(int val) : value(val), next(nullptr)
{
}

// -------------------------------------------------

class List
{
public:
  List();
  void push_front(int value);
  bool pop_front(int &value);
  void push_back(int value);
  int size(); 
private:
  // other members you may have used
  Node* head;
  Node* tail;
};

List::List() : head(nullptr), tail(nullptr)
{
}

void List::push_front(int value)
{
    int size = this->size(); 
    
    Node* new_head = new Node(value);
    new_head->next = head;
    head=new_head;
    if (size == 0) {
            // Create tail pointer and point to the last value
            this->tail->next = this->head->next; 
    }
}

int List::size() {
    int size = 0; 
    Node* size_pointer = head; 
    while (size_pointer != nullptr) {
        // Make our pointer point to the next element in the list
        size_pointer = size_pointer->next; 
        // Increment our size var - the list is one element bigger
        size++; 
    }
    cout << "size: " << size << endl; 
    return size; 
}

// START
// +------+   +-----+      +-----+
// | head |-->|  X  |  +-->|  Y  |
// +------+   +-----+  |   +-----+
//            |next |--+   |next |-->nullptr
//            +-----+      +-----+
//                           ^
// +------+                  |
// | tail |------------------+
// +------+
//
// STEP 1
//                                            new Node
// +------+   +-----+      +-----+             +-----+
// | head |-->|  X  |  +-->|  Y  |             |  Z  |
// +------+   +-----+  |   +-----+             +-----+
//            |next |--+   |next |-->nullptr   |next |-->nullptr
//            +-----+      +-----+             +-----+
//                           ^
// +------+                  |
// | tail |------------------+
// +------+
//
// STEP 2
//
// +------+   +-----+      +-----+       +-----+
// | head |-->|  X  |  +-->|  Y  |   +-->|  Z  |
// +------+   +-----+  |   +-----+   |   +-----+
//            |next |--+   |next |--+    |next |-->nullptr
//            +-----+      +-----+       +-----+
//                           ^
// +------+                  |
// | tail |------------------+
// +------+
//
// STEP 3
// +------+   +-----+      +-----+       +-----+
// | head |-->|  X  |  +-->|  Y  |   +-->|  Z  |
// +------+   +-----+  |   +-----+   |   +-----+
//            |next |--+   |next |--+    |next |-->nullptr
//            +-----+      +-----+       +-----+
//                                          ^
// +------+                                 |
// | tail |---------------------------------+
// +------+
void List::push_back(int value)
{
    int size = this->size(); 
    if (size == 0) {
        Node* head = new Node(value); 
        Node* tail = head; 
        // We need head to point to the value part of whatever 
        // Assign tail to the end of the list
        this->tail = tail; 
        this->head = head; 
        return;
    }
    Node* new_tail = new Node(value); 
    // Set the original last value to point to the new last value
    this->tail->next = new_tail; 
    // Set the tail to point to the new last value
    this->tail = new_tail; 
}

bool List::pop_front(int &value)
{
  try {
    if (head == nullptr) {
      return false; 
    }
      Node* old_head = head; 
      // Assign popped value to our output
      value = head->value; 
      // Repoint head to next value in the list
      head = head->next; 
      // Delete what old-head points to (the first value in the original list before popping)
      delete old_head; 
      // Changed this to return the parameter passed in. 
      cout << "Popped: " << value << " ";
      this->size(); 
      return true;
  } catch (const char* msg) {
    cout << "Error: " << msg; 
    return false; 
  }
}

// ---------------------------------------------------

int main()
{
  List list;
  //
  list.push_back(1);
  list.push_back(2);
  list.push_back(3);
  list.push_back(4);

  int value = 0;
  while (list.pop_front(value))
  {
    continue; 
  }
  return 0;
}