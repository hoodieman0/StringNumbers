#ifndef UNIT_TEST_STRINGINT_HPP
#define UNIT_TEST_STRINGINT_HPP

#include <iostream>
#include <iomanip>

#include "StringInt.hpp"

using namespace std;

int UnitTest_RunAll();
int UnitTest_DefaultConstruction();
int UnitTest_CreateClass();
int UnitTest_asInt();
int UnitTest_asString();
int UnitTest_Equivalnce();
int UnitTest_SimpleAdd();
int UnitTest_CarryOverAdd();

int UnitTest_GreaterThan();
int UnitTest_LessThan();

bool compareResult(const StringInt result, const string expected);

#endif