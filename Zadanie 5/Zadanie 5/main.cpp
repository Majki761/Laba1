#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    // Konstruktor domyœlny
    Complex() : real(0.0), imag(0.0) {}

    // Konstruktor parametryczny
    Complex(double r, double i) : real(r), imag(i) {}

    // Konstruktor kopiuj¹cy
    Complex(const Complex& other) : real(other.real), imag(other.imag) {}

    // Destruktor
    ~Complex() {}

    // Operator przypisania
    Complex& operator=(const Complex& other) {
        if (this != &other) {
            real = other.real;
            imag = other.imag;
        }
        return *this;
    }

    // Operator dodawania
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Operator odejmowania
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Operator mno¿enia
    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    // Operator dzielenia
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex(
            (real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator
        );
    }

    // Metoda pomocnicza do wypisywania liczby zespolonej
    void print() const {
        std::cout << real;
        if (imag >= 0)
            std::cout << " + " << imag << "i";
        else
            std::cout << " - " << -imag << "i";
        std::cout << std::endl;
    }
};

// Przyk³ad u¿ycia
int main() {
    Complex a(2.0, 3.0);
    Complex b(1.0, -4.0);
    Complex c;

    c = a + b;
    std::cout << "a + b = ";
    c.print();

    c = a - b;
    std::cout << "a - b = ";
    c.print();

    c = a * b;
    std::cout << "a * b = ";
    c.print();

    c = a / b;
    std::cout << "a / b = ";
    c.print();

    return 0;
}
