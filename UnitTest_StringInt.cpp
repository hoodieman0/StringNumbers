#include <iostream>
#include <iomanip>

#include "StringInt.hpp"

using namespace std;

int UnitTest_DefaultConstruction(){
    try {
        StringInt text;

        vector<int> receivedValues = text.asInt();
        
        if (receivedValues.size() != 1) throw "Values Do Not Meet Expected Amount";
        else if (receivedValues[0] != 0) throw "Default Construction Does Not Yield 0";
        cout << "Default Constructor's value is: " << receivedValues[0] << endl;
    }
    catch (...) { return 1; }

    return 0;
}

int UnitTest_CreateClass(){
    try {
        StringInt text("1234567890");
    }
    catch (...) { return 1; }

    return 0;
}


int UnitTest_asInt(){
    try {
        int parts[3] = {7890, 3456, 12};
        StringInt text("1234567890");
        vector<int> receivedValues = text.asInt();
        for (int i = 0; i < receivedValues.size(); i++){
            cout << i+1 << ") Expected: " << parts[i] << setw(20) << "Received: " << receivedValues[i] << endl;
            if (receivedValues[i] != parts[i]) throw "Non-matching values";
        }
    }
    catch (...) { return 1; }

    return 0;
}

int UnitTest_RunAll(){
    int passed = 0, failed = 0;

    cout << "Running all unit tests for StringInt class" << endl;
    cout << "------------------------------------------------------" << endl;

    cout << "Running Unit Test - DefaultConstruction..." << endl;
    if (UnitTest_DefaultConstruction()) { cout << "Unit Test - DefaultConstruction -> Failed Test \u274c" << endl; failed++;}
    else { cout << "Unit Test - DefaultConstruction -> Passed Test \u2713" << endl; passed++; }

    cout << "------------------------------------------------------" << endl;

    cout << "Running Unit Test - CreateClass..." << endl;
    if (UnitTest_CreateClass()) { cout << "Unit Test - CreateClass -> Failed Test \u274c" << endl; failed++;}
    else { cout << "Unit Test - CreateClass -> Passed Test \u2713" << endl; passed++; }

    cout << "------------------------------------------------------" << endl;

    cout << "Running Unit Test - asInt..." << endl;
    if (UnitTest_asInt()) { cout << "Unit Test - asInt -> Failed Test \u274c" << endl; failed++;}
    else { cout << "Unit Test - asInt -> Passed Test \u2713" << endl; passed++; }

    cout << "------------------------------------------------------" << endl;
    cout << "Finished running all tests" << endl;
    cout << "\u2713 Passed Tests: " << passed << endl;
    cout << "\u274c Failed Tests: " << failed << endl;
}