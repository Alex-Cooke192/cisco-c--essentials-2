#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class IPAddress {
    protected:
    string address; 
    public:
    IPAddress(string address) {this->address = address;}; 
    IPAddress(const IPAddress& other) {this->address = other.address;}; 
    virtual void printStatus() {cout << "Address: " << this->address << endl;}; 
};


// ------------------------------------------------------

class IPAddressChecked : public IPAddress {
    private:
    bool checked; 
    public:
    IPAddressChecked(string address); 
    IPAddressChecked(const IPAddressChecked& other); 
    void printStatus() override; 
    void check(); 
}; 

IPAddressChecked::IPAddressChecked(string address) : IPAddress(address) {
    this->address = address; 
    this->checked = false; 
}

IPAddressChecked::IPAddressChecked(const IPAddressChecked& other) : IPAddress(other){
    this->address = other.address; 
    this->checked = other.checked; 
}

void IPAddressChecked::printStatus() {
    cout << "Address: " << this->address << endl;
    if (this->checked) {
        cout << "Checked: true" << endl;
    } else {
        cout << "Checked: false" << endl;
    }
    
}

void IPAddressChecked::check() {
    stringstream ss(this->address); 

    string number; 
    while (getline(ss, number, '.')) {
        int num = stoi(number); 
        if (num < 0 || num > 255) {
            // Number is outside valid range
            cout << "This address is not valid" << endl;
            this->checked = true; 
            return; 
        }
    }
    cout << "This address is valid" << endl; 
    this->checked = true; 
    return;
}

// ----------------------------------------------------------

int main() {
    cout << "Start of program!" << endl; 

    string address1; 
    cout << "Enter first address" << endl; 
    cin >> address1; 
    IPAddress* ipAddressPtr = new IPAddress(address1); 
    ipAddressPtr->printStatus(); 

    string checkAddress1;
    cout << "Enter second address (this one will be checked)" << endl; 
    cin >> checkAddress1; 
    IPAddressChecked* ipAddressCheckedPtr1 = new IPAddressChecked(checkAddress1); 
    ipAddressCheckedPtr1->check(); 
    ipAddressCheckedPtr1->printStatus(); 

    string checkAddress2;
    cout << "Enter third address (this one will be checked)" << endl; 
    cin >> checkAddress2; 
    IPAddressChecked* ipAddressCheckedPtr2 = new IPAddressChecked(checkAddress2); 
    ipAddressCheckedPtr2->check();
    ipAddressCheckedPtr2->printStatus(); 
}