#ifndef ALGORITHMSANDDATASTRUCTURES_COMPLEXNUMBER_H
#define ALGORITHMSANDDATASTRUCTURES_COMPLEXNUMBER_H

// normal realization https://en.cppreference.com/w/cpp/numeric/complex

#include <utility>
#include <cmath>

// made for operator overload training
class ComplexNumber {
private:
    double real = 0.0;
    double imag = 0.0;
public:git
    ComplexNumber() = default;
    ComplexNumber(double real, double imag) : real(real), imag(imag) { }
    ComplexNumber(const ComplexNumber& other) = default;

    // std::move() not necessary because real is trivially-copyable
    ComplexNumber(ComplexNumber&& other) noexcept : real(other.real), imag(other.imag) { }
    ~ComplexNumber() = default;
    ComplexNumber& operator=(const ComplexNumber& other) &;
    ComplexNumber& operator=(ComplexNumber&& other) & noexcept;
private:
    void swap(ComplexNumber& other) {
        std::swap(real, other.real);
        std::swap(imag, other.imag);
    }
public:
    ComplexNumber& operator+=(const ComplexNumber& other);
    ComplexNumber& operator-=(const ComplexNumber& other);
    ComplexNumber& operator*=(const ComplexNumber& other);
    ComplexNumber& operator/=(const ComplexNumber& other);
    friend std::ostream& operator<<(std::ostream& ostream, const ComplexNumber& complexNumber);

    // modulo comparison
    friend bool operator<(const ComplexNumber& lhs, const ComplexNumber& rhs);
    friend bool operator>(const ComplexNumber& lhs, const ComplexNumber& rhs);
    friend bool operator<=(const ComplexNumber& lhs, const ComplexNumber& rhs);
    friend bool operator>=(const ComplexNumber& lhs, const ComplexNumber& rhs);
    friend bool operator==(const ComplexNumber& lhs, const ComplexNumber& rhs);
    friend bool operator!=(const ComplexNumber& lhs, const ComplexNumber& rhs);
};

ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs);
ComplexNumber operator-(const ComplexNumber& lhs, const ComplexNumber& rhs);
ComplexNumber operator*(const ComplexNumber& lhs, const ComplexNumber& rhs);
ComplexNumber operator/(const ComplexNumber& lhs, const ComplexNumber& rhs);



// copy and swap idiom
ComplexNumber &ComplexNumber::operator=(const ComplexNumber &other) &{
    ComplexNumber copy = other;
    swap(copy);
    return *this;
}

ComplexNumber &ComplexNumber::operator=(ComplexNumber &&other) & noexcept {
    if (this == &other) {
        return *this;
    }
    real = other.real; // std::move() not necessary because real is trivially-copyable
    imag = other.imag; // analogically
    return *this;
}

ComplexNumber &ComplexNumber::operator+=(const ComplexNumber &other) {
    real += other.real;
    imag += other.imag;
    return *this;
}

ComplexNumber &ComplexNumber::operator-=(const ComplexNumber &other) {
    real -= other.real;
    imag -= other.imag;
    return *this;
}

ComplexNumber &ComplexNumber::operator*=(const ComplexNumber &other) {
    real = (real * other.real) - (imag * other.imag);
    imag = (real * other.imag) + (imag * other.real);
    return *this;
}

ComplexNumber &ComplexNumber::operator/=(const ComplexNumber &other) {
    ComplexNumber complexConjugate(other.real, -other.imag);
    ComplexNumber numerator((real * complexConjugate.real) - (imag * complexConjugate.imag),
                            (real * complexConjugate.imag) + (imag * complexConjugate.real));
    double denominator = (other.real * complexConjugate.real) - (other.imag * complexConjugate.imag);
    real = numerator.real / denominator;
    imag = numerator.imag / denominator;
    return *this;
}

// overloading with the += operator
ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs) {
    ComplexNumber copy = lhs;
    copy += rhs;
    return copy;
}

// overloading with the -= operator
ComplexNumber operator-(const ComplexNumber& lhs, const ComplexNumber& rhs) {
    ComplexNumber copy = lhs;
    copy -= rhs;
    return copy;
}

// overloading with the *= operator
ComplexNumber operator*(const ComplexNumber& lhs, const ComplexNumber& rhs) {
    ComplexNumber copy = lhs;
    copy *= rhs;
    return copy;
}

// overloading with the /= operator
ComplexNumber operator/(const ComplexNumber& lhs, const ComplexNumber& rhs) {
    ComplexNumber copy = lhs;
    copy /= rhs;
    return copy;
}

std::ostream& operator<<(std::ostream& ostream, const ComplexNumber& complexNumber) {
    ostream << '(' << complexNumber.real << ", " << complexNumber.imag << ')';
    return ostream;
}

bool operator<(const ComplexNumber& lhs, const ComplexNumber& rhs) {
    double modulLhs = sqrt(pow(lhs.real, 2) + pow(lhs.imag, 2));
    double modulRhs = sqrt(pow(rhs.real, 2) + pow(rhs.imag, 2));
    return modulLhs < modulRhs;
}

bool operator>(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    return rhs < lhs;
}

bool operator<=(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    return !(lhs > rhs);
}

bool operator>=(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    return !(lhs < rhs);
}

bool operator==(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    double modulLhs = sqrt(pow(lhs.real, 2) + pow(lhs.imag, 2));
    double modulRhs = sqrt(pow(rhs.real, 2) + pow(rhs.imag, 2));
    return modulLhs == modulRhs;
}

bool operator!=(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    return !(lhs == rhs);
}


#endif //ALGORITHMSANDDATASTRUCTURES_COMPLEXNUMBER_H
