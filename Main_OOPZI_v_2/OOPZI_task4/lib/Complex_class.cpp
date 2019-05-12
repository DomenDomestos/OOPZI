using namespace std;
#include <iostream>
class Complex
{
public:
	Complex()
	{
		Re = 0;
		Im = 0;
	}
	Complex(double re, double im)
	{
		Re = re;
		Im = im;
	}
	operator double()
	{
		return r();
	}
	/*
	explicit operator double()
	{
		return r();
	}*/
	double R()
	{
		return r();
	}
	double Phi()
	{
		return phi();
	}
	double Re, Im;
private:

	double r()
	{
		return sqrt(Re*Re + Im * Im);
	}
	double phi()
	{
		return tan(Im / Re);
	}
};
//Переопределение операций числа типа complex

//Сложение
Complex operator+(Complex a, Complex b)
{
	Complex c;
	c.Re=a.Re + b.Re;
	c.Im = a.Im + b.Im;
	return c;
}
//Вычитание
Complex operator-(Complex a, Complex b)
{
	Complex c;
	c.Re = a.Re - b.Re;
	c.Im = a.Im - b.Im;
	return c;
}
//Умножение
Complex operator*(Complex a, Complex b)
{
	Complex c;
	c.Re = a.Re*b.Re - a.Im*b.Im;
	c.Im = a.Im*b.Re + a.Re*b.Im;
	return c;
}
//Деление
Complex operator/(Complex a, Complex b)
{
	Complex c;
	c.Re = (a.Re*b.Re + a.Im*b.Im)/(b.Re*b.Re+ b.Im*b.Im);
	c.Im = (a.Im*b.Re + a.Re*b.Im) / (b.Re*b.Re + b.Im*b.Im);
	return c;
}

Complex pow1(Complex z1, Complex z2)
{
	Complex h = z1;
	for (int i = 1; i < (double)z2; i++)
	{
		h = h * z1;
	}
	return h;
}
double sh(Complex z)
{
	return (exp((double)z) - exp(-(double)z)) / 2;
}
double ch(Complex z)
{
	return (exp((double)z) + exp(-(double)z)) / 2;
}
double th(Complex z1)
{
	return sh(z1) / ch(z1);
}
Complex y(Complex &z)
{
	return Complex(1,0) + pow1(z, Complex(5, 0))+Complex(th(z)/2,0);
}


ostream &operator<<(ostream &stream, const Complex &instance)
{
	if (instance.Im >= 0)
	{
		stream << instance.Re << " + " << instance.Im << "i";
	}
	else
	{
		stream << instance.Re << " " << instance.Im << "i";
	}
	return stream;

}