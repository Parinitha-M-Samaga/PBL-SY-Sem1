//SYCOD214
#include<iostream>
#include<string>
using namespace std;

class Vehicle
{
	public:
	float mileage;
	int price;
};

class Car:virtual public Vehicle
{
	public:
		float ownership;
		int warranty;
		int seatingcap;
		char fueltype;
};

class Bike:virtual public Vehicle
{
	public:
		int nofcylinders;
		int nofgears;
		char coolingtype;
		char wheeltype;
		float fueltanksize;
};

class Ford:virtual public Car
{
	public:
		string modeltype;
		friend void getdata(Ford *, int);
		friend void putdata(Ford *, int);
};

class Audi:virtual public Car
{
	public:
		string modeltype;
		void getdata();
		void putdata();
};

void Audi::getdata()
{
	cout<<"\nEnter the model type: ";
	cin.ignore();
	getline(cin, modeltype);
	cout<<"\nEnter mileage: ";
	cin>>mileage;
	cout<<"\nEnter the price: ";
	cin>>price;
	cout<<"\nEnter the ownership cost: ";
	cin>>ownership;
	cout<<"\nEnter the warranty by years: ";
	cin>>warranty;
	cout<<"\nEnter the seating capacity: ";
	cin>>seatingcap;
	cout<<"\nEnter the fuel type (d=diesel/p=petrol): ";
	cin>>fueltype;
}

void Audi::putdata()
{
	cout<<"\nThe model type is: "<<modeltype;
	cout<<"\nThe mileage is: "<<mileage<<" kmpl";
	cout<<"\nThe price is: "<<price<<" Rupees";
	cout<<"\nThe ownership price is: "<<ownership<<" Rupees";
	cout<<"\nThe warranty is: "<<warranty<<" years";
	cout<<"\nThe seating capacity is: "<<seatingcap<<" persons";
	cout<<"\nThe fuel type is: ";
	if(fueltype=='p')
		cout<<"Petrol";
	else if(fueltype=='d')
		cout<<"Diesel";
	else
		cout<<"Not specified";
	cout<<endl;
}

class Bajaj:virtual public Bike
{
	public:
		string maketype;
		friend void getdata(Bajaj *, int);
		friend void putdata(Bajaj *, int);
};

class TVS:virtual public Bike
{
	public:
		string maketype;
		void getdata();
		void putdata();
};

void TVS::getdata()
{
	cout<<"\nEnter the make-type: ";
	cin.ignore();
	getline(cin, maketype);
	cout<<"\nEnter the mileage: ";
	cin>>mileage;
	cout<<"\nEnter the price: ";
	cin>>price;
	cout<<"\nEnter the number of cylinders: ";
	cin>>nofcylinders;
	cout<<"\nEnter the number of gears: ";
	cin>>nofgears;
	cout<<"\nEnter the cooling type (a=air/l=liquid/o=oil): ";
	cin>>coolingtype;
	cout<<"\nEnter the wheel type (a=alloys/s=spokes): ";
	cin>>wheeltype;
	cout<<"\nEnter the fuel tank size in inches: ";
	cin>>fueltanksize;
}

void TVS::putdata()
{
	cout<<"\nThe make-type is: "<<maketype;
	cout<<"\nThe mileage is: "<<mileage<<" kmpl";
	cout<<"\nThe price is: "<<price<<" Rupees";
	cout<<"\nThe number of cylinders are: "<<nofcylinders;
	cout<<"\nThe number of gears are: "<<nofgears;
	cout<<"\nThe cooling type is: ";
	if(coolingtype=='a')
		cout<<"Air";
	else if(coolingtype=='l')
		cout<<"Liquid";
	else if(coolingtype=='o')
		cout<<"Oil";
	else
		cout<<"Not specified";
	cout<<"\nThe wheel type is: ";
	if(wheeltype=='a')
		cout<<"Alloys";
	else if(wheeltype=='s')
		cout<<"Spokes";
	else
		cout<<"Not specified";
	cout<<"\nThe fuel tank size is: "<<fueltanksize<<" inches";
	cout<<endl;
}

void getdata(Ford * fordobj, int c1)
{
	Ford *temp;
	temp=fordobj;
	int i=0;
	while(c1>i)
	{
		cout<<"\nEnter the model type: ";
		cin.ignore();
		getline(cin, temp->modeltype);
		cout<<"\nEnter mileage: ";
		cin>>temp->mileage;
		cout<<"\nEnter the price: ";
		cin>>temp->price;
		cout<<"\nEnter the ownership cost: ";
		cin>>temp->ownership;
		cout<<"\nEnter the warranty by years: ";
		cin>>temp->warranty;
		cout<<"\nEnter the seating capacity: ";
		cin>>temp->seatingcap;
		cout<<"\nEnter the fuel type (d=diesel/p=petrol): ";
		cin>>temp->fueltype;
		cout<<"\n-----------------------------------------------------------------";
		++temp;
		++i;
	}
}

void putdata(Ford * fordobj, int c1)
{
	Ford *temp;
	temp=fordobj;
	int i=0;
	cout<<"\nThe entries of the Ford cars are:\n";
	while(c1>i)
	{
		cout<<"\nThe model type is: "<<temp->modeltype;
		cout<<"\nThe mileage is: "<<temp->mileage<<" kmpl";
		cout<<"\nThe price is: "<<temp->price<<" Rupees";
		cout<<"\nThe ownership price is: "<<temp->ownership<<" Rupees";
		cout<<"\nThe warranty is: "<<temp->warranty<<" years";
		cout<<"\nThe seating capacity is: "<<temp->seatingcap<<" persons";
		cout<<"\nThe fuel type is: ";
		if(temp->fueltype=='p')
			cout<<"Petrol";
		else if(temp->fueltype=='d')
			cout<<"Diesel";
		else
			cout<<"Not specified";
		cout<<endl;
		++temp;
		++i;
	}
	cout<<"\n-----------------------------------------------------------------\n-----------------------------------------------------------------";
}

void getdata(Bajaj * bajajobj, int b1)
{
	Bajaj *temp;
	temp=bajajobj;
	int i=0;
	while(b1>i)
	{
		cout<<"\nEnter the make-type: ";
		cin.ignore();
		getline(cin, temp->maketype);
		cout<<"\nEnter the mileage: ";
		cin>>temp->mileage;
		cout<<"\nEnter the price: ";
		cin>>temp->price;
		cout<<"\nEnter the number of cylinders: ";
		cin>>temp->nofcylinders;
		cout<<"\nEnter the number of gears: ";
		cin>>temp->nofgears;
		cout<<"\nEnter the cooling type (a=air/l=liquid/o=oil): ";
		cin>>temp->coolingtype;
		cout<<"\nEnter the wheel type (a=alloys/s=spokes): ";
		cin>>temp->wheeltype;
		cout<<"\nEnter the fuel tank size in inches: ";
		cin>>temp->fueltanksize;
		cout<<"\n-----------------------------------------------------------------";
		++temp;
		++i;
	}
}

void putdata(Bajaj * bajajobj, int b1)
{
	Bajaj *temp;
	temp=bajajobj;
	int i=0;
	cout<<"\nThe entries of the Bajaj bikes are:\n";
	while(b1>i)
	{
		cout<<"\nThe make-type is: "<<temp->maketype;
		cout<<"\nThe mileage is: "<<temp->mileage<<" kmpl";
		cout<<"\nThe price is: "<<temp->price<<" Rupees";
		cout<<"\nThe number of cylinders are: "<<temp->nofcylinders;
		cout<<"\nThe number of gears are: "<<temp->nofgears;
		cout<<"\nThe cooling type is: ";
		if(temp->coolingtype=='a')
			cout<<"Air";
		else if(temp->coolingtype=='l')
			cout<<"Liquid";
		else if(temp->coolingtype=='o')
			cout<<"Oil";
		else
			cout<<"Not specified";
		cout<<"\nThe wheel type is: ";
		if(temp->wheeltype=='a')
			cout<<"Alloys";
		else if(temp->wheeltype=='s')
			cout<<"Spokes";
		else
			cout<<"Not specified";
		cout<<"\nThe fuel tank size is: "<<temp->fueltanksize<<" inches";
		cout<<endl;
		++temp;
		++i;
	}
	cout<<"\n-----------------------------------------------------------------\n-----------------------------------------------------------------\n";
}

int main()
{
	int c1, c2, b1, b2;
	cout<<"\nEnter the number of Ford models: ";
	cin>>c1;
	Ford fordobj[c1];
	cout<<"\nEnter the details of Ford cars:\n";
	getdata(fordobj, c1);
	cout<<"\nEnter the number of Audi models: ";
	cin>>c2;
	Audi audiobj[c2];
	cout<<"\nEnter the details of Audi cars:\n";
	for(int i=0;i<c2;++i)
	{
		audiobj[i].getdata();
		cout<<"\n-----------------------------------------------------------------";
	}
	cout<<"\nEnter the number of Bajaj models: ";
	cin>>b1;
	Bajaj bajajobj[b1];
	cout<<"\nEnter the details of Bajaj bikes:\n";
	getdata(bajajobj, b1);
	cout<<"\nEnter the number of TVS models: ";
	cin>>b2;
	TVS tvsobj[b2];
	cout<<"\nEnter the details of TVS bikes:\n";
	for(int i=0;i<b2;++i)
	{
		tvsobj[i].getdata();
		cout<<"\n-----------------------------------------------------------------";
	}
	putdata(fordobj, c1);
	cout<<"\nThe entries of the Audi cars are:\n";
	for(int i=0;i<c2;++i)
		audiobj[i].putdata();
	cout<<"\n-----------------------------------------------------------------\n-----------------------------------------------------------------";
	putdata(bajajobj, b1);
	cout<<"The entries of the TVS bikes are:\n";
	for(int i=0;i<b2;++i)
		tvsobj[i].putdata();
	cout<<"\n-----------------------------------------------------------------\n-----------------------------------------------------------------\n";
	cout<<"\nThank you!\n";
	return 0;
}
