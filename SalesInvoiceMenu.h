#ifndef SALESINVOICEMENU_H
#define SALESINVOICEMENU_H
#include <iostream>
#include <string>
#include <stack>
#include <ctime>
#include <cstdlib>

using namespace std;

struct SalesInvoiceStructure {
    string date;
    int invoiceCode;
    string description;
    SalesInvoiceStructure* next;

    SalesInvoiceStructure(const string& d, int ic, const string& desc)
        : date(d), invoiceCode(ic), description(desc), next(NULL) {}
};

class SalesInvoice {
private:
    SalesInvoiceStructure* head;
    stack<SalesInvoiceStructure*> history;

    string getCurrentTime() const {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char buffer[20];
        sprintf(buffer, "%04d-%02d-%02d %02d:%02d:%02d",
                1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday,
                ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
        return string(buffer);
    }

    int generateRandomID() const {
        srand(time(0));
        return rand() % 1000000000;
    }

public:
    SalesInvoice() : head(NULL) {}
    ~SalesInvoice() {
        while (head) {
            SalesInvoiceStructure* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addInvoice(const string& description) {
        string date = getCurrentTime();
        int invoiceCode = generateRandomID();
        SalesInvoiceStructure* newInvoice = new SalesInvoiceStructure(date, invoiceCode, description);
        newInvoice->next = head;
        head = newInvoice;
        history.push(newInvoice);
        cout << "Invoice added successfully.\n";
        system("pause"); 
    }

    void printInvoices() const {
        SalesInvoiceStructure* current = head;
        while (current) {
            cout << "Date: " << current->date << ", Invoice Code: " << current->invoiceCode << ", Description: " << current->description << "\n";
            current = current->next;
        }
    }

    void printInvoiceHistory() const {
        stack<SalesInvoiceStructure*> temp = history;
        while (!temp.empty()) {
            SalesInvoiceStructure* invoice = temp.top();
            cout << "Date: " << invoice->date << ", Invoice Code: " << invoice->invoiceCode << ", Description: " << invoice->description << "\n";
            temp.pop();
        }
    }

	void updateInvoice(int invoiceCode) {
	    SalesInvoiceStructure* current = head;
	    while (current) {
	        if (current->invoiceCode == invoiceCode) {
	            string description;
	            system("cls");
	            cout << "=====================================================" << endl;
	            cout << "         Harley Report Management System             " << endl;
	            cout << "=====================================================" << endl;
	            cout << "                                                     " << endl;
	            cout << "Update Menu:                                      " << endl;
	            cout << "                                                     " << endl;
	            cout << "Enter new description: ";
	            getline(cin, description);
	            current->description = description;
	            cout << "Description updated successfully!\n";
	            cout << "                                                     " << endl;
	            cout << "=====================================================" << endl;
	            return;
	        }
	        current = current->next;
	    }
	    cout << "Invoice not found.\n";
	}

    void deleteInvoice(int invoiceCode) {
        SalesInvoiceStructure* current = head;
        SalesInvoiceStructure* prev = NULL;

        while (current && current->invoiceCode != invoiceCode) {
            prev = current;
            current = current->next;
        }

        if (!current) {
            cout << "Invoice not found.\n";
            return;
        }

        if (!prev) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        history.push(current);
        delete current;
        cout << "Invoice deleted successfully.\n";
    }
};

#endif 

