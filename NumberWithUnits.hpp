#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;


namespace ariel {
    class NumberWithUnits {
    private:
        map<double, string> units;

    public:
        NumberWithUnits(double number, string unit) {}
        ~NumberWithUnits(){}; 

        static void read_units(ifstream &file_name);

        NumberWithUnits operator+(const NumberWithUnits &element);
        NumberWithUnits &operator+=(const NumberWithUnits &element);
        NumberWithUnits &operator+(); 

        NumberWithUnits operator-(const NumberWithUnits &element);
        NumberWithUnits &operator-=(const NumberWithUnits &element);
        NumberWithUnits &operator-();
  
      
        bool operator<(const NumberWithUnits &element);
        bool operator<=(const NumberWithUnits &element);
        bool operator>(const NumberWithUnits &element); 
        bool operator>=(const NumberWithUnits &element);
        bool operator==(const NumberWithUnits &element);
        bool operator!=(const NumberWithUnits &element);

        NumberWithUnits &operator++(int);
        NumberWithUnits &operator--(int);

        NumberWithUnits &operator++();
        NumberWithUnits &operator--();

        friend NumberWithUnits operator*(const NumberWithUnits &element, double num);
        friend NumberWithUnits operator*=(const NumberWithUnits &element, double num);

        friend NumberWithUnits operator*(double num, const NumberWithUnits &element);
        friend NumberWithUnits operator*=(double num, const NumberWithUnits &element);

        friend std::istream &operator<<(istream &os, const NumberWithUnits &input);
        friend std::ostream &operator>>(ostream &os, NumberWithUnits &output);
    };
}
