#include "StringInt.hpp"

StringInt::
StringInt(const string num) {
    for (int i = 0; i < num.size(); i++){
        number.push_back(num[i]);
    }
}

