#include <string>

#include <iostream>

class Car {
private:
    std::string brand;
    std::string model;
    int year;
    int maxPassengers;

public:
    Car(std::string b, std::string m, int y, int mP){
        brand = b;
        model = m;
        year = y;
        maxPassengers = mP;
        std::cout << "Building a " << brand << " " << model << " from " << year << " of max capacity " << maxPassengers << " passenger(s)." << std::endl;
    }
};

int main(){
    std::cout << "hello world" << std::endl;
    Car toyotaCorola("Toyota", "Corola", 1990, 5);
    Car renaudKangoo("Renaud", "kangoo", 2024, 5 );
    Car tracteur("Massey", "P27", 1950, 1);
    return 0;
}
