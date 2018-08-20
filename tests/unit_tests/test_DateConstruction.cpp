#include "gtest/gtest.h"
#include "Date.h"

TEST(TestDateConstruction, TestDefaultConstructor){
    Date da;
    EXPECT_EQ(da.getDoy(), 1);
    EXPECT_EQ(da.getYear(), 2000);
    EXPECT_EQ(da.getMonth(), 1);
    EXPECT_EQ(da.getDay(), 1);
}

TEST(TestDateConstruction, TestParameterDayConstructorSettingMembers){
    int year = 2008;
    int month = 9;
    int day = 8;
    Date d(year, month, day);
    EXPECT_EQ(d.getYear(), year);
    EXPECT_EQ(d.getMonth(), month);
    EXPECT_EQ(d.getDay(), day);
}

TEST(TestDateConstruction, TestParameterDayConstructorDoyCalculationLeapYear){
    int year = 2008;
    int month = 9;
    int day = 10;
    int doy = 254;
    Date d(year, month, day);
    EXPECT_EQ(d.getDoy(), doy);
}

TEST(TestDateConstruction, TestParameterDayConstructorDoyCalculationNoLeapYear){
    int year = 1999;
    int month = 12;
    int day = 31;
    int doy = 365;
    Date d(year, month, day);
    EXPECT_EQ(d.getDoy(), doy);
}

TEST(TestDateConstruction, TestParameterDoyConstructorSettingMembers){
    int year = 2000;
    int doy = 1;
    Date d(year, doy);
    EXPECT_EQ(d.getYear(), year);
    EXPECT_EQ(d.getDoy(), doy);
}

TEST(TestDateConstruction, TestParameterDayConstructorDayCalculationLeapYear){
    int year = 2000;
    int doy = 1;
    Date d(year, doy);
    EXPECT_EQ(d.getMonth(), 1);
    EXPECT_EQ(d.getDay(), 1);
}