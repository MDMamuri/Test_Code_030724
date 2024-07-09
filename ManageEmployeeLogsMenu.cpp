#include "ManageEmployeeLogsMenu.h"
//#include "ManageEmployeeMenu.h"
#include "ActivityLogMenu.h"
#include <iostream>
#include <string>



void ManageEmployeeLogsMenu(ManageEmployeeMain& employeeList, ActivityLog& activityLog, int& choice) {
    int id;
    string name;

    system("cls");

    do {
        cout << "-----------------------------------------------------" << endl;
        cout << "         Harley Report Management System             " << endl;
        cout << "-----------------------------------------------------" << endl;
        cout << "                                                     " << endl;
        cout << "    Employee Logs                                    " << endl;
        cout << "                                                     " << endl;
        cout << "        [1] - Add Employee                           " << endl;
        cout << "        [2] - Read Employee Logs                     " << endl;
        cout << "        [3] - Update Logs                            " << endl;
        cout << "        [4] - Record Time In                         " << endl;
        cout << "        [5] - Record Time Out                        " << endl;
        cout << "        [6] - Return Main Menu                       " << endl;
        cout << "                                                     " << endl;
        cout << "-----------------------------------------------------" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if ((choice >= 2 && choice <= 5) && !employeeList.hasEmployees()) {
            cout << "No employees found." << endl;
            system("pause");
            continue;
        }

        switch (choice) {
        case 1:
            system("cls");
            cout << "Enter Employee ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Employee Name: ";
            getline(cin, name);
            employeeList.addEmployee(id, name);
            activityLog.addLog("Added employee");
            break;

        case 2:
            system("cls");
            employeeList.displayEmployees();
            activityLog.addLog("Viewed employee logs.");
            break;

        case 3:
            system("cls");
            cout << "Enter Employee ID to update: ";
            cin >> id;
            cin.ignore();
            cout << "Enter new Employee Name: ";
            getline(cin, name);
            employeeList.updateEmployee(id, name);
            activityLog.addLog("Updated employee");
            break;

        case 4:
            system("cls");
            cout << "Enter Employee ID: ";
            cin >> id;
            cin.ignore();
            employeeList.recordTimeIn(id);
            //activityLog.addLog("Recorded time in for employee ID " + to_string(id));
            break;

        case 5:
            system("cls");
            cout << "Enter Employee ID: ";
            cin >> id;
            cin.ignore();
            employeeList.recordTimeOut(id);
            //activityLog.addLog("Recorded time out for employee ID " + to_string(id));
            break;

        case 6:
            cout << "Returning to main menu..." << endl;
            activityLog.addLog("Returned to Main Menu");
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 6);
}

