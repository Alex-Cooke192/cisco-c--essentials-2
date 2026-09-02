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
  cout << "+Node" << endl;
}

Node::~Node()
{
  cout << "-Node" << endl;
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
      // Check size 
      // Changed this to return the parameter passed in. 
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
}

// --------------------------------------------------------

int main()
{
  List list;
  //
  list.push_front(1);
  list.push_front(2);
  list.push_front(3);
  list.push_front(4);
  list.push_front(5);

  return 0;
}