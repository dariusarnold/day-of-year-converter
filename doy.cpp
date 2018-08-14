#include <ctime>
#include <iostream>
#include <sstream>
//https://github.com/jarro2783/cxxopts
#include "cxxopts.hpp"

using namespace std;

int monthdays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
std::string monthnames[] = {"January", "February", "March", "April", "May", "June", "Juli", "August", "September", "October", "November", "December"};
int year, month, day, doy;

int toDoy(int year, int month, int day);
std::string toDate(int doy, bool leapYear=false);
bool isLeapYear(int year);

int main(int argc, char *argv[]) {
    
    cxxopts::Options options("DOY", "Convert between date and doy");
    options.add_options()
        ("h,help", "Show help")
        ("l,leap", "Is a leap year");

    auto result = options.parse(argc, argv);

    //show help/usage
    if (result.count("help")){
        std::cout << "Usage" << std::endl;
        std::cout << "doy - gives doy of current date" << std::endl;
        std::cout << "doy 1994 09 19 - gives doy of given date"  << std::endl;
        std::cout << "doy 205 - gives date of given doy.";
        std::cout << "          If year is leapyear, add -l/--leap flag" << std::endl;
        std::cout << "doy 205 2014 - gives date of given doy in year, accounting for possible leap year" << std::endl;
        return(0);
    }
    
    int doy = -1;
    
    if (argc == 1){
        // no arguments, get doy of current data
        time_t t = time(0);   // get time now
        struct tm * now = localtime(& t);
        doy = toDoy(now->tm_year, now->tm_mon, now->tm_mday);
    }

    else if (argc == 2){
        //expected input is doy
        istringstream iss(argv[1]);
        if (!(iss >> doy) or doy <= 0){
            cerr << "Invalid argument doy: " << doy << endl;
            return 1;
        }
        std::string date;
        if (result.count("leap")){
            std::cout << "leap";
            date = toDate(doy, true);
        }else{
            date = toDate(doy);
        }
        std::cout << date << std::endl;
        return 0;
    }

    else if (argc == 3){
        //input is doy yyyy, handle leap years by checking for them
        int doy, year;
        istringstream iss(argv[1]);
        if (!(iss >> doy) or doy <= 0){
            std::cerr << "Invalid argument doy: " << doy << endl;
            return 1;
        }
        iss.clear();
        iss.str(argv[2]);
        if (!(iss >> year)){
            std::cerr << "Invalid argument year: " << year << std::endl;
            return 1;
        }
        auto date = toDate(doy, isLeapYear(year));
        std::cout << date << std::endl;
    }

    else if (argc == 4){
        //expected input is yyyy mm dd
        istringstream iss(argv[1]);
        if (!(iss >> year)){
            cerr << "Invalid argument year: " << year << endl;
        }
        iss.clear();
        iss.str(argv[2]);
        if (!(iss >> month)){
            cerr << "Invalid argument month: " << month << endl;
        }
        iss.clear();
        iss.str(argv[3]);
        if (!(iss >> day)){
            cerr << "Invalid argument day: " << day << endl;
        }
        doy = toDoy(year, month-1, day);
    }
    else if (argc > 4){
        cerr << "Too many arguments!" << endl;
        return -1;
    }

    if (doy != -1){
        cout << doy << endl;
        return 0;
    }
    else{
        return -1;
    }
}

int toDoy(int year, int month, int day){
    /**
     * Convert date to Day of Year (doy), respecting leap years
     * Parameter month goes from 0...11 for January...December
     */
    
    // check inputs
    if (month < 0 or month > 11 or day < 0 or day > 31){
        cerr << "Invalid date given" << endl;
        return -1;
    }

    //month -= 1;
    if (isLeapYear(year)){
        monthdays[1] = 29;
        std::cout << "Leapyear" << std::endl;
    }
    int doy = 0;
    for (int i=0; i<month; ++i){
        doy += monthdays[i];
    }
    doy += day;
    return doy;
}

std::string toDate(int doy, bool leapYear){
    /**
     * Convert doy to a date (day, month). Year can not be recovered.
     */
    if (leapYear){
        monthdays[1] = 29;
    }
    int index_month = 0;
    while (doy > monthdays[index_month]){
        doy -= monthdays[index_month];
        index_month++;
    }
    monthdays[1] = 28;
    return (std::to_string(doy) + "." + std::to_string(index_month+1) + ".");
}

bool isLeapYear(int year){
    /**
     * Return true if year is leap year, false otherwise
     */
    bool leapyear = false;
    if (year % 4 == 0 and year % 100 != 0){
        leapyear = true;
    }
    if (year % 400 == 0){
        leapyear = true;
    }
    return leapyear;
}