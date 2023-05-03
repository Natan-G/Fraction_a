#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


using namespace std;

namespace ariel{

    class Fraction{

        int _numerator;
        int _denominator;


        public:
            
            Fraction(int numerator , int denominator);
            

            Fraction operator+ (const Fraction& frac);
            Fraction operator+ (const float& frac);
            friend Fraction operator+ (const float& frac1 , const Fraction& frac2);
            
            Fraction operator- (const Fraction& frac);
            Fraction operator- (const float& frac);
            friend Fraction operator- (const float& frac1 , const Fraction& frac2);

            Fraction operator* (const Fraction& frac);
            Fraction operator* (const float& frac);
            friend Fraction operator* (const float& frac1 , const Fraction& frac2);

            Fraction operator/ (const Fraction& frac);
            Fraction operator/ (const float& frac);
            friend Fraction operator/ (const float& frac1 , const Fraction& frac2);

            bool operator> (const Fraction& frac) const;
            bool operator> (const float& frac) const;
            friend bool operator> (const float& frac1 , const Fraction& frac2);

            bool operator< (const Fraction& frac) const;
            bool operator< (const float& frac) const;
            friend bool operator< (const float& frac1 , const Fraction& frac2);

            bool operator== (const Fraction& frac) const;
            bool operator== (const float& frac) const;
            friend bool operator== (const float& frac1 , const Fraction& frac2);

            bool operator>= (const Fraction& frac) const;
            bool operator>= (const float& frac) const;
            friend bool operator>= (const float& frac1 , const Fraction& frac2);

            bool operator<= (const Fraction& frac) const;
            bool operator<= (const float& frac) const;
            friend bool operator<= (const float& frac1 , const Fraction& frac2);

            bool operator!= (const Fraction& frac) const;
            bool operator!= (const float& frac) const;
            friend bool operator!= (const float& frac1 , const Fraction& frac2);

            Fraction operator++();
            Fraction operator++(int);
            Fraction operator--();
            Fraction operator--(int);

            friend ostream& operator << (std::ostream& output, const Fraction& frac);
            friend istream& operator >> (std::istream& input , Fraction& frac);

            int getNumerator();
            int getDenominator();

    };

    










}