//SYCOD214
#include<iostream>
#include<string>
using namespace std;

int surveyed_customers=20;
int pizza_customers;
int burger_customers;
int total_customers;

class Food
{
        string name;
        public:
                friend void get_data(Food *, Food *);
                friend void p_or_b(Food *, Food *);
                friend void both_pb(Food *, Food *);
                friend void only_p(Food *, Food *);
                friend void only_b(Food *, Food *);
                friend void neither_pb(Food *, Food *);
                Food()
                {
                       
                }
};

void get_data(Food *pizza, Food *burger)
{
        int ch;
        cout<<"\nEnter names of people who like pizzas:\n";
        for(int i=0;i<surveyed_customers;++i)
        {
                cout<<"\nEnter name: ";
                cin>>pizza[i].name;
                cout<<"More entries? (0/1): ";
                cin>>ch;
                if(ch==0)
                {
                        pizza_customers=i+1;
                        break;
                }
        }
        cout<<"\nEnter names of people who like burgers:\n";
        for(int i=0;i<surveyed_customers;++i)
        {
                cout<<"\nEnter name: ";
                cin.ignore();
                cin>>burger[i].name;
                cout<<"More entries? (0/1): ";
                cin>>ch;
                if(ch==0)
                {
                        burger_customers=i+1;
                        break;
                }
        }
}

void p_or_b(Food *pizza, Food *burger)
{
       int i;
       cout<<"\nPeople who like pizza or burger or both:";
       for(i=0;i<pizza_customers;++i)
       	cout<<endl<<pizza[i].name;
       total_customers=i;
       for(int i=0;i<burger_customers;++i)
       {
       	int flag=0;
       	for(int j=0;j<pizza_customers;++j)
       	{
       		if(burger[i].name==pizza[j].name)
       		{
       			flag=1;
       			break;
       		}
       	}
       	if(flag==0)
       	{
       		cout<<endl<<burger[i].name;
       		++total_customers;
       	}
       }
       cout<<"\nTotal number of people liking pizzas or burgers or both is: "<<total_customers<<endl;
}

void both_pb(Food *pizza, Food *burger)
{
	int total=0;
	cout<<"\nPeople who like both pizza and burger:";
	for(int i=0;i<pizza_customers;++i)
		for(int j=0;j<burger_customers;++j)
			if(pizza[i].name==burger[j].name)
			{
				cout<<endl<<pizza[i].name;
				++total;
				break;
			}
	cout<<"\nTotal number of liking both pizzas and burgers is: "<<total<<endl;
}

void only_p(Food *pizza, Food *burger)
{
	cout<<"\nPeople who like only pizzas:";
	int total=0;
	for(int i=0;i<pizza_customers;++i)
	{
		int flag=0;
		for(int j=0;j<burger_customers;++j)
		{
			if(pizza[i].name==burger[j].name)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<endl<<pizza[i].name;
			++total;
		}
	}
	cout<<"\nTotal number of people liking only pizzas is: "<<total<<endl;
}

void only_b(Food *pizza, Food *burger)
{
	cout<<"\nPeople who like only burgers:";
	int total=0;
	for(int i=0;i<burger_customers;++i)
	{
		int flag=0;
		for(int j=0;j<pizza_customers;++j)
		{
			if(burger[i].name==pizza[j].name)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			cout<<endl<<burger[i].name;
			++total;
		}
	}
	cout<<"\nTotal number of people liking only burgers is: "<<total<<endl;
}

void neither_pb(Food *pizza, Food *burger)
{
	cout<<"\nNumber of people liking neither pizzas nor burgers is: "<<(surveyed_customers-total_customers)<<endl;
}

int main()
{
        int choice;
        cout<<"\nA total of "<<surveyed_customers<<" customers were surveyed.\n";
        Food pizza[surveyed_customers], burger[surveyed_customers];
        get_data(pizza, burger);
        while(1)
        {
                cout<<"\nMenu:";
                cout<<"\n1. Display names of customers who like pizza or burger or both.";
                cout<<"\n2. Display names of customers who like both pizza and burger.";
                cout<<"\n3. Display names of customers who like only pizzas.";
                cout<<"\n4. Display names of customers who like only burgers.";
                cout<<"\n5. Display number of customers who like neither pizza nor burger.";
                cout<<"\n6. Exit";
                cout<<"\nEnter your choice: ";
                cin>>choice;
                switch(choice)
                {
                        case 1:
                                p_or_b(pizza, burger);
                                continue;
                       
                        case 2:
                                both_pb(pizza, burger);
                                continue;
                       
                        case 3:
                                only_p(pizza, burger);
                                continue;
                       
                        case 4:
                                only_b(pizza, burger);
                                continue;
                       
                        case 5:
                                neither_pb(pizza, burger);
                                continue;
                       
                        case 6:
                                cout<<"\nThank you!\n";
                                return 0;
                       
                        default:
                                cout<<"\nInvalid choice.\n";
                }
        }
        return 0;
}
