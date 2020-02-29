//Name:Supriya Das   Roll:301910501008
//6.	Define functions f(int, int) and f (char, int). Call the functions with arguments of type (int, char), (char,char) and (float, float).
#include<iostream>
using namespace std;
void f(int x,int y)
{
	cout<<"\nFunction executed f(int,int)";
	cout<<"\ninteger is="<<x<<" and "<<y;
}
void f(char a,int b)
{
	cout<<"\nFunction executed f(char,int)";
	cout<<"\ncharacter is= "<<a<<" and integer is= "<<b;
}
int main()
{
	int x=2,y=3;
	float p=9.6,q=6.7;
	char m='A',n='e';
	f(x,m);
	f(m,n);
//	f(p,q);
	return 0;
}
//errorous execution for call of overloaded f() is ambiguous
