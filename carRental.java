import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Car {
    private String carId;
    private String brand;
    private String model;
    private double basePricePerDay;
    private boolean isAvailable;

    public Car(String carId, String brand, String model, double basePricePerDay) {
        this.carId = carId;
        this.brand = brand;
        this.model = model;
        this.basePricePerDay = basePricePerDay;
        this.isAvailable = true;
    }

    public String getCarId() {
        return carId;
    }

    public String getBrand() {
        return brand;
    }

    public String getModel() {
        return model;
    }

    public double calculatePrice(int rentalDays) {
        return basePricePerDay * rentalDays;
    }

    public boolean isAvailable() {
        return isAvailable;
    }

    public void rent() {
        isAvailable = false;
    }

    public void returnCar() {
        isAvailable = true;
    }
}

class Customer {
    private String customerId;
    private String name;

    public Customer(String customerId, String name) {
        this.customerId = customerId;
        this.name = name;
    }

    public String getCustomerId() {
        return customerId;
    }

    public String getName() {
        return name;
    }
}

class Rental {
    private Car car;
    private Customer customer;
    private int days;

    public Rental(Car car, Customer customer, int days) {
        this.car = car;
        this.customer = customer;
        this.days = days;
    }

    public Car getCar() {
        return car;
    }

    public Customer getCustomer() {
        return customer;
    }

    public int getDays() {
        return days;
    }
}

class CarRentalSystem {
    private List<Car> cars;
    private List<Customer> customers;
    private List<Rental> rentals;

    public CarRentalSystem() {
        cars = new ArrayList<>();
        customers = new ArrayList<>();
        rentals = new ArrayList<>();

        // Adding initial cars
        Car car1 = new Car("CAR1", "Toyota", "Corolla", 30.0);
        Car car2 = new Car("CAR2", "Honda", "Civic", 35.0);
        Car car3 = new Car("CAR3", "Ford", "Focus", 40.0);
        Car car4 = new Car("CAR4", "Chevrolet", "Malibu", 38.0);
        Car car5 = new Car("CAR5", "Nissan", "Altima", 37.0);
        Car car6 = new Car("CAR6", "Mazda", "Mazda3", 32.0);
        Car car7 = new Car("CAR7", "Hyundai", "Elantra", 36.0);
        Car car8 = new Car("CAR8", "Volkswagen", "Jetta", 34.0);
        Car car9 = new Car("CAR9", "Subaru", "Impreza", 33.0);
        Car car10 = new Car("CAR10", "Kia", "Forte", 39.0);
        Car car11 = new Car("CAR11", "Mercedes-Benz", "C-Class", 28.0);
        Car car12 = new Car("CAR12", "BMW", "3 Series", 29.0);
        Car car13 = new Car("CAR13", "Audi", "A4", 27.0);
        Car car14 = new Car("CAR14", "Lexus", "IS", 26.0);
        Car car15 = new Car("CAR15", "Tesla", "Model 3", 60.0);
        Car car16 = new Car("CAR16", "Chevrolet", "Camaro", 22.0);
        Car car17 = new Car("CAR17", "Ford", "Mustang", 25.0);
        Car car18 = new Car("CAR18", "Dodge", "Challenger", 23.0);
        Car car19 = new Car("CAR19", "Porsche", "911", 24.0);
        Car car20 = new Car("CAR20", "Jaguar", "XE", 30.0);

        cars.add(car1);
        cars.add(car2);
        cars.add(car3);
        cars.add(car4);
        cars.add(car5);
        cars.add(car6);
        cars.add(car7);
        cars.add(car8);
        cars.add(car9);
        cars.add(car10);
        cars.add(car11);
        cars.add(car12);
        cars.add(car13);
        cars.add(car14);
        cars.add(car15);
        cars.add(car16);
        cars.add(car17);
        cars.add(car18);
        cars.add(car19);
        cars.add(car20);
    }

    public void addCar(Car car) {
        cars.add(car);
    }

    public void addCustomer(Customer customer) {
        customers.add(customer);
    }

    public void rentCar(Car car, Customer customer, int days) {
        if (car.isAvailable()) {
            car.rent();
            rentals.add(new Rental(car, customer, days));

        } else {
            System.out.println("Car is not available for rent.");
        }
    }

    public void returnCar(Car car) {
        car.returnCar();
        Rental rentalToRemove = null;
        for (Rental rental : rentals) {
            if (rental.getCar() == car) {
                rentalToRemove = rental;
                break;
            }
        }
        if (rentalToRemove != null) {
            rentals.remove(rentalToRemove);

        } else {
            System.out.println("Car was not rented.");
        }
    }

    private Car getCarById(String carId) {
        for (Car car : cars) {
            if (car.getCarId().equals(carId)) {
                return car;
            }
        }
        return null;
    }

    private Rental getRentalByCarId(String carId) {
        for (Rental rental : rentals) {
            if (rental.getCar().getCarId().equals(carId)) {
                return rental;
            }
        }
        return null;
    }

    public void addNewCar(Car car) {
        cars.add(car);
    }

    public void removeCar(String carId) {
        Car carToRemove = getCarById(carId);
        Rental rentalToRemove = getRentalByCarId(carId);

        if (carToRemove != null) {
            if (rentalToRemove != null) {
                System.out.println("Car is currently rented. Cannot remove.");
                return;
            }
            cars.remove(carToRemove);
            System.out.println("Car removed successfully.");
        } else {
            System.out.println("Car not found.");
        }
    }

    public void menu() {
        Scanner scanner = new Scanner(System.in);

        while (true) {
            System.out.println("1. Rent a Car");
            System.out.println("2. Return a Car");
            System.out.println("3. Add a Car");
            System.out.println("4. Remove a Car");
            System.out.println("5. Exit");
            System.out.print("Enter your choice: ");

            int choice = scanner.nextInt();
            scanner.nextLine(); // Consume newline

            if (choice == 1) {
                System.out.println("\n== Rent a Car ==\n");
                System.out.print("Enter your name: ");
                String customerName = scanner.nextLine();

                System.out.println("\nAvailable Cars:");
                for (Car car : cars) {
                    if (car.isAvailable()) {
                        System.out.println(car.getCarId() + " - " + car.getBrand() + " " + car.getModel());
                    }
                }

                System.out.print("\nEnter the car ID you want to rent: ");
                String carId = scanner.nextLine();

                System.out.print("Enter the number of days for rental: ");
                int rentalDays = scanner.nextInt();
                scanner.nextLine(); // Consume newline

                Customer newCustomer = new Customer("CUS" + (customers.size() + 1), customerName);
                addCustomer(newCustomer);

                Car selectedCar = null;
                for (Car car : cars) {
                    if (car.getCarId().equals(carId) && car.isAvailable()) {
                        selectedCar = car;
                        break;
                    }
                }

                if (selectedCar != null) {
                    double totalPrice = selectedCar.calculatePrice(rentalDays);
                    System.out.println("\n== Rental Information ==\n");
                    System.out.println("Customer ID: " + newCustomer.getCustomerId());
                    System.out.println("Customer Name: " + newCustomer.getName());
                    System.out.println("Car: " + selectedCar.getBrand() + " " + selectedCar.getModel());
                    System.out.println("Rental Days: " + rentalDays);
                    System.out.printf("Total Price: $%.2f%n", totalPrice);

                    System.out.print("\nConfirm rental (Y/N): ");
                    String confirm = scanner.nextLine();

                    if (confirm.equalsIgnoreCase("Y")) {
                        rentCar(selectedCar, newCustomer, rentalDays);
                        System.out.println("\nCar rented successfully.");
                    } else {
                        System.out.println("\nRental canceled.");
                    }
                } else {
                    System.out.println("\nInvalid car selection or car not available for rent.");
                }
            } else if (choice == 2) {
                System.out.println("\n== Return a Car ==\n");
                System.out.print("Enter the car ID you want to return: ");
                String carId = scanner.nextLine();

                Car carToReturn = null;
                for (Car car : cars) {
                    if (car.getCarId().equals(carId) && !car.isAvailable()) {
                        carToReturn = car;
                        break;
                    }
                }

                if (carToReturn != null) {
                    Customer customer = null;
                    for (Rental rental : rentals) {
                        if (rental.getCar() == carToReturn) {
                            customer = rental.getCustomer();
                            break;
                        }
                    }

                    if (customer != null) {
                        returnCar(carToReturn);
                        System.out.println("Car returned successfully by " + customer.getName());
                    } else {
                        System.out.println("Car was not rented or rental information is missing.");
                    }
                } else {
                    System.out.println("Invalid car ID or car is not rented.");
                }
            } else if (choice == 3) {
                System.out.println("\n== Add a Car ==\n");
                System.out.print("Enter the car ID: ");
                String carId = scanner.nextLine();

                System.out.print("Enter the car brand: ");
                String brand = scanner.nextLine();

                System.out.print("Enter the car model: ");
                String model = scanner.nextLine();

                System.out.print("Enter the car's base price per day: ");
                double basePricePerDay = scanner.nextDouble();
                scanner.nextLine(); // Consume newline

                Car newCar = new Car(carId, brand, model, basePricePerDay);
                addNewCar(newCar);

                System.out.println("\nCar added successfully.");

            } else if (choice == 4) {
                System.out.println("\n== Remove a Car ==\n");
                System.out.print("Enter the car ID: ");
                String carId = scanner.nextLine();

                removeCar(carId);
            } else if (choice == 5) {
                break;
            } else {
                System.out.println("Invalid choice. Please enter a valid option.");
            }
        }

        System.out.println("\nThank you for using the Car Rental System!");
    }
}

public class Main {
    public static void main(String[] args) {
        CarRentalSystem carRentalSystem = new CarRentalSystem();
        carRentalSystem.menu();
    }
}