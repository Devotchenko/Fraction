#include "Fraction.h"
#include <cmath>

int Fraction::gcd(int a, int b) const {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

void Fraction::reduce() {
    if (numerator == 0) {
        denominator = 1;
    }
    else {
        int gcd_value = gcd(std::abs(numerator), std::abs(denominator));
        numerator /= gcd_value;
        denominator /= gcd_value;
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
    }
}

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    reduce();
}

Fraction Fraction::operator+(const Fraction& other) const {
    Fraction result(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    result.reduce();
    return result;
}

Fraction Fraction::operator-(const Fraction& other) const {
    Fraction result(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    result.reduce();
    return result;
}

Fraction Fraction::operator*(const Fraction& other) const {
    Fraction result(numerator * other.numerator, denominator * other.denominator);
    result.reduce();
    return result;
}

Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0) {
        throw std::invalid_argument("Cannot divide by fraction with zero numerator");
    }
    Fraction result(numerator * other.denominator, denominator * other.numerator);
    result.reduce();
    return result;
}

bool Fraction::operator==(const Fraction& other) const {
    return numerator * other.denominator == other.numerator * denominator;
}

bool Fraction::operator!=(const Fraction& other) const {
    return !(*this == other);
}

std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    if (f.denominator == 1) {
        out << f.numerator;
    }
    else {
        out << f.numerator << "/" << f.denominator;
    }
    return out;
}
