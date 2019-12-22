#include <ctime>
#include "DoyConverter.h"


Date DoyConverter::toDate(int year, int doy) {
    Date d(year, doy);
    return d;
}


int DoyConverter::toDoy(int year, int month, int day) {
    Date d = Date(year, month, day);
    return d.getDoy();
}


int DoyConverter::toDoy(std::tm time) {
    Date d(time.tm_year, time.tm_mon+1, time.tm_mday);
    return d.getDoy();
}
