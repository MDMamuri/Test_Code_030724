#include <iostream>
#include <string>
#include "ActivityLogMenu.h"

using namespace std;

void ActivityLogMenu(ActivityLog& log, int& choice) {
    string activity;
    
    system("cls"); 
    cout << "=====================================================" << endl;
    cout << "         Harley Report Management System             " << endl;
    cout << "=====================================================" << endl;
    cout << "                                                     " << endl;
    cout << "Activity Logs										  " <<endl;
    cout << "                                                     " << endl;
    log.addLog("User accessed the activity log menu.");
    log.printLogs();
    cout << "                                                     " << endl;
    cout << "=====================================================" << endl;
	system("pause");
}

