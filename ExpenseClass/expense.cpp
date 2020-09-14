#include "expense.h"

//constructor
expense::expense() {
    amt = 0.0;
    purpose = "null";
}

void expense::setExpense(double a, string p) {
    amt = a;
    purpose = p;
}

void expense::print(ostream &out) {
    out << "Expense:" << endl;
    out << "\tAmount=$" << amt << endl;
    out << "\tPurpose=" << purpose << endl;
}


//constructor
daily::daily() {
    numexp = 0;
    day = -1;
}

int daily::addExpense(double a, string p) {

    if (numexp<dsize) {
        exps[numexp].setExpense(a,p);
        numexp++;
    }
    return numexp;
}

void daily::print(ostream &out) {

    int i;
    cout << "Daily=======================\n";
    for(i=0;i<numexp;i++) {
        exps[i].print(out);
    }
    cout << "Daily=======================\n";

}
double daily::getDailyExpense(){
    double dailyExpense=0;
    for (int i=0; i<numexp; i++) {
        dailyExpense+=exps[i].getAmt();
    }
    return dailyExpense;
}


//constructor

monthly::monthly(){
}
void monthly::setMonth(int m){
    month=m;
    maxdays=mday[m];
}
void monthly::addExpense(int d, double amt, string p){
    
    days[d].addExpense(amt, p);
}
double monthly::getDailyExpense(int d){
    
    return days[d].getDailyExpense();
}
double monthly::getMonthlyExpense(){
    double monthyExpense=0;
    for (int i=0; i<maxdays; i++) {
        monthyExpense+=days[i].getDailyExpense();
    }
    return monthyExpense;
}
void monthly::printOneDay(ostream &out, int d){
    days[d].print(out);
}

void monthly::print(ostream &out){
    for (int i=0; i<maxdays; i++) {
        printOneDay(out, i);
    }
}

//constructor
yearly::yearly(){
    year=0;
}
void yearly::setYear(int y){
    year = y;
}
void yearly::addExpense(int m, int d, double amt, string p){
    months[m].setMonth(m);
    
    months[m].addExpense(d, amt, p);
}
double yearly::getDailyExpense(int m, int d){
    return months[m-1].getDailyExpense(d-1);
}

double yearly::getMonthlyExpense(int m){
    return months[m-1].getMonthlyExpense();
}

double yearly::getYearlyExpense(){
    double yearlyExpense=0;
    for (int i=0; i<ysize; i++) {
        yearlyExpense+=months[i].getMonthlyExpense();
    }
    return yearlyExpense;
}

int yearly::loadDataFromFile(string s){
    
       fstream inputFile;
       inputFile.open(s);
       
       if (inputFile.fail())
       {
           cout << "File not found" << endl;
       }
    
            //constants
           int d=0, m=0, y=0, numLines=0;
           double amt=0.0;
           string p;
           
          
       if (inputFile.is_open()) {
           
           while (inputFile>>m>>d>>y>>amt>>p) {
               setYear(y);
               addExpense(m-1, d-1, amt, p); //array for month starts at 0
               numLines++;


           }
           
           
       }
    
    inputFile.close();
    return numLines;
}

void yearly::printOneDay(ostream &out, int m, int d){
    months[m-1].printOneDay(out, d-1); //array for month starts at 0
}

void yearly::printOneMonth(ostream &out, int m){
    months[m-1].print(out); //array for month starts at 0
}

void yearly::print(ostream &out){
    for (int i=0; i<ysize; i++) {
        months[i].print(out);
    }
}





