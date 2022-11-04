#ifndef AED_PROJECT_SCHEDULEMANAGER_H
#define AED_PROJECT_SCHEDULEMANAGER_H

#include <string>
#include <vector>
#include <queue>
using namespace std;

class ScheduleManager {
    public:
        ScheduleManager();
        void menu();
        void readFiles();
        void createRequest(const vector<string>& request);
        bool checkValidRequest(vector<string> request);
        void analyseRequests();

    private:
        queue<vector<string>> q_ = {};
};


#endif
