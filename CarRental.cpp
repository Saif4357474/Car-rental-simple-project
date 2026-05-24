#include <string>
#include <iostream>
using namespace std;

// Car structure to hold details of a car
struct Car
{
    int id;                // Unique car ID
    string brand;          // Car brand
    string model;          // Car model
    string color;          // Car color
    double rentalPrice;    // Rental price per day
    string insurance;      // Insurance details
    bool isAvailable;      // Availability status (true if available)
};

// Array to store up to 10 cars
Car cars[10];              
int carCount = 0;          // Counter to track how many cars are currently stored

// Function to modify details of a car by ID
void modifyCar(int id, double rentalPrice, string insurance, bool availability)
{
    for (int i = 0; i < carCount; i++) // Loop through all added cars
    {
        if (cars[i].id == id) // Find the car with the matching ID
        {
            // Update car details
            cars[i].rentalPrice = rentalPrice;
            cars[i].insurance = insurance;
            cars[i].isAvailable = availability;
            cout << "Car details updated successfully." << endl;
            return;
        }
    }
    // If car not found
    cout << "Car not found." << endl;
}

// Function to display all cars
void listCars()
{
    for (int i = 0; i < carCount; i++) // Loop through each car
    {
        // Display car information
        cout << "ID:" << cars[i].id 
             << " Brand:" << cars[i].brand 
             << " Model:" << cars[i].model
             << " Color:" << cars[i].color
             << " Price:" << cars[i].rentalPrice 
             << " Insurance:" << cars[i].insurance
             << " Available:" << (cars[i].isAvailable ? "Yes" : "No") << endl;
    }
}

// Function to rent a car by ID
void rentCar(int id)
{
    for (int i = 0; i < carCount; i++) // Search for the car
    {
        if (cars[i].id == id && cars[i].isAvailable) // If car is available
        {
            cars[i].isAvailable = false; // Mark as rented
            cout << "Car rented successfully!" << endl;
            return;
        }
    }
    // If car is not found or unavailable
    cout << "Car not available!" << endl;
}

// Function to return a rented car by ID
void returnCar(int id)
{
    for (int i = 0; i < carCount; i++) // Search for the car
    {
        if (cars[i].id == id && !cars[i].isAvailable) // If car is currently rented
        {
            cars[i].isAvailable = true; // Mark as available
            cout << "Car returned successfully!" << endl;
            return;
        }
    }
    // If car is not found or already available
    cout << "Car not found or not rented!" << endl;
}

// Function to add a new car
void addCar()
{
    if (carCount >= 10)
    {
        cout << "Car storage is full. Cannot add more cars." << endl;
        return;
    }

    Car newCar;
    cout << "Enter Car ID: ";
    cin >> newCar.id;
    cout << "Enter Brand: ";
    cin >> newCar.brand;
    cout << "Enter Model: ";
    cin >> newCar.model;
    cout << "Enter Color: ";
    cin >> newCar.color;
    cout << "Enter Rental Price: ";
    cin >> newCar.rentalPrice;
    cout << "Enter Insurance: ";
    cin >> newCar.insurance;
    cout << "Is Available? (1 for Yes, 0 for No): ";
    cin >> newCar.isAvailable;

    cars[carCount++] = newCar;
    cout << "Car added successfully!" << endl;
}

// Main program - menu-driven
int main()
{
    // Add some initial cars to the system
    cars[0] = {1, "Toyota", "Corolla", "White", 45.5, "Full", true};
    cars[1] = {2, "Honda", "Civic", "Black", 50.0, "Basic", true};
    cars[2] = {3, "Ford", "Focus", "Blue", 48.0, "Premium", false};
    carCount = 3;

    int choice;
    do
    {
        // Display the menu
        cout << "\nCar Rental System\n";
        cout << "1. Modify Car\n2. List Cars\n3. Rent Car\n4. Return Car\n5. Exit\n6. Add New Car\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Variables for user input
        int id;
        string brand, model, insurance, color;
        double price;
        bool available;

        // Handle user choice
        switch (choice)
        {
        case 1:
            // Modify a car's details
            cout << "Enter ID to modify, new Price, new Insurance, Availability (1/0): ";
            cin >> id >> price >> insurance >> available;
            modifyCar(id, price, insurance, available);
            break;
        case 2:
            // List all cars
            listCars();
            break;
        case 3:
            // Rent a car
            cout << "Enter Car ID to rent: ";
            cin >> id;
            rentCar(id);
            break;
        case 4:
            // Return a car
            cout << "Enter Car ID to return: ";
            cin >> id;
            returnCar(id);
            break;
        case 5:
            // Exit the system
            cout << "Exiting system..." << endl;
            break;
        case 6:
            // Add a new car
            addCar();
            break;
        default:
            // Invalid option
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 5); // Keep showing menu until user chooses to exit

    return 0;
}
