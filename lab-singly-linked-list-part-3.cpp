#include <iostream>
#include <unistd.h>

using namespace std;

class Node
{
public:
  Node(int val);
  ~Node();
  int value;
  Node* next;
};

Node::Node(int val) : value(val), next(nullptr)
{
}

Node::~Node()
{
}

// -------------------------------------------------------

class List
{
public:
  List();
  ~List(); 
  void push_front(int value);
  bool pop_front(int &value);
  int size(); 
private:
  Node* head;
};

List::List() : head(nullptr) {
}

List::~List() {
    while (head != nullptr) {
        int value = 0; 
        this->pop_front(value); 
    }
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

void List::push_front(int value)
{
  Node* new_head = new Node(value);
  new_head->next = head;
  head=new_head;
  cout << "Pushed " << value << " "; 
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

// --------------------------------------------------------

int main()
{
  List list;
  //
  list.push_front(1);
  list.size(); 
  list.push_front(2);
  list.size(); 
  list.push_front(3);
  list.size(); 
  list.push_front(4);
  list.size();
  list.push_front(5);
  list.size(); 

  return 0;
}