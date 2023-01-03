//SYCOD214
#include<fstream>
#include<iostream>
using namespace std;

class Employee
{
        static int assignID;
        int empID;
        char name[10];
        int age;
        char department[15];
        char post[15];
        int salary;
        public:
                static int IDfunc()
                {
                        ++assignID;
                        return assignID;
                }
                void getdata();
                void display();
                void search();
                void update();
                Employee()
                {
                }
};

void Employee::getdata()
{
        ofstream file;
        Employee emp;
        file.open("Employee.txt", ios::app | ios::binary);
        bool choice;
        do
        {
                emp.empID=IDfunc();
                cout<<"\nEnter name: ";
                cin>>emp.name;
                cout<<"\nEnter age: ";
                cin>>emp.age;
                cout<<"\nEnter department: ";
                cin>>emp.department;
                cout<<"\nEnter post: ";
                cin>>emp.post;
                cout<<"\nEnter salary: ";
                cin>>emp.salary;
                file.write((char *)&emp, sizeof(emp));
                cout<<"\nDo you want to enter a new record? (0/1): ";
                cin>>choice;
                if(choice==0)
                        break;
        }while(1);
        file.close();
}

void Employee::display()
{
        ifstream file;
        Employee emp;
        file.open("Employee.txt",ios::binary);
        while(file.read((char *)&emp, sizeof(emp)))
        {
                cout<<"\nEmployee's ID: "<<emp.empID;
                cout<<"\nEmployee's name: "<<emp.name;
                cout<<"\nEmployee's age: "<<emp.age;
                cout<<"\nEmployee's department: "<<emp.department;
                cout<<"\nEmployee's post: "<<emp.post;
                cout<<"\nEmployee's salary: "<<emp.salary<<" Rupees";
                cout<<endl;
        }
        file.close();
}

void Employee::search()
{
        ifstream file;
        Employee emp;
        int searchID, flag=0;
        file.open("Employee.txt",ios::binary);
        cout<<"\nEnter the ID of the employee: ";
        cin>>searchID;
        while(file.read((char *)&emp, sizeof(emp)))
        {
                if(emp.empID==searchID)
                {
                        cout<<"\nEmployee's ID: "<<emp.empID;
                        cout<<"\nEmployee's name: "<<emp.name;
                        cout<<"\nEmployee's age: "<<emp.age;
                        cout<<"\nEmployee's department: "<<emp.department;
                        cout<<"\nEmployee's post: "<<emp.post;
                        cout<<"\nEmployee's salary: "<<emp.salary;
                        cout<<endl;
                        flag=1;
                        break;
                }
        }
        if(flag==0)
                cout<<"\nRecord not found!\n";
        file.close();
}

void Employee::update()
{
        fstream file;
        Employee emp;
        int searchID, entpos=0, flag=0;
        file.open("Employee.txt", ios::in | ios::out | ios::binary);
        cout<<"\nEnter the ID of the employee: ";
        cin>>searchID;
        while(file.read((char *)&emp, sizeof(emp)))
        {
                if(emp.empID==searchID)
                {
                        file.seekp(entpos*sizeof(emp), ios::beg);
                        cout<<"\nEnter new post of the employee: ";
                        cin>>emp.post;
                        cout<<"\nEnter new salary of the employee: ";
                        cin>>emp.salary;
                        file.write((char *)&emp, sizeof(emp));
                        flag=1;
                        break;
                }
                ++entpos;
        }
        if(flag==0)
                cout<<"\nRecord not found!\n";
        file.close();
}

int Employee::assignID=0;

int main()
{
        int choice;
        Employee empl;
        while(1)
        {
                cout<<"\nMenu:";
                cout<<"\n1. Enter new records.";
                cout<<"\n2. Display all records.";
                cout<<"\n3. Search for a record.";
                cout<<"\n4. Update a record.";
                cout<<"\n5. Exit.";
                cout<<"\nEnter your choice: ";
                cin>>choice;
                switch(choice)
                {
                        case 1:
                                empl.getdata();
                                continue;
                       
                        case 2:
                                empl.display();
                                continue;
                       
                        case 3:
                                empl.search();
                                continue;
                       
                        case 4:
                                empl.update();
                                continue;
                       
                        case 5:
                                cout<<"\nThank you!\n";
                                exit(0);
                        
                        default:
                                cout<<"\nInvalid choice!\n";
                }
        }
        return 0;
}
