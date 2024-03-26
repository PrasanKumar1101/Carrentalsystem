# Car Rental System

This is a simple car rental system implemented in Python. It allows users to rent cars, return rented cars, add new cars to the system, remove cars from the system, and exit the program.

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

## How to Use

1. **Run the program**.
2. **Choose from the menu options** to perform various tasks.
3. **Follow the prompts** to complete the selected task.
4. **Exit the program** when done.

## Additional Notes

- Initial cars are pre-populated in the system.
- Customers are automatically assigned unique IDs.
- Car availability is automatically managed by the system based on rentals.

## Collaboration

Contributions are welcome! Feel free to fork the repository and submit pull requests.

## Potential Improvements

- **Persistence**: Consider saving car, customer, and rental data to a file or database for persistence across program runs.
- **User Authentication**: Implement login functionality to differentiate between users and admins. This can enhance security.
- **Reporting**: Add features to generate reports on rentals, revenue, popular cars, etc. This can provide valuable insights.

This document provides a clear and informative overview of a Python car rental system. With further development, it can become a robust and user-friendly application.
