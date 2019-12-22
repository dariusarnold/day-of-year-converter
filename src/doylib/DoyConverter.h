#ifndef DAY_OF_YEAR_CONVERTER_DOYCONVERTER_H
#define DAY_OF_YEAR_CONVERTER_DOYCONVERTER_H

#include "Date.h"

class DoyConverter{
public:

    /**
     * Convert year month day to day of year
     * @param year
     * @param month
     * @param day
     * @return doy as a number between 1 and 366
     */
    int toDoy(int year, int month, int day);

    /**
     * Convert a tm struct to Day of year.
     * The struct members tm_year, tm_mon and tm_mday must be set correctly
     * @param time
     * @return Day of year
     */
    int toDoy(std::tm time);

    /**
     * Convert doy and year to a date
     * @param doy
     * @return
     */
    Date toDate(int year, int doy);

};

#endif //DAY_OF_YEAR_CONVERTER_DOYCONVERTER_H
