#include "InventoryManagementMenu.h"
#include "ActivityLogMenu.h"
#include <iostream>

using namespace std;

void InventoryManagementMenu(InventoryManagementMain& inv, ActivityLog& activityLog, int& choice) {
    do {
        system("cls");
        cout << "-----------------------------------------------------" << endl;
        cout << "         Harley Inventory Management System         " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "                                                     " << endl;
        cout << "    Inventory Management                            " << endl;
        cout << "                                                     " << endl;
        cout << "        [1] - Add Product                            " << endl;
        cout << "        [2] - Show Product List                      " << endl;
        cout << "        [3] - Update Specific Product                " << endl;
        cout << "        [4] - Exit                                    " << endl;
        cout << "                                                     " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int quantity;
                string name;
                double price;

                system("cls");
                cout << "Enter product name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter product quantity: ";
                cin >> quantity;
                cout << "Enter product price: ";
                cin >> price;

                inv.addProduct(name, quantity, price); 
                activityLog.addLog("Added Product");
                break;
            }
            case 2:
                inv.showProductList();
                activityLog.addLog("Viewed Product List");
                system("pause");
                break;
            case 3: {
                int id;
                inv.showProductList();
                cout << "Enter product ID to update: ";
                cin >> id;
                inv.updateSpecificProduct(id, activityLog);
                break;
            }
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                activityLog.addLog("Exited Inventory Management");
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

    } while (choice != 4);
}

