#ifndef INVENTORYMANAGEMENTMAIN_H
#define INVENTORYMANAGEMENTMAIN_H

#include <iostream>
#include <string>

using namespace std;

struct Product {
    int id;
    string name;
    int quantity;
    double price;
    Product* next;

    Product(int i, string n, int q, double p) : id(i), name(n), quantity(q), price(p), next(NULL) {}
};

class InventoryManagementMain {
private:
    Product* head;

public:
    InventoryManagementMain() : head(NULL) {}

    ~InventoryManagementMain() {
        while (head) {
            Product* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addProduct(int id, string name, int quantity, double price) {
        Product* newProduct = new Product(id, name, quantity, price);
        newProduct->next = head;
        head = newProduct;
        cout << "Product added successfully!" << endl;
        system ("Pause");
    }

    void showProductList() {
        Product* current = head;
        if (current == NULL) {
            cout << "No products in inventory." << endl;
            system ("Pause");
            return;
        }
        while (current) {
            cout << "ID: " << current->id << ", Name: " << current->name
                 << ", Quantity: " << current->quantity << ", Price: $" << current->price << endl;
            current = current->next;
            system ("Pause");
        }
    }

    void updateSpecificProduct(int id) {
        Product* current = head;
        while (current) {
            if (current->id == id) {
            	system ("cls");
                int choice;
                cout << "-----------------------------------------------------" << endl;
                cout << "         Harley Inventory Management System         " << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "   Update Menu:                                       " << endl;
                cout << "                                                      " << endl;
                cout << "       [1] - Update Name"                            << endl;
                cout << "       [2] - Add Quantity"                           << endl;
                cout << "       [3] - Subtract Quantity"                      << endl; 
                cout << "       [4] - Update Price"                           << endl;
                cout << "                                                      " << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "Choose an option: ";
                cin >> choice;
                cin.ignore();

                switch (choice) {
                    case 1: {
                        string name;
                        cout << "Enter new name: ";
                        getline(cin, name);
                        current->name = name;
                        cout << "Name updated successfully!" << endl;
                        system ("Pause");
                        break;
                    }
                    case 2: {
                        int quantity;
                        cout << "Enter quantity to add: ";
                        cin >> quantity;
                        current->quantity += quantity;
                        cout << "Quantity added successfully!" << endl;
                        system ("Pause");
                        break;
                    }
                    case 3: {
                        int quantity;
                        cout << "Enter quantity to subtract: ";
                        cin >> quantity;
                        if (quantity > current->quantity) {
                            cout << "Error: Not enough quantity to subtract!" << endl;
                            system ("Pause");
                        } else {
                            current->quantity -= quantity;
                            cout << "Quantity subtracted successfully!" << endl;
                            system ("Pause");
                        }
                        break;
                    }
                    case 4: {
                        double price;
                        cout << "Enter new price: ";
                        cin >> price;
                        current->price = price;
                        cout << "Price updated successfully!" << endl;
                        system ("Pause");
                        break;
                    }
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        system ("Pause");
                        break;
                }
                return;
            }
            current = current->next;
        }
        cout << "Product not found." << endl;
    }
};

#endif

