//Name:Supriya Das   Roll:301910501008
//2.	Write a function swap (a, b) to interchange the values of two variables. Do not use pointers.
#include<iostream>
using namespace std;
class SWAP
{
	int a;
	public:
		SWAP(int a1)
		{
			a=a1;
		}
		friend void swap(SWAP&,SWAP&);
};
void swap(SWAP& s1, SWAP& s2)
{
	int temp;
	cout<<"\nBefore Swapping: "<<s1.a<<" "<<s2.a;
	temp=s1.a;
	s1.a=s2.a;
	s2.a=temp;
	cout<<"\nAfter swapping: "<<s1.a<<" "<<s2.a;
}
int main()
{
	SWAP a(6),b(9);
	swap(a,b);
	return 0;
}
