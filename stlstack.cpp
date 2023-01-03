//SYCOD214
#include<iostream>
#include<string>
#include<cmath>
#include<stack>
#include<map>
using namespace std;

stack <int> get_bin(int size)
{
	stack <int> entstack;
	string str;
	int binary;
	bool pass=false;
	while(!pass)
	{
		cout<<"\nEnter a binary number: ";
		cin>>binary;
		str=to_string(binary);
		int len=str.length();
		if(len!=(size+1))
			cout<<"\nLength of the binary number exceeds the limit!\n";
		else
			pass=true;
	}
	int i=pow(10, size);
	while(i!=0)
	{
		entstack.push(binary/i);
		binary%=i;
		i/=10;
	}
	return entstack;
}

int binary_add(stack <int> stack1, stack <int> stack2)
{
	int sum=0, carry=0, size=0, binsum=0;
	stack <int> stacksum;
	while(!stack1.empty())
	{
		int bit1=stack1.top();
		int bit2=stack2.top();
		int buffer=bit1+bit2+carry;
		if(buffer==0)
		{
			sum=0;
			carry=0;
		}
		else if(buffer==1)
		{
			sum=1;
			carry=0;
		}
		else if(buffer==2)
		{
			sum=0;
			carry=1;
		}
		else if(buffer==3)
		{
			sum=1;
			carry=1;
		}
		stacksum.push(sum);
		stack1.pop();
		stack2.pop();
		++size;
	}
	--size;
	if(carry==1)
	{
		stacksum.push(carry);
		++size;
	}
	int i=pow(10, size);
	while(i!=0)
	{
		binsum+=(stacksum.top())*i;
		stacksum.pop();
		i/=10;
	}
	return binsum;
}

int main()
{
	stack <int> stack1, stack2;
	int binsum, size;
	cout<<"\nEnter the number of bits in the binary numbers: ";
	cin>>size;
	--size;
	stack1=get_bin(size);
	stack2=get_bin(size);
	binsum=binary_add(stack1, stack2);
	cout<<"\nThe addition of the two binary numbers is: "<<binsum<<endl;
	return 0;
}
