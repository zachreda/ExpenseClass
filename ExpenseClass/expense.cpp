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

    if (numexp<24) {
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

//constructor

monthly::monthly(){
    month=0;
    maxdays=-1;
}
void monthly::setMonth(int m){
    
}
void monthly::addExpense(<#int#>, <#double#>, <#string#>){
    
}
//double monthly::getDailyExpense(<#int#>){
//
//}
//double monthly::getMonthlyExpense(){
//
//}
void monthly::printOneDay(<#ostream &#>, <#int#>){
    
}

void monthly::print(ostream&){
    
}

//constructor
yearly::yearly(){
    year=0;
}
void yearly::setYear(int y){
    year = y;
}
void yearly::addExpense(<#int#>, <#int#>, <#double#>, <#string#>){
    
}
//double yearly::getDailyExpense(<#int#>, <#int#>){
//
//}
//
//double yearly::getMonthlyExpense(<#int#>){
//
//}
//
//double yearly::getYearlyExpense(){
//
//}

//int yearly::loadDataFromFile(<#string#>){
//
//}

void yearly::printOneDay(<#ostream &#>, <#int#>, <#int#>){
    
}
void yearly::printOneDay(<#int#>, <#int#>, <#int#>){
    
}

void yearly::printOneMonth(<#ostream &#>, <#int#>){
    
}

void yearly::print(<#ostream &#>){
    
}





