//SYCOD214
#include <iostream>
using namespace std;

class Shape
{
	public:
		double base;
		double height;
		void get_data()
		{
			cout<<"\nEnter base: ";
			cin>>base;
			cout<<"\nEnter height: ";
			cin>>height;
		}
		virtual void display_area()=0;
};

class Triangle: public Shape
{
	public:
		void display_area()
		{
			double area;
			area=0.5*base*height;
			cout<<"\nArea of the triangle is: "<<area;
			cout<<endl;
			cout<<"-------------------------------------------";
		}
};

class Rectangle: public Shape
{
	public:
	void display_area()
	{
		double area;
		area=base*height;
		cout<<"\nArea of the rectangle is: "<<area;
		cout<<endl;
		cout<<"-------------------------------------------";
		cout<<endl;
	}
};

int main()
{
	Triangle triobj;
	Rectangle rectobj;
	cout<<"\nEnter dimensions of the triangle.\n";
	triobj.get_data();
	triobj.display_area();
	cout<<"\nEnter dimensions of the rectangle.\n";
	rectobj.get_data();
	rectobj.display_area();
	return 0;
}
