#include "StringInt.hpp"

StringInt::
StringInt(const string num) {
    char c;
    unsigned int i = 0;
    if (num[0] == '-'){
        isNegative = true;
        i++;
    }
    else isNegative = false;

    c = num[i];
    while (c == '0' && i+1 < num.size()) i++; // do not add leading 0s

    for (; i < num.size(); i++ ) {
        c = num[i];
        if (c < 48 || c > 57) throw "Not a Number";
        number += c;
    }
}

// MAX_INT is 32767
// 157 appears as <1, 5, 7>
vector<int> StringInt::
asInt() const {
    vector<int> result;

    if (number.size() == 0) return result;
    for (char c : number) result.push_back(c - 48);

    return result;
}

StringInt StringInt::
operator+(const StringInt other) const {
    vector<int> numCopy = this->asInt();
    vector<int> otherCopy = other.asInt();
    int carryOver = 0;

    string reversed = "";

    unsigned int i = 0;
    int temp;
    while (true){
        temp = numCopy[numCopy.size() - 1 - i] + otherCopy[otherCopy.size() - 1 - i] + carryOver;
        carryOver = 0;

        if (temp > 9){
            carryOver = 1;
            temp = temp % 10;
        }
        reversed += temp + 48;
        i++;

        if (i == numCopy.size()){
            while (i < otherCopy.size()){
                temp = otherCopy[i++] + carryOver;
                carryOver = 0;
                if (temp > 9){
                    carryOver = 1;
                    temp = temp % 10;
                }
                reversed += temp + 48;
            }

            if (carryOver) reversed += carryOver + 48;

            break;
        }
        else if (i == otherCopy.size()){
            while (i < numCopy.size()){
                temp = numCopy[i++] + carryOver;
                carryOver = 0;
                if (temp > 9){
                    carryOver = 1;
                    temp = temp % 10;
                }
                reversed += temp + 48;
            }

            if (carryOver) reversed += carryOver + 48;

            break;
        }
    }

    string resultString = "";
    for (int i = reversed.size() - 1; i >= 0; i--) resultString.push_back(reversed[i]);

    return StringInt(resultString);
}

// this - sub = result
StringInt StringInt::
operator-(const StringInt sub) const {
    if (*this < sub) throw "Negative numbers not implemented";

    vector<int> numCopy = this->asInt();
    vector<int> otherCopy = sub.asInt();

    string reversed = "";
    int num1, num2;

    unsigned int i = 0;
    int temp;
    while (true){
        num1 = numCopy[numCopy.size() - 1 - i];
        num2 = otherCopy[otherCopy.size() - 1 - i];

        if (num2 > num1) { 
            num1 += 10;

            unsigned int j = i + 1;
            while (numCopy[numCopy.size() - 1 - j] == 0) {
                numCopy[numCopy.size() - 1 - j] = 9;
                j++;
                if (j == numCopy.size()) throw "Cannot find number to carry over";
            }
            numCopy[numCopy.size() - 1 - j] = numCopy[numCopy.size() - 1 - j] - 1; 
        }
        temp = num1 - num2;

        reversed += temp + 48;
        i++;

        // 2 - 10 TODO Make a sub function to flip inputs and make result negative
       
        if (i == otherCopy.size()){ // reached otherCopy's left-most digit
            while (i < numCopy.size()) reversed += numCopy[numCopy.size() - 1 - i++] + 48;// ad the remaining top digits to result
            while (reversed.back() == '0' && reversed.size() > 1) reversed.pop_back(); // remove leading zeros
            break;
        }
        else if (i == numCopy.size()){
            throw "negative numbers not implemented";
            break;
        } 
    }

    string resultString = reversed;
    reverse(resultString.begin(), resultString.end()); 
    return StringInt(resultString);
}

bool StringInt::
operator==(const StringInt compare) const {
    if (number.size() != compare.number.size()) return false;
    for (unsigned int i = 0; i < number.size(); i++) {
        if (number[i] != compare.number[i]) return false;
    }

    return true;
}

// this > compare
// does not work with negative numbers
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

// this < compare
// does not work with negative numbers
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