class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int startHrs = stoi(startTime.substr(0, 2));
        int endHrs = stoi(endTime.substr(0, 2));

        int startMins = stoi(startTime.substr(3, 2));
        int endMins = stoi(endTime.substr(3, 2));

        int startSec = stoi(startTime.substr(6, 2));
        int endSec = stoi(endTime.substr(6, 2));

        int start = (startHrs * 3600) + (startMins * 60) + startSec;
        int end = (endHrs * 3600) + (endMins * 60) + endSec;

        return end - start;
    }
};