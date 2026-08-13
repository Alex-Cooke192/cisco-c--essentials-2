#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Point2D{
public:
  Point2D(double x, double y);
  string toString();
  double toDouble();
  // ...
  double distanceTo(Point2D that);
private:
  double x;
  double y;
};

Point2D::Point2D(double x, double y) {
    this->x = x; 
    this->y = y; 
}

string Point2D::toString() {
    string str = to_string(x) + " " + to_string(y); 
    return str; 
}

double Point2D::toDouble() {
    cout << x << " " << y << endl;
    return x;
}

double Point2D::distanceTo(Point2D that) {
    double diff_x = this->x - that.x; 
    double diff_y = this->y - that.y; 
    
    double distance = sqrt((diff_x*diff_x)+(diff_y*diff_y)); 

    return distance; 
}

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

    float length = first_coordinate.distanceTo(second_coordinate); 

    cout << "Distance between cordinates = " << length << endl; 
}
