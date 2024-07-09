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
        cout << "    Sales Invoice                                     " << endl;
        cout << "                                                     " << endl;
        cout << "        [1] - Add Invoice                            " << endl;
        cout << "        [2] - Invoice History                        " << endl;
        //cout << "        [3] - Update Invoice                         " << endl;
        cout << "        [3] - Void Invoice                         " << endl;
        cout << "        [4] - Return Main Menu                       " << endl;
        cout << "                                                     " << endl;
        cout << "=====================================================" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        system("cls");

        string description;
        int invoiceCode;
        double total;

        switch (choice) {
            case 1:
                cout << "=====================================================" << endl;
                cout << "         Harley Report Management System             " << endl;
                cout << "=====================================================" << endl;
                cout << "                                                     " << endl;
                cout << "Enter Description (Ex. Order Description - 1): ";
                getline(cin, description);
                cout << "Enter Total Amount: ";
                cin >> total;
                salesInvoice.addInvoice(description, total);
                activityLog.addLog("Added Invoice");
                cout << "                                                     " << endl;
                cout << "=====================================================" << endl;
                break;
            case 2:
                cout << "=====================================================" << endl;
                cout << "         Harley Report Management System             " << endl;
                cout << "=====================================================" << endl;
                cout << "                                                     " << endl;
                cout << "Accumulated Funds: $" << salesInvoice.getAccumulatedFunds() << endl;
                salesInvoice.printInvoices();
                cout << "                                                     " << endl;
                cout << "                                                     " << endl;
                cout << "=====================================================" << endl;
                system("pause");
                activityLog.addLog("Viewed Invoice History and Accumulated Funds.");
                break;
            /*case 3:
                cout << "=====================================================" << endl;
                cout << "         Harley Report Management System             " << endl;
                cout << "=====================================================" << endl;
                cout << "                                                     " << endl;
                salesInvoice.printInvoices();
                cout << "Enter invoice code to update: ";
                cin >> invoiceCode;
                cin.ignore();
                salesInvoice.updateInvoice(invoiceCode);
                activityLog.addLog("Updated Invoice");
                system("pause");
                break;*/
            case 3:
                cout << "=====================================================" << endl;
                cout << "         Harley Report Management System             " << endl;
                cout << "=====================================================" << endl;
                cout << "                                                     " << endl;
                salesInvoice.printInvoices();
                cout << "Enter invoice code to void: ";
                cin >> invoiceCode;
                cin.ignore();
                salesInvoice.deleteInvoice(invoiceCode);
                activityLog.addLog("void Invoice");
                system("Pause");
                break;
            case 4:
                return;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (true);
}


