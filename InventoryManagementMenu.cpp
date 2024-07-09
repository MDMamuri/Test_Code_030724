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
                int id, quantity;
                string name;
                double price;

                cout << "Enter product ID: ";
                cin >> id;
                cout << "Enter product name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter product quantity: ";
                cin >> quantity;
                cout << "Enter product price: ";
                cin >> price;

                inv.addProduct(id, name, quantity, price);
                activityLog.addLog("Added Product");
                break;
            }
            case 2:
                inv.showProductList();
                activityLog.addLog("Viewed Product List");
                system("pause"); // Pause after displaying the list
                break;
            case 3: {
                int id;
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
                system("pause");
                break;
        }

    } while (choice != 4);
}

