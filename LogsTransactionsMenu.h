#ifndef LOGSTRANSACTIONSMENU_H
#define LOGSTRANSACTIONSMENU_H
#include "ActivityLogMenu.h"
#include <iostream>
#include <string>
#include <stack>
#include <ctime>

using namespace std;

struct Transaction {
    int id;
    string description;
    string timestamp;
    Transaction* next;
};

class LogsManagementMain {
private:
    Transaction* head; 
    stack<Transaction*> transactionStack; 

    string getCurrentTime() const {
        time_t now = time(0);
        tm *ltm = localtime(&now);
        char buffer[20];
        sprintf(buffer, "%04d-%02d-%02d %02d:%02d:%02d",
                1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday,
                ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
        return string(buffer);
    }

public:
    LogsManagementMain() : head(NULL) {}

    void logTransaction(int id, const string& description) {
        // Check if transaction with the same ID already exists
        Transaction* temp = head;
        while (temp) {
            if (temp->id == id) {
                cout << "Transaction with ID " << id << " already exists." << endl;
                system("pause");
                return;
            }
            temp = temp->next;
        }


        Transaction* newTransaction = new Transaction;
        newTransaction->id = id;
        newTransaction->description = description;
        newTransaction->timestamp = getCurrentTime();
        newTransaction->next = head;

        head = newTransaction;
        transactionStack.push(newTransaction);
        cout << "Transaction logged successfully." << endl;
        system("pause");
    }

    bool hasTransactions() const {
        return head != NULL;
    }

    void displayTransactions() const {
        if (!head) {
            cout << "No transactions found." << endl;
            return;
        }
        Transaction* temp = head;
        while (temp) {
            cout << "ID: " << temp->id << ", Description: " << temp->description << ", Timestamp: " << temp->timestamp << endl;
            temp = temp->next;
        }

    }

    void searchTransaction(int id) const {
        Transaction* temp = head;
        while (temp) {
            if (temp->id == id) {
                cout << "Transaction found: ID: " << temp->id << ", Description: " << temp->description << ", Timestamp: " << temp->timestamp << endl;
                system("pause");
                return;
            }
            temp = temp->next;
        }
        cout << "Transaction not found." << endl;
        system("pause");
    }

    void deleteTransaction(int id) {
        Transaction* temp = head;
        Transaction* prev = NULL;

        while (temp && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Transaction not found." << endl;
            system("pause");
            return;
        }

        if (prev) {
            prev->next = temp->next;
        } else {
            head = temp->next;
        }

        delete temp;
        cout << "Transaction deleted successfully." << endl;
        system("pause");
    }

    void searchTransactionsByKeyword(const string& keyword) const {
        bool found = false;
        Transaction* temp = head;
        while (temp) {
            if (temp->description.find(keyword) != string::npos) {
                if (!found) {
                    cout << "Transactions containing \"" << keyword << "\":" << endl;
                    found = true;
                }
                cout << "ID: " << temp->id << ", Description: " << temp->description << ", Timestamp: " << temp->timestamp << endl;
            }
            temp = temp->next;
        }
        if (!found) {
            cout << "No transactions found containing \"" << keyword << "\"." << endl;
        }
        system("pause");
    }
};


#endif 

