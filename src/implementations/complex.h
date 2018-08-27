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
    Complex oppositeComplex(-_realNumber, -_imaginaryNumber);
    return oppositeComplex;
};

Complex Complex::operator+(Complex complexToBeAdd)
{
    double realNumberResult = _realNumber + complexToBeAdd.GetRealNumber();
    double imaginaryNumberResult = _imaginaryNumber + complexToBeAdd.GetImaginaryNumber();
    Complex resultComplex(realNumberResult, imaginaryNumberResult);
    return resultComplex;
};

Complex Complex::operator-(Complex complexToBeSubtract)
{
    double realNumberResult = _realNumber - complexToBeSubtract.GetRealNumber();
    double imaginaryNumberResult = _imaginaryNumber - complexToBeSubtract.GetImaginaryNumber();
    Complex resultComplex(realNumberResult, imaginaryNumberResult);
    return resultComplex;
};

Complex Complex::operator*(Complex complexToBeMultiplicate)
{
    double realNumberMultiplicate = _realNumber * complexToBeMultiplicate.GetRealNumber();
    double imaginaryNumberMultiplicate = _imaginaryNumber * complexToBeMultiplicate.GetImaginaryNumber();
    double realNumberResult = realNumberMultiplicate - imaginaryNumberMultiplicate;

    double realNumberMultiplicateImaginaryNumber = _realNumber * complexToBeMultiplicate.GetImaginaryNumber();
    double imaginaryNumberMultiplicateRealNumber = _imaginaryNumber * complexToBeMultiplicate.GetRealNumber();
    double imaginaryNumberResult = realNumberMultiplicateImaginaryNumber + imaginaryNumberMultiplicateRealNumber;

    Complex resultComplex(realNumberResult, imaginaryNumberResult);
    return resultComplex;
};

Complex Complex::operator/(Complex complexToBeDivided)
{
    Complex currentComplex(_realNumber, _imaginaryNumber);
    Complex numerator = currentComplex * complexToBeDivided.Conjugated();
    double denominator = pow(complexToBeDivided.GetRealNumber(), 2) + pow(complexToBeDivided.GetImaginaryNumber(), 2);

    Complex resultComplex(numerator.GetRealNumber() / denominator, numerator.GetImaginaryNumber() / denominator);
    return resultComplex;
};

#pragma endregion