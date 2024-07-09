#include "SalesInvoiceMenu.h"
#include "ActivityLogMenu.h"
#include <iostream>
#include <string>

using namespace std;

void SalesInvoiceMenu(SalesInvoice& salesInvoice,ActivityLog& activityLog, int& choice){

    do {
        system("cls");
        cout << "-----------------------------------------------------" << endl;
        cout << "         Harley Report Management System             " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "                                                     " << endl;
        cout << "Sales Invoice                                        " << endl;
        cout << "                                                     " << endl;
        cout << "        [1] - Add Invoice                            " << endl;
        cout << "        [2] - Invoice History                        " << endl;
        cout << "        [3] - Search Invoice                         " << endl;
        cout << "        [4] - Delete Invoice                         " << endl;
        cout << "        [5] - Return Main Menu                       " << endl;
        cout << "                                                     " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << ": ";
        cin >> choice;
        cin.ignore();
        system("cls");

        string date, invoiceCode, description;

        switch (choice) {
            case 1:
                cout << "Date of Purchase (MM/DD/YYYY): ";
                getline(cin, date);
                cout << "Enter Invoice Code: ";
                getline(cin, invoiceCode);
                cout << "Enter Description: ";
                getline(cin, description);
                salesInvoice.addInvoice(date, invoiceCode, description);
                activityLog.addLog("Added Invoice");
                break;
            case 2:
                salesInvoice.printInvoices();
                activityLog.addLog("Viewed Invoice History.");
                system("pause");
                break;
            case 3:
                cout << "Enter invoice code to search: ";
                getline(cin, invoiceCode);
                salesInvoice.searchInvoice(invoiceCode);
                activityLog.addLog("Searched Invoice");
                system("pause");
                break;
            case 4:
                cout << "Enter invoice code to delete: ";
                getline(cin, invoiceCode);
                salesInvoice.deleteInvoice(invoiceCode);
                activityLog.addLog("Deleted Invoice");
                system("pause");
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (true);
}

