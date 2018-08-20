#include <stdexcept>
#include "Date.h"

Date::Date() : m_year{2000}, m_month{1}, m_dayOfMonth{1}, m_dayOfYear{1} {}

Date::Date(int year, int month, int day) : m_year{year}, m_month{month}, m_dayOfMonth{day} {
    m_dayOfYear = calculateDayOfYear(year, month, day);
}

Date::Date(int year, int doy) : m_year{year}, m_dayOfYear{doy} {
    m_month = calculateMonth(year, doy);
    m_dayOfMonth = calculateDayOfMonth(year, doy);
}

bool Date::isLeapYear(int year) {
    if (year % 4 == 0 and year % 100 != 0){
        return true;
    }
    if (year % 400 == 0){
        return true;
    }
    return false;
}

int Date::calculateMonth(int year, int doy){
    int daysLeft = doy;
    if (isLeapYear(year)){
        monthDays[1] = 29;
    }
    int index_month = 0;
    while (daysLeft > monthDays[index_month]){
    daysLeft -= monthDays[index_month];
    index_month++;
    }
    monthDays[1] = 28;
    return index_month+1;
    }

int Date::calculateDayOfMonth(int year, int doy) {
    int daysLeft = doy;
    if (isLeapYear(year)){
        monthDays[1] = 29;
    }
    int index_month = 0;
    while (daysLeft > monthDays[index_month]){
        daysLeft -= monthDays[index_month];
        index_month++;
    }
    monthDays[1] = 28;
    return daysLeft;
}

int Date::calculateDayOfYear(int year, int month, int day) {
    if (month < 0 or month > 12){
        throw std::invalid_argument("Invalid month given");
    }
    if (day > getMonthDay(month, year)){
        throw std::invalid_argument("Invalid day given");
    }

    int doy = 0;
    // sum up all days in finished/complete months
    for (int running_month_index=1; running_month_index<month; ++running_month_index){
        doy += getMonthDay(running_month_index, year);
    }
    // add the days from the current month
    doy += day;
    return doy;
}

int Date::getDoy(){
    return m_dayOfYear;
}

int Date::getYear() {
    return m_year;
}

int Date::getMonth() {
    return m_month;
}

int Date::getDay() {
    return m_dayOfMonth;
}

int Date::getMonthDay(int month, int year) {
    int monthDay = monthDays[month-1];
    // check for february leap year additional day
    if (isLeapYear(year) and month == 2) monthDay++;
    return monthDay;
}
