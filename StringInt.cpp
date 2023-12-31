#include "StringInt.hpp"

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
// only use the first four digits of the int to allow for 9,999 to be represented
vector<int> StringInt::
asInt() const {
    vector<int> result;

    if (number.size() == 0) return result;

    // handler edge case of 0
    if (number.size() == 1 && number[0] == '0') {
        result.push_back(0);
        return result;
    }

    int section = 0;

    for (unsigned int i = 0; i < number.size(); i++) {
        if (i % 4 == 0 && i != 0){
            result.push_back(section);
            section = (int(pow(10, 3 - (i%4)))) * (number[i] - 48);
        }
        else { section += (int(pow(10, 3 - (i%4)))) * (number[i] - 48); }
    }

    

    if (section){ 
        int size1 = number.size(); // 10
        int size2 = (result.size() + 1) * 4; // 12
        cout << size1 << endl;
        cout << size2 << endl;

        while (size1 < size2) { section /= 10; size2--; }
        cout << section << endl;
        
        result.push_back(section);
    }

    return result;
}



StringInt StringInt::
operator+(const StringInt other) const {
    string numCopy = number;
    string otherCopy = other.number;

    unsigned int digitPlace;
    int carryOver = 0;
    string resultString = "";

    string temp;

    // choose the smallest sized number for addition
    if (numCopy.size() > otherCopy.size()) digitPlace = otherCopy.size();
    else digitPlace = numCopy.size();
    
    for (unsigned int i = 0; i < digitPlace; i++){
        if (carryOver > 0){
            temp = add(carryOver + 48, numCopy[i]);
            if (temp.size() == 1){
                numCopy[i] = temp[0];
                carryOver = 0;
            } 
            else {
                numCopy[i] = temp[1];
                carryOver = temp[0] - 48;
            }
        }

        temp = add(numCopy[i], otherCopy[i]);
        if (temp.size() == 1) resultString.append(temp);
        else {
            resultString += temp[1];
            carryOver += temp[0] - 48;
        }
    }

    if (carryOver > 0){
        if (otherCopy.size() > digitPlace){
            temp = add(carryOver + 48, otherCopy[otherCopy.size()]);
            if (temp.size() > 1) throw "Error with final carry over";
            resultString += temp[0];
        }
        else if (numCopy.size() > digitPlace){
            temp = add(carryOver + 48, numCopy[numCopy.size()]);
            if (temp.size() > 1) throw "Error with final carry over";
            resultString += temp[0];
        }
    }

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