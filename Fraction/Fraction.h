#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>

class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) const;
    void reduce();

public:
    Fraction(int numerator = 0, int denominator = 1);
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    bool operator==(const Fraction& other) const;
    bool operator!=(const Fraction& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
};

#endif // FRACTION_H
