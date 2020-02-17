#include<iostream>
using namespace std;

class Complex
{
	float real;
	float imag;
public:
	Complex(float r = 0, float i = 0) : real(r), imag(i) {}
	Complex operator+(const Complex&);
	Complex operator-(const Complex&);
	Complex operator*(const Complex&);

	friend ostream& operator<<(ostream&, const Complex&);
	friend Complex operator*(float, const Complex&);
};

Complex Complex::operator+(const Complex& c)
{
	return Complex(real + c.real, imag + c.imag);
}

Complex Complex::operator-(const Complex& c)
{
	return Complex(real - c.real, imag - c.imag);
}

Complex Complex::operator*(const Complex& c)
{
	return Complex(real * c.real - imag * c.imag, real * c.imag + imag * c.real);
}

ostream& operator<<(ostream& os, const Complex& c)
{
	os << c.real << ' ';
	if(c.imag > 0)
		os << "+ " << c.imag << " i";
	else if(c.imag < 0)
		os << "- " << -c.imag << " i";

	return os;
}

Complex operator*(float f, const Complex& c)
{
	return Complex(f * c.real, f * c.imag);
}

int main(void)
{
	Complex c1(1.1, 2.4);
	Complex c2(2.2, 1);

	cout << c1 << endl << c2 << endl;

	Complex c3 = c1 + c2;
	Complex c4 = c2 - 2 * c1;
	Complex c5 = Complex(2, 2) * Complex(2, -2);

	cout << c3 << endl << c4 << endl << c5 << endl;

	return 0;


}
