#include "StringInt.hpp"

StringInt::
StringInt(const string num) : number(num) { 
    for (char c : number ) {
        if (c < 48 || c > 57) throw "Not a Number";
    }
}

// MAX_INT is 32767
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

bool StringInt::
operator==(const StringInt compare) const {
    if (number.size() != compare.number.size()) return false;
    for (unsigned int i = 0; i < number.size(); i++) {
        if (number[i] != compare.number[i]) return false;
    }

    return true;
}