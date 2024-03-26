class Car:
    def _init_(self, carId, brand, model, basePricePerDay):
        self.carId = carId
        self.brand = brand
        self.model = model
        self.basePricePerDay = basePricePerDay
        self.available = True

    def getCarId(self):
        return self.carId

    def getBrand(self):
        return self.brand

    def getModel(self):
        return self.model

    def calculatePrice(self, rentalDays):
        return self.basePricePerDay * rentalDays

    def isCarAvailable(self):
        return self.available

    def rent(self):
        self.available = False

    def returnCar(self):
        self.available = True


class Customer:
    def _init_(self, customerId, name):
        self.customerId = customerId
        self.name = name

    def getCustomerId(self):
        return self.customerId

    def getName(self):
        return self.name


class Rental:
    def _init_(self, car, customer, days):
        self.car = car
        self.customer = customer
        self.days = days

    def getCar(self):
        return self.car

    def getCustomer(self):
        return self.customer

    def getDays(self):
        return self.days


class CarRentalSystem:
    def _init_(self):
        self.cars = []
        self.customers = []
        self.rentals = []

        # Adding initial cars
        car1 = Car("CAR1", "Toyota", "Corolla", 30.0)
        car2 = Car("CAR2", "Honda", "Civic", 35.0)
        car3 = Car("CAR3", "Ford", "Focus", 40.0)
        car4 = Car("CAR4", "Chevrolet", "Malibu", 32.5)
        car5 = Car("CAR5", "Nissan", "Altima", 33.8)
        car6 = Car("CAR6", "BMW", "3 Series", 37.2)
        car7 = Car("CAR7", "Mercedes-Benz", "C-Class", 36.5)
        car8 = Car("CAR8", "Audi", "A4", 34.7)
        car9 = Car("CAR9", "Hyundai", "Elantra", 31.5)
        car10 = Car("CAR10", "Kia", "Forte", 29.3)
        car11 = Car("CAR11", "Mazda", "Mazda3", 30.9)
        car12 = Car("CAR12", "Volkswagen", "Jetta", 28.6)
        car13 = Car("CAR13", "Subaru", "Impreza", 30.2)
        car14 = Car("CAR14", "Chrysler", "300", 33.4)
        car15 = Car("CAR15", "Buick", "Regal", 31.8)
        car16 = Car("CAR16", "Lexus", "IS", 36.1)
        car17 = Car("CAR17", "Infiniti", "Q50", 35.5)
        car18 = Car("CAR18", "Acura", "ILX", 34.0)
        car19 = Car("CAR19", "Genesis", "G70", 38.2)
        car20 = Car("CAR20", "Jaguar", "XE", 39.6)

        self.cars.append(car1)
        self.cars.append(car2)
        self.cars.append(car3)
        self.cars.append(car4)
        self.cars.append(car5)
        self.cars.append(car6)
        self.cars.append(car7)
        self.cars.append(car8)
        self.cars.append(car9)
        self.cars.append(car10)
        self.cars.append(car11)
        self.cars.append(car12)
        self.cars.append(car13)
        self.cars.append(car14)
        self.cars.append(car15)
        self.cars.append(car16)
        self.cars.append(car17)
        self.cars.append(car18)
        self.cars.append(car19)
        self.cars.append(car20)

    def addCar(self, car):
        self.cars.append(car)

    def addCustomer(self, customer):
        self.customers.append(customer)

    def rentCar(self, car, customer, days):
        if car.isCarAvailable():
            car.rent()
            self.rentals.append(Rental(car, customer, days))
        else:
            print("Car is not available for rent.")

    def returnCar(self, car):
        car.returnCar()
        rentalToRemove = None
        for rental in self.rentals:
            if rental.getCar() == car:
                rentalToRemove = rental
                break
        if rentalToRemove is not None:
            self.rentals.remove(rentalToRemove)
        else:
            print("Car was not rented.")

    def getCarById(self, carId):
        for car in self.cars:
            if car.getCarId() == carId:
                return car
        return None

    def getRentalByCarId(self, carId):
        for rental in self.rentals:
            if rental.getCar().getCarId() == carId:
                return rental
        return None

    def addNewCar(self, car):
        self.cars.append(car)

    def removeCar(self, carId):
        carToRemove = self.getCarById(carId)
        rentalToRemove = self.getRentalByCarId(carId)

        if carToRemove is not None:
            if rentalToRemove is not None:
                print("Car is currently rented. Cannot remove.")
                return
            self.cars.remove(carToRemove)
            print("Car removed successfully.")
        else:
            print("Car not found.")

    def menu(self):
        while True:
            print("1. Rent a Car")
            print("2. Return a Car")
            print("3. Add a Car")
            print("4. Remove a Car")
            print("5. Exit")
            choice = int(input("Enter your choice: "))

            if choice == 1:
                print("== Rent a Car ==")
                customerName = input("Enter your name: ")

                print("Available Cars:")
                for car in self.cars:
                    if car.isCarAvailable():
                        print(car.getCarId(), "-", car.getBrand(), car.getModel())

                carId = input("Enter the car ID you want to rent: ")
                rentalDays = int(input("Enter the number of days for rental: "))

                newCustomer = Customer("CUS" + str(len(self.customers) + 1), customerName)
                self.addCustomer(newCustomer)

                selectedCar = None
                for car in self.cars:
                    if car.getCarId() == carId and car.isCarAvailable():
                        selectedCar = car
                        break

                if selectedCar is not None:
                    totalPrice = selectedCar.calculatePrice(rentalDays)
                    print("== Rental Information ==")
                    print("Customer ID:", newCustomer.getCustomerId())
                    print("Customer Name:", newCustomer.getName())
                    print("Car:", selectedCar.getBrand(), selectedCar.getModel())
                    print("Rental Days:", rentalDays)
                    print("Total Price: $", format(totalPrice, ".2f"))

                    confirm = input("Confirm rental (Y/N): ")

                    if confirm == "Y" or confirm == "y":
                        self.rentCar(selectedCar, newCustomer, rentalDays)
                        print("Car rented successfully.")
                    else:
                        print("Rental canceled.")
                else:
                    print("Invalid car selection or car not available for rent.")
            elif choice == 2:
                print("== Return a Car ==")
                carId = input("Enter the car ID you want to return: ")

                carToReturn = None
                for car in self.cars:
                    if car.getCarId() == carId and not car.isCarAvailable():
                        carToReturn = car
                        break

                if carToReturn is not None:
                    customer = None
                    for rental in self.rentals:
                        if rental.getCar() == carToReturn:
                            customer = rental.getCustomer()
                            break

                    if customer is not None:
                        self.returnCar(carToReturn)
                        print("Car returned successfully by", customer.getName())
                    else:
                        print("Car was not rented or rental information is missing.")
                else:
                    print("Invalid car ID or car is not rented.")
            elif choice == 3:
                print("== Add a Car ==")
                carId = input("Enter the car ID: ")
                brand = input("Enter the car brand: ")
                model = input("Enter the car model: ")
                basePricePerDay = float(input("Enter the car's base price per day: "))

                newCar = Car(carId, brand, model, basePricePerDay)
                self.addCar(newCar)

                print("Car added successfully.")
            elif choice == 4:
                print("== Remove a Car ==")
                carId = input("Enter the car ID: ")

                self.removeCar(carId)
            elif choice == 5:
                break
            else:
                print("Invalid choice. Please enter a valid option.")

        print("Thank you for using the Car Rental System!")


carRentalSystem = CarRentalSystem()
carRentalSystem.menu()