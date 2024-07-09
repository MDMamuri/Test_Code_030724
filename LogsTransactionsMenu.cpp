#include "LogsTransactionsMenu.h"
#include "ActivityLogMenu.h"
#include <iostream>
#include <string>


using namespace std;

void LogsTransactionsMainMenu(LogsManagementMain& logSystem, ActivityLog& activityLog, int& choice){
    int id;
    string description;
    string keyword; 

    system("cls");

    do {
    	system("cls");
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
            cout << "Enter Transaction Description (Ex. Description - 1): ";
            getline(cin, description);
            logSystem.logTransaction(id, description);
            cout << "                                                     " << endl;
            cout << "=====================================================" << endl;
            activityLog.addLog("Transaction Added");
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
            activityLog.addLog("Displayed Transaction History");
            system ("Pause");
            break;

        case 3:
            system("cls");
            cout << "=====================================================" << endl;
            cout << "         Harley Report Management System             " << endl;
            cout << "=====================================================" << endl;
            cout << "                                                     " << endl;
            cout << "Enter keyword (Case Sensitive): ";
            cin >> keyword;
            logSystem.searchTransactionsByKeyword(keyword);
            cout << "                                                     " << endl;
            cout << "=====================================================" << endl;
            break;

        case 4:
            system("cls");
            cout << "=====================================================" << endl;
        	cout << "         Harley Report Management System             " << endl;
        	cout << "=====================================================" << endl;
        	cout << "                                                     " << endl;
        	logSystem.displayTransactions();
        	cout << "                                                     " << endl;
            cout << "Enter Transaction ID to delete: ";
            cin >> id;
            logSystem.deleteTransaction(id);
            cout << "                                                     " << endl;
            cout << "=====================================================" << endl;
            activityLog.addLog("Delete Transaction");
            break;

        case 5:
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 5);
}

