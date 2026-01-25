#include <string>

#include <iostream>

// Define a vehicle abstract class
// Abstract class has pur function that is not implemented and turns 0;
class Vehicle {
protected:
    int numberWheels;
    void addWheels(int nW) {
        numberWheels = nW;
    };
    Vehicle(){
        numberWheels = 0;
    }
public:
    int getNumberWheels() {
        std::cout << "ℹ️ This vehicle has " << numberWheels << " wheels." << std::endl;
        return numberWheels;
    }

};


class Car : public Vehicle {
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
        addWheels(4);
        std::cout << "Building a " << brand << " " << model << " from " << year << " of max capacity " << maxPassengers << " passenger(s)." << std::endl;
    }

    std::string getBrand() {
        return brand;
    }


    bool addPassengers(int nP){
        if (currentPassengers == 0){
            std::cout << "⚠️ There is no driver in " << model << "!" << std::endl;
            return false;
        }
        if (currentPassengers + nP > maxPassengers){
            std::cout << "⚠️ There is already " << currentPassengers << " passengers in " << model << ", max is " << maxPassengers << ", you can't add " << nP << " more!" << std::endl;
            return false;
        }
        currentPassengers += nP;
        std::cout << "Adding " << nP << " passengers to " << model << "." << std::endl;
        return true;
    }

    void displayCurrentPassengers(){
        std::cout << "ℹ️ There is " << (currentPassengers -1 ) << " passengers in " << model << "." << std::endl;
    }

    int getCurrentPassengers(){
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
    Car renaultKangoo("Renault", "Kangoo", 2024, 5 );
    Car tracteur("Massey", "P27", 1950, 1);


    std::cout << tracteur.getBrand() << std::endl;
    std::cout << renaultKangoo.getBrand() << std::endl;
    toyotaCorola.getCurrentPassengers();
    toyotaCorola.removeDriver();
    toyotaCorola.addDriver();
    toyotaCorola.addDriver();
    toyotaCorola.displayCurrentPassengers();
    toyotaCorola.addPassengers(1);
    toyotaCorola.addPassengers(4);
    toyotaCorola.addPassengers(3);
    
    toyotaCorola.removeDriver();
    toyotaCorola.displayCurrentPassengers();
    toyotaCorola.getNumberWheels();
    
    toyotaCorola.removeDriver();
    return 0;
}
