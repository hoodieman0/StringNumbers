#ifndef STRINT_HPP
#define STRINT_HPP

#include <string>
#include <vector>

using namespace std;

class StringInt {
    private:
        vector<char> number;

    public:
        StringInt(const string number);

        vector<int> asInt();

        StringInt operator+(const StringInt add) const;
        StringInt operator+(const int add) const;
        StringInt operator+(const float add) const;

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
};

#endif STRINT_HPP