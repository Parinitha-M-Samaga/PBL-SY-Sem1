//SYCOD214
#include<iostream>
using namespace std;

int size;

int* sort(int *array)
{
	for(int i=0;i<size-1;++i)
	{
		int min=i;
		for(int j=i+1;j<size;++j)
			if(array[min]>array[j])
				min=j;
		int temp=array[i];
		array[i]=array[min];
		array[min]=temp;
	}
	return array;
}

void frequency(int *array)
{
	for(int i=0;i<size-1;++i)
	{
		int freq=1;
		while(array[i+1]==array[i])
		{
			++freq;
			++i;
		}
		cout<<"\nFrequency of "<<array[i]<<" is: "<<freq;
	}
	cout<<endl;
}

int main()
{
	cout<<"\nEnter the size of your array: ";
	cin>>size;
	int array[size];
	cout<<"\nEnter elements of the array: ";
	for(int i=0;i<size;++i)
		cin>>array[i];
	int* sorted;
	sorted=sort(array);
	frequency(sorted);
	return 0;
}
