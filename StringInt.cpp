#include "StringInt.hpp"

/// @brief Class constructor
/// Handles input validation of the class
/// @param num a string that follows -?[0-9]*
/// @note does not handle negative numbers or decimals
StringInt::
StringInt(const string num) {
    char c;
    unsigned int i = 0;

    // check if there is a negative sign
    if (num[0] == '-'){                       
        isNegative = true;
        i++;
    }
    else isNegative = false;

    // do not add leading 0s
    c = num[i];
    while (c == '0' && i+1 < num.size()) i++; 

    // add the rest of num to number, checking if they are valid characters
    for (; i < num.size(); i++ ) {
        c = num[i];
        if (c < 48 || c > 57) throw "Not a Number";
        number += c;
    }
}

/// @brief returns number as a vector of its digits, ex: 65535 becomes < 6, 5, 5, 3, 5 >
vector<int> StringInt::
asInt() const {
    vector<int> result;

    // char representation to its int is put in the result 
    if (number.size() == 0) return result;
    for (char c : number) result.push_back(c - 48);

    return result;
}

/// @brief handles addition for two StringInts
/// @param other the StringInt to add to the current StringInt
/// @note code formatted as (this + other)
/// @note does not handle negative or decimal numbers
/// @return a StringInt that is the result of the addition
StringInt StringInt::
operator+(const StringInt other) const {
    vector<int> numCopy = this->asInt();
    vector<int> otherCopy = other.asInt();
    int carryOver = 0;

    string reversed = "";

    unsigned int i = 0;
    int temp;
    
    // go through each digit, starting with the least-significant digit
    while (true){
        temp = numCopy[numCopy.size() - 1 - i] + otherCopy[otherCopy.size() - 1 - i] + carryOver;
        carryOver = 0;

        // check if there needs to be a carry-over
        if (temp > 9){
            carryOver = 1;
            temp = temp % 10;
        }
        // add the number as a character
        reversed += temp + 48;
        i++;

        // if numCopy has no more digits 
        if (i == numCopy.size()){
            // add the rest of otherCopy's numbers to reversed
            while (i < otherCopy.size()){
                temp = otherCopy[i++] + carryOver;
                carryOver = 0;
                if (temp > 9){
                    carryOver = 1;
                    temp = temp % 10;
                }
                reversed += temp + 48;
            }
            
            // add the remaining carry-over
            if (carryOver) reversed += carryOver + 48;

            break;
        }
        // if otherCopy has no more digits
        else if (i == otherCopy.size()){
            // add the rest of numCopy's numbers to reversed
            while (i < numCopy.size()){
                temp = numCopy[i++] + carryOver;
                carryOver = 0;
                if (temp > 9){
                    carryOver = 1;
                    temp = temp % 10;
                }
                reversed += temp + 48;
            }

            // add the remaining carry-over
            if (carryOver) reversed += carryOver + 48;

            break;
        }
    }

    // reverse the string and return it as an object
    string resultString = reversed;
    reverse(resultString.begin(), resultString.end()); 

    return StringInt(resultString);
}

/// @brief handles subtraction for two StringInts
/// @param sub the StringInt to subtract the current StringInt by
/// @note code formatted as (this + other)
/// @note does not handle negative or decimal numbers
/// @return a StringInt that is the result of the subtraction
StringInt StringInt::
operator-(const StringInt sub) const {
    if (*this < sub) throw "Negative numbers not implemented";

    vector<int> numCopy = this->asInt();
    vector<int> otherCopy = sub.asInt();

    string reversed = "";
    int num1, num2;

    unsigned int i = 0;
    int temp;

    // go through each digit, starting with the least-significant digit
    while (true){
        num1 = numCopy[numCopy.size() - 1 - i];
        num2 = otherCopy[otherCopy.size() - 1 - i];

        // if the digit being subtracted is less than sub's digit
        if (num2 > num1) { 
            num1 += 10; // add 10 to make the subtraction work

            // determine how many carry-overs need to be done
            unsigned int j = i + 1;
            while (numCopy[numCopy.size() - 1 - j] == 0) {
                numCopy[numCopy.size() - 1 - j] = 9;
                j++;
                if (j == numCopy.size()) throw "Cannot find number to carry over";
            }
            numCopy[numCopy.size() - 1 - j] = numCopy[numCopy.size() - 1 - j] - 1; 
        }
        temp = num1 - num2; // do the subtraction of the digits

        // add it to the string
        reversed += temp + 48;
        i++;

        // TODO Make a sub function to flip inputs and make result negative
       
        if (i == otherCopy.size()){ // reached otherCopy's left-most digit
            while (i < numCopy.size()) reversed += numCopy[numCopy.size() - 1 - i++] + 48;// add the remaining top digits to result
            while (reversed.back() == '0' && reversed.size() > 1) reversed.pop_back(); // remove leading zeros
            break;
        }
        // this case will only trigger when the result is negative
        else if (i == numCopy.size()){
            throw "negative numbers not implemented";
            break;
        } 
    }

    // reverse the string and return the result as a StringInt object
    string resultString = reversed;
    reverse(resultString.begin(), resultString.end()); 
    return StringInt(resultString);
}

/// @brief check if two StringInts are equal
/// @param compare the other StringInt to check equivalence
/// @note formatted as this == compare
/// @return true if they are the same, false if not
bool StringInt::
operator==(const StringInt compare) const {
    if (number.size() != compare.number.size()) return false;
    for (unsigned int i = 0; i < number.size(); i++) {
        if (number[i] != compare.number[i]) return false;
    }

    return true;
}

/// @brief check if the StringInt is greater than compare
/// @param compare the other StringInt to check greater than
/// @note formatted as this > compare
/// @note does not work with negative numbers
/// @return true if this is greater than compare, false if not
bool StringInt::
operator>(const StringInt compare) const{
    if (number.size() < compare.number.size()) return false; // is left smaller than right?
    else if (number.size() > compare.number.size()) return true; // is left greater than right?

    // if they are the same size...
    for (unsigned int i = 0; i < number.size(); i++) {
        if (number[i] > compare.number[i]) return true; // is the digit on the left greater than the right?
        else if (number[i] < compare.number[i]) return false; // if the digit on the left is less than the right the number is less
    }

    return false; // left and right are the same number
}

/// @brief check if the StringInt is less than compare
/// @param compare the other StringInt to check less than
/// @note formatted as this < compare
/// @note does not work with negative numbers
/// @return true if this is less than compare, false if not
bool StringInt::
operator<(const StringInt compare) const{
    if (number.size() < compare.number.size()) return true; // is left smaller than right?
    else if (number.size() > compare.number.size()) return false; // is left greater than right?

    // if they are the same size...
    for (unsigned int i = 0; i < number.size(); i++) {
        if (number[i] < compare.number[i]) return true; // is the digit on the left less than the right?
        else if (number[i] > compare.number[i]) return false; // if the digit on the left is greater than the right the number is greater
    }

    return false; // left and right are the same number
}