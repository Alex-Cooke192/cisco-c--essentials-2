// An empty list:
//
//  Node*
// +------+
// | head |-->nullptr
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
//
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

class List
{
public:
  List();
  void push_front(int value);
  bool pop_front(int &value);
private:
  Node* head;
};

List::List() : head(nullptr)
{
}

void List::push_front(int value)
{
  Node* new_head = new Node(value);
  new_head->next = head;
  head=new_head;
}

// START
// +------+   +-----+      +-----+
// | head |-->|  X  |  +-->|  Y  |
// +------+   +-----+  |   +-----+
//            |next |--+   |next |-->nullptr
//            +-----+      +-----+
//
// STEP 1
//
//            +------+
//            |popped|
//            +------+
//               |
//               V
// +------+   +-----+      +-----+
// | head |-->|  X  |  +-->|  Y  |
// +------+   +-----+  |   +-----+
//            |next |--+   |next |-->nullptr
//            +-----+      +-----+
//
// STEP 2
// +------+
// | head |-------------------+
// +------+                   |
//                            V
// +------+   +-----+      +-----+
// |popped|-->|  X  |  +-->|  Y  |
// +------+   +-----+  |   +-----+
//            |next |--+   |next |-->nullptr
//            +-----+      +-----+
//
// STEP 3
// returned = popped->value;
// delete popped;
// +------+   +-----+
// | head |-->|  Y  |
// +------+   +-----+
//            |next |-->nullptr
//            +-----+

bool List::pop_front(int &value)
{
  try {
    if (head == nullptr) {
      return false; 
    }
      // Point head to the new element before deleting
      // This will be whatever points to the value pointed to by head
      // I want new_head to point to the head->next->value

      Node* old_head = head; 

      // Assign popped value to our output
      value = head->value; 

      // Repoint head to next value in the list
      head = head->next; 
      // Delete what old-head points to (the first value in the original list before popping)
      delete old_head; 
      // Changed this to return the parameter passed in
      return true;
  } catch (const char* msg) {
    cout << "Error: " << msg; 
    return false; 
  }
}

int main()
{
  List list;

  // Add values to the list
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);

  // Remove values from the list
  int value = 0;
  while (list.pop_front(value))
  {
    cout << value << endl;
  }
  return 0;
}