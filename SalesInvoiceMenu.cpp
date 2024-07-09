#include "SalesInvoiceMenu.h"
#include "ActivityLogMenu.h"
#include <iostream>
#include <string>

using namespace std;

void SalesInvoiceMenu(SalesInvoice& salesInvoice, ActivityLog& activityLog, int& choice) {
    do {
        system("cls");
        cout << "=====================================================" << endl;
        cout << "         Harley Report Management System             " << endl;
        cout << "=====================================================" << endl;
        cout << "                                                     " << endl;
        cout << "Sales Invoice                                        " << endl;
        cout << "                                                     " << endl;
        cout << "        [1] - Add Invoice                            " << endl;
        cout << "        [2] - Invoice History                        " << endl;
        cout << "        [3] - Update Invoice                         " << endl;
        cout << "        [4] - Delete Invoice                         " << endl;
        cout << "        [5] - Return Main Menu                       " << endl;
        cout << "                                                     " << endl;
        cout << "=====================================================" << endl;
        cout << ": ";
        cin >> choice;
        cin.ignore();
        system("cls");

        string date, invoiceCode, description;

        switch (choice) {
            case 1:
                cout << "=====================================================" << endl;
                cout << "         Harley Report Management System             " << endl;
                cout << "=====================================================" << endl;
                cout << "                                                     " << endl;
                cout << "Date of Purchase (MM/DD/YYYY): ";
                getline(cin, date);
                cout << "Enter Invoice Code: ";
                getline(cin, invoiceCode);
                cout << "Enter Description: ";
                getline(cin, description);
                salesInvoice.addInvoice(date, invoiceCode, description);
                activityLog.addLog("Added Invoice");
                cout << "                                                     " << endl;
                cout << "=====================================================" << endl;
                break;
            case 2:
                cout << "=====================================================" << endl;
                cout << "         Harley Report Management System             " << endl;
                cout << "=====================================================" << endl;
                cout << "                                                     " << endl;
                salesInvoice.printInvoices();
                activityLog.addLog("Viewed Invoice History.");
                cout << "                                                     " << endl;
                cout << "=====================================================" << endl;
                system("pause");
                break;
            case 3:
                cout << "=====================================================" << endl;
                cout << "         Harley Report Management System             " << endl;
                cout << "=====================================================" << endl;
                cout << "                                                     " << endl;
                salesInvoice.printInvoices();
                cout << "Enter invoice code to update: ";
                getline(cin, invoiceCode);
                salesInvoice.updateInvoice(invoiceCode);
                activityLog.addLog("Updated Invoice");
                cout << "                                                     " << endl;
                cout << "=====================================================" << endl;
                system("pause");
                break;
            case 4:
                cout << "=====================================================" << endl;
                cout << "         Harley Report Management System             " << endl;
                cout << "=====================================================" << endl;
                cout << "                                                     " << endl;
                cout << "Enter invoice code to delete:                        ";
                getline(cin, invoiceCode);
                salesInvoice.deleteInvoice(invoiceCode);
                cout << " Invoice Deleted                                     " <<endl;
                activityLog.addLog("Deleted Invoice");
                cout << "                                                     " << endl;
                cout << "=====================================================" << endl;
                break;
            case 5:
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (true);
}

