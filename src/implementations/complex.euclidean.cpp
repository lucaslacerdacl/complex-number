#include <cmath>
#include "../interfaces/complex.h"

#pragma region[Constructors]

Complex::Complex(void)
{
    _realNumber = 0;
    _imaginaryNumber = 0;
};

Complex::Complex(double realNumber)
{
    _realNumber = realNumber;
    _imaginaryNumber = 0;
};

Complex::Complex(double realNumber, double imaginaryNumber)
{
    _realNumber = realNumber;
    _imaginaryNumber = imaginaryNumber;
};

#pragma endregion

#pragma region[Properties]

double Complex::GetRealNumber()
{
    return _realNumber;
};

double Complex::GetImaginaryNumber()
{
    return _imaginaryNumber;
};

#pragma endregion

#pragma region[Methods]

double Complex::Module()
{
    double squaredRealNumber = pow(GetRealNumber(), 2);
    double squaredImaginaryNumber = pow(GetImaginaryNumber(), 2);
    return sqrt(squaredRealNumber + squaredImaginaryNumber);
};

Complex Complex::Conjugated()
{
    Complex conjugated(GetRealNumber(), -GetImaginaryNumber());
    return conjugated;
};

Complex Complex::Invert()
{
    double denominator = pow(GetRealNumber(), 2) + pow(GetImaginaryNumber(), 2);
    Complex resultComplex(GetRealNumber() / denominator, GetImaginaryNumber() / denominator);
    return resultComplex;
};

#pragma endregion

#pragma region[Operators]

bool Complex::operator==(Complex x)
{
    if (GetRealNumber() == x.GetRealNumber() && GetImaginaryNumber() == x.GetImaginaryNumber())
    {
        return true;
    }

    else
    {
        return false;
    }
};

void Complex::operator=(Complex x)
{
    _realNumber = x.GetRealNumber();
    _imaginaryNumber = x.GetImaginaryNumber();
};

Complex Complex::operator-()
{
    Complex oppositeComplex(-GetRealNumber(), -GetImaginaryNumber());
    return oppositeComplex;
};

Complex Complex::operator+(Complex complexToBeAdd)
{
    double realNumberResult = GetRealNumber() + complexToBeAdd.GetRealNumber();
    double imaginaryNumberResult = GetImaginaryNumber() + complexToBeAdd.GetImaginaryNumber();
    Complex resultComplex(realNumberResult, imaginaryNumberResult);
    return resultComplex;
};

Complex Complex::operator-(Complex complexToBeSubtract)
{
    double realNumberResult = GetRealNumber() - complexToBeSubtract.GetRealNumber();
    double imaginaryNumberResult = GetImaginaryNumber() - complexToBeSubtract.GetImaginaryNumber();
    Complex resultComplex(realNumberResult, imaginaryNumberResult);
    return resultComplex;
};

Complex Complex::operator*(Complex complexToBeMultiplicate)
{
    double realNumberMultiplicate = GetRealNumber() * complexToBeMultiplicate.GetRealNumber();
    double imaginaryNumberMultiplicate = GetImaginaryNumber() * complexToBeMultiplicate.GetImaginaryNumber();
    double realNumberResult = realNumberMultiplicate - imaginaryNumberMultiplicate;

    double realNumberMultiplicateImaginaryNumber = GetRealNumber() * complexToBeMultiplicate.GetImaginaryNumber();
    double imaginaryNumberMultiplicateRealNumber = GetImaginaryNumber() * complexToBeMultiplicate.GetRealNumber();
    double imaginaryNumberResult = realNumberMultiplicateImaginaryNumber + imaginaryNumberMultiplicateRealNumber;

    Complex resultComplex(realNumberResult, imaginaryNumberResult);
    return resultComplex;
};

Complex Complex::operator/(Complex complexToBeDivided)
{
    Complex currentComplex(GetRealNumber(), GetImaginaryNumber());
    Complex numerator = currentComplex * complexToBeDivided.Conjugated();
    double denominator = pow(complexToBeDivided.GetRealNumber(), 2) + pow(complexToBeDivided.GetImaginaryNumber(), 2);

    Complex resultComplex(numerator.GetRealNumber() / denominator, numerator.GetImaginaryNumber() / denominator);
    return resultComplex;
};

#pragma endregion