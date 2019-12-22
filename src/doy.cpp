#include <ctime>
#include <iostream>
//https://github.com/jarro2783/cxxopts
#include "cxxopts.hpp"
#include "doylib/DoyConverter.h"

std::tm* getCurrentTime(){
    // no arguments, get doy of current data
    time_t t = time(0);   // get time now
    struct tm* now = localtime(& t);
    return now;
}

DoyConverter converter;

void print_usage() {
    std::cout << "Usage\n";
    std::cout << "doy            - gives doy of current date.\n";
    std::cout << "doy YYYY MM DD - gives doy of given date.\n";
    std::cout << "doy DOY        - gives MM-DD of given doy.\n";
    std::cout << "                 If m_year is leapyear, add -l/--leap flag.\n";
    std::cout << "doy DOY YYYY   - gives date of given doy in year, accounting for possible leap year.\n";
}

void print_current_doy() {
    std::tm *now = getCurrentTime();
    int doy = converter.toDoy(*now);
    std::cout << doy << std::endl;
}

void convert_doy(int doy, bool leapyear) {
    int year = leapyear ? 2000 : 1999;
    Date date = converter.toDate(year, doy);
    std::cout << date.getMonth() << "-" << date.getDay() << std::endl;
}

void convert_doy_year(int doy, int year) {
    Date date = converter.toDate(year, doy);
    std::cout << date << std::endl;
}

void convert_ymd_to_doy(int year, int month, int day) {
    int doy = converter.toDoy(year, month, day);
    std::cout << doy << std::endl;
}

int extract_int(const char *str) {
    char *end;
    return std::strtol(str, &end, 10);
}

int main(int argc, char *argv[]) {
    cxxopts::Options options("DOY", "Convert between date and doy");
    options.add_options()
            ("h,help", "Show help.")
            ("l,leap", "Specify if year is a leap year when converting doy to year month day.");

    auto result = options.parse(argc, argv);

    //show help/usage
    if (result.count("help")) {
        print_usage();
        return (0);
    }

    switch (argc) {
        case 1:
            // 0 positional arguments provided: Print Doy of current date
            print_current_doy();
            break;
        case 2:
            // 1 positional argument: Convert given doy to a date. If leap year flag is not set, assume no leap year
            convert_doy(extract_int(argv[1]), result.count("leap"));
            break;
        case 3:
            // 2 positional arguments: doy yyyy, convert to date, checking for leap year and print full date
            convert_doy_year(extract_int(argv[1]), extract_int(argv[2]));
            break;
        case 4:
            // 3 positional arguments: YYYY MM DD, convert to doy and print
            convert_ymd_to_doy(extract_int(argv[1]), extract_int(argv[2]), extract_int(argv[3]));
            break;
        default:
            std::cerr << "Too many arguments!" << std::endl;
            return -1;
    }
}