#include <ctime>
#include <iostream>
#include <sstream>
//https://github.com/jarro2783/cxxopts
#include "cxxopts.hpp"
#include "doylib/DoyConverter.h"

std::tm* getCurrentTime(){
    // no arguments, get doy of current data
    time_t t = time(0);   // get time now
    struct tm* now = localtime(& t);
    return now;
}

int doy, year, month, day;

int main(int argc, char *argv[]) {

    DoyConverter converter;
    
    cxxopts::Options options("DOY", "Convert between date and doy");
    options.add_options()
        ("h,help", "Show help")
        ("l,leap", "Is a leap m_year");

    auto result = options.parse(argc, argv);

    //show help/usage
    if (result.count("help")){
        std::cout << "Usage" << std::endl;
        std::cout << "doy - gives doy of current date" << std::endl;
        std::cout << "doy 1994 09 19 - gives doy of given date"  << std::endl;
        std::cout << "doy 205 - gives MM-DD of given doy.";
        std::cout << "          If m_year is leapyear, add -l/--leap flag" << std::endl;
        std::cout << "doy 205 2014 - gives date of given doy in year, accounting for possible leap year" << std::endl;
        return(0);
    }

    /**
     * 0 positional arguments provided: Print Doy of current date
     */
    if (argc == 1){
        std::tm* now = getCurrentTime();
        int doy = converter.toDoy(*now);
        std::cout << doy << std::endl;
    }

    /**
     * 1 positional argument: Convert given doy to a date. If leap year flag is not set, assume no leap year
     */
    else if (argc == 2){
        std::istringstream iss(argv[1]);
        if (!(iss >> doy) or doy <= 0){
            std::cerr << "Invalid argument doy: " << doy << std::endl;
            return 1;
        }
        Date date;
        if (result.count("leap")){
            date = converter.toDate(2000, doy);
        }else{
            date = converter.toDate(1999, doy);
        }
        std::cout << date.getMonth() << "-" << date.getDay() << std::endl;
        return 0;
    }

    /**
     * 2 positional arguments: doy yyyy, convert to date, checking for leap year and print full date
     */
    else if (argc == 3){
        int doy, year;
        std::istringstream iss(argv[1]);
        if (!(iss >> doy) or doy <= 0){
            std::cerr << "Invalid argument doy: " << doy << std::endl;
            return 1;
        }
        iss.clear();
        iss.str(argv[2]);
        if (!(iss >> year)){
            std::cerr << "Invalid argument m_year: " << year << std::endl;
            return 1;
        }
        Date date = converter.toDate(year, doy);
        std::cout << date << std::endl;
    }

    /**
     * 3 positional arguments: YYYY MM DD, convert to doy and print
     */
    else if (argc == 4){
        std::istringstream iss(argv[1]);
        if (!(iss >> year)){
            std::cerr << "Invalid argument m_year: " << year << std::endl;
        }
        iss.clear();
        iss.str(argv[2]);
        if (!(iss >> month)){
            std::cerr << "Invalid argument m_month: " << month << std::endl;
        }
        iss.clear();
        iss.str(argv[3]);
        if (!(iss >> day)){
            std::cerr << "Invalid argument m_dayOfMonth: " << day << std::endl;
        }
        doy = converter.toDoy(year, month, day);
        std::cout << doy << std::endl;
    }

    else if (argc > 4){
        std::cerr << "Too many arguments!" << std::endl;
        return -1;
    }

}