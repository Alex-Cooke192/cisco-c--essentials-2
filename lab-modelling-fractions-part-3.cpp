#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator);

    string toString();
    double toDouble();

    bool isGreaterThan(Fraction that);
    bool isLessThan(Fraction that);
    bool isEqual(Fraction that);

private:
    int numerator;
    int denominator;

    void reduce();
};


Fraction::Fraction(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;

    reduce();
}


void Fraction::reduce() {

    int num = abs(numerator);
    int den = abs(denominator);

    int greatestFactor = 1;

    for (int i = 1; i <= num && i <= den; i++) {
        if (num % i == 0 && den % i == 0) {
            greatestFactor = i;
        }
    }

    numerator /= greatestFactor;
    denominator /= greatestFactor;

    // Keep the negative sign on the numerator
    if (denominator < 0) {
        denominator *= -1;
        numerator *= -1;
    }
}


// Type manipulation methods
// ------------------------------------------------------------

string Fraction::toString() {

    int wholeNumber = numerator / denominator;
    int remainder = numerator % denominator;

    // Proper fraction
    if (wholeNumber == 0) {
        return to_string(numerator) + "/" + to_string(denominator);
    }

    // Exact whole number
    if (remainder == 0) {
        return to_string(wholeNumber);
    }

    // Mixed number
    return to_string(wholeNumber) + " " +
           to_string(abs(remainder)) + "/" +
           to_string(abs(denominator));
}


double Fraction::toDouble() {
    return double(numerator) / double(denominator);
}


// Comparison methods
// ------------------------------------------------------------

bool Fraction::isGreaterThan(Fraction that) {
    return this->toDouble() > that.toDouble();
}


bool Fraction::isLessThan(Fraction that) {
    return this->toDouble() < that.toDouble();
}


bool Fraction::isEqual(Fraction that) {
    return this->toDouble() == that.toDouble();
}


// Main
// ------------------------------------------------------------

int main() {

    string input1 = "";
    string input2 = "";
    string ints[3];

    cout << "Enter first fraction (e.g. 7 / 3): ";
    getline(cin, input1);

    cout << "Enter second fraction (e.g. 2 / 3): ";
    getline(cin, input2);


    stringstream ss1(input1);
    stringstream ss2(input2);

    string word;
    int counter = 0;

    while (ss1 >> word) {
        ints[counter] = word;
        counter++;
    }

    int numerator_1 = stoi(ints[0]);
    int denominator_1 = stoi(ints[2]);


    counter = 0;

    while (ss2 >> word) {
        ints[counter] = word;
        counter++;
    }

    int numerator_2 = stoi(ints[0]);
    int denominator_2 = stoi(ints[2]);


    Fraction fraction_1(numerator_1, denominator_1);
    Fraction fraction_2(numerator_2, denominator_2);


    if (fraction_1.isGreaterThan(fraction_2)) {

        cout << fraction_1.toString()
             << " > "
             << fraction_2.toString()
             << endl;

    } else if (fraction_1.isLessThan(fraction_2)) {

        cout << fraction_1.toString()
             << " < "
             << fraction_2.toString()
             << endl;

    } else {

        cout << fraction_1.toString()
             << " = "
             << fraction_2.toString()
             << endl;
    }

    return 0;
}