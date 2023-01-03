//SYCOD214
#include<iostream>
using namespace std;

template<class axis, class scalar>
class Vector
{
        axis x;
        axis y;
        axis z;
        public:
                void create();
                void modify();
                Vector scalar_multply();
                void display();
                Vector()
                {
                }
};

template<class axis, class scalar>
void Vector <axis, scalar>::create()
{
        cout<<"\nEnter x_value: ";
        cin>>x;
        cout<<"\nEnter y_value: ";
        cin>>y;
        cout<<"\nEnter z_value: ";
        cin>>z;
}

template<class axis, class scalar>
void Vector <axis, scalar>::modify()
{
        char change;
        cout<<"\nEnter the type of value you want to modify(x/y/z): ";
        cin>>change;
        if(change=='x'||change=='X')
        {
                cout<<"\nEnter new value of x: ";
                cin>>x;
        }
        else if(change=='y'||change=='Y')
        {
                cout<<"\nEnter new value of y: ";
                cin>>y;
        }
        else if(change=='z'||change=='Z')
        {
                cout<<"\nEnter new value of z: ";
                cin>>z;
        }
        else
                cout<<"\nPlease enter a valid option.\n";
}

template<class axis, class scalar>
Vector<axis, scalar> Vector<axis, scalar>::scalar_multply()
{
        scalar numb;
        cout<<"\nEnter scalar value: ";
        cin>>numb;
        Vector <float, float> scalar_product;
        scalar_product.x=x*numb;
        scalar_product.y=y*numb;
        scalar_product.z=z*numb;
        return scalar_product;
}

template<class axis, class scalar>
void Vector <axis, scalar>::display()
{
        cout<<"\nThe vector is: ";
        cout<<"("<<x<<","<<y<<","<<z<<")";
}

int main()
{
        Vector<float, float> vec;
        int choice;
        while(1)
        {
                cout<<"\nMenu:";
                cout<<"\n1. Create a vector.";
                cout<<"\n2. Modify the entered vector.";
                cout<<"\n3. Multiply the entered vector with a scalar value.";
                cout<<"\n4. Display vector.";
                cout<<"\n5. Exit.";
                cout<<"\nEnter your choice: ";
                cin>>choice;
                switch(choice)
                {
                        case 1:
                                vec.create();
                                continue;
               
                        case 2:
                                vec.modify();
                                continue;
               
                        case 3:
                                vec=vec.scalar_multply();
                                continue;
               
                        case 4:
                                vec.display();
                                continue;
                       
                        case 5:
                                cout<<"\nThank you!\n";
                                exit(0);
                        
                        default:
                                cout<<"\nInvalid choice.\n";
                }
        }
        return 0;
}
