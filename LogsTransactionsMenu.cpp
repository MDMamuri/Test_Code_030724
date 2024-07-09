#include "LogsTransactionsMenu.h"
#include <iostream>
#include <string>

using namespace std;

void LogsTransactionsMainMenu(LogsManagementMain& logSystem, int& choice) {
    int id;
    string description;

    system("cls");

    do {
        cout << "=====================================================" << endl;
        cout << "         Harley Report Management System             " << endl;
        cout << "=====================================================" << endl;
        cout << "                                                     " << endl;
        cout << "  Logs of Transactions                               " << endl;
        cout << "                                                     " << endl;
        cout << "        [1] - Log Transaction                        " << endl;
        cout << "        [2] - Transaction History                    " << endl;
        cout << "        [3] - Search Transaction                     " << endl;
        cout << "        [4] - Delete Transaction                     " << endl;
        cout << "        [5] - Return Main Menu                       " << endl;
        cout << "                                                     " << endl;
        cout << "=====================================================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if ((choice >= 2 && choice <= 5) && !logSystem.hasTransactions()) {
            cout << "No transactions found." << endl;
            system("pause");
            continue;
        }

        switch (choice) {
        case 1:
            system("cls");
            cout << "=====================================================" << endl;
        	cout << "         Harley Report Management System             " << endl;
        	cout << "=====================================================" << endl;
        	cout << "                                                     " << endl;
            cout << "Enter Transaction ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Transaction Description: ";
            getline(cin, description);
            logSystem.logTransaction(id, description);
            cout << "                                                     " << endl;
            cout << "=====================================================" << endl;
            break;

        case 2:
            system("cls");
            cout << "=====================================================" << endl;
        	cout << "         Harley Report Management System             " << endl;
        	cout << "=====================================================" << endl;
        	cout << "                                                     " << endl;
            logSystem.displayTransactions();
            cout << "                                                     " << endl;
            cout << "=====================================================" << endl;
            break;

        case 3:
            system("cls");
            cout << "=====================================================" << endl;
        	cout << "         Harley Report Management System             " << endl;
        	cout << "=====================================================" << endl;
        	cout << "                                                     " << endl;
            cout << " Enter Transaction ID to search: ";
            cin >> id;
            cin.ignore();
            logSystem.searchTransaction(id);
            cout << "                                                     " << endl;
            cout << "=====================================================" << endl;
            break;

        case 4:
            system("cls");
            cout << "=====================================================" << endl;
        	cout << "         Harley Report Management System             " << endl;
        	cout << "=====================================================" << endl;
        	cout << "                                                     " << endl;
            cout << "Enter Transaction ID to delete: ";
            cin >> id;
            cin.ignore();
            logSystem.deleteTransaction(id);
            cout << "                                                     " << endl;
            cout << "=====================================================" << endl;
            break;

        case 5:
            cout << "Returning to main menu..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 6);
}

