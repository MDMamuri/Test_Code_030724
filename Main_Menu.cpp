#include <iostream>
#include "ManageEmployeeLogsMenu.h"
#include "InventoryManagementMenu.h"
#include "LogsTransactionsMenu.h" 
#include "SalesInvoiceMenu.h"
#include "ActivityLogMenu.h"

using namespace std;

void ManageEmployeeLogsMenu(ManageEmployeeMain& employeeList, ActivityLog& activityLog, int& choice);
void InventoryManagementMenu(InventoryManagementMain& inv, int& choice);
void LogsTransactionsMainMenu(LogsManagementMain& logSystem, int& choice); 
void ActivityLogMenu(ActivityLog& log, int& choice);
void SalesInvoiceMenu(SalesInvoice& salesInvoice, int& choice);

int main() {
    ManageEmployeeMain employeeList;
    InventoryManagementMain inv;
    LogsManagementMain logSystem;
    SalesInvoice salesInvoice;
    ActivityLog log;
    int choice;

    do {
        system("cls");
        cout << "=====================================================" << endl;
        cout << "         Harley Report Management System             " << endl;
        cout << "=====================================================" << endl;
        cout << "                                                     " << endl;
        cout << "     [1] - Manage Employee Logs                      " << endl;
        cout << "     [2] - Inventory Management                      " << endl;
        cout << "     [3] - Logs of Transactions                      " << endl;
        cout << "     [4] - Activity Log                              " << endl;
        cout << "     [5] - Sales Invoice                             " << endl;
        cout << "     [0] - Exit                                      " << endl;
        cout << "                                                     " << endl;
        cout << "=====================================================" << endl;
        cout << ": ";
        cin >> choice;

        switch (choice) {
            case 1:
                ManageEmployeeLogsMenu(employeeList, log, choice);
                break;
            case 2:
                InventoryManagementMenu(inv, choice);
                break;
            case 3:
                LogsTransactionsMainMenu(logSystem, choice); 
                break;
            case 4:
                ActivityLogMenu(log, choice);
                break;
            case 5:
                SalesInvoiceMenu(salesInvoice, choice);
                break;
            case 0:
                system("cls");
                cout << "Exiting!!" << endl;
                break;
            default:
                cout << "Invalid Choice. Please Try Again!!" << endl;
                system("cls");
                break;
        }
    } while (choice != 0);

    cout << "Thank you so much!!" << endl;
    return 0;
}

