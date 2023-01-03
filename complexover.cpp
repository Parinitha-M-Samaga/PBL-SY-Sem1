//SYCOD214
#include <iostream>

using namespace std;

class Complex
{
	private:
		int real;
		int imaginary;
	public:
		Complex()
		{
			real=0;
			imaginary=0;
		}
		Complex(int re, int imag)
		{
			real=re;
			imaginary=imag;
		}
		Complex operator + (Complex comp)
		{
			Complex compassign;
			compassign.real=real+comp.real;
			compassign.imaginary=imaginary+comp.imaginary;
			return compassign;
		}
		Complex operator * (Complex comp)
		{
			Complex compassign;
			compassign.real=(real*comp.real)-(imaginary*comp.imaginary);
			compassign.imaginary=(real*comp.imaginary)+(comp.real*imaginary);
			return compassign;
		}
		void operator << (Complex comp)
		{
			cout<<comp.real<<"+("<<comp.imaginary<<")i";
			cout<<endl;
		}
		void operator >> (Complex &comp)
		{
			cout<<"Enter the real and imaginary parts of a complex number: ";
			cin>>comp.real>>comp.imaginary;
		}
};

int main()
{
	Complex comp1, comp2, sum, product, urvi;
	urvi>>comp1;
	urvi>>comp2;
	sum=comp1+comp2;
	product=comp1*comp2;
	cout<<"\nThe first complex number is: ";
	urvi<<comp1;
	cout<<"\nThe second complex number is: ";
	urvi<<comp2;
	cout<<"\nThe sum of the two complex numbers is: ";
	urvi<<sum;
	cout<<"\nThe product of the two complex numbers is: ";
	urvi<<product;
	return 0;
}
