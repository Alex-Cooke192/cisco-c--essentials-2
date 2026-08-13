#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Fraction{
public:
  Fraction(int numerator, int denominator);
  string toString();
  double toDouble();
  Fraction simplify(); 
  // the functions below do not change the object
  // on which they are called, they produce a new object
  Fraction plus(Fraction that);
  Fraction minus(Fraction that);
  Fraction times(Fraction that);
  Fraction by(Fraction that);
private:
  int numerator;
  int denominator;
  void reduce();
};

Fraction::Fraction(int numerator, int denominator) {
    this->numerator = numerator; 
    this->denominator = denominator; 
}

Fraction Fraction::plus(Fraction that) {
    int num, den;
    if (this->denominator == that.denominator) {
        den = this->denominator; 
        num = this->numerator + that.numerator; 
    } else {
        // Multiply numbers together to get a common multiple
        den = this->denominator * that.denominator;
        num = (this->numerator * that.denominator) + (that.numerator * this->denominator); 
    }
    Fraction result(num, den); 

    return result; 
}

Fraction Fraction::minus(Fraction that) {
    int num, den; 
    if (this->denominator == that.denominator) {
        den = this->denominator; 
        num = this->numerator - that.numerator; 
    } else {
        // Multiply numbers together to get a common multiple
        den = this->denominator * that.denominator;
        num = (this->numerator * that.denominator) - (that.numerator * this->denominator); 
    }
    Fraction result(num, den); 

    return result; 
}

Fraction Fraction::times(Fraction that)
{
  int num = this->numerator * that.denominator;
  int den = this->denominator * that.denominator;
  Fraction result(num, den);
  // we could call result.reduce() here
  // or use it just before it is necessary
  return result;
}

Fraction Fraction::by(Fraction that) {
    int num = this->numerator * (that.denominator); 
    int den = this-> denominator * (that.numerator); 

    Fraction result(num, den); 

    return result; 
}

Fraction Fraction::simplify() {
    for (int i = 1; i < 11; i++) {
        for (int j = 1; j < 11; j++) {
            if ((this->numerator % j == 0) && (this->denominator % j ==0)) 
            {
                this->numerator = this->numerator/j;
                this->denominator = this->denominator/j; 
            }
        }
    }
    Fraction result(this->numerator, this->denominator); 

    return result; 
}

string Fraction::toString() {
    string str; 

    int intValue = 0; 
    while (abs(numerator) > abs(denominator)) {
        numerator -= denominator; 
        intValue++;
    }

    if (denominator < 0 && numerator > 0) {
        denominator *= -1; 
        numerator *= -1; 
        intValue = -abs(intValue); 
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

int main(void) {
    int num, den;
    std::string input1 = "";
    std::string input2 = ""; 
    string ints[3];
    std::getline(std::cin, input1);
    std::getline(std::cin, input2); 

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

	//cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal " << endl;

    cout << fraction_1.plus(fraction_2).simplify().toString() << endl; 
    cout << fraction_1.minus(fraction_2).simplify().toString() << endl; 
    cout << fraction_1.times(fraction_2).simplify().toString() << endl; 
    cout << fraction_1.by(fraction_2).simplify().toString() << endl; 
	return 0;
}