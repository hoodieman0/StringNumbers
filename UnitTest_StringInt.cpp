#include "UnitTest_StringInt.hpp"

bool isEqual(const StringInt result, const string expected){
    const vector<int> resultInt = result.asInt();
    const string resultStr = result.asString();

    if (resultInt.size() != expected.size()) return false;

    for (unsigned int i = 0; i < resultInt.size(); i++){
        if (resultInt[i] != expected[i] - 48) return false;
    }

    if (resultStr != expected) return false;

    return true;
}

int UnitTest_DefaultConstruction(){
    try {
        StringInt text;

        vector<int> receivedValues = text.asInt();
        
        if (receivedValues.size() != 1) throw "Values Do Not Meet Expected Amount";
        else if (receivedValues[0] != 0) throw "Default Construction Does Not Yield 0";
        cout << "Default Constructor's value is: " << receivedValues[0] << endl;
    } catch(const char* a) {
        cout << a << endl; return 1;
    } catch (...) { return 1; }

    return 0;
}

int UnitTest_CreateClass(){
    try {
        StringInt text1("1234567890");
        StringInt text2("00001");
        if (text2.asString() != "1") throw "Constructor did not remove leading 0s";
    } catch(const char* a) {
        cout << a << endl; return 1;
    } catch (...) { return 1; }

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
    } catch(const char* a) {
        cout << a << endl; return 1;
    } catch (...) { return 1; }

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
    } catch(const char* a) {
        cout << a << endl; return 1;
    } catch (...) { return 1; }
    return 0;
}

int UnitTest_asString(){
    try{
        StringInt text1("1234567890");
        string test = text1.asString();
        cout << "\n'1234567890' ?= \'" << test << "\'\n" << endl;
        
        if (test != "1234567890") throw "unexpected return string from StringInt";

    } catch(const char* a) {
        cout << a << endl; return 1;
    } catch (...) { return 1; }
    return 0;
}

int UnitTest_SimpleAdd(){
    try{
        StringInt text1("2");
        StringInt text2("2");

        StringInt text3 = text1 + text2;

        if (!isEqual(text3, "4")) throw "simple addition failed to add 2 + 2";
        
        StringInt text4 = text3 + text1;
        if (!isEqual(text4, "6")) throw "simple addition failed to add 4 + 2";
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

        if (!isEqual(text3, "10")) throw "carry over failed to add 5 + 5";
        
        StringInt text4("999999"); // 999,999
        StringInt text5("1");
        StringInt text6 = text4 + text5;
        if (!isEqual(text6, "1000000")) throw "carry over failed to add 999,999 + 1";

        text6 = text5 + text4;
        if (!isEqual(text6, "1000000")) throw "carry over failed to add 1 + 999,999";

        StringInt text7("999999"); // 999,999
        StringInt text8("999999"); // 999,999
        StringInt text9 = text7 + text8;

        if (!isEqual(text9, "1999998")) throw "carry over failed to add 999,999 + 999,999";
        
    } catch(const char* a) {
        cout << a << endl; return 1;
    } catch (...) { return 1; }
    return 0;
}

int UnitTest_SimpleSub(){
    try{
        StringInt text1("2");
        StringInt text2("2");
        StringInt text3 = text1 - text2;

        if (!isEqual(text3, "0")) throw "StringInt failed to subtract 2 - 2";

    } catch(const char* a) {
        cout << a << endl; return 1;
    } catch (...) { return 1; }
    return 0;
}

int UnitTest_PositiveSub(){
    try{
        StringInt text1("1000");
        StringInt text2("1");
        StringInt text3 = text1 - text2;
        if (!isEqual(text3, "999")) throw "StringInt failed to subtract 1000 - 1";


        StringInt text4("757");
        StringInt text5("757");
        StringInt text6 = text4 - text5;
        if (!isEqual(text6, "0")) throw "StringInt failed to subtract 0757 - 757";

        StringInt text7("157843");
        StringInt text8("23981");
        StringInt text9 = text7 - text8;
        if (!isEqual(text9, "133862")) throw "StringInt failed to subtract 157843 - 23981";
        
        StringInt text10("9998");
        StringInt text11("1119");
        StringInt text12 = text10 - text11;
        if (!isEqual(text12, "8879")) throw "StringInt failed to subtract 9998 - 1119";

    } catch(const char* a) {
        cout << a << endl; return 1;
    } catch (...) { return 1; }
    return 0;
}

int UnitTest_GreaterThan(){
    try {
        StringInt text1("100");
        StringInt text2("10");

        if ( !(text1 > text2) ) throw "100 > 10 gives false";
        if (text2 > text1) throw "10 > 100 gives true";
        if (text1 > text1) throw "100 > 100 gives true";

        StringInt text3("101");
        if (!(text3 > text1)) throw "101 > 100 gives false";

        StringInt text4("9998");
        StringInt text5("1119");
        if (!(text4 > text5)) throw "9998 > 1119 gives false";
        if (text5 > text4) throw "1119 > 9998 gives true";

    } catch(const char* a) {
        cout << a << endl; return 1;
    } catch (...) { return 1; }
    
    return 0;
}

int UnitTest_LessThan(){
    try {
        StringInt text1("100");
        StringInt text2("10");

        if ( !(text2 < text1) ) throw "10 < 100 gives false";
        if (text1 < text2) throw "100 < 10 gives true";
        if (text1 < text1) throw "100 < 100 gives true";

        StringInt text3("101");
        if (!(text1 < text3)) throw "100 < 101 gives false";

        StringInt text4("9998");
        StringInt text5("1119");
        if (!(text5 < text4)) throw "1119 < 9998 gives false";
        if (text4 < text5) throw "9998 < 1119 gives true";

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

    cout << "Running Unit Test - SimpleSub..." << endl;
    if (UnitTest_SimpleSub()) { cout << "Unit Test - SimpleSub -> Failed Test \u274c" << endl; failed++;}
    else { cout << "Unit Test - SimpleSub -> Passed Test \u2713" << endl; passed++; }

    cout << "------------------------------------------------------" << endl;

    cout << "Running Unit Test - PositiveSub..." << endl;
    if (UnitTest_PositiveSub()) { cout << "Unit Test - PositiveSub -> Failed Test \u274c" << endl; failed++;}
    else { cout << "Unit Test - PositiveSub -> Passed Test \u2713" << endl; passed++; }

    cout << "------------------------------------------------------" << endl;

    cout << "Running Unit Test - GreaterThan..." << endl;
    if (UnitTest_GreaterThan()) { cout << "Unit Test - GreaterThan -> Failed Test \u274c" << endl; failed++;}
    else { cout << "Unit Test - GreaterThan -> Passed Test \u2713" << endl; passed++; }

    cout << "------------------------------------------------------" << endl;

    cout << "Running Unit Test - LessThan..." << endl;
    if (UnitTest_LessThan()) { cout << "Unit Test - LessThan -> Failed Test \u274c" << endl; failed++;}
    else { cout << "Unit Test - LessThan -> Passed Test \u2713" << endl; passed++; }

    cout << "------------------------------------------------------" << endl;
    cout << "Finished running all tests" << endl;
    cout << "\u2713 Passed Tests: " << passed << endl;
    cout << "\u274c Failed Tests: " << failed << endl;

    return 0;
}