//
// Created by Zé Pedro on 17/12/2021.
//
#include "utilities.h"

namespace Utilities{
const char *getMonth(int month) {
    switch (month) {
        case 1:
            return "January";
        case 2:
            return "February";
        case 3:
            return "March";
        case 4:
            return "April";
        case 5:
            return "May";
        case 6:
            return "June";
        case 7:
            return "July";
        case 8:
            return "August";
        case 9:
            return "September";
        case 10:
            return "October";
        case 11:
            return "November";
        case 12:
            return "December";
        default:
            return "Other Month";
    }
}

const char *getOrdinalIndicator(int day) {
    if (day == 1 || (day % 10 == 1 && day % 100 != 11)) {
        return "st";
    } else if (day == 2 || (day % 10 == 2 && day % 100 != 12)) {
        return "nd";
    } else if (day == 3 || (day % 10 == 3 && day % 100 != 13)) {
        return "rd";
    } else return "th";
}

const char *getGreetings(int hour) {
    if (hour > 5 && hour < 14) {
        return "Good Morning";
    } else if (hour >= 14 && hour < 18) {
        return "Good Afternoon";
    } else if (hour >= 18 || hour <= 5) {
        return "Good Evening";
    } else return "Hello";
}

void get_date(int *date) {
    // http://en.cppreference.com/w/cpp/chrono/c/time
    const std::time_t now = std::time(nullptr); // get the current time point

    // convert it to (local) calendar time
    // http://en.cppreference.com/w/cpp/chrono/c/localtime
    const std::tm calendar_time = *std::localtime(std::addressof(now));

    // print out some relevant fields http://en.cppreference.com/w/cpp/chrono/c/tm
    date[0] = calendar_time.tm_year + 1900;
    date[1] = calendar_time.tm_mon + 1; //jan=0
    date[2] = calendar_time.tm_mday;
    date[3] = calendar_time.tm_hour; //(24-hr clock)"
    date[4] = calendar_time.tm_min;
    date[5] = calendar_time.tm_sec;
}

}