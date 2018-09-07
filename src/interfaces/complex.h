#pragma once

class Complex
{
  public:
    Complex(void);
    Complex(double realNumber);
    Complex(double realNumber, double imaginaryNumber);

    double Module();

    Complex Conjugated();
    Complex Invert();

    bool operator==(Complex x);
    void operator=(Complex x);

    Complex operator-();
    Complex operator+(Complex complexToBeAdd);
    Complex operator-(Complex complexToBeSubtract);
    Complex operator*(Complex complexToBeMultiplicate);
    Complex operator/(Complex complexToBeDivided);

    double GetRealNumber();
    double GetImaginaryNumber();

  private:
    double _realNumber;
    double _imaginaryNumber;
};