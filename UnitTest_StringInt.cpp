#include "UnitTest_StringInt.hpp"

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
        int parts[3] = {12, 3456, 7890};
        StringInt text("1234567890");
        vector<int> receivedValues = text.asInt();
        if (receivedValues.size() != 3) throw "wrong amount of vector return values";
        for (unsigned int i = 0; i < receivedValues.size(); i++){
            cout << i+1 << ") Expected: " << parts[i] << setw(20) << "Received: " << receivedValues[i] << endl;
            if (receivedValues[i] != parts[i]) throw "Non-matching values";
        }
    }
    catch (...) { return 1; }

    return 0;
}

int UnitTest_Equivalence(){
    try {
        StringInt text1("123456789");
        StringInt text2("123456789");
        StringInt text3("101");
        StringInt text4("987654321");

        if(!(text1 == text1)) throw "text1 (123456789) does not equal itself";
        if(!(text1 == text2)) throw "text1 (123456789) does not equal text2 (123456789)";
        if(text1 == text3) throw "text1 (123456789) equals text3 (101)";
        if(text1 == text4) throw "text1 (123456789) equals text4 (987654321)";
    }
    catch (...) { return 1; }
    return 0;
}

int UnitTest_SimpleAdd(){
    try{
        StringInt text1("2");
        StringInt text2("2");
        StringInt text3 = text1 + text2;

        if (text3)

    } catch (...) { return 1; }
    return 0;
}

// int UnitTest_Addition(){
//     try {
//         StringInt text1("9999");
//         StringInt text2("1");

//         StringInt text3 = text1 + text2;
//     }
//     catch (...) { return 1; }

//     return 0;
// }

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

    cout << "Running Unit Test - Equivalence..." << endl;
    if (UnitTest_Equivalence()) { cout << "Unit Test - Equivalence -> Failed Test \u274c" << endl; failed++;}
    else { cout << "Unit Test - Equivalence -> Passed Test \u2713" << endl; passed++; }

    cout << "------------------------------------------------------" << endl;
    cout << "Finished running all tests" << endl;
    cout << "\u2713 Passed Tests: " << passed << endl;
    cout << "\u274c Failed Tests: " << failed << endl;

    return 0;
}