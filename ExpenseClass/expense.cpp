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

