//SYCOD214
#include<iostream>
#include<string>
#include<map>
using namespace std;

struct Date
{
	int day;
	int month;
	int year;
};

class Person
{
	int id;
	static int asid;
	string name;
	Date dob;
	long int phone;
	public:
		static int assignid()
		{
			++asid;
			return asid;
		}
		friend void getdata(map <int, Person>*);
		friend void display(map <int, Person>);
		friend void search(map <int, Person>);
		friend void delent(map <int, Person>*);
		friend void update(map <int, Person>*);
};

int Person::asid=0;

void getdata(map <int, Person> *rec)
{
	Person per;
	per.id=per.assignid();
	cout<<"\nEnter name: ";
	cin>>per.name;
	cout<<"\nEnter Date of Birth (DD/MM/YYYY): ";
	cin>>per.dob.day>>per.dob.month>>per.dob.year;
	cout<<"\nEnter phone number: ";
	cin>>per.phone;
	(*rec).insert(pair<int, Person>(per.id, per));
}

void display(map <int, Person> rec)
{
	map <int, Person>::iterator itr;
	for(itr=rec.begin();itr!=rec.end();++itr)
	{
		cout<<"\nID: "<<itr->first;
		cout<<"\nName: "<<(itr->second).name;
		cout<<"\nDate of Birth: "<<(itr->second).dob.day<<"/"<<(itr->second).dob.month<<"/"<<(itr->second).dob.year;
		cout<<"\nPhone number: "<<(itr->second).phone;
		cout<<endl;
	}
}

void search(map <int, Person> rec)
{
	int searchid, flag=0;
	cout<<"\nEnter the ID: ";
	cin>>searchid;
	map <int, Person>::iterator itr;
	for(itr=rec.begin();itr!=rec.end();++itr)
	{
		if(searchid==itr->first)
		{
			cout<<"\nID: "<<itr->first;
			cout<<"\nName: "<<(itr->second).name;
			cout<<"\nDate of Birth: "<<(itr->second).dob.day<<"/"<<(itr->second).dob.month<<"/"<<(itr->second).dob.year;
			cout<<"\nPhone number: "<<(itr->second).phone;
			cout<<endl;
			flag=1;
			break;
		}
	}
	if(flag==0)
		cout<<"\nRecord not found!\n";
}

void delent(map <int, Person> *rec)
{
	map <int, Person>::iterator itr;
	int delid;
	cout<<"\nEnter the ID of the entry to delete: ";
	cin>>delid;
	itr=(*rec).find(delid);
	if(itr!=(*rec).end())
	{
		(*rec).erase(delid);
		cout<<"\nEntry successfully deleted.\n";
	}
	else
		cout<<"\nRecord not found!\n";
}

void update(map <int, Person> *rec)
{
	map <int, Person>::iterator itr;
	int searchid, flag=0;
	cout<<"\nEnter the ID of entry to update: ";
	cin>>searchid;
	for(itr=(*rec).begin();itr!=(*rec).end();++itr)
	{
		if(searchid==itr->first)
		{
			cout<<"\nEnter the new phone number: ";
			cin>>(itr->second).phone;
			flag=1;
			cout<<"\nEntry successfully updated.\n";
			break;
		}
	}
	if(flag==0)
		cout<<"\nRecord not found!\n";
}

int main()
{
	map <int, Person> records;
	int choice;
	while(1)
	{
		cout<<"\nMenu:";
		cout<<"\n1. Add an entry.";
		cout<<"\n2. Display all entries.";
		cout<<"\n3. Search for an entry.";
		cout<<"\n4. Delete an entry.";
		cout<<"\n5. Update an entry.";
		cout<<"\n6. Exit.";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				getdata(&records);
				continue;
			
			case 2:
				display(records);
				continue;
			
			case 3:
				search(records);
				continue;
			
			case 4:
				delent(&records);
				continue;
			
			case 5:
				update(&records);
				continue;
			
			case 6:
				cout<<"\nThank you!\n";
				exit(0);
			
			default:
				cout<<"\nInvalid choice!\n";
		}
	}		
	return 0;
}
