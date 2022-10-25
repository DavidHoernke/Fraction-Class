//
// Created by David Hoernke on 10/17/2022.
//

#ifndef ASSIGNMENT2_FRACTION_20DASH_H
#define ASSIGNMENT2_FRACTION_20DASH_H

#endif //ASSIGNMENT2_FRACTION_20DASH_H
#include <string>
#include <vector>

using namespace std;
// exception class
class FractionException {
public:
    FractionException(const string& message);
    string& what();

private:
    string message;
};
// Fraction Class ----------------------------------------
class Fraction{
    public:
        // constructors
        Fraction();
        Fraction(const int& numerator);
        Fraction(const int& numerator, const int& denominator);
        Fraction& operator++();
        Fraction operator++(int unused);
        Fraction operator-();
        Fraction& operator+=(const Fraction right);
        int numerator();
        int denominator();
        void reduceSelf();
        int gcd(int, int);
    private:
        int fracNumerator;
        int fracDenominator;
        static Fraction reduce(Fraction fraction);


    // - negation
    // ++ post increment
    // pre increment
    friend Fraction operator+=(const Fraction& first, const int& add);// add and assign +=
    friend bool operator<(const Fraction& first, const Fraction& second);// <
    friend bool operator<=(const Fraction& first, const Fraction& second);//<=
    friend bool operator==(const Fraction& first, const Fraction& second);//==
    friend bool operator!=(const Fraction& first, const Fraction& second);// !=
    friend bool operator>=(const Fraction& first, const Fraction& second);// >=
    friend bool operator>(const Fraction& first, const Fraction& second);// >

    // binary operators
    friend Fraction operator+(const Fraction& first, const Fraction& second);
    friend Fraction operator-(const Fraction& first, const Fraction& second);
    friend Fraction operator/(const Fraction& first, const Fraction& second);
    friend Fraction operator*(const Fraction& first, const Fraction& second);
    friend ostream& operator<<(ostream& out, const Fraction& fraction);
    friend istream& operator>>(istream& in, Fraction& val);
};