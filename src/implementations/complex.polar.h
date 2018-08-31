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
    double squaredRealNumber = pow(_realNumber, 2);
    double squaredImaginaryNumber = pow(_imaginaryNumber, 2);
    return sqrt(squaredRealNumber + squaredImaginaryNumber);
};

Complex Complex::Conjugated()
{
    double imaginaryNumberInverse = -_imaginaryNumber;
    Complex conjugated(_realNumber, -_imaginaryNumber);
    return conjugated;
};

Complex Complex::Invert()
{
    double denominator = pow(_realNumber, 2) + pow(_imaginaryNumber, 2);
    Complex resultComplex(_realNumber / denominator, _imaginaryNumber / denominator);
    return resultComplex;
};

#pragma endregion

#pragma region[Operators]

bool Complex::operator==(Complex x)
{
    if (_realNumber == x.GetRealNumber() && _imaginaryNumber == x.GetImaginaryNumber())
    {
        return true;
    }

    else
    {
        return false;
    }
};

bool Complex::operator=(Complex x)
{
    _realNumber = x.GetRealNumber();
    _imaginaryNumber = x.GetImaginaryNumber();
    return true;
};

Complex Complex::operator-()
{
    //TO DO
};

Complex Complex::operator+(Complex complexToBeAdd)
{
    //TO DO
};

Complex Complex::operator-(Complex complexToBeSubtract)
{
    //TO DO
};

Complex Complex::operator*(Complex complexToBeMultiplicate)
{
    double moduleResult = Module() * complexToBeMultiplicate.Module();
    double realResult = moduleResult * GetRealNumber() + complexToBeMultiplicate.GetRealNumber();
    double imaginaryResult = moduleResult * GetImaginaryNumber() + complexToBeMultiplicate.GetImaginaryNumber();
    Complex resultComplex(realResult, imaginaryResult);
    return resultComplex;
};

Complex Complex::operator/(Complex complexToBeDivided)
{
    double moduleResult = Module() / complexToBeDivided.Module();
    double realResult = moduleResult * GetRealNumber() - complexToBeDivided.GetRealNumber();
    double imaginaryResult = moduleResult * GetImaginaryNumber() - complexToBeDivided.GetImaginaryNumber();
    Complex resultComplex(realResult, imaginaryResult);
    return resultComplex;
};

#pragma endregion