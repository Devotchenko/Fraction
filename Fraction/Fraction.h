#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <sstream>
#include <stdexcept>

class Fraction {
private:
    int numerator;
    int denominator;

    // Функция для вычисления НОД
    int gcd(int a, int b) const {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    // Метод для сокращения дроби
    void reduce() {
        if (numerator == 0) {
            denominator = 1;  
        }
        else {
            int gcd_value = gcd(numerator, denominator);
            numerator /= gcd_value;
            denominator /= gcd_value;
        }
    }

public:
    // Конструкторы
    Fraction(int numerator = 0, int denominator = 1) : numerator(numerator), denominator(denominator) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        if (numerator == 0 && denominator != 1) {
            throw std::invalid_argument("Zero numerator must have denominator as 1");
        }
        reduce();
    }
    // Арифметические операции
    Fraction operator+(const Fraction& other) const {
        Fraction result(numerator * other.denominator + other.numerator * denominator,
            denominator * other.denominator);
        result.reduce();
        return result;
    }

    Fraction operator-(const Fraction& other) const {
        Fraction result(numerator * other.denominator - other.numerator * denominator,
            denominator * other.denominator);
        result.reduce();
        return result;
    }

    Fraction operator*(const Fraction& other) const {
        Fraction result(numerator * other.numerator, denominator * other.denominator);
        result.reduce();
        return result;
    }

    Fraction operator/(const Fraction& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Cannot divide by fraction with zero numerator");
        }
        Fraction result(numerator * other.denominator, denominator * other.numerator);
        result.reduce();
        return result;
    }

    // Сравнение
    bool operator==(const Fraction& other) const {
        return numerator * other.denominator == other.numerator * denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    // Перегруженный оператор для вывода
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f) {
        if (f.denominator == 1) {
            out << f.numerator;
        }
        else {
            out << f.numerator << "/" << f.denominator;
        }
        return out;
    }
};

#endif // FRACTION_H
