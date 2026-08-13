#include <iostream>

class FlightBooking {
  public:
  FlightBooking(int id, int capacity, int reserved);
  void printStatus(int reserved, int capacity);
  private:
  int id;
  int capacity;
  int reserved;
  };

void FlightBooking::printStatus(int reserved, int capacity)
{
  float percentage = (float(reserved)/float(capacity))*100; 
  percentage = int(percentage);
  std::cout << "Flight " << id << " : " << reserved << "/" << capacity << " (" << percentage << "%) seats reserved" << std::endl;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
  this->id = id; 
  this->capacity = capacity;
  this->reserved = reserved; 
}

int main() {
  int reserved = 0,
      capacity = 0;
  std::cout << "Provide flight capacity: ";
  std::cin >> capacity;
  std::cout << "Provide number of reserved seats: ";
  std::cin >> reserved;
  FlightBooking booking(1, capacity, reserved);
  booking.printStatus(reserved, capacity);
  return 0;
}