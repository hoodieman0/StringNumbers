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
        int parts[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
        StringInt text("1234567890");
        vector<int> receivedValues = text.asInt();
        if (receivedValues.size() != 10) throw "wrong amount of vector return values";
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

int UnitTest_asString(){
    try{
        StringInt text1("1234567890");
        string test = text1.asString();
        cout << "\n'1234567890' ?= \'" << test << "\'\n" << endl;
        
        if (test != "1234567890") throw "unexpected return string from StringInt";

    } catch (...) { return 1; }
    return 0;
}

int UnitTest_SimpleAdd(){
    try{
        StringInt text1("2");
        StringInt text2("2");

        StringInt text3 = text1 + text2;

        if (text3.asString() != "4" || text3.asInt()[0] != 4) throw "simple addition failed to add 2 + 2";
        
        StringInt text4 = text3 + text1;
        if (text4.asString() != "6" || text4.asInt()[0] != 6) throw "simple addition failed to add 4 + 2";
    } catch(const char* a) {
        cout << a << endl; return 1;
    } catch (...) { return 1; }
    return 0;
}

int UnitTest_CarryOverAdd(){
    try{
        StringInt text1("5");
        StringInt text2("5");
        StringInt text3 = text1 + text2;

        if (text3.asString() != "10" || text3.asInt()[0] != 1 || text3.asInt()[1] != 0) 
            throw "carry over failed to add 5 + 5";
        
        StringInt text4("999999"); // 999,999
        StringInt text5("1");
        StringInt text6 = text4 + text5;
        
        int expected1[7] = {1, 0, 0, 0, 0, 0, 0};
        vector<int> result1 = text6.asInt();

        if (result1.size() != 7) throw "carry over failed to add 999,999 + 1";
        for (unsigned int i = 0; i < result1.size(); i++ ){
            if (result1[i] != expected1[i]) throw "carry over failed to add 999,999 + 1";
        }

        if (text6.asString() != "1000000") 
            throw "carry over failed to add 999,999 + 1";


        text6 = text5 + text4;
        result1 = text6.asInt();

        if (result1.size() != 7) throw "carry over failed to add 999,999 + 1";
        for (unsigned int i = 0; i < result1.size(); i++ ){
            if (result1[i] != expected1[i]) throw "carry over failed to add 999,999 + 1";
        }

        if (text6.asString() != "1000000") 
            throw "carry over failed to add 999,999 + 1";

        StringInt text7("999999"); // 999,999
        StringInt text8("999999"); // 999,999
        StringInt text9 = text7 + text8;

        int expected2[7] = {1, 9, 9, 9, 9, 9, 8};
        vector<int> result2 = text9.asInt();

        if (result2.size() != 7) throw "carry over failed to add 999,999 + 999,999";
        for (unsigned int i = 0; i < result2.size(); i++ ){
            if (result2[i] != expected2[i]) throw "carry over failed to add 999,999 + 999,999";
        }

        if (text9.asString() != "1999998") 
            throw "carry over failed to add 999,999 + 999,999";

        
    } catch(const char* a) {
        cout << a << endl; return 1;
    } catch (...) { return 1; }
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

    cout << "Running Unit Test - Equivalence..." << endl;
    if (UnitTest_Equivalence()) { cout << "Unit Test - Equivalence -> Failed Test \u274c" << endl; failed++;}
    else { cout << "Unit Test - Equivalence -> Passed Test \u2713" << endl; passed++; }

    cout << "------------------------------------------------------" << endl;

    cout << "Running Unit Test - asString..." << endl;
    if (UnitTest_asString()) { cout << "Unit Test - asString -> Failed Test \u274c" << endl; failed++;}
    else { cout << "Unit Test - asString -> Passed Test \u2713" << endl; passed++; }

    cout << "------------------------------------------------------" << endl;

    cout << "Running Unit Test - SimpleAdd..." << endl;
    if (UnitTest_SimpleAdd()) { cout << "Unit Test - SimpleAdd -> Failed Test \u274c" << endl; failed++;}
    else { cout << "Unit Test - SimpleAdd -> Passed Test \u2713" << endl; passed++; }

    cout << "------------------------------------------------------" << endl;

    cout << "Running Unit Test - CarryOverAdd..." << endl;
    if (UnitTest_CarryOverAdd()) { cout << "Unit Test - CarryOverAdd -> Failed Test \u274c" << endl; failed++;}
    else { cout << "Unit Test - CarryOverAdd -> Passed Test \u2713" << endl; passed++; }

    cout << "------------------------------------------------------" << endl;
    cout << "Finished running all tests" << endl;
    cout << "\u2713 Passed Tests: " << passed << endl;
    cout << "\u274c Failed Tests: " << failed << endl;

    return 0;
}