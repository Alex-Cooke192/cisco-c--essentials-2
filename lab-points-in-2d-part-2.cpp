#include <iostream>
#include <sstream>
#include <regex>

using namespace std;

// Lone methods
// -------------------------------------------------------------------
double round_to(double value, double precision = 1.0)
{
    return std::round(value / precision) * precision;
}

// Class interfaces
// ---------------------------------------------------------

class Point2D{
public:
  Point2D(double x, double y);
  string toString();
  double getX(); 
  double getY(); 
private:
  double x;
  double y;
};

class Line2D{
public:
  Line2D(double slope, double y_intercept);
  Line2D(Point2D pointA, Point2D pointB);
  string toString();
private:
  double slope;
  double y_intercept;
};

// Point2D methods
// ----------------------------------------------------
Point2D::Point2D(double x, double y) {
    this->x = x; 
    this->y = y; 
}

string Point2D::toString() {
    string str = to_string(x) + " " + to_string(y); 
    return str; 
}

double Point2D::getX() {
    return this->x; 
}

double Point2D::getY() {
    return this->y; 
}

// Line2D methods
// ------------------------------------------------------
Line2D::Line2D(double slope, double y_intercept) {
    this->slope = slope;
    this->y_intercept = y_intercept;  
}

Line2D::Line2D(Point2D pointA, Point2D pointB) {
    // Calculate slope + y-intercept
    double slope = (pointB.getY() - pointA.getY()) / (pointB.getX() - pointA.getX()); 
    double y_intercept = pointA.getY() - (slope*pointA.getX()); 

    this->slope = slope; 
    this->y_intercept = y_intercept; 
}

string Line2D::toString() {
    double slope_rounded = round_to(slope, 1.00); 
    double y_intercept_rounded = round_to(y_intercept, 1.00); 

    string str = to_string(slope_rounded) + "x + " + to_string(y_intercept_rounded);  

    // string str = to_string(slope) + "x + " + to_string(y_intercept);  
    return str; 
}

// ---------------------------------------------------------------------

int main() {
    string coordinate_1 = ""; 
    string coordinate_2 = ""; 
    double coord_1[2]; 
    double coord_2[2]; 
    std::getline(std::cin, coordinate_1); 
    std::getline(std::cin, coordinate_2); 

    stringstream ss1(coordinate_1); 
    stringstream ss2(coordinate_2); 

    string value; 
    int counter = 0; 
    while (ss1 >> value) {
        coord_1[counter] = stod(value); 
        counter++; 
    }

    counter = 0; 
    while (ss2 >> value)
    {
        coord_2[counter] = stod(value); 
        counter++; 
    }

    Point2D first_coordinate(coord_1[0], coord_1[1]); 
    Point2D second_coordinate(coord_2[0], coord_2[1]); 

    Line2D line(first_coordinate, second_coordinate); 
    string lineString = line.toString(); 

    cout << lineString << endl; 
}