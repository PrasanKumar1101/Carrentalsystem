# Car Rental System

This is a simple car rental system implemented in Python, Java, and C++. It allows users to rent cars, return rented cars, add new cars to the system, remove cars from the system, and exit the program.

## Classes

- **Car** (stores information):
  - ID (integer)
  - Brand (string)
  - Model (string)
  - Price per day (float)
  - Availability (boolean)
- **Customer** (represents a renting customer):
  - ID (integer, unique)
  - Name (string)
- **Rental** (links a car with a customer):
  - Car ID (integer)
  - Customer ID (integer)
  - Rental duration (integer, days)
- **CarRentalSystem** (manages the overall system):
  - Cars (list of Car objects)
  - Customers (list of Customer objects)
  - Rentals (list of Rental objects)
  - User interface (functions for menu, prompts, etc.)

## Features

- **Rent a Car**: Users can rent available cars by providing their name, selecting a car, and specifying the rental duration.
- **Return a Car**: Users can return a previously rented car by providing the car's ID.
- **Add a Car** (Admin): Admins can add new cars to the system by providing details like ID, brand, model, and base price per day.
- **Remove a Car** (Admin): Admins can remove cars from the system by providing the car's ID.
- **Exit**: Exit the program.

## Tech Stack Used

- [Python](https://www.python.org/)
- [Java](https://www.java.com/)
- [C++](https://isocpp.org/)

## How to Use

1. **Ensure you have Python, Java, and C++ installed on your system**.
2. **Clone the repository**:

    ```bash
    git clone https://github.com/yourusername/car-rental-system.git
    cd car-rental-system
    ```

3. **Run the Python program**:

    ```bash
    python main.py
    ```

4. **Run the Java program**:

    ```bash
    java Main.java
    ```

5. **Compile and run the C++ program**:

    ```bash
    g++ main.cpp -o main
    ./main
    ```

6. **Choose from the menu options** to perform various tasks.
7. **Follow the prompts** to complete the selected task.
8. **Exit the program** when done.

## Additional Notes

- Initial cars are pre-populated in the system.
- Customers are automatically assigned unique IDs.
- Car availability is automatically managed by the system based on rentals.

## Learn More

To learn more about programming languages used in this project, take a look at the following resources:

- [Python Documentation](https://docs.python.org/3/) - learn about Python features and API.
- [Java Documentation](https://docs.oracle.com/en/java/) - learn about Java features and API.
- [C++ Documentation](https://isocpp.org/) - learn about C++ features and API.

## Collaboration

Contributions are welcome! Feel free to fork the repository and submit pull requests.

## Potential Improvements

- **Persistence**: Consider saving car, customer, and rental data to a file or database for persistence across program runs.
- **User Authentication**: Implement login functionality to differentiate between users and admins. This can enhance security.
- **Reporting**: Add features to generate reports on rentals, revenue, popular cars, etc. This can provide valuable insights.

## Author
Prasan Kumar
