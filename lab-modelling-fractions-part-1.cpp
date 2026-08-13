#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Fraction{
public:
  Fraction(int numerator, int denominator);
  string toString(); 
  double toDouble();
private:
  int numerator;
  int denominator;
};

Fraction::Fraction(int numerator, int denominator) {
    this->numerator = numerator; 
    this->denominator = denominator; 
}

string Fraction::toString() {
    string str; 
    
    if (denominator < 0 && numerator > 0) {
        denominator *= -1; 
        numerator *= -1; 
    }

    int intValue = 0; 
    while (numerator > denominator) {
        numerator -= denominator; 
        intValue++;
    }

    if (intValue != 0) {
        str = to_string(intValue) + " " + to_string(numerator) + "/" + to_string(denominator); 
    } else {
        str = to_string(numerator) + "/" + to_string(denominator); 
    }

    return str; 
}

double Fraction::toDouble() {
    double val; 

    val = float(numerator) / float(denominator); 

    return val; 
}

// Lone functions
// --------------------------------------------

string removeSpaces(string& s) {
    int n = s.length();

    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') {

            // shift all characters to the left
            // starting from current index
            for (int j = i; j < n - 1; j++) {
                s[j] = s[j + 1];
            }
            n--;    
            i--;   
        }
    }

    // return string up to new valid length
    // without spaces
    return s.substr(0, n);
}

int main(void) {
    int num, den;
    std::string input = "";
    string ints[3];
    std::getline(std::cin, input);

    stringstream ss(input); 

    string word;
    int counter = 0; 
    while (ss >> word) {
        ints[counter] = word; 
        counter++; 
    }
    int numerator = stoi(ints[0]); 
    int denominator = stoi(ints[2]); 
    Fraction fraction(numerator, denominator); 

	cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal " << endl;
	return 0;
}