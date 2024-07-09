#ifndef ACTIVITYLOGMENU_H
#define ACTIVITYLOGMENU_H

#include <iostream>
#include <string>
#include <ctime>

using namespace std;

struct LogNode {
    string log;
    string timestamp;
    LogNode* next;
    LogNode(const string& log, const string& timestamp) : log(log), timestamp(timestamp), next(NULL) {}
};

class ActivityLog {
private:
    LogNode* head;

    string getCurrentTime() const {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        char buffer[20];
        sprintf(buffer, "%04d-%02d-%02d %02d:%02d:%02d",
                1900 + ltm->tm_year, 1 + ltm->tm_mon, ltm->tm_mday,
                ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
        return string(buffer);
    }

public:
    ActivityLog() : head(NULL) {}

    ~ActivityLog() {
        while (head) {
            LogNode* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addLog(const string& log) {
        string timestamp = getCurrentTime();
        LogNode* newNode = new LogNode(log, timestamp);
        newNode->next = head;
        head = newNode;
    }

    void printLogs() const {
        LogNode* current = head;
        while (current) {
            cout << current->timestamp << " - " << current->log << endl;
            current = current->next;
        }
    }

   
    void clearLogs() {
        LogNode* current = head;
        while (current) {
            LogNode* next = current->next;
            delete current;
            current = next;
        }
        head = NULL;
    }
};

#endif

