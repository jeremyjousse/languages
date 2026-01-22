#include <string>

#include <iostream>

class Car {
private:
    std::string brand;
    std::string model;
    int year;
    int maxPassengers;
    int currentPassengers;

public:
    Car(std::string b, std::string m, int y, int mP){
        brand = b;
        model = m;
        year = y;
        maxPassengers = mP;
        currentPassengers = 0;
        std::cout << "Building a " << brand << " " << model << " from " << year << " of max capacity " << maxPassengers << " passenger(s)." << std::endl;
    }

    std::string getBrand() {
        return brand;
    }

    int getCurrentPassengers(){
        std::cout << "ℹ️ There is " << currentPassengers << " passengers in " << model << "." << std::endl;
        return currentPassengers;
    }

    bool addDriver() {
        if (currentPassengers == 0){
            currentPassengers = 1;
            std::cout << "Adding driver to " << model << "." << std::endl;
            return true;
        }
        std::cout << "⚠️ There is already a driver in " << model << "." << std::endl;
        return false;
    }

    bool removeDriver(){
        if (currentPassengers > 1 ) {
            std::cout << "⚠️ There is at least a passenger in " << model << "." << std::endl;
            return false;
        } else if (currentPassengers == 1) {
            currentPassengers = 0;
            std::cout << "Removing the driver from " << model << "." << std::endl;
            return true;
        }
        std::cout << "⚠️ There is no driver in " << model << "." << std::endl;
        return false;


    }


};

int main(){
    std::cout << "hello world" << std::endl;
    Car toyotaCorola("Toyota", "Corola", 1990, 5);
    Car renaudKangoo("Renaud", "Kangoo", 2024, 5 );
    Car tracteur("Massey", "P27", 1950, 1);


    std::cout << tracteur.getBrand() << std::endl;
    std::cout << renaudKangoo.getBrand() << std::endl;
    toyotaCorola.getCurrentPassengers();
    toyotaCorola.removeDriver();
    toyotaCorola.addDriver();
    toyotaCorola.getCurrentPassengers();
    toyotaCorola.addDriver();
    toyotaCorola.getCurrentPassengers();
    toyotaCorola.removeDriver();


    return 0;
}
