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

// MAX_INT is 32767
// only use the first four digits of the int to allow for 9,999 to be represented
vector<int> StringInt::
asInt() const {
    vector<int> result;
    int section = 0;

    for (int i = 0; i < number.size(); i++) {
        if (i % 4 == 0 && i != 0){
            result.push_back(section);
            section = (number[i] - 48);
        }
        else { section += (int(pow(10, i%4))) * (number[i] - 48); }
    }

    if (section) {
        result.push_back(section);
    }
    
    return result;
}