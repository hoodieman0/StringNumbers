#ifndef STRINT_HPP
#define STRINT_HPP

#include <string>
#include <vector>
#include <cmath>

#include <iostream>

using namespace std;

class StringInt {
    private:
        string number;
        bool isNegative;

    public:
        StringInt() { number.push_back('0'); }
        StringInt(const string num);
        ~StringInt()=default;

        // returns a vector of the digits of number, ex: 65535 becomes < 6, 5, 5, 3, 5 >
        vector<int> asInt() const;
        string asString() const { return isNegative ? "-" + number : number; }

        StringInt operator+(const StringInt other) const;
        StringInt operator+(const int other) const;
        StringInt operator+(const float other) const;

        StringInt operator-(const StringInt sub) const;
        StringInt operator-(const int sub) const;
        StringInt operator-(const float sub) const;

        StringInt operator*(const StringInt mul) const;
        StringInt operator*(const int mul) const;
        StringInt operator*(const float mul) const;

        StringInt operator/(const StringInt div) const;
        StringInt operator/(const int div) const;
        StringInt operator/(const float div) const;

        StringInt operator%(const StringInt mod) const;
        StringInt operator%(const int mod) const;
        StringInt operator%(const float mod) const;

        StringInt operator++(int add);
        StringInt operator--(int sub);

        bool operator==(const StringInt compare) const;
        bool operator==(const int compare) const;
        bool operator==(const float compare) const;
        
        bool operator!=(const StringInt compare) const;
        bool operator!=(const int compare) const;
        bool operator!=(const float compare) const;

        bool operator>(const StringInt compare) const;
        bool operator>=(const StringInt compare) const;
        bool operator<(const StringInt compare) const;
        bool operator<=(const StringInt compare) const;
        
        char operator[](size_t idx) const;
};

inline ostream& operator<<(ostream& out, const StringInt& num) {
    return out << num.asString();
}

#endif 