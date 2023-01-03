//SYCOD214
#include<iostream>
using namespace std;

int n;

class Bank
{
	private:
		char name[20];
		long int accno;
		float withdraw;
		float balance;
	public:
		void getdata();
		friend int deposit(Bank*, long int);
		friend void withdraw_balance(Bank[]);
		int display(long int);
};

void Bank::getdata()
{
	cout<<"\nEnter your name: ";
	cin>>name;
	cout<<"\nEnter account number: ";
	cin>>accno;
	cout<<"\nEnter initial deposit: ";
	cin>>balance;
}

int deposit(Bank* b, long int acc)
{
	float depo;
	if(acc==b->accno)
	{
		cout<<"\nEnter amount to be deposited: ";
		cin>>depo;
		b->balance+=depo;
		cout<<"\nYour current balance is: "<<b->balance;
		return 1;
	}
	else
		return 0;
}

void withdraw_balance(Bank det[])
{
	long int acc;
	float bal;
	int flag=0;
	cout<<"\nEnter your account number: ";
	cin>>acc;
	for(int i=0;i<n;++i)
	{
		if(acc==det[i].accno)
		{
			flag=1;
			cout<<"\nYour balance is: "<<det[i].balance;
			cout<<"\nEnter amount to withdraw: ";
			cin>>det[i].withdraw;
			bal=det[i].balance-det[i].withdraw;
			if(bal<0)
			{
				cout<<"\nYou cannot withdraw the mentioned amount from your account as it exceeds your balance.";
				break;
			}
			else
			{
				det[i].balance=bal;
				cout<<"\nYour balance after withdrawal: "<<det[i].balance;
				break;
			}
		}
	}
	if(flag==0)
		cout<<"\nPlease enter a valid account number.\n";
}

inline int Bank::display(long int acc)
{
	if(acc==accno)
	{
		cout<<"\nYour name: "<<name;
		cout<<"\nYour current balance: "<<balance;
		cout<<"\n";
		return 1;
	}
	else
		return 0;
}

int main()
{
	int choice, cont, flag=0;
	long int acc;
	Bank *address;
	cout<<"\nEnter number of accounts: ";
	cin>>n;
	Bank details[n];
	for(int i=0;i<n;++i)
		details[i].getdata();
	while(1)
	{
		cout<<"\nMenu:";
		cout<<"\n1. Deposit amount.";
		cout<<"\n2. Withdraw amount after checking your balance.";
		cout<<"\n3. Display your name and balance.";
		cout<<"\n4. Exit.";
		cout<<"\nPlease enter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"\nEnter your account number: ";
				cin>>acc;
				address=details;
				for(int i=0;i<n;++i)
				{
					cont=deposit(address, acc);
					++address;
					if(cont)
					{
						break;
					}
				}
				if(cont==0)
					cout<<"\nPlease enter a valid account number.\n";
				continue;
				
			case 2:
				withdraw_balance(details);
				continue;
			
			case 3:
				cout<<"\nEnter your account number: ";
				cin>>acc;
				for(int i=0;i<n;++i)
				{
					flag=details[i].display(acc);
					if(flag)
						break;
				}
				if(flag==0)
					cout<<"\nPlease enter a valid account number.\n";
				continue;
			
			case 4:
				cout<<"\nThank you!\n";
				return 0;
			
			default:
				cout<<"\nPlease enter a valid choice.\n";
		}
	}
	return 0;
}
