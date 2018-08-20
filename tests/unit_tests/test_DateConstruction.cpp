#include "gtest/gtest.h"
#include "Date.h"

/**
 * Test if the default constructor initializes the fields
 * TODO: This is implementation dependent, is there another way to test for initialized values?
 */
TEST(TestDateConstruction, TestDefaultConstructor){
    Date da;
    EXPECT_EQ(da.getDoy(), 1);
    EXPECT_EQ(da.getYear(), 2000);
    EXPECT_EQ(da.getMonth(), 1);
    EXPECT_EQ(da.getDay(), 1);
}

/**
 * Test if setting the members given in the Year/Month/Day constructor works correctly
 */
TEST(TestDateConstruction, TestParameterDayConstructorSettingMembers){
    int year = 2008;
    int month = 9;
    int day = 8;
    Date d(year, month, day);
    EXPECT_EQ(d.getYear(), year);
    EXPECT_EQ(d.getMonth(), month);
    EXPECT_EQ(d.getDay(), day);
}

/**
 * Test if setting the members not given in the Year/Month/Day constructor by calculating them
 * works correctly and takes the leap year into account
 */
TEST(TestDateConstruction, TestParameterDayConstructorDoyCalculationLeapYear){
    int year = 2008;
    int month = 9;
    int day = 10;
    int doy = 254;
    Date d(year, month, day);
    EXPECT_EQ(d.getDoy(), doy);
}

/**
 * Test if setting the members not given in the Year/Month/Day constructor by calculating them
 * works correctly and takes the leap year into account
 */
TEST(TestDateConstruction, TestParameterDayConstructorDoyCalculationNoLeapYear){
    int year = 1999;
    int month = 12;
    int day = 31;
    int doy = 365;
    Date d(year, month, day);
    EXPECT_EQ(d.getDoy(), doy);
}

/**
 * Test if the Year/Doy constructor sets the given parameters correctly
 */
TEST(TestDateConstruction, TestParameterDoyConstructorSettingMembers){
    int year = 2000;
    int doy = 1;
    Date d(year, doy);
    EXPECT_EQ(d.getYear(), year);
    EXPECT_EQ(d.getDoy(), doy);
}

/**
 * Test if the Year/Doy constructor calculates the missing member values Month and Day of Month correctly
 */
TEST(TestDateConstruction, TestParameterDayConstructorDayCalculation){
    int year = 2000;
    int doy = 1;
    Date d(year, doy);
    EXPECT_EQ(d.getMonth(), 1);
    EXPECT_EQ(d.getDay(), 1);
}

/**
 * Test if the Year/Doy constructor calculates the missing member values Month and Day of Month correctly,
 * taking the additional leap day into account
 */
TEST(TestDateConstruction, TestParameterDayConstructorDayCalculationLeapYear){
    int year = 2000;
    int doy = 366;
    Date d(year, doy);
    EXPECT_EQ(d.getMonth(), 12);
    EXPECT_EQ(d.getDay(), 31);
}