#include <iostream>

using namespace std; 

class FlightBooking {
  public:
  FlightBooking(int id, int capacity, int reserved);
  void printStatus();
  bool reserveSeats(int number_ob_seats);
  bool cancelReservations(int number_ob_seats);
  private:
  int id;
  int capacity;
  int reserved;
};

void FlightBooking::printStatus()
{
    float percentage = (float(this->reserved)/float(this->capacity))*100; 
    percentage = int(percentage);
    std::cout << "Flight " << this->id << " : " << this->reserved << "/" << this->capacity << " (" << percentage << "%) seats reserved" << std::endl;
}

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
  this->id = id; 
  this->capacity = capacity;
  this->reserved = reserved; 
}

bool FlightBooking::reserveSeats(int number_ob_seats)
{
    float new_percentage = (static_cast<float>(reserved+number_ob_seats)/capacity)*100; 
    if (new_percentage > 105.0) {
        cout << "Flight booking above maximum capacity, cannot reserve anymore seats"; 
        return false; 
    } else {
        this->reserved = reserved + number_ob_seats;
        cout << "Number of reserved seats is now :" << reserved; 
        return true; 
    }
  return false;
}

bool FlightBooking::cancelReservations(int number_ob_seats)
{
    float percentage = (static_cast<float>(reserved-number_ob_seats)/capacity)*100; 
    if (percentage <= 0.0) {
        cout << "Cannot perform this operation."; 
        return false; 
    } else {
        this->reserved = reserved - number_ob_seats;
        cout << "Number of reserved seats is now :" << reserved; 
        return true; 
    }
  return false;
}

int main() {
  int reserved = 0,
      capacity = 0;
  std::cout << "Provide flight capacity: ";
  std::cin >> capacity;
  std::cout << "Provide number of reserved seats: ";
  std::cin >> reserved;
  FlightBooking booking(1, capacity, reserved);
  std::string command = "";
  booking.printStatus();
  while (command != "quit")
  {
    std::cout << "What would you like to do?: " << endl;
    std::cout << "To reserve seats, type 'r'" << endl; 
    std::cout << "To cancel reservations, type 'c'" << endl; 
    std::cout << "To print the current status of the reservation, type 'p'" << endl; 
    std::getline(std::cin, command);
    if (command == "r") {
        int seats_to_reserve; 
        cout << "How many seats to reserve?" << endl; 
        cin >> seats_to_reserve; 
        booking.reserveSeats(seats_to_reserve);
    } else if (command == "d") {
        int seats_to_cancel; 
        cout << "How many reservations to delete?" << endl; 
        cin >> seats_to_cancel; 
        booking.cancelReservations(seats_to_cancel);
    } else if (command == "p") {
           booking.printStatus();
    }
  }
  return 0;
}