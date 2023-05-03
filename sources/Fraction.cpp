#include <iostream>
#include <string>
#include "Fraction.hpp"
using namespace std;

namespace ariel{

    Fraction::Fraction(int numerator , int denominator){
        this->_numerator = numerator;
        this->_denominator = denominator;
    }


    Fraction Fraction::operator+ (const Fraction& frac){
        return *this;
    }

    Fraction Fraction::operator+(const float& frac)
    {
        return *this;
    }

    Fraction operator+ (const float& frac1 ,  const Fraction& frac2){
        
        return Fraction(0,0);
    }

    Fraction Fraction::operator-(const Fraction &frac){
    
        return *this;
    }

    Fraction Fraction::operator-(const float &frac)
    {
        return *this;
    }

    Fraction operator-(const float &frac1 , const Fraction& frac2)
    {
        
        return Fraction(0,0);   
        }

    Fraction Fraction::operator*(const Fraction& frac){
        return *this;
    }

    Fraction Fraction::operator*(const float& frac){
        return *this;
    }

    Fraction operator*(const float& frac1 , const Fraction& frac2){
        return Fraction(0,0);
    }

    Fraction Fraction::operator/(const Fraction& frac){
        return *this;
    }

    Fraction Fraction::operator/(const float& frac){
        return *this;
    }

    Fraction operator/(const float& frac1 , const Fraction& frac2){
       
        return Fraction(0,0);
    }

    bool Fraction::operator>(const Fraction& frac)const{
        return false;
    }

    bool Fraction::operator>(const float& frac)const{
        return false;
    }
    
    bool operator>(const float& frac1 , const Fraction& frac2){
        return false;
    }

    bool Fraction::operator<(const Fraction& frac)const{
        return false;
    }

    bool Fraction::operator<(const float& frac)const{
        return false;
    }

    bool operator<(const float& frac1 , const Fraction& frac2){
        return false;
    }

    bool Fraction::operator==(const Fraction& frac)const{
        return false;
    }

    bool Fraction::operator==(const float& frac)const{
        return false;
    }

    bool operator==(const float& frac1 , const Fraction& frac2){
        return false;
    }

    bool Fraction::operator>=(const Fraction& frac)const{
        return false;
    }

    bool Fraction::operator>=(const float& frac)const{
        return false;
    }

    bool operator>=(const float& frac1 , const Fraction& frac2){
        return false;
    }

    bool Fraction::operator<=(const Fraction& frac)const{
        return false;
    }

    bool Fraction::operator<=(const float& frac)const{
        return false;
    }

    bool operator<=(const float& frac1 , const Fraction& frac2){
        return false;
    }

    bool Fraction::operator!=(const Fraction& frac)const{
        return false;
    }

    bool Fraction::operator!=(const float& frac)const{
        return false;
    }


    bool operator!=(const float& frac1 , const Fraction& frac2){
        return false;
    }

    Fraction Fraction::operator++(){
        return *this;
    }

    Fraction Fraction::operator++(int){
        return *this;
    }

    Fraction Fraction::operator--(){
        return *this;
    }

    Fraction Fraction::operator--(int){
        return *this;
    }

    int Fraction::getNumerator(){
        return this->_numerator;
    }

    int Fraction::getDenominator(){
        return this->_denominator;
    }
    





    ostream& operator << (ostream& output, const Fraction& frac){
        
        return output;
    }

    istream& operator >> (istream& input , Fraction& frac){
        return input;
    }










}