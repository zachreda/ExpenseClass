//
//  expense.h
//  ExpenseClass
//
//  Created by Zach Reda on 9/8/20.
//  Copyright © 2020 Zach Reda. All rights reserved.
//

#ifndef expense_h
#define expense_h

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

// const array to remember days of month (not doing leap year)
// start with 0 so months start at 1
const int mday[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

// expense class
class expense {
private:
    double amt;
    string purpose;

public:
    // default constructor
    expense();
    
    // setter
    void setExpense(double,string);

    // getter
    double getAmt() { return amt; }

    // print an expense
    void print(ostream&);

};

// daily expense class
class daily {
private:
    expense exps[24];
    int numexp;
    int day;

public:
    // default constructor
    daily();

    // add an expense
    int addExpense(double, string);

    // setter
    void setDay(int d) { day = d; }

    // get total for day
    double getDailyExpense();

    // print all expenses for day
    void print(ostream&);

};

class monthly {
private:
    daily days[31];
    int maxdays;
    int month;

public:
    monthly();

    // setter
    // setting the month also sets the maxdays
    // and sets the day value for each day
    void setMonth(int m);

    // add an expense for a day
    void addExpense(int, double, string);

    // get totals
    double getDailyExpense(int);
    double getMonthlyExpense();

    // print
    void printOneDay(ostream&, int);
    void print(ostream&);

};

class yearly {
private:
    monthly months[12];
    int year;

public:
    // constructor
    // creating a year also sets all the months
    yearly();

    // setter
    void setYear(int);

    // add an expense for a month and day
    void addExpense(int, int, double, string);

    // get totals
    double getDailyExpense(int,int);
    double getMonthlyExpense(int);
    double getYearlyExpense();

    // load data
    int loadDataFromFile(string);

    // print
    void printOneDay(ostream&, int, int);
    void printOneMonth(ostream&, int);
    void print(ostream&);

};


#endif /* expense_h */
