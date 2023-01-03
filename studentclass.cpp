//SYCOD214
#include <iostream>
#include <string>
using namespace std;

int n=5;

struct DateOfBirth
{
	int day;
	int month;
	int year;
};

class Student
{
	private:
		char name[20];
		int clas;
		char division;
		DateOfBirth dob;
		char bloodtype[4];
		long int contact;
		string address;
		long int telephone;
	public:
		static int count;
		int roll;
		static int rollfun()
		{
			++count;
			return count;
		}
		friend void enter_details(Student *);
		void display();
		Student()
		{
			contact=0;
			telephone=0;
		}
		~Student()
		{
			//Destructor
		}
};

void enter_details(Student *s)
{
	for(int i=0;i<n;++i)
	{
		cout<<"\nEnter the name of the student: ";
		cin>>s[i].name;
		cout<<"\nEnter the class of the student: ";
		cin>>s[i].clas;
		cout<<"\nEnter the division of the student: ";
		cin>>s[i].division;
		cout<<"\nEnter the date of birth of the student(in DD MM YYYY format): ";
		cin>>s[i].dob.day>>s[i].dob.month>>s[i].dob.year;
		cout<<"\nEnter the bloodtype of the student: ";
		cin>>s[i].bloodtype;
		cout<<"\nEnter the contact number of the student: ";
		cin>>s[i].contact;
		cout<<"\nEnter the address of the student: ";
		cin.ignore();
		getline(cin, s[i].address);
		cout<<"\nEnter the telephone number of the student: ";
		cin>>s[i].telephone;
		cout<<"\n------------------------------------------------------------------------------";
	}
}

inline void Student::display()
{
	cout<<"\nName of the student: ";
	cout<<name;
	cout<<"\nRoll number of the student: ";
	cout<<roll;
	cout<<"\nClass of the student: ";
	cout<<clas;
	cout<<"\nDivision of the student: ";
	cout<<division;
	cout<<"\nDate of birth of the student(in DD MM YYYY format): ";
	cout<<dob.day<<"/"<<dob.month<<"/"<<dob.year;
	cout<<"\nBloodtype of the student: ";
	cout<<bloodtype;
	cout<<"\nContact number of the student: ";
	cout<<contact;
	cout<<"\nAddress of the student: ";
	cout<<address;
	cout<<"\nTelephone number of the student: ";
	cout<<telephone;
	cout<<endl;
}

int Student::count=0;

int main()
{
	Student s[n];
	for(int i=0;i<n;++i)
		s[i].roll=s[i].rollfun();
	enter_details(s);
	cout<<"\n------------------------------------------------------------------------------";
	for(int i=0;i<n;++i)
	{
		cout<<"\nDetails of student "<<i+1<<":\n";
		s[i].display();
		cout<<"\n------------------------------------------------------------------------------";
	}
	cout<<"\n------------------------------------------------------------------------------";
	cout<<"\nTotal number of students is: "<<s[0].count;
	cout<<"\n------------------------------------------------------------------------------\n------------------------------------------------------------------------------\n";
	return 0;
}
