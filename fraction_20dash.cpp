//
// Created by 19058 on 10/17/2022.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

#include "fraction_20dash.h"
using namespace std;
// Exception Class ------------------------------------------------------
FractionException::FractionException(const string& message): message(message) {}
string& FractionException::what(){
    return message;
}


// constructors ---------------------------------------------------------
Fraction::Fraction(){
    fracNumerator=0;
    fracDenominator=1;
}

Fraction::Fraction(const int& num){
    fracNumerator=num;
    fracDenominator=1;
}

Fraction::Fraction(const int& numerator,const int& denominator){
    if(denominator==0){ throw FractionException("Error: Zero denominator");}

    else {


        fracNumerator = numerator;
        fracDenominator = denominator;
        if(fracDenominator<0){
            fracDenominator=fracDenominator*-1;
            fracNumerator=fracNumerator*-1;
        }
        reduceSelf();

    }

}
// gcd and reduce ----------------------------------------------------
void Fraction::reduceSelf() {
    // find gcd of num and denom
    //int GCD = gcd(abs(fracNumerator),abs(fracDenominator));
    int GCD= gcd(abs(fracDenominator),abs(fracNumerator));
    //divide num and denom by gcd
    fracDenominator=fracDenominator/GCD;
    fracNumerator=fracNumerator/GCD;

}
int Fraction::gcd(int n, int m) {
    if(m<=n && n%m==0) {
        return m;
    } else if(n<m) {
        return gcd(m,n);
    } else {
        int temp = n%m;
        return gcd(m,temp);
    }
}
Fraction Fraction::reduce(Fraction fraction) {

    // find gcd of num and denom
    int gcd = fraction.gcd(fraction.fracNumerator,fraction.fracDenominator);
    //divide num and denom by gcd
    fraction.fracDenominator/=gcd;
    fraction.fracNumerator/=gcd;
    //return fraction
    return fraction;
}
// accessors ------------------------------------------------------------
int Fraction::denominator() {
    return this->fracDenominator;
}
int Fraction::numerator() {
    return this->fracNumerator;
}

ostream& operator <<(ostream& out, const Fraction& fraction){
    out << fraction.fracNumerator <<'/'<<fraction.fracDenominator;
    return out;
}
istream& operator >>(istream& in, Fraction& val){
    string temporary;
    cin >> ws;
    cin >> temporary;
    if(temporary.find('/')==temporary.npos)
    {
        val= Fraction(stoi(temporary));
        return in;
    }
    string numerator(temporary.begin(),temporary.end()-(temporary.size()-temporary.find('/')));
    string denominator(temporary.begin()+temporary.find('/')+1, temporary.end());
    if(stoi(denominator) == 0) { throw FractionException("ERROR: Zero denominator invalid"); }
    else {
        val = Fraction(stoi(numerator), stoi(denominator));
        return in;
    }

}



// operators binary
Fraction operator+(const Fraction& left,const Fraction& right){
    Fraction sum(left.fracNumerator*right.fracDenominator+right.fracNumerator*left.fracDenominator,right.fracDenominator*left.fracDenominator);
    return (Fraction::reduce(sum));
}
Fraction operator-(const Fraction& left,const Fraction& right){
    Fraction subtract(left.fracNumerator*right.fracDenominator-right.fracNumerator*left.fracDenominator,right.fracDenominator*left.fracDenominator);
    return (Fraction::reduce(subtract));
}
Fraction operator/(const Fraction& left,const Fraction& right){
    Fraction quotient(right.fracDenominator,right.fracNumerator);
    return (left*quotient);

}
Fraction operator*(const Fraction& left,const Fraction& right){
    Fraction product(left.fracNumerator*right.fracNumerator,right.fracDenominator*left.fracDenominator);
    return (Fraction::reduce(product));
}
// operators unary
Fraction& Fraction::operator+=(const Fraction right){
    this->fracNumerator = (this->fracNumerator*right.fracDenominator)+(right.fracNumerator*this->fracDenominator);
    this->fracDenominator = this->fracDenominator*right.fracDenominator;
    this->reduceSelf();
    return *this;
};
Fraction Fraction::operator-(){
  return Fraction(-this->fracNumerator,this->fracDenominator);
}
Fraction &Fraction::operator++(){
    fracNumerator+= fracDenominator;
    reduceSelf();
    return *this;
}
Fraction Fraction::operator++(int unused){

    Fraction clone(fracNumerator, fracDenominator);
    fracNumerator += fracDenominator;
    reduceSelf();
    return clone;
}

bool operator==(const Fraction& left, const Fraction& right) {
    if((double)(left.fracNumerator)/(double)(left.fracDenominator) == (double)(right.fracNumerator)/(double)(right.fracDenominator)) {
        return true;
    }
    else {
        return false;
    }
}
bool operator!=(const Fraction& left, const Fraction& right) {
    if((double)(left.fracNumerator)/(double)(left.fracDenominator) == (double)(right.fracNumerator)/(double)(right.fracDenominator)) {
        return false;
    }
    else {
        return true;
    }
}
bool operator>=(const Fraction& left, const Fraction& right) {
    if((double)(left.fracNumerator)/(double)(left.fracDenominator) >= (double)(right.fracNumerator)/(double)(right.fracDenominator)) { return true; }
    else { return false; }
}
bool operator<=(const Fraction& left, const Fraction& right) {
    if((double)(left.fracNumerator)/(double)(left.fracDenominator) <= (double)(right.fracNumerator)/(double)(right.fracDenominator)) { return true; }
    else { return false; }
}
bool operator<(const Fraction& left, const Fraction& right) {
    if((double)(left.fracNumerator)/(double)(left.fracDenominator) < (double)(right.fracNumerator)/(double)(right.fracDenominator)) { return true; }
    else { return false; }
}

bool operator>(const Fraction& left, const Fraction& right) {
    if((double)(left.fracNumerator)/(double)(left.fracDenominator) > (double)(right.fracNumerator)/(double)(right.fracDenominator)) {
        return true; }
    else { return false; }
}
