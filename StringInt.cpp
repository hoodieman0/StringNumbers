#include "StringInt.hpp"

StringInt::
StringInt(const string num) : number(num) { 
    for (char c : number ) {
        if (c < 48 || c > 57) throw "Not a Number";
    }
}

string StringInt::
add(char a, char b) const {
    if (a < 48 || a > 57 || b < 48 || b > 57) throw "Not a Number"; // if it is not a number character
   
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
    unsigned int digitPlace;
    int carryOver = 0;
    int temp;
    string resultString = "";
    string reversed = "";

    if (numCopy.size() > otherCopy.size()) digitPlace = otherCopy.size();
    else digitPlace = numCopy.size();

    for (int i = 0; i < digitPlace; i++){
        temp = numCopy[numCopy.size() - 1 - i] + otherCopy[otherCopy.size() - 1 - i] + carryOver;
        carryOver = 0;
        if (temp > 9){
            carryOver = 1;
            temp = temp % 10;
        }
        reversed += temp + 48;
    }



    for ()

    // string numCopy = number;
    // string otherCopy = other.number;

    // unsigned int digitPlace;
    // int carryOver = 0;
    // string resultString = "";

    // string temp;

    // // choose the smallest sized number for addition
    // if (numCopy.size() > otherCopy.size()) digitPlace = otherCopy.size();
    // else digitPlace = numCopy.size();
    
    // for (unsigned int i = 0; i < digitPlace; i++){
    //     if (carryOver > 0){
    //         temp = add(carryOver + 48, numCopy[i]);
    //         if (temp.size() == 1){
    //             numCopy[i] = temp[0];
    //             carryOver = 0;
    //         } 
    //         else {
    //             numCopy[i] = temp[1];
    //             carryOver = temp[0] - 48;
    //         }
    //     }

    //     temp = add(numCopy[i], otherCopy[i]);
    //     if (temp.size() == 1) resultString.append(temp);
    //     else {
    //         resultString += temp[1];
    //         carryOver += temp[0] - 48;
    //     }
    // }

    // if (carryOver > 0){
    //     if (otherCopy.size() > digitPlace){
    //         temp = add(carryOver + 48, otherCopy[otherCopy.size()]);
    //         if (temp.size() > 1) throw "Error with final carry over";
    //         resultString += temp[0];
    //     }
    //     else if (numCopy.size() > digitPlace){
    //         temp = add(carryOver + 48, numCopy[numCopy.size()]);
    //         if (temp.size() > 1) throw "Error with final carry over";
    //         resultString += temp[0];
    //     }
    // }

    // return StringInt(resultString);
}

bool StringInt::
operator==(const StringInt compare) const {
    if (number.size() != compare.number.size()) return false;
    for (unsigned int i = 0; i < number.size(); i++) {
        if (number[i] != compare.number[i]) return false;
    }

    return true;
}