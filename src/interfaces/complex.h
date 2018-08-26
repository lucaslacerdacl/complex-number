class Complex
{
    public:
    Complex();
    Complex(double realNumber);
    Complex(double realNumber, double imaginaryNumber);
    
    double Module();
    
    Complex Conjugated();
    Complex Invert();
    
    bool operator==(Complex x);
    bool operator=(Complex x);
    
    Complex operator-();
    Complex operator+(Complex complexToBeAdd);
    Complex operator-(Complex complexToBeSubtract);
    Complex operator*(Complex complexToBeMultiplicate);
    Complex operator/(Complex complexToBeDivided);

    private:
    double _realNumber;
    double _imaginaryNumber;
}