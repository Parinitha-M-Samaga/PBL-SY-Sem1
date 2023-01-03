//SYCOD214
#include<iostream>
using namespace std;

class DNode
{
	public:
		int data;
		DNode *prev;
		DNode *next;
};

class DLlist
{
	public:
		DNode *head;
		DNode *tail;
		DNode* getnode(int);
		void create();
		void insert();
		void delnode();
		void display();
		DLlist()
		{
			head=NULL;
			tail=NULL;
			create();
		}
};

DNode* DLlist::getnode(int value)
{
	DNode *newnode;
	newnode=new DNode;
	newnode->data=value;
	newnode->next=newnode->prev=NULL;
	return newnode;
}

void DLlist::create()
{
	DNode *temp=head;
	for(int i=0;i<10;++i)
	{
		DNode *newnode;
		newnode=getnode(i+1);
		if(i==0)
			head=newnode;
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
		}
		temp=newnode;
	}
	tail=temp;
}

void DLlist::insert()
{
	int value;
	cout<<"\nEnter the freed seat number: ";
	cin>>value;
	DNode *newnode;
	newnode=getnode(value);
	if(value<(head->data))
	{
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
	}
	else if(value>(tail->data))
	{
		tail->next=newnode;
		newnode->prev=tail;
		tail=newnode;
	}
	else
	{
		DNode *temp=head;
		while((temp->data)<value)
			temp=temp->next;
		temp=temp->prev;
		newnode->next=temp->next;
		newnode->prev=temp;
		(temp->next)->prev=newnode;
		temp->next=newnode;
	}
}

void DLlist::delnode()
{
	int value;
	DNode *temp=head;
	cout<<"\nEnter your desired seat number: ";
	cin>>value;
	if(value==(head->data))
		head=head->next;
	else if(value==(tail->data))
	{
		temp=tail;
		tail=tail->prev;
		tail->next=NULL;
	}
	else
	{
		while((temp->data)!=value)
			temp=temp->next;
		(temp->prev)->next=temp->next;
		(temp->next)->prev=temp->prev;
	}
	delete temp;
}

void DLlist::display()
{
	DNode *temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<"  ";
		temp=temp->next;
	}
	cout<<endl;
}

int main()
{
	DLlist seats[15];
	int choice;
	for(int i=0;i<15;++i)
	{
		DLlist dll;
		seats[i]=dll;
	}
	while(1)
	{
		cout<<"\nMenu:";
		cout<<"\n1. Display all free seats.";
		cout<<"\n2. Reserve a seat.";
		cout<<"\n3. Cancel a reservation.";
		cout<<"\n4. Exit.";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
				for(int i=0;i<15;++i)
				{
					cout<<"\nRow "<<i+1<<":\n";
					seats[i].display();
				}
				continue;
			}
			
			case 2:
			{
				cout<<"\nFree seats:\n";
				for(int i=0;i<15;++i)
				{
					cout<<"\nRow "<<i+1<<":\n";
					seats[i].display();
				}
				int row;
				cout<<"\nEnter desired row: ";
				cin>>row;
				seats[row-1].delnode();
				continue;
			}
			
			case 3:
			{
				int row;
				cout<<"\nEnter row: ";
				cin>>row;
				seats[row-1].insert();
				continue;
			}
			
			case 4:
				cout<<"\nThank you!\n";
				return 0;
			
			default:
				cout<<"\nInvalid choice.\n";
		}
	}
	return 0;
}
