//SYCOD214
#include<iostream>
using namespace std;

void check_char(char value)
{
	int ascii=value;
	if(ascii>=65 && ascii<=90)
		cout<<endl<<value<<" is an Uppercase alphabet.";
	else if(ascii>=97 && ascii<=122)
		cout<<endl<<value<<" is a Lowercase alphabet.";
	else if(ascii>=48 && ascii<=57)
		cout<<endl<<value<<" is a digit.";
	else
		cout<<endl<<value<<" is a special character.";
	cout<<endl;
}

int main()
{
	char value;
	int choice;
	bool cont=true;
	do
	{
		cout<<"\nEnter a character: ";
		cin>>value;
		check_char(value);
		cout<<"\nDo you want to enter another character? (0/1): ";
		cin>>choice;
		if(choice==0)
			cont=false;
	}while(cont);
	cout<<"\nThank You!\n";
	return 0;
}
