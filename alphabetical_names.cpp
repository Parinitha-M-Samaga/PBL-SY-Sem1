//SYCOD214
#include<iostream>
#include<string>
using namespace std;

int size;

void sort(string *names)
{
	for(int i=0;i<size-1;++i)
	{
		int min=i;
		for(int j=i+1;j<size;++j)
			if(names[min]>names[j])
				min=j;
		string temp=names[i];
		names[i]=names[min];
		names[min]=temp;
	}
	cout<<"\nThe names in alphabetical order are:";
	for(int i=0;i<size;++i)
		cout<<endl<<names[i];
	cout<<endl;
}

int main()
{
	cout<<"\nEnter the number of names: ";
	cin>>size;
	string names[size];
	cout<<"\nEnter the names: ";
	for(int i=0;i<size;++i)
		cin>>names[i];
	sort(names);
	return 0;
}
