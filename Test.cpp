//  test unit file - created by rawnaq amer on 12/04/2021.
//

#include <stdio.h>
#include <fstream>
#include <sstream>
#include "doctest.h"
#include "NumberWithUnits.hpp"


using std::istringstream;
using std::string;
using namespace std;

using namespace ariel;

/*
* 1 km = 1000 m
* 1 m = 100 cm
* 1 kg = 1000 g
* 1 ton = 1000 kg
* 1 hour = 60 min
* 1 min = 60 sec
* 1 USD = 3.33 ILS
*/

// Distances + Weights +  Time units
NumberWithUnits cm{400, "cm"};     // 0.004km = 4m = 400cm
NumberWithUnits m{40, "m"};    // 0.04km = 40m = 4000cm
NumberWithUnits km{4, "km"};     // 4km = 4,000m = 400,000cm
NumberWithUnits cm1{-400, "cm"};  // -0.004km = -4m = -400cm
NumberWithUnits m1{-40, "m"}; // -0.04km = -40m = -4000cm
NumberWithUnits km1{-4, "km"};  // -4km = -4,000m = -400,000cm
NumberWithUnits ton{1 , "ton"}; // 1ton = 1000kg = 2e+6g = 2e+9mg
NumberWithUnits kg{10 , "kg"}; // 0.01ton = 10kg = 10000g = 1e+7mg  
NumberWithUnits g{100 , "g"}; // 1e-4ton = 0.1kg = 100g = 100000mg 
NumberWithUnits mg{1000 , "mg"}; // 1e-6ton = 0.001kg = 1g = 1000mg
NumberWithUnits hour{1 , "hour"}; // 1hour = 60min = 3600sec
NumberWithUnits min{60 , "min"}; // 1hour = 60min = 3600sec
NumberWithUnits sec{3600 , "sec"}; // 1hour = 60min = 3600sec
NumberWithUnits USD(1,"USD"); // 1USD = 3.33ILS 
NumberWithUnits ILS(2,"ILS"); // 2ILS = 6.66USD


ifstream units_file{"units.txt"};
NumberWithUnits::read_units(units_file);

TEST_CASE("checks operators")
{
    // test addition operator +
    CHECK(cm + m == NumberWithUnits(44, "m"));
    CHECK(cm + km == NumberWithUnits(400400, "cm"));
    CHECK(m + km == NumberWithUnits(4.04, "km"));
    CHECK(m + cm == NumberWithUnits(4400, "cm"));
    CHECK(km + cm == NumberWithUnits(4.004, "km"));
    CHECK(km + m == NumberWithUnits(4040, "m"));
    //  test subtraction operator -
    CHECK(m - cm == NumberWithUnits(36, "m"));
    CHECK(m - cm == NumberWithUnits(3600, "cm"));
    CHECK(km - m == NumberWithUnits(3.96, "km"));
    CHECK(km - cm == NumberWithUnits(399600, "cm"));
    // test plus Onri operator +=
    CHECK(km += NumberWithUnits{10, "km"} == NumberWithUnits(14, "km"));
    CHECK(m += NumberWithUnits{40, "m"} == NumberWithUnits(80, "m"));
    CHECK(cm += NumberWithUnits{200, "cm"} == NumberWithUnits(600, "cm"));
    // test  minus Onri operator -=
    CHECK(km -= NumberWithUnits{1, "km"} == NumberWithUnits(3, "km"));
    CHECK(m -= NumberWithUnits{20, "m"} == NumberWithUnits(20, "m"));
    CHECK(cm -= NumberWithUnits{80, "cm"} == NumberWithUnits(320, "cm"));
}


TEST_CASE("multiplication operator")
{
    //  test multiplication operator *
    CHECK(cm * 1 == NumberWithUnits(400, "cm"));
    CHECK(m * 3 == NumberWithUnits(120, "m"));
    CHECK(km * 4 == NumberWithUnits(16, "km"));
    CHECK(ton * 4 == NumberWithUnits(4, "ton"));
    CHECK(kg * 10 == NumberWithUnits(100, "kg"));
    CHECK(hour * 8 == NumberWithUnits(8, "hour"));
    CHECK(1 * cm == NumberWithUnits(400, "cm"));
    CHECK(3 * m == NumberWithUnits(120, "m"));
    CHECK(4 * km == NumberWithUnits(16, "km"));
    CHECK(4 * ton == NumberWithUnits(4, "ton"));
    CHECK(10 * kg == NumberWithUnits(100, "kg"));
    CHECK(8 * hour == NumberWithUnits(8, "hour"));
 
}

TEST_CASE("unary operators")
{
    // test plus Onri operator +
    CHECK((+cm1) == cm);
    CHECK((+m1) == m);
    CHECK((+km1) == km);
    // test  minus Onri operator -
    CHECK((-m) == m1);
    CHECK((-cm) == cm1);
    CHECK((-km) == km1);
}


TEST_CASE("checks operators")
{
  
    NumberWithUnits g_1{100, "g"}; 
    NumberWithUnits kg_1{400, "kg"};
    NumberWithUnits ton_1{1, "ton"};
    NumberWithUnits km_1{4, "km"};
    NumberWithUnits m_1{400, "m"};
    NumberWithUnits cm_1{40, "cm"};
    NumberWithUnits hour_1{2 , "hour"};
    NumberWithUnits min_1{60 , "min"}; 
    NumberWithUnits sec_1{3600 , "sec"};
    NumberWithUnits USD_1(1,"USD"); 
    NumberWithUnits ILS_1(2,"ILS");
  
  
   
   
    // test addition operator +
    CHECK_THROWS(g_1 + min_1);
    CHECK_THROWS(km_1 + ton_1);
    CHECK_THROWS(USD_1 + hour_1);
    CHECK_THROWS(kg_1 + cm_1);
    CHECK_THROWS(m_1 + sec_1);
    CHECK_THROWS(min_1 + g_1);
    //  test subtraction operator -
    CHECK_THROWS(g_1 - min_1);
    CHECK_THROWS(km_1 - ton_1);
    CHECK_THROWS(USD_1 - hour_1);
    CHECK_THROWS(kg_1 - cm_1);
    CHECK_THROWS(m_1 - sec_1);
    CHECK_THROWS(min_1 - g_1);
    // test plus Onri operator +=
    CHECK_THROWS(m_1 += m_1);
    CHECK_THROWS(sec_1 += sec_1);
    CHECK_THROWS(kg_1 += kg_1);
    CHECK_THROWS(ton_1 += ton_1);
    CHECK_THROWS(ILS_1 += ILS_1);
    CHECK_THROWS(km_1 += km_1);
    // test  minus Onri operator -=
    CHECK_THROWS(m_1 -= m_1);
    CHECK_THROWS(sec_1 -= sec_1);
    CHECK_THROWS(kg_1 -= kg_1);
    CHECK_THROWS(ton_1 -= ton_1);
    CHECK_THROWS(ILS_1 -= ILS_1);
    CHECK_THROWS(km_1 -= km_1);
}



TEST_CASE("checks equality operators")
{
  // test equality operators >=
  CHECK(km_1 >= m_1000);
  CHECK(km_1 >= cm_100000);
  CHECK(m_1000 >= cm_100000);

  
  
  
  
  
  
  
}



TEST_CASE("pre/post fix")
{
    // pre
    CHECK((++a) == 2);
    CHECK((++b) == 201);
    CHECK((--a) == 1);
    CHECK((--b) == 200);

    // post
    CHECK((a++) == 2);
    CHECK((b++) == 201);
    CHECK((a--) == 1);
    CHECK((b--) == 200);
}




TEST_CASE("I/O operators") // TODO: FIX operators recognition 
{
    // input
    NumberWithUnits input();
    istringstream my_stream("1[km]");
    my_stream >> input;
    CHECK(input == a);

    NumberWithUnits input_2();
    istringstream my_stream("2 0 0 [ m ] ");
    my_stream >> input;
    CHECK(input == b);

    // output
    string output;
    output << cout << a;
    CHECK(output == "1[km]");

    string output2;
    output2 << cout << b;
    CHECK(output2 == "200[m]");
}
