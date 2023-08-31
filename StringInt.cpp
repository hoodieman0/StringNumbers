#include "StringInt.hpp"

// the number is represented in reverse order to reduce position calculations for arithmetic
// ex: 1469 is represented as 9641
StringInt::
StringInt(const string num) {
    for (int i = num.size() - 1; i > -1; i--){
        if (num[i] < 48 || num[i] > 57) throw "NaN"; // if it is not a number character
        number.push_back(num[i]); 
    }
}

string StringInt::
add(char a, char b) const {
    if (a < 48 || a > 57 || b < 48 || b > 57) throw "NaN"; // if it is not a number character

    string result = "";

    int c = (a - 48) + (b - 48);

    if (c > 9) {
        result += '1';
        result += ((c - 10) + 48);
    }
    else {
        result += (c + 48);
    }

    return result;
}
