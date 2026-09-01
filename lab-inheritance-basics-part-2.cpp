#include <iostream>
#include <sstream>

using namespace std;

// FOR TOMORROW: 
// water comsumption = daily consumption * weight

class FarmAnimal{
public:
  FarmAnimal(double water_consumption, double weight);
  double getWaterConsumption();
  // ...
private:
  double water_consumption;
protected:
  double weight; 
};

FarmAnimal::FarmAnimal(double water_consumption, double weight) {
  this->water_consumption = water_consumption;
  this->weight = weight; 
}; 

double FarmAnimal::getWaterConsumption() {
  return water_consumption;
}; 

// ------------------------------------------------------------

class Cow : public FarmAnimal {
public:
  Cow(double water_consumption, double weight); 
}; 

Cow::Cow(double water_consumption, double weight) : FarmAnimal((8.6/100)*weight, weight) {
}; 

// ----------------------------------------------------------

class Sheep : public FarmAnimal {
public:
  Sheep(double water_consumption, double weight); 
}; 

Sheep::Sheep(double water_consumption, double weight) : FarmAnimal((1.1/10)*weight, weight) {
}; 

// ------------------------------------------------------------

class Horse : public FarmAnimal {
public:
  Horse(double water_consumption, double weight); 
};

Horse::Horse(double water_consumption, double weight) : FarmAnimal((6.8/100)*weight, weight) {
};

// ------------------------------------------------------------

class ConsumptionAccumulator
{
public:
  ConsumptionAccumulator();
  double getTotalConsumption();
  void addConsumption(FarmAnimal &FarmAnimal);
private:
  double total_consumption;
};

ConsumptionAccumulator::ConsumptionAccumulator() :
  total_consumption(0)
{
}

double ConsumptionAccumulator::getTotalConsumption()
{
  return total_consumption;
}

void ConsumptionAccumulator::addConsumption(FarmAnimal &FarmAnimal)
{
  total_consumption += FarmAnimal.getWaterConsumption();
}


int main()
{
  ConsumptionAccumulator accumulator;

  // read user input
  // create appropriate objects and add them to the accumulator
  string inputValue = ""; 
  string input[2]; 
  while (true) {
    std::getline(std::cin, inputValue); 
    if (inputValue == "") {
        break; 
    }
    stringstream ss(inputValue);
    
    string token; 
    // Put input into an array
    int counter = 0; 
    while (ss >> token) {
        input[counter] = token; 
        counter++; 
    }
    // Figure out which amimal to create
    string name = input[0]; 
    double weight = std::stod(input[1]);
    if (name == "Sheep" || name == "sheep") {
        // Create a sheep
        Sheep sheep(weight, weight); 
        accumulator.addConsumption(sheep);  
    } else if (name == "Cow" || name =="cow") {
        // Create a cow
        Cow cow (weight, weight); 
        accumulator.addConsumption(cow);  
    } else if (name == "Horse" || name == "horse") {
        // Create a horse
        Horse horse(weight, weight);
        accumulator.addConsumption(horse);  
    } else {
        std::cout << "Animal invalid, try again" << std::endl;
        continue;
    }; 
  }; 

  cout << accumulator.getTotalConsumption();

  return 0;
}