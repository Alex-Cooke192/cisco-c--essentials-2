#include <iostream>
#include <sstream>
#include <string>

using namespace std; 

class FlightBooking {
public:
  FlightBooking(int id, int capacity, int reserved);
  FlightBooking();
  void printStatus();
  bool reserveSeats(int number_ob_seats);
  bool cancelReservations(int number_ob_seats);
  int getId() { return id; };
private:
  int id;
  int capacity;
  int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved)
{
  this->id = id; 
  this->capacity = capacity;
  this->reserved = reserved; 
}

FlightBooking::FlightBooking()
{
  id = 0; capacity = 0; reserved = 0;
}

void FlightBooking::printStatus()
{
    float percentage = (float(this->reserved)/float(this->capacity))*100; 
    percentage = int(percentage);
    std::cout << "Flight " << this->id << " : " << this->reserved << "/" << this->capacity << " (" << percentage << "%) seats reserved" << std::endl;
}

bool FlightBooking::reserveSeats(int number_ob_seats){
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
  FlightBooking booking[10] = {};
  int booking_slot = 0; 

  // Use this to have some starting value
  // booking[0] = FlightBooking(1, 400, 0);
  // booking[0].printStatus();

  std::string commandLine = "";
  while (commandLine != "quit")
  {
    std::cout << "What would you like to do?: "; 
    std::getline(std::cin, commandLine);

    istringstream iss(commandLine); 
    string command; 
    iss >> command; 

    if (command == "create") {
        int id, capacity; 
        if (iss >> id >> capacity) 
        {
            booking[booking_slot] = FlightBooking(id, capacity, 0); 
            booking_slot++; 
        }
    } else if (command == "add") {
        int id, number; 
        if (iss >> id >> number) {
            // Find booking slot with ID = id
            for (int i = 0; i < 10; i++) {
                if (booking[i].getId() == id) {
                    booking_slot = i; 
                }
            }
            booking[booking_slot].reserveSeats(number);
        }
    } else if (command == "remove") {
        int id, number; 
        if (iss >> id >> number) {
        // Find booking slot with ID = id
            for (int i = 0; i < 10; i++) {
                if (booking[i].getId() == id) {
                    booking_slot = i; 
                }
            }
            booking[booking_slot].cancelReservations(number); 
        }
    } else if (command == "delete") {
        int id; 
        if (iss >> id) {
        // Find booking slot with ID = id
            for (int i = 0; i < 10; i++) {
                if (booking[i].getId() == id) {
                    booking_slot = i; 
                }
            }
            booking[booking_slot] = FlightBooking(); 
        }
    } else if (command == "print") {
        for (int i=0; i<10; i++) {
            booking[i].printStatus(); 
        }
    } else {
        cout << "Command invalid, exiting program."; 
        return 1; 
        }

    }
    return 0;
}