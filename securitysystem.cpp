//Second Year Computer Engineering, D1 batch
//Parinitha M. Samaga (SYCOD214)
//Satyam Mirgane (SYCOD222)
//Tarun Rathod (SYCOD223)
//Sarthak Shelar (SYCOD224)

#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<fstream>
using namespace std;

class User
{
	protected:
		char name[20];
		char password[15];
		char security_question[20];             //user's answer to one of the security questions
	public:
		static int count;
		int id;                               //will get its values from count, using a static function
		int check_password();     	       //conditions of a password
		void new_details();
		bool pattern_test();                  //only allows to proceed if pattern test is passed
		void quiz();
		static int assign_id()
		{
			++count;
			return count;
		}
		User()
		{
			name[0]='_';
			password[0]='_';
			security_question[0]='_';
		}
};

class ForgotPassword:public User
{
	public:
		int choice;                           //stores question number
		friend void get_details(vector<ForgotPassword>* vec);            //accepts inputs from a user with an existing account
		void backup_questions();              //display questions to choose from and accepts answer
		friend int change_password(vector<ForgotPassword>* vec);
		friend void delentry(vector<ForgotPassword>* vec);
};

int User::check_password()
{
	int alphaflag=0, digflag=0, specflag=0, blankflag=0, len, ret;
	cout<<"\nEnter your new password (Password should have more than 6 and less than 12 characters. Please include aplhabets, digits and a special character(@ or * or $ or #) and no blank spaces.): ";
	cin>>password;
	len=strlen(password);
	if(!(len>=6 && len<=12))
	{
		cout<<"\nThe password should contain 6 or more and 12 or less characters.\n";
		return 0;
	}
	for(auto c:password)
	{
		if(isalpha(c))
			alphaflag=1;
		if(isdigit(c))
			digflag=1;
		if(c==9 || c==32)
			blankflag=1;
		if(c==64 || c==35 || c==36 || c==42)
			specflag=1;
	}
	if(alphaflag==0)
		cout<<"\nThe password should contain an alphabet.\n";
	if(digflag==0)
		cout<<"\nThe password should contain a digit.\n";
	if(specflag==0)
		cout<<"\nThe password should contain a special character.\n";
	if(blankflag==1)
		cout<<"\nThe password should not contain a black space/tab.\n";
	else if(alphaflag==1 && digflag==1 && specflag==1 && blankflag==0)
		ret=1;
	else
		ret=0;
	return ret;
}

void User::new_details()
{
	cout<<"\nEnter your name: ";
	cin>>name;
	id=assign_id();
}

void ForgotPassword::backup_questions()
{
	cout<<"\nChoose your backup question:";
	cout<<"\n1. What was/is your first pet's name?";
	cout<<"\n2. What is the name of your favourite book?";
	cout<<"\n3. What is the name of your favourite movie?";
	cout<<"\n4. Who is your favourite fictional character?";
	cout<<"\n5. What is your favourite dish?";
	cout<<"\nEnter your choice: ";
	cin>>choice;
	cout<<"\nType your answer: ";
	cin>>security_question;
}

bool User::pattern_test()
{
	bool pass=false;
	int ans, tries=0;
	while(!pass)
	{
		++tries;
		if(tries>3)
		{
			cout<<"\nYou have exceeded 3 tries. Please log in and try again.\n";
			break;
		}
		srand(time(0));
		int numb=rand()%5;
		switch(numb)
		{
			case 0:
			{
				char pattern[5][5]={{'%','*','*','$','#'}, {'&','%','&','*','@'}, {'#','*','%','$','@'}, {'@','@','%','$','$'}, {'&','&','$','#','*'}};
				for(int i=0;i<5;++i)
				{
					for(int j=0;j<5;++j)
						cout<<pattern[i][j]<<"  ";
					cout<<endl;
				}
				cout<<"\nEnter the number of '*' in the above pattern: ";
				cin>>ans;
				if(ans==5)
					pass=true;
				else
					cout<<"\nSorry. Try again.\n";
				continue;
			}
			
			case 1:
			{
				char pattern[5][5]={{'f','e','b','d','h'}, {'w','b','b','k','l'}, {'t','w','b','f','e'}, {'e','t','g','h','b'}, {'b','d','d','l','k'}};
				for(int i=0;i<5;++i)
				{
					for(int j=0;j<5;++j)
						cout<<pattern[i][j]<<"  ";
					cout<<endl;
				}
				cout<<"\nEnter the number of 'b' in the above pattern: ";
				cin>>ans;
				if(ans==6)
					pass=true;
				else
					cout<<"\nSorry. Try again.\n";
				continue;
			}
			
			case 2:
			{
				int pattern[5][5]={{7, 4, 8, 3, 19}, {45, 9, 7, 25, 4}, {3, 8, 50, 8, 23}, {1, 90, 2, 7, 38}, {73, 59, 22, 77, 2}};
				for(int i=0;i<5;++i)
				{
					for(int j=0;j<5;++j)
						cout<<pattern[i][j]<<"  ";
					cout<<endl;
				}
				cout<<"\nEnter the number of even numbers in the above pattern: ";
				cin>>ans;
				if(ans==11)
					pass=true;
				else
					cout<<"\nSorry. Try again.\n";
				continue;
			}
			
			case 3:
			{
				char pattern[5][5]={{'m','m','n','n','m'}, {'n','m','m','m','m'}, {'m','n','n','m','n'}, {'m','m','n','m','n'}, {'m','m','n','m','m'}};
				for(int i=0;i<5;++i)
				{
					for(int j=0;j<5;++j)
						cout<<pattern[i][j]<<"  ";
					cout<<endl;
				}
				cout<<"\nEnter the number of 'n' in the above pattern: ";
				cin>>ans;
				if(ans==9)
					pass=true;
				else
					cout<<"\nSorry. Try again.\n";
				continue;
			}
			
			case 4:
			{
				char pattern[5][5]={{'!','~','&','!','^'}, {'&','*','~','^','!'}, {'*','&','^','^','*'}, {'&','&','!','~','*'}, {'!','*','^','~','~'}};
				for(int i=0;i<5;++i)
				{
					for(int j=0;j<5;++j)
						cout<<pattern[i][j]<<"  ";
					cout<<endl;
				}
				cout<<"\nEnter the number of '&' in the above pattern: ";
				cin>>ans;
				if(ans==5)
					pass=true;
				else
					cout<<"\nSorry. Try again.\n";
				continue;
			}
		}
	}
	return pass;
}

void User::quiz()
{
	cout<<"\n********SUCCESFULL LOGIN!!!!!! **********"<<endl;
	while(1)
	{
		cout<<"\nMenu:";
		cout<<"\n1.QUIZ"<<setw(40)<<"2.ACCOUNT DETAILS"<<endl<<"3.EXIT"<<endl;
		int ch;
		cout<<"\nEnter your choice: ";
		cin>>ch;
		if(ch==1)
		{
			cout<<"*****************Welcome to the quiz*****************"<<endl;
			int count=0;
			string a,b;
			int c,d,e;
			cout<<"\n1. What is the capital of India?"<<endl;
			cout<<"Type your answer: ";
			cin.ignore();
			getline(cin,a);
			cout<<endl;
			try
			{
				if(a=="delhi"||a=="DELHI"||a=="new delhi" || a=="NEW DELHI")
					count=count+10;
				else
					throw a;
			}
			catch(string ans)
			{
				cout<<"\nWrong answer!";
				cout<<"\nThe correct answer is: New Delhi\n";
			}
			cout<<"\n2. What is the present highest Rank of Indian Army?"<<endl;
			cout<<"Type your answer: ";
			cin>>b;
			cout<<endl;
			try
			{
				if(b=="general"||b=="GENERAL")
					count=count+10;
				else
					throw b;
			}
			catch(string ans)
			{
				cout<<"\nWrong answer!";
				cout<<"\nThe correct answer is: General\n";
			}
			cout<<"\n3. fstream,ios,iostream,fstreambase are the examples of:"<<endl<<endl<<"1.Library"<<setw(15)<<"2.Class"<<endl<<endl<<"3.Variable"<<setw(15)<<"4.Functions"<<endl;
			cout<<"Type the correct option: ";
			cin>>c;
			cout<<endl;
			try
			{
				if(c==1)
					count=count+10;
				else
					throw c;
			}
			catch(int ans)
			{
				cout<<"\nWrong answer!";
				cout<<"\nThe correct answer is: 1. Library\n";
			}
			cout<<"\n4. Which is the most sensitive organ in the human body?"<<endl<<endl<<"1.Brain"<<setw(15)<<"2.Heart"<<endl<<endl<<"3.Skin"<<setw(15)<<"4.Kidney"<<endl;
			cout<<"Type the correct option: ";
			cin>>d;
			cout<<endl;
			try
			{
				if(d==3)
					count=count+10;
				else
					throw d;
			}
			catch(int ans)
			{
				cout<<"\nWrong answer!";
				cout<<"\nThe correct answer is: 3. Skin\n";
			}
			cout<<"\n5. Who designed the Indian Flag?"<<endl<<endl<<"1.Jawaharlal Nehru"<<setw(30)<<"2.Pingali Venkayya"<<endl<<endl<<"3.Puli Thevar"<<setw(30)<<"4.Lal Bahadur Shastri"<<endl;
			cout<<"Type the correct option: ";
			cin>>e;
			cout<<endl;
			try
			{
				if(e==2)
					count=count+10;
				else
					throw e;
			}
			catch(int ans)
			{
				cout<<"\nWrong answer!";
				cout<<"\nThe correct answer is: 2. Pingali Venkayya\n";
			}
			cout<<"**********YOUR SCORE IS: "<<count<<"/50******************"<<endl;
		}
		else if(ch==2)
		{
			cout<<"\nYour details:";
			cout<<"\nName: "<<name;
			cout<<"\nID: "<<id;
			cout<<"\nPassword: "<<password;
			cout<<endl;
		}
		else if(ch==3)
		{
			cout<<"\nThank you!\n";
			break;
		}
		else
			cout<<"\nInvalid choice!\n";
	}
}

void get_details(vector<ForgotPassword>* vec)
{
	int entid, tries=0, passchange;
	string entpass;
	bool pass=false;
	vector<ForgotPassword> *temp=vec;
	while(!pass)
	{
		int flag=0;
		++tries;
		if(tries>=3 && tries<=5)
		{
			int ch;
			cout<<"\nForgot password? (0/1): ";
			cin>>ch;
			if(ch==1)
			{
				passchange=change_password(vec);
				if(passchange==0)
					break;
			}
		}
		if(tries>5)
		{
			cout<<"\nYou have exceeded 5 tries. Please log in and try again.\n";
			break;
		}
		cout<<"\nEnter your login ID: ";
		cin>>entid;
		int loc=0;
		for(auto o:(*temp))
		{
			if((*temp).at(loc).id==entid)
			{
				flag=1;
				break;
			}
			++loc;
		}
		if(flag==0)
			cout<<"\nInvalid login ID!\n";
		else
		{
			bool pass1;
			cout<<"\nEnter your password: ";
			cin>>entpass;
			if((*temp).at(loc).password==entpass)
			{
				pass1=(*temp).at(loc).pattern_test();
				if(pass1)
				{
					pass=true;
					(*temp).at(loc).quiz();
				}
				else
					break;
			}
			else
				cout<<"\nIncorrect password!\n";
		}
	}
}

int change_password(vector<ForgotPassword>* vec)
{
	int entid, tries=0, retval, loc=0;
	string entsecans;
	vector<ForgotPassword> *temp=vec;
	bool pass=false;
	cout<<"\nEnter your login ID: ";
	cin>>entid;
	for(auto o:(*temp))
	{
		if((*temp).at(loc).id==entid)
			break;
		++loc;
	}
	switch((*temp).at(loc).choice)
	{
		case 1:
			cout<<"\n1. What was/is your first pet's name?";
			break;
		
		case 2:
			cout<<"\n2. What is the name of your favourite book?";
			break;
		
		case 3:
			cout<<"\n3. What is the name of your favourite movie?";
			break;
		
		case 4:
			cout<<"\n4. Who is your favourite fictional character?";
			break;
		
		case 5:
			cout<<"\n5. What is your favourite dish?";
			break;
	}
	while(!pass)
	{
		++tries;
		if(tries>3)
		{
			cout<<"\nYou have exceeded 3 tries. Please log in and try again.\n";
			retval=0;
			break;
		}
		cout<<"\nType your answer: ";
		cin.ignore();
		getline(cin, entsecans);
		if(entsecans==(*temp).at(loc).security_question)
		{
			pass=true;
			int passnew=0;
			while(!passnew)
				passnew=(*temp).at(loc).check_password();
			retval=1;
		}
		else
			cout<<"\nWrong answer!\n";
	}
	return retval;
}

void delentry(vector<ForgotPassword> *vec)
{
	int entid, loc=0, flag=0;
	string entpass;
	cout<<"\nEnter your login ID: ";
	cin>>entid;
	for(auto o:(*vec))
	{
		if((*vec).at(loc).id==entid)
		{
			flag=1;
			break;
		}
		++loc;
	}
	if(flag==0)
		cout<<"\nInavlid login ID!\n";
	else
	{
		cout<<"\nEnter your password: ";
		cin>>entpass;
		if((*vec).at(loc).password==entpass)
		{
			(*vec).erase((*vec).begin()+loc);
			cout<<"\nAccount successfully deleted!\n";
		}
		else
			cout<<"\nInvalid password!\n";
	}
}

int User::count=0;

int main()
{
	cout<<"\n*********************************Security System*********************************";
	cout<<"\nProject By:";
	cout<<"\nParinitha M. Samaga (SYCOD214)\nSatyam Mirgane (SYCOD222)\nTarun Rathod (SYCOD223)\nSarthak Shelar(SYCOD224)\n\n";
	vector <ForgotPassword> userdetails;
	ifstream file;
	ForgotPassword obj;
	file.open("Users.txt", ios::in | ios::binary);
	while(file.read((char *)&obj, sizeof(obj)))
	{
		userdetails.push_back(obj);
		User::count=obj.id;
	}
	file.close();
	int opt, count;
	while(1)
	{
		cout<<"\nMenu: ";
		cout<<"\n1. Create a new account.";
		cout<<"\n2. Use an existing account.";
		cout<<"\n3. Delete an account.";
		cout<<"\n4. Exit.";
		cout<<"\nEnter your choice: ";
		cin>>opt;
		switch(opt)
		{
			case 1:
			{
				ForgotPassword obj;
				obj.new_details();
				int pass=0;
				while(!pass)
					pass=obj.check_password();
				obj.backup_questions();
				userdetails.push_back(obj);
				cout<<"\nYour user ID is: "<<obj.id<<". Please remember it for logging in in the future.\n";
				continue;
			}
			
			case 2:
			{
				get_details(&userdetails);
				continue;
			}
			
			case 3:
			{
				delentry(&userdetails);
				continue;
			}
			
			case 4:
			{
				ofstream file1;
				file1.open("Users.txt", ios::out | ios::binary);
				ForgotPassword temp;
				for(auto temp: userdetails)
					file1.write((char *)&temp, sizeof(temp));
				file1.close();
				cout<<"\nThank you!\n";
				exit(0);
			}
			
			default:
				cout<<"\nInvalid choice!\n";
		}
	}
	return 0;
}
