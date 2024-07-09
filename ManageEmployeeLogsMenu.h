#ifndef MANAGEEMPLOYEEMENU_H
#define MANAGEEMPLOYEEMENU_H
#include "ActivityLogMenu.h"
#include <iostream>
#include <string>
#include <stack>
#include <ctime>

using namespace std;

struct Employee {
    int id;
    string name;
    string timeIn;
    string timeOut;
    Employee* next;

    // Constructor with initializer list
    Employee(int id, const string& name, const string& timeIn = "", const string& timeOut = "", Employee* next = NULL)
        : id(id), name(name), timeIn(timeIn), timeOut(timeOut), next(next) {}
};

class ManageEmployeeMain {
private:
    Employee* head;
    stack<Employee*> employeeStack;

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
    ManageEmployeeMain() : head(NULL) {}
    ~ManageEmployeeMain() {
        while (head) {
            Employee* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addEmployee(int id, const string& name) {
        Employee* temp = head;
        while (temp) {
            if (temp->id == id) {
                cout << "Employee ID already exists." << endl;
                return;
            }
            temp = temp->next;
        }

        Employee* newEmployee = new Employee(id, name, "", "", head);
        head = newEmployee;
        employeeStack.push(newEmployee);
        cout << "Employee added successfully." << endl;
    }

    bool hasEmployees() const {
        return head != NULL;
    }

    void displayEmployees() const {
        if (!head) {
            cout << "No employees found." << endl;
            return;
        }
        Employee* temp = head;
        while (temp) {
            cout << "ID: " << temp->id << ", Name: " << temp->name;
            if (!temp->timeIn.empty()) cout << ", Time In: " << temp->timeIn;
            if (!temp->timeOut.empty()) cout << ", Time Out: " << temp->timeOut;
            cout << endl;
            temp = temp->next;
        }
    }

    void updateEmployee(int id, const string& name) {
        Employee* temp = head;
        while (temp) {
            if (temp->id == id) {
                temp->name = name;
                cout << "Employee updated successfully." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Employee not found." << endl;
    }

    void recordTimeIn(int id) {
        Employee* temp = head;
        while (temp) {
            if (temp->id == id) {
                if (temp->timeIn.empty()) {
                    temp->timeIn = getCurrentTime();
                    cout << "Time In recorded successfully: " << temp->timeIn << endl;
                } else {
                    cout << "Time In already recorded." << endl;
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Employee not found." << endl;
    }

    void recordTimeOut(int id) {
        Employee* temp = head;
        while (temp) {
            if (temp->id == id) {
                if (!temp->timeIn.empty() && temp->timeOut.empty()) {
                    temp->timeOut = getCurrentTime();
                    cout << "Time Out recorded successfully: " << temp->timeOut << endl;
                } else if (temp->timeIn.empty()) {
                    cout << "Time In not recorded yet." << endl;
                } else {
                    cout << "Time Out already recorded." << endl;
                }
                return;
            }
            temp = temp->next;
        }
        cout << "Employee not found." << endl;
    }

    void showStack() const {
        if (employeeStack.empty()) {
            cout << "No employees in stack." << endl;
            return;
        }
        stack<Employee*> tempStack = employeeStack;
        while (!tempStack.empty()) {
            Employee* emp = tempStack.top();
            cout << "ID: " << emp->id << ", Name: " << emp->name;
            if (!emp->timeIn.empty()) cout << ", Time In: " << emp->timeIn;
            if (!emp->timeOut.empty()) cout << ", Time Out: " << emp->timeOut;
            cout << endl;
            tempStack.pop();
        }
    }
};

#endif // MANAGEEMPLOYEEMENU_H

