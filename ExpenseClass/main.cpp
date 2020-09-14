#include <iostream>
#include <string>

using namespace std;

#include "expense.h"

int main() {

    cout << "Program Started\n";

    yearly y;
    
    
   cout << "y size = " << sizeof(y) << endl;
    y.loadDataFromFile("data1.txt");
  //  y.printOneDay(cout,12,31);
  // y.printOneMonth(cout,1);
//
//   cout << y.getDailyExpense(1,1) << endl;
//    int i;
//    for(i=1;i<=12;i++) {
//        cout << "month=" << i << ",total=" << y.getMonthlyExpense(i) << endl;
//    }
    cout << y.getYearlyExpense() << endl;


    return 0;
}

