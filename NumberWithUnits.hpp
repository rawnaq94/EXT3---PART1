#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include<string>
#include<stdexcept>

namespace ariel {
    class NumberWithUnits {
    private:
double num;
std::string unitn;
    public:
        NumberWithUnits(double number, std::string unit) {}
        ~NumberWithUnits(){}; 

        static void read_units(std::ifstream &units_file);

        NumberWithUnits operator+(const NumberWithUnits &element)const;
        NumberWithUnits &operator+=(const NumberWithUnits &element);
        NumberWithUnits operator+()const; 

        NumberWithUnits operator-(const NumberWithUnits &element)const;
        NumberWithUnits &operator-=(const NumberWithUnits &element);
        NumberWithUnits operator-()const;
  
      
        bool operator<(const NumberWithUnits &element) const;
        bool operator<=(const NumberWithUnits &element)const;
        bool operator>(const NumberWithUnits &element)const; 
        bool operator>=(const NumberWithUnits &element)const;
        bool operator==(const NumberWithUnits &element)const;
        bool operator!=(const NumberWithUnits &element)const;

        NumberWithUnits operator++(int);
        NumberWithUnits operator--(int);

        NumberWithUnits &operator++();
        NumberWithUnits &operator--();

         friend NumberWithUnits operator*(double num, NumberWithUnits &element);

    
        friend std::istream &operator>>(std::istream &os,  NumberWithUnits &input);
        friend std::ostream &operator<<(std::ostream &is, const NumberWithUnits &input);
    };
}
