//Name:Supriya Das   Roll:301910501008
//4.	Write a function that will have income and tax rate as arguments and will return tax amount. In case tax rate is not provided it will be automatically taken as 10%. Call it with and without tax rate.
#include<iostream>
using namespace std;
class amount
{
	float res,inc;
	public:
		void get_amount(float t1)
		{
			printf("\nEnter amount for given tax-rate:");
			cin>>inc;
		}
		void get_amount()
		{
			printf("\nEnter amount for default tax-rate:");
			cin>>inc;
		}
		void set_value()
		{
			float i=10;
			res=(inc*i)/100;
		}
		void set_value(float t1)
		{
			res=(inc*t1)/100;
		}
		void display()
		{
			cout<<"\nThe tax for Rs- "<< inc<<" is: "<<res;
		}
};
int main()
{
	amount k1,k2;
	float t;
	cout<<"\nWith default taxrate:";
	k1.get_amount();
	k2.get_amount(t);
	cout<<"\nEnter taxrate:";
	cin>>t;
	k1.set_value();
	k2.set_value(t);
	cout<<"\nWith default tax-rate:";
	k1.display();
	cout<<"\nWithout default tax-rate:";
	k2.display();
	return 0;
}
