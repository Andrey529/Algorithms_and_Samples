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
public:
    ComplexNumber() = default;
    ComplexNumber(double real, double imag) : real(real), imag(imag) { }
    ComplexNumber(const ComplexNumber& other) = default;

    // std::move() not necessary because real is trivially-copyable
    ComplexNumber(ComplexNumber&& other) noexcept : real(other.real), imag(other.imag) { }
    ~ComplexNumber() = default;
    ComplexNumber& operator=(const ComplexNumber& other) &;
    ComplexNumber& operator=(ComplexNumber&& other) & noexcept;
private:
    void swap(ComplexNumber& other) noexcept {
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

    // unary arithmetic operators
    ComplexNumber operator+() const;
    ComplexNumber operator-() const;

    ComplexNumber& operator++(); // prefix
    ComplexNumber& operator--();
    const ComplexNumber operator++(int); // postfix
    const ComplexNumber operator--(int);
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

//    if (this == std::addressof(other) /* &other */) {
//        return *this;
//    }
//    real = other.real;
//    imag = other.imag;
//    return *this;
}

ComplexNumber &ComplexNumber::operator=(ComplexNumber &&other) & noexcept {
    ComplexNumber copy = std::move(other); // перемещение
    swap(copy);
    return *this;

//    if (this == std::addressof(other) /* &other */) {
//        return *this;
//    }
//    real = other.real; // std::move() not necessary because real is trivially-copyable
//    imag = other.imag; // analogically
//    return *this;
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
//    return std::rel_ops::operator>(lhs, rhs);
}

bool operator<=(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    return !(lhs > rhs);
//    return std::rel_ops::operator<=(lhs, rhs);
}

bool operator>=(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    return !(lhs < rhs);
//    return std::rel_ops::operator>=(lhs, rhs);
}

bool operator==(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    double modulLhs = sqrt(pow(lhs.real, 2) + pow(lhs.imag, 2));
    double modulRhs = sqrt(pow(rhs.real, 2) + pow(rhs.imag, 2));
    return modulLhs == modulRhs;
}

bool operator!=(const ComplexNumber &lhs, const ComplexNumber &rhs) {
    return !(lhs == rhs);
//    return std::rel_ops::operator!=(lhs, rhs);
}

ComplexNumber ComplexNumber::operator+() const {
//    return ComplexNumber(real, imag);
    return {real, imag};
}

ComplexNumber ComplexNumber::operator-() const {
//    return ComplexNumber(-real, -imag);
    return {-real, -imag};
}

ComplexNumber &ComplexNumber::operator++() {
    real += 1;
    imag += 1;
    return *this;
}

ComplexNumber &ComplexNumber::operator--() {
    real -= 1;
    imag -= 1;
    return *this;
}

// overloading with the ++ prefix operator
const ComplexNumber ComplexNumber::operator++(int) {
    ComplexNumber comp(*this);
    ++*this;
    return comp;
}

// overloading with the -- prefix operator
const ComplexNumber ComplexNumber::operator--(int) {
    ComplexNumber comp(*this);
    --*this;
    return comp;
}


#endif //ALGORITHMSANDDATASTRUCTURES_COMPLEXNUMBER_H
