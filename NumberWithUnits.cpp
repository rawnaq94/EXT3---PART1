#include "NumberWithUnits.hpp"
#include <string>
#include <iostream>
using namespace std;
namespace ariel
{

    void NumberWithUnits::read_units(ifstream &file_name)
    {
        cout << "Rawnaq";
    }

    NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &element) const
    {
        return {0, ""};
    }
    NumberWithUnits &NumberWithUnits::operator+=(const NumberWithUnits &element)
    {
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator+() const
    {
        return {0, ""};
    }

    NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits &element) const
    {
        return {0, ""};
    }
    NumberWithUnits &NumberWithUnits::operator-=(const NumberWithUnits &element)
    {
        return *this;
    }
    NumberWithUnits NumberWithUnits::operator-() const
    {
        return {0, ""};
    }

    bool NumberWithUnits::operator<(const NumberWithUnits &element) const { return true; }
    bool NumberWithUnits::operator<=(const NumberWithUnits &element) const { return true; }
    bool NumberWithUnits::operator>(const NumberWithUnits &element) const { return true; }
    bool NumberWithUnits::operator>=(const NumberWithUnits &element) const { return true; }
    bool NumberWithUnits::operator==(const NumberWithUnits &element) const { return true; }
    bool NumberWithUnits::operator!=(const NumberWithUnits &element) const { return true; }

    NumberWithUnits NumberWithUnits::operator++(int)
    {
        return {0, ""};
    }
    NumberWithUnits NumberWithUnits::operator--(int)
    {
        return {0, ""};
    }

    NumberWithUnits operator*(double num, NumberWithUnits &element)
    {
        return {0, ""};
    }

    istream &operator>>(istream &os, NumberWithUnits &input)
    {
        string s;
        return os>>input.unitn >> input.num;
    }
    ostream &operator<<(ostream &is, const NumberWithUnits &input)
    {
        return is<<input.num <<input.unitn ;
    }
}