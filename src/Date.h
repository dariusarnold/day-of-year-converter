#ifndef DOYCONVERTER_DATE_H
#define DOYCONVERTER_DATE_H

class Date {
public:
    Date();

    Date(int year, int month, int day);
    /**
     * Construct from year and doy. Automatically sets day of month and month
     * @param year
     * @param doy
     */
    Date(int year, int doy);

    int getDoy();
    int getYear();
    int getMonth();
    int getDay();

private:
    /**
     * Check if year is a leap year
     * @param year
     * @return true if year is leap year, false otherwise
     */
    bool isLeapYear(int year);

    /**
     * Calculate the month for a given year and doy
     * @param year
     * @param doy
     * @return
     */
    int calculateMonth(int year, int doy);

    /**
     * Calculate the day of the month for a given year and doy
     * @param year
     * @param doy
     * @return
     */
    int calculateDayOfMonth(int year, int doy);

    /**
     * Calculate Day of year
     * @param year
     * @param month
     * @param day
     * @return
     */
    int calculateDayOfYear(int year, int month, int day);

    /**
     * Get the days in a month, taking into accoount wether the given year is a leap year
     * @param month 1..12
     * @param year
     * @return
     */
    int getMonthDay(int month, int year);

    // year from -INT_MAX..+INT_MAX
    int m_year;
    // month from 1...12
    int m_month;
    // day of month from 1..31
    int m_dayOfMonth;
    // day of year from 1..366
    int m_dayOfYear;

    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
};

#endif //DOYCONVERTER_DATE_H
