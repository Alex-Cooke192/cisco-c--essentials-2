#include <iostream> 
#include <string>

using namespace std;

class membership {
    public:
    membership(int id, std::string name); 
    deleteMembership(int id); 
    extendMembership(int id, int duration); 
    cancelMembership(int id); 
    getId() { return id; }; 

    private:
    int id; 
    std::string name; 
    int duration;  
}

membership::membership() {
    this->id = 0; 
    this->name = ""; 
    this->duration = 0; 
}

membership::membership(int id, std::string name) {
    this->id = id; 
    this->name = name; 
    this->duration = 0; 
}

membership::deleteMembership(int id) {
    membership(); 
}

membership::extendMembership(int duration) {
    this->duration += duration; 
}

membership::cancelMembership() {
    this->duration = 0; 
}

membership::printStatus() {
    if (this->id != 0) {
        cout << "Membership ID: " << id << endl; 
        cout << "Name: " << name << endl; 
        cout << "Duration:" << duration << endl; 
        cout<< endl; 
    }
}

int main() {
    int member_capacity = 10; 
    membership members[member_capacity] = {};
    int membership_slot = 0;

    string commandLine; 
    commandLine = ""; 

    while (commandLine != "quit") {
        std::getline(std::cin, commandLine)

        iss = istringstream(commandLine); 
        string command; 
        iss >> command; 

        if (command == "create") {
            if (iss >> id >> name) {
                members[membership_slot] = membership(id, name)
                membership_slot++; 
            }
        } else if (command == "delete") {
            if (iss >> id) {
                for (int i=0; i<member_capacity) {
                    if (members[i].id == id) {
                        members[i] = membership(); 
                    }
                }

            } 
        } else if (command == "extend") {
            if (iss >> id >> extension) {
                for (int i=0; i<member_capacity; i++) {
                    if (members[i].id = id) {
                        members[i].duration += extension; 
                    }
                }
            }
        } else if (command == "cancel") {
            if (iss >> id) {
                for (int i=0; i<member_capacity; i++) {
                    if (members[i].id = id) {
                        members[i].duration = 0; 
                    }
                }
            }
        } else if (command == "print") {
            for (i=0; i<member_capacity; i++) {
                members[i].printStatus(); 
            }
        } else {
            cout << "Command invalid"; 
        }
    }
}