#include "doctest.h"
#include "sources/Fraction.hpp"
#include <iostream>

using namespace std;
using namespace ariel;

TEST_CASE("constructor & arguments"){
    
    // 0 denominator
    CHECK_THROWS(Fraction(0,0));
    CHECK_THROWS(Fraction(1,0));
    CHECK_THROWS(Fraction(-7,0));
    //good input
    CHECK_NOTHROW(Fraction(0,1));
    CHECK_NOTHROW(Fraction(0,-1));
    CHECK_NOTHROW(Fraction(1,2));
    CHECK_NOTHROW(Fraction(-4,7));
    CHECK_NOTHROW(Fraction(200,-100));
    CHECK_NOTHROW(Fraction(-1234,-5678));

    Fraction f(1,2);
    CHECK_EQ(f.getNumerator(),1);
    CHECK_EQ(f.getDenominator(),2);
}

TEST_CASE("operators overload"){

    SUBCASE("=="){
        CHECK(Fraction(0,2) == Fraction(0,-1));
        CHECK(Fraction(2,6) == Fraction(3,9));
        CHECK(Fraction(3,2) == Fraction(6,4));

        CHECK(Fraction(-1,2) == Fraction(1,-2));
        CHECK((Fraction(4,2) == Fraction(-4,-2)) == Fraction(2,1));

        float fn0 = 0.000;
        float fn1 = 0.333;
        float fn2 = -1.333;
        float fn3 = 0.3325;
        
        CHECK(Fraction(0,1) == fn0);
        CHECK(Fraction(1,3) == fn1);
        CHECK(Fraction(2,6) == fn1);
        CHECK(Fraction(-4,3) == fn2);
        CHECK(Fraction(1,3) == fn3);

        //recuded form
        CHECK((Fraction(1,2) == Fraction(10,20)) == Fraction(-50,-100));
        CHECK((Fraction(-2,4) == Fraction(6,-12)) == Fraction(-50,100));
        CHECK((Fraction(7,1) == Fraction(14,2)) == Fraction(700,100));
    }

    SUBCASE("+"){
        //positive result
        CHECK_EQ(Fraction(0,3) + Fraction(0,-10) , Fraction(0,0));
        CHECK_EQ(Fraction(1,4) + Fraction(3,5) , Fraction(17,20));
        CHECK_EQ(Fraction(-1,-2) + Fraction(-3,-5) , Fraction(11,10));
        
        //negative result
        CHECK_EQ(Fraction(-4,5) + Fraction(-7 , 9) , Fraction(-71,45));
        CHECK_EQ(Fraction(1,-3) + Fraction(-11,19) , Fraction(52,-57));

        //positive & negative
        CHECK_EQ(Fraction(1,2) + Fraction(-1,3) , Fraction(1,6));
        CHECK_EQ(Fraction(1,9) + Fraction(2,-7) , Fraction(11,-63));
        CHECK_EQ(Fraction(-7,9) + Fraction(4,1) , Fraction(29,9));
        CHECK_EQ(Fraction(49,-11) + Fraction(1,5) , Fraction(-234,55));

        //same denominator
        CHECK_EQ(Fraction(3,5) + Fraction(1,5) , Fraction(4,5));
        CHECK_EQ(Fraction(-3,5) + Fraction(1,-5) , Fraction(-4,5));
        CHECK_EQ(Fraction(-3,5) + Fraction(1,5) , Fraction(-2,5));
        CHECK_EQ(Fraction(3,5) + Fraction(1,-5) , Fraction(2,5));

        //reduced form
        CHECK_EQ(Fraction(4,6) + Fraction(6,3) , Fraction(8,3));
        CHECK_EQ(Fraction(-4,6) + Fraction(6,3) , Fraction(4,3));
        CHECK_EQ(Fraction(4,6) + Fraction(-6,3) , Fraction(-4,3));
        CHECK_EQ(Fraction(4,-6) + Fraction(6,-3) , Fraction(-8,3));

        //floats
        CHECK_EQ(Fraction(1,2) + Fraction(1,3) , 0.833);//0.833333333
        CHECK_EQ(Fraction(1,2) + 0.833 , Fraction(1,3));
        CHECK_EQ(0.833 + Fraction(1,2) , Fraction(1,3));
        CHECK_EQ(Fraction(3,5) + 1.321 , Fraction(1921,1000));
    }

    SUBCASE("-"){
        //positive result
        CHECK_EQ(Fraction(1,2) - Fraction(1,3) , Fraction(1,6));
        CHECK_EQ(Fraction(4,3) - Fraction(1,2) , Fraction(5,6));
        CHECK_EQ(Fraction(-1,-2) - Fraction(-1,-4) , Fraction(1,4));

        //negative result
        CHECK_EQ(Fraction(1,2) - Fraction(3,4) , Fraction(-1,4));
        CHECK_EQ(Fraction(3,2) - Fraction(2,1) , Fraction(1,-2));
        CHECK_EQ(Fraction(-1,2) - Fraction(1,3) , Fraction(-5,6));

        //positive & negative
        CHECK_EQ(Fraction(1,3) - Fraction(1,5) , Fraction(2,15));
        CHECK_EQ(Fraction(-1,3) - Fraction(-1,5) , Fraction(-2,15));
        CHECK_EQ(Fraction(1,-3) - Fraction(1,5) , Fraction(8,15));
        CHECK_EQ(Fraction(-1,-3) - Fraction(-1,5) , Fraction(8,-15));

        //same denominator
        CHECK_EQ(Fraction(7,2) - Fraction(5,2) , Fraction(2,2));
        CHECK_EQ(Fraction(-7,2) - Fraction(5,2) , Fraction(-2,2));
        CHECK_EQ(Fraction(7,2) - Fraction(-5,2) , Fraction(6,1));

        //reduced form
        CHECK_EQ(Fraction(1,3) - Fraction(2,6) , Fraction(0,0));
        CHECK_EQ(Fraction(2,4) - Fraction(5,15) , Fraction(1,6));
        CHECK_EQ(Fraction(-3,9) - Fraction(-1,5) , Fraction(-2,15));

        //floats
        CHECK_EQ(Fraction(1,2) - 0.250 , Fraction(2,4));
        CHECK_EQ(Fraction(3,5) - 1.321 , Fraction(-721,1000));
        float fn = -0.777;
        CHECK_EQ(Fraction(-1,2) - fn ,Fraction(277,1000));
    }  
    
    SUBCASE("*"){
        //positive & negative
        CHECK_EQ(Fraction(1,2) * Fraction(3,5) , Fraction(3,10));
        CHECK_EQ(Fraction(-1,2) * Fraction(3,5) , Fraction(3,-10));
        CHECK_EQ(Fraction(1,2) * Fraction(3,-5) , Fraction(-3,10));
        CHECK_EQ(Fraction(-1,2) * Fraction(-3,5) , Fraction(3,10));

        //reduced form
        CHECK_EQ(Fraction(2,4) * Fraction(6,2) , Fraction(3,2));
        CHECK_EQ(Fraction(100,100) * Fraction(200,200) , Fraction(1,1));
        CHECK_EQ(Fraction(10,2) * Fraction(-10,5) , Fraction(-10,1));

        //float
        CHECK_EQ(Fraction(2,3) * 0.241 ,Fraction(241,1500));
        CHECK_EQ(Fraction(2,3) * (-0.241) ,Fraction(-241,1500));
        CHECK_EQ(Fraction(2,3) * 0.000 ,Fraction(0,0));
    }      

    SUBCASE("/"){

        //positive & negative
        CHECK_EQ(Fraction(1,2) / Fraction(3,5) , Fraction(5,6));
        CHECK_EQ(Fraction(3,5) / Fraction(1,2) , Fraction(6,5));
        CHECK_EQ(Fraction(1,2) / Fraction(-3,5) , Fraction(-5,6));
        CHECK_EQ(Fraction(-1,2) / Fraction(3,5) , Fraction(5,-6));
        CHECK_EQ(Fraction(-1,2) / Fraction(-3,5) , Fraction(5,6));

        //reduced form
        CHECK_EQ(Fraction(10,2) / Fraction(10,5) , Fraction(5,2));
        CHECK_EQ(Fraction(10,1) / Fraction(2,1) , Fraction(5,1));
        CHECK_EQ(Fraction(-36,6) / Fraction(12,2) , Fraction(-1,1));

        //float
        CHECK_EQ(Fraction(3,4) / 4.665 , Fraction(50,311));
        CHECK_EQ(Fraction(3,4) / -4.665 , Fraction(-50,311));
        CHECK_EQ(Fraction(-3,4) / 4.665 , Fraction(-50,311));
        CHECK_EQ(Fraction(-3,4) / -4.665 , Fraction(50,311));

    } 

    SUBCASE("> && >="){
        Fraction f1(3,4);
        Fraction f2(2,3);
        Fraction f3(1,2);
        Fraction f4(-1,4);

        CHECK(f1 > f2);
        CHECK(f1 > f3);
        CHECK(f2 > f3);
        CHECK(f3 > f4);

        CHECK(f1 >= f1);
        CHECK(f4 >= f4);
        
        CHECK(Fraction(4,2) >= Fraction(6,3));
        CHECK(Fraction(1,1) >= Fraction(1000,1000));

        float fn = 0.249;
        float fn1 = 0.2501111;
        float fn2 = 0.2499;
        CHECK(f3 > fn);
        CHECK(f3 >= fn1);
        CHECK(f3 >= fn2);
    } 

    SUBCASE("< & <="){
        Fraction f1(1,2);
        Fraction f2(2,3);
        Fraction f3(3,4);
        Fraction f4(-1,4);

        CHECK((f1 < f2));
        CHECK(f1 < f3);
        CHECK(f2 < f3);
        CHECK(f4 < f3);
        
        CHECK(f1 <= f1);
        CHECK(f4 <= f4);
        
        CHECK(Fraction(4,2) <= Fraction(6,3));
        CHECK(Fraction(10,10) <= Fraction(1000,1000));

        float fn = 0.2511111;
        float fn1 = 0.249;
        CHECK(f1 < fn);
        CHECK(f1 <= fn1);
    }     

    SUBCASE("!="){
        CHECK(Fraction(2,3) != Fraction(5,7));
        CHECK(Fraction(-2,3) != Fraction(5,7));
        CHECK(Fraction(2,3) != Fraction(-5,7));
        CHECK(Fraction(1,100) != Fraction(1,1000));
        CHECK(Fraction(100,1) != Fraction(1,100));

        CHECK(Fraction(1,2) != 0.4994);
        CHECK(Fraction(2,1) != 0.201);
    } 

    SUBCASE("++ prefix and postfix"){
       //prefix
       Fraction f1(3,4);
       Fraction f2(7,4);
       CHECK(++f1 == f2);
       CHECK(++f1 != f2);
       
       //sign change
       Fraction f3(-1,2);
       Fraction f4(1,2);
       CHECK(++f3 == f4);
       CHECK(++f3 != f4);

       //postfix
       Fraction f5(2,3);
       Fraction f6(5,3);
       CHECK(f5++ != f6);
       CHECK(f5++ == f6);
       CHECK(f5 != f6); 
    }

    SUBCASE("-- prefix and postfix"){
       //prefix
       Fraction f1(7,4);
       Fraction f2(3,4);
       CHECK(--f1 == f2);
       CHECK(--f1 != f2);
       
       //sign change
       Fraction f3(1,2);
       Fraction f4(-1,2);
       CHECK(--f3 == f4);
       CHECK(--f3 != f4);

       //postfix
       Fraction f5(5,3);
       Fraction f6(2,3);
       CHECK(f5-- != f6);
       CHECK(f5-- == f6);
       CHECK(f5 != f6); 
    }     
}