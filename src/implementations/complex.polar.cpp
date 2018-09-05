#include <cmath>
#include "../interfaces/complex.h"

#define PI 180

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
    return std::abs(GetRealNumber());
};

Complex Complex::Conjugated()
{
    float rounds = GetImaginaryNumber() / (2 * PI);
    int maxAngle = (2 * PI) * ceil(rounds);
    Complex conjugated(GetRealNumber(), maxAngle - GetImaginaryNumber());
    return conjugated;
};

Complex Complex::Invert()
{
    Complex resultComplex(1/GetRealNumber(), -GetImaginaryNumber());
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
    Complex oppositeComplex(-GetRealNumber(), GetImaginaryNumber());
    return oppositeComplex;
};

Complex Complex::operator+(Complex complexToBeAdd)
{
    double realNumberAsEuclidean = cos(GetImaginaryNumber()) * Module();
    double imaginaryNumberAsEuclidean = sin(GetImaginaryNumber()) * Module();

    double complexToBeAddRealNumberAsEuclidean = cos(complexToBeAdd.GetImaginaryNumber()) * complexToBeAdd.Module();
    double complexToBeAddImaginaryNumberAsEuclidean = sin(complexToBeAdd.GetImaginaryNumber()) * complexToBeAdd.Module();

    double realNumberResultAsPolar = sqrt(pow(imaginaryNumberAsEuclidean + complexToBeAddImaginaryNumberAsEuclidean,2) + pow(realNumberAsEuclidean + complexToBeAddRealNumberAsEuclidean, 2));
    double imaginaryNumberResultAsPolar = std::atan2((complexToBeAddImaginaryNumberAsEuclidean + imaginaryNumberAsEuclidean), (complexToBeAddRealNumberAsEuclidean + realNumberAsEuclidean));
    
    Complex result(realNumberResultAsPolar, imaginaryNumberResultAsPolar);

    return result;
};

Complex Complex::operator-(Complex complexToBeSubtract)
{
    double realNumberAsEuclidean = cos(GetImaginaryNumber()) * Module();
    double imaginaryNumberAsEuclidean = sin(GetImaginaryNumber()) * Module();

    double complexToBeSubtractRealNumberAsEuclidean = cos(complexToBeSubtract.GetImaginaryNumber()) * complexToBeSubtract.Module();
    double complexToBeSubtractImaginaryNumberAsEuclidean = sin(complexToBeSubtract.GetImaginaryNumber()) * complexToBeSubtract.Module();

    double realNumberResultAsPolar = sqrt(pow(imaginaryNumberAsEuclidean - complexToBeSubtractImaginaryNumberAsEuclidean, 2) + pow(realNumberAsEuclidean - complexToBeSubtractRealNumberAsEuclidean, 2));
    double imaginaryNumberResultAsPolar = std::atan2((complexToBeSubtractImaginaryNumberAsEuclidean - imaginaryNumberAsEuclidean), (complexToBeSubtractRealNumberAsEuclidean - realNumberAsEuclidean));

    Complex result(realNumberResultAsPolar, imaginaryNumberResultAsPolar);

    return result;
};

Complex Complex::operator*(Complex complexToBeMultiplicate)
{
    double realResult = Module() * complexToBeMultiplicate.Module();
    double imaginaryResult = GetImaginaryNumber() + complexToBeMultiplicate.GetImaginaryNumber();
    Complex resultComplex(realResult, imaginaryResult);
    return resultComplex;
};

Complex Complex::operator/(Complex complexToBeDivided)
{
    double realResult = Module() / complexToBeDivided.Module();
    double imaginaryResult = GetImaginaryNumber() - complexToBeDivided.GetImaginaryNumber();
    Complex resultComplex(realResult, imaginaryResult);
    return resultComplex;
};

#pragma endregion