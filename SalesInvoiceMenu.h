#ifndef SALESINVOICEMENU_H
#define SALESINVOICEMENU_H
#include <iostream>
#include <string>
#include <stack>

using namespace std;

struct SalesInvoiceStructure {
    string date, invoiceCode, description;
    SalesInvoiceStructure* next;

    SalesInvoiceStructure(const string& d, const string& ic, const string& desc)
        : date(d), invoiceCode(ic), description(desc), next(NULL) {}
};

class SalesInvoice {
private:
    SalesInvoiceStructure* head;
    stack<SalesInvoiceStructure*> history;
    
public:
    SalesInvoice() : head(NULL) {}
    ~SalesInvoice() {
        while (head) {
            SalesInvoiceStructure* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addInvoice(const string& date, const string& invoiceCode, const string& description) {
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

    void searchInvoice(const string& invoiceCode) const {
        SalesInvoiceStructure* current = head;
        while (current) {
            if (current->invoiceCode == invoiceCode) {
                cout << "Invoice found: Date: " << current->date << ", Invoice Code: " << current->invoiceCode << ", Description: " << current->description << "\n";
                return;
            }
            current = current->next;
        }
        cout << "Invoice not found.\n";
    }

    void deleteInvoice(const string& invoiceCode) {
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
