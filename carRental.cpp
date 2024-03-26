#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip> // for std::setprecision

class Car {
private:
    std::string carId;
    std::string brand;
    std::string model;
    double basePricePerDay;
    bool available;

public:
    Car(std::string carId, std::string brand, std::string model, double basePricePerDay) {
        this->carId = carId;
        this->brand = brand;
        this->model = model;
        this->basePricePerDay = basePricePerDay;
        this->available = true;
    }

    std::string getCarId() {
        return carId;
    }

    std::string getBrand() {
        return brand;
    }

    std::string getModel() {
        return model;
    }

    double calculatePrice(int rentalDays) {
        return basePricePerDay * rentalDays;
    }

    bool isCarAvailable() {
        return available;
    }

    void rent() {
        available = false;
    }

    void returnCar() {
        available = true;
    }
};

class Customer {
private:
    std::string customerId;
    std::string name;

public:
    Customer(std::string customerId, std::string name) {
        this->customerId = customerId;
        this->name = name;
    }

    std::string getCustomerId() {
        return customerId;
    }

    std::string getName() {
        return name;
    }
};

class Rental {
private:
    Car* car;
    Customer* customer;
    int days;

public:
    Rental(Car* car, Customer* customer, int days) {
        this->car = car;
        this->customer = customer;
        this->days = days;
    }

    Car* getCar() {
        return car;
    }

    Customer* getCustomer() {
        return customer;
    }

    int getDays() {
        return days;
    }
};

class CarRentalSystem {
private:
    std::vector<Car*> cars;
    std::vector<Customer*> customers;
    std::vector<Rental*> rentals;

public:
    CarRentalSystem() {
        // Adding initial cars
        cars.push_back(new Car("CAR1", "Toyota", "Corolla", 30.0));
        cars.push_back(new Car("CAR2", "Honda", "Civic", 35.0));
        cars.push_back(new Car("CAR3", "Ford", "Focus", 40.0));
        cars.push_back(new Car("CAR4", "Chevrolet", "Malibu", 32.5));
        cars.push_back(new Car("CAR5", "Nissan", "Altima", 33.8));
        cars.push_back(new Car("CAR6", "BMW", "3 Series", 37.2));
        cars.push_back(new Car("CAR7", "Mercedes-Benz", "C-Class", 36.5));
        cars.push_back(new Car("CAR8", "Audi", "A4", 34.7));
        cars.push_back(new Car("CAR9", "Hyundai", "Elantra", 31.5));
        cars.push_back(new Car("CAR10", "Kia", "Forte", 29.3));
        cars.push_back(new Car("CAR11", "Mazda", "Mazda3", 30.9));
        cars.push_back(new Car("CAR12", "Volkswagen", "Jetta", 28.6));
        cars.push_back(new Car("CAR13", "Subaru", "Impreza", 30.2));
        cars.push_back(new Car("CAR14", "Chrysler", "300", 33.4));
        cars.push_back(new Car("CAR15", "Buick", "Regal", 31.8));
        cars.push_back(new Car("CAR16", "Lexus", "IS", 36.1));
        cars.push_back(new Car("CAR17", "Infiniti", "Q50", 35.5));
        cars.push_back(new Car("CAR18", "Acura", "ILX", 34.0));
        cars.push_back(new Car("CAR19", "Genesis", "G70", 38.2));
        cars.push_back(new Car("CAR20", "Jaguar", "XE", 39.6));


    }

    void addCar(Car* car) {
        cars.push_back(car);
    }

    void addCustomer(Customer* customer) {
        customers.push_back(customer);
    }

    void rentCar(Car* car, Customer* customer, int days) {
        if (car->isCarAvailable()) {
            car->rent();
            rentals.push_back(new Rental(car, customer, days));
        } else {
            std::cout << "Car is not available for rent." << std::endl;
        }
    }

    void returnCar(Car* car) {
        car->returnCar();
        Rental* rentalToRemove = nullptr;
        for (Rental* rental : rentals) {
            if (rental->getCar() == car) {
                rentalToRemove = rental;
                break;
            }
        }
        if (rentalToRemove != nullptr) {
            rentals.erase(std::remove(rentals.begin(), rentals.end(), rentalToRemove), rentals.end());
        } else {
            std::cout << "Car was not rented." << std::endl;
        }
    }

    Car* getCarById(std::string carId) {
        for (Car* car : cars) {
            if (car->getCarId() == carId) {
                return car;
            }
        }
        return nullptr;
    }

    Rental* getRentalByCarId(std::string carId) {
        for (Rental* rental : rentals) {
            if (rental->getCar()->getCarId() == carId) {
                return rental;
            }
        }
        return nullptr;
    }

    void addNewCar(Car* car) {
        cars.push_back(car);
    }

    void removeCar(std::string carId) {
        Car* carToRemove = getCarById(carId);
        Rental* rentalToRemove = getRentalByCarId(carId);

        if (carToRemove != nullptr) {
            if (rentalToRemove != nullptr) {
                std::cout << "Car is currently rented. Cannot remove." << std::endl;
                return;
            }
            cars.erase(std::remove(cars.begin(), cars.end(), carToRemove), cars.end());
            std::cout << "Car removed successfully." << std::endl;
        } else {
            std::cout << "Car not found." << std::endl;
        }
    }

    void menu() {
        while (true) {
            std::cout << "1. Rent a Car" << std::endl;
            std::cout << "2. Return a Car" << std::endl;
            std::cout << "3. Add a Car" << std::endl;
            std::cout << "4. Remove a Car" << std::endl;
            std::cout << "5. Exit" << std::endl;
            std::cout << "Enter your choice: ";

            int choice;
            std::cin >> choice;
            std::cin.ignore(); // Consume newline

            if (choice == 1) {
                std::cout << "== Rent a Car ==" << std::endl;
                std::cout << "Enter your name: ";
                std::string customerName;
                std::getline(std::cin, customerName);

                std::cout << "Available Cars:" << std::endl;
                for (Car* car : cars) {
                    if (car->isCarAvailable()) {
                        std::cout << car->getCarId() << " - " << car->getBrand() << " " << car->getModel() << std::endl;
                    }
                }

                std::cout << "Enter the car ID you want to rent: ";
                std::string carId;
                std::getline(std::cin, carId);

                std::cout << "Enter the number of days for rental: ";
                int rentalDays;
                std::cin >> rentalDays;
                std::cin.ignore(); // Consume newline

                Customer* newCustomer = new Customer("CUS" + std::to_string(customers.size() + 1), customerName);
                addCustomer(newCustomer);

                Car* selectedCar = nullptr;
                for (Car* car : cars) {
                    if (car->getCarId() == carId && car->isCarAvailable()) {
                        selectedCar = car;
                        break;
                    }
                }

                if (selectedCar != nullptr) {
                    double totalPrice = selectedCar->calculatePrice(rentalDays);
                    std::cout << "== Rental Information ==" << std::endl;
                    std::cout << "Customer ID: " << newCustomer->getCustomerId() << std::endl;
                    std::cout << "Customer Name: " << newCustomer->getName() << std::endl;
                    std::cout << "Car: " << selectedCar->getBrand() << " " << selectedCar->getModel() << std::endl;
                    std::cout << "Rental Days: " << rentalDays << std::endl;
                    std::cout << "Total Price: $" << std::fixed << std::setprecision(2) << totalPrice << std::endl;

                    std::cout << "Confirm rental (Y/N): ";
                    std::string confirm;
                    std::getline(std::cin, confirm);

                    if (confirm == "Y" || confirm == "y") {
                        rentCar(selectedCar, newCustomer, rentalDays);
                        std::cout << "Car rented successfully." << std::endl;
                    } else {
                        std::cout << "Rental canceled." << std::endl;
                    }
                } else {
                    std::cout << "Invalid car selection or car not available for rent." << std::endl;
                }
            } else if (choice == 2) {
                std::cout << "== Return a Car ==" << std::endl;
                std::cout << "Enter the car ID you want to return: ";
                std::string carId;
                std::getline(std::cin, carId);

                Car* carToReturn = nullptr;
                for (Car* car : cars) {
                    if (car->getCarId() == carId && !car->isCarAvailable()) {
                        carToReturn = car;
                        break;
                    }
                }

                if (carToReturn != nullptr) {
                    Customer* customer = nullptr;
                    for (Rental* rental : rentals) {
                        if (rental->getCar() == carToReturn) {
                            customer = rental->getCustomer();
                            break;
                        }
                    }

                    if (customer != nullptr) {
                        returnCar(carToReturn);
                        std::cout << "Car returned successfully by " << customer->getName() << std::endl;
                    } else {
                        std::cout << "Car was not rented or rental information is missing." << std::endl;
                    }
                } else {
                    std::cout << "Invalid car ID or car is not rented." << std::endl;
                }
            } else if (choice == 3) {
                std::cout << "== Add a Car ==" << std::endl;
                std::cout << "Enter the car ID: ";
                std::string carId;
                std::getline(std::cin, carId);

                std::cout << "Enter the car brand: ";
                std::string brand;
                std::getline(std::cin, brand);

                std::cout << "Enter the car model: ";
                std::string model;
                std::getline(std::cin, model);

                std::cout << "Enter the car's base price per day: ";
                double basePricePerDay;
                std::cin >> basePricePerDay;
                std::cin.ignore(); // Consume newline

                Car* newCar = new Car(carId, brand, model, basePricePerDay);
                addCar(newCar);

                std::cout << "Car added successfully." << std::endl;
            } else if (choice == 4) {
                std::cout << "== Remove a Car ==" << std::endl;
                std::cout << "Enter the car ID: ";
                std::string carId;
                std::getline(std::cin, carId);

                removeCar(carId);
            } else if (choice == 5) {
                break;
            } else {
                std::cout << "Invalid choice. Please enter a valid option." << std::endl;
            }
        }

        std::cout << "Thank you for using the Car Rental System!" << std::endl;
    }
};

int main() {
    CarRentalSystem carRentalSystem;

    carRentalSystem.menu();

    return 0;
}