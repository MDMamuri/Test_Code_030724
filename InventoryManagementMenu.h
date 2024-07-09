#ifndef INVENTORYMANAGEMENTMAIN_H
#define INVENTORYMANAGEMENTMAIN_H

#include "ActivityLogMenu.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

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

    int generateRandomID() {
        srand(time(0)); 
        return rand() % 1000000000; 
    }

    void deleteProduct(Product* productToDelete) {
        if (!head) return;
        
        if (head == productToDelete) {
            head = head->next;
        } else {
            Product* current = head;
            while (current->next && current->next != productToDelete) {
                current = current->next;
            }
            if (current->next == productToDelete) {
                current->next = productToDelete->next;
            }
        }
        delete productToDelete;
        cout << "Product deleted successfully!" << endl;
    }

    bool productExists(const string& name) {
        string lowerName = toLower(name);

        Product* current = head;
        while (current) {
            if (toLower(current->name) == lowerName) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    string toLower(const string& str) {
        string lowerStr = str;
        for (size_t i = 0; i < lowerStr.size(); ++i) {
            lowerStr[i] = tolower(lowerStr[i]);
        }
        return lowerStr;
    }

public:
    InventoryManagementMain() : head(NULL) {}

    ~InventoryManagementMain() {
        while (head) {
            Product* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addProduct(string name, int quantity, double price) {
        if (productExists(name)) {
            cout << "Product already exists!" << endl;
            system("pause");
            return;
        }
        
        int id = generateRandomID(); 
        Product* newProduct = new Product(id, name, quantity, price);
        newProduct->next = head;
        head = newProduct;
        cout << "Product added successfully!" << endl;
        system("pause"); 
    }

    void showProductList() {
        Product* current = head;
        if (current == NULL) {
            cout << "No products in inventory." << endl;
            return;
        }
        while (current) {
            cout << "ID: " << current->id << ", Name: " << current->name
                 << ", Quantity: " << current->quantity << ", Price: $" << current->price << endl;
            current = current->next;
        } 
    }

    void updateSpecificProduct(int id, ActivityLog& activityLog) {
        Product* current = head;
        while (current) {
            if (current->id == id) {
                int choice;
                system("cls");
                cout << "=====================================================" << endl;
                cout << "         Harley Report Management System             " << endl;
                cout << "=====================================================" << endl;
                cout << "                                                     " << endl;
                cout << "   Update Menu:                                      " << endl;
                cout << "                                                     " << endl;
                cout << "       [1] - Update Name"                              << endl;
                cout << "       [2] - Add Quantity"                             << endl;
                cout << "       [3] - Subtract Quantity"                        << endl;
                cout << "       [4] - Update Price"                             << endl;
                cout << "                                                      "<< endl;
                cout << "=====================================================" << endl;
                cout << "Choose an option: ";
                cin >> choice;
                cin.ignore();

                switch (choice) {
                    case 1: {
                        string name;
                        system("cls");
                        cout << "=====================================================" << endl;
                        cout << "         Harley Report Management System             " << endl;
                        cout << "=====================================================" << endl;
                        cout << "                                                     " << endl;
                        cout << "Enter new name: ";
                        getline(cin, name);

                        if (productExists(name)) {
                            cout << "Product name already exists!" << endl;
                            activityLog.addLog("Product name update failed: name already exists.");
                        } else {
                            current->name = name;
                            cout << "Name updated successfully!" << endl;
                            activityLog.addLog("Product Name updated successfully!");
                        }
                        cout << "                                                     " << endl;
                        cout << "=====================================================" << endl;
                        system("pause");
                        break;
                    }
                    case 2: {
                        int quantity;
                        system("cls");
                        cout << "=====================================================" << endl;
                        cout << "         Harley Report Management System             " << endl;
                        cout << "=====================================================" << endl;
                        cout << "                                                     " << endl;
                        cout << "Enter quantity to add: ";
                        cin >> quantity;
                        current->quantity += quantity;
                        cout << "Quantity added successfully!" << endl;
                        activityLog.addLog("Product Quantity added successfully!");
                        cout << "                                                     " << endl;
                        cout << "=====================================================" << endl;
                        system("pause"); 
                        break;
                    }
                    case 3: {
                        int quantity;
                        system("cls");
                        cout << "=====================================================" << endl;
                        cout << "         Harley Report Management System             " << endl;
                        cout << "=====================================================" << endl;
                        cout << "                                                     " << endl;
                        cout << "Enter quantity to subtract: ";
                        cin >> quantity;
                        if (quantity > current->quantity) {
                            cout << "Error: Not enough quantity to subtract!" << endl;
                            cout << "                                                     " << endl;
                            cout << "=====================================================" << endl;
                            activityLog.addLog("Error: Not enough quantity to subtract!");
                            system("pause"); 
                        } else {
                            current->quantity -= quantity;
                            if (current->quantity == 0) {
                                Product* temp = current;
                                current = current->next;
                                deleteProduct(temp);
                                cout << "                                                     " << endl;
                                cout << "=====================================================" << endl;
                                activityLog.addLog("Product deleted due to quantity reaching 0!");
                            } else {
                                cout << "Quantity subtracted successfully!" << endl;
                                activityLog.addLog("Product Quantity subtracted successfully!");
                                cout << "                                                     " << endl;
                                cout << "=====================================================" << endl;
                            }
                            system("pause"); 
                        }
                        break;
                    }
                    case 4: {
                        double price;
                        system("cls");
                        cout << "=====================================================" << endl;
                        cout << "         Harley Report Management System             " << endl;
                        cout << "=====================================================" << endl;
                        cout << "                                                     " << endl;
                        cout << "Enter new price: ";
                        cin >> price;
                        current->price = price;
                        cout << "Price updated successfully!" << endl;
                        cout << "                                                     " << endl;
                        cout << "=====================================================" << endl;
                        system("pause"); 
                        break;
                    }
                    default:
                        cout << "Invalid choice. Please try again." << endl;
                        system("pause"); 
                        break;
                }
                return;
            }
            current = current->next;
        }
        cout << "Product not found." << endl;
        system("pause");
    }
};

#endif

