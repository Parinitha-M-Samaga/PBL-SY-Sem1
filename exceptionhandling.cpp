//SYCOD214
#include <iostream>
using namespace std;

template <class Dtype>
class Matrix
{
	int nofrows1, nofcolumns1;
	int nofrows2, nofcolumns2;
	Dtype mat1[5][5];
	Dtype mat2[5][5];
	Dtype sum[5][5];
	Dtype difference[5][5];
	Dtype product[5][5];
	public:
		Matrix()
		{

		}
		void dimensions();
		void check_operation(int);
		void addition();
		void subtraction();
		void multiplication();
		void create_matrix();
		void display(Dtype [][5], int, int);
};

template <class Dtype>
void Matrix <Dtype>::dimensions()
{
	int pass=1;
	int nofrows1, nofcolumns1, nofrows2, nofcolumns2;
	while(pass)
	{
		try
		{
			cout<<"\nEnter number of rows of first matrix: ";
			cin>>nofrows1;
			if(nofrows1>5)
				throw(nofrows1);
			else
			{
				pass=0;
				this->nofrows1=nofrows1;
				break;
			}
		}
		catch(int nofrows1)
		{
			cout<<"\nNumber of rows exceeds maximum rows (5). Please try again.\n";
		}
	}
	pass=1;
	while(pass)
	{
		try
		{
			cout<<"\nEnter number of columns of first matrix: ";
			cin>>nofcolumns1;
			if(nofcolumns1>5)
				throw(nofcolumns1);
			else
			{
				pass=0;
				this->nofcolumns1=nofcolumns1;
				break;
			}
		}
		catch(int nofcolumns1)
		{
			cout<<"\nNumber of columns exceeds maximum columns (5). Please try again.\n";
		}
	}
	pass=1;
	while(pass)
	{
		try
		{
			cout<<"\nEnter number of rows of second matrix: ";
			cin>>nofrows2;
			if(nofrows2>5)
				throw(nofrows2);
			else
			{
				pass=0;
				this->nofrows2=nofrows2;
				break;
			}
		}
		catch(int nofrows2)
		{
			cout<<"\nNumber of rows exceeds maximum rows (5). Please try again.\n";
		}
	}
	pass=1;
	while(pass)
	{
		try
		{
			cout<<"\nEnter number of columns of second matrix: ";
			cin>>nofcolumns2;
			if(nofcolumns2>5)
				throw(nofcolumns2);
			else
			{
				pass=0;
				this->nofcolumns2=nofcolumns2;
				break;
			}
		}
		catch(int nofcolumns2)
		{
			cout<<"\nNumber of columns exceeds maximum columns (5). Please try again.\n";
		}
	}
}

template <class Dtype>
void Matrix <Dtype>::check_operation(int choice)
{
	if(choice==1)
	{
		try
		{
			if(nofrows1==nofrows2 && nofcolumns1==nofcolumns2)
			{
				create_matrix();
				addition();
			}
			else
				throw(choice);
		}
		catch(int ch)
		{
			cout<<"\nNumber of rows of the first matrix and columns of first matrix should be equal to the number of rows of the second matrix and columns of second matrix respectively.";
		}
	}
	else if(choice==2)
	{
		try
		{
			if(nofrows1==nofrows2 && nofcolumns1==nofcolumns2)
			{
				create_matrix();
				subtraction();
			}
			else
				throw(choice);
		}
		catch(int ch)
		{
			cout<<"\nNumber of rows of the first matrix and columns of first matrix should be equal to the number of rows of the second matrix and columns of second matrix respectively.";
		}
	}
	else if(choice==3)
	{
		try
		{
			if(nofrows1==nofcolumns2 && nofrows2==nofcolumns1)
			{
				create_matrix();
				multiplication();
			}
			else
				throw(choice);
		}
		catch(int ch)
		{
			cout<<"\nNumber of rows of the first matrix should be equal to columns of second matrix and vice versa.";
		}
	}
}

template <class Dtype>
void Matrix <Dtype>::create_matrix()
{
	cout<<"\nEnter "<<nofrows1*nofcolumns1<<" values for first matrix: ";
	for(int i=0;i<nofrows1;++i)
		for(int j=0;j<nofcolumns1;++j)
			cin>>mat1[i][j];
	cout<<"\nEnter "<<nofrows2*nofcolumns2<<" values for second matrix: ";
	for(int i=0;i<nofrows2;++i)
		for(int j=0;j<nofcolumns2;++j)
			cin>>mat2[i][j];
	cout<<"\nFirst matrix:\n";
	display(mat1, nofrows1, nofcolumns1);
	cout<<"\nSecond matrix:\n";
	display(mat2, nofrows2, nofcolumns2);
}

template <class Dtype>
void Matrix <Dtype>::addition()
{
	for(int i=0;i<nofrows1;++i)
		for(int j=0;j<nofcolumns1;++j)
			sum[i][j]=mat1[i][j]+mat2[i][j];
	cout<<"\nThe sum of the two matrices is:\n";
	display(sum, nofrows1, nofcolumns1);
}

template <class Dtype>
void Matrix <Dtype>::subtraction()
{
	for(int i=0;i<nofrows1;++i)
		for(int j=0;j<nofcolumns1;++j)
			difference[i][j]=mat1[i][j]-mat2[i][j];
	cout<<"\nThe difference of the two matrices is:\n";
	display(difference, nofrows1, nofcolumns1);
}

template <class Dtype>
void Matrix <Dtype>::multiplication()
{
	for(int i=0;i<nofrows2;++i)
		for(int j=0;j<nofcolumns1;++j)
		{
			product[i][j]=0;
			for(int k=0;k<nofrows1;++k)
				product[i][j]+=mat1[k][j]*mat2[i][k];
		}
	cout<<"\nThe product of the two matrices is:\n";
	display(product, nofrows2, nofcolumns1);
}

template <class Dtype>
void Matrix <Dtype>::display(Dtype mat[][5], int rows, int cols)
{
	for(int i=0;i<rows;++i)
	{
		for(int j=0;j<cols;++j)
			cout<<mat[i][j]<<"  ";
		cout<<endl;
	}
}

int main()
{
	Matrix <float> obj;
	int choice;
	while(1)
	{
		cout<<"\n----------------------------------------------------------------------";
		cout<<"\nMenu:";
		cout<<"\n1. Add two matrices.";
		cout<<"\n2. Subtract two matrices.";
		cout<<"\n3. Multiply two matrices.";
		cout<<"\n4. Exit.";
		cout<<"\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				obj.dimensions();
				obj.check_operation(1);
				continue;
			
			case 2:
				obj.dimensions();
				obj.check_operation(2);
				continue;
			
			case 3:
				obj.dimensions();
				obj.check_operation(3);
				continue;
			
			case 4:
				cout<<"\nThank you!\n";
				return 0;
			
			default:
				cout<<"\nInvalid choice!\n";
		}
	}
	return 0;
}
