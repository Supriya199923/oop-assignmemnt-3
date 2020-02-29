//Name:Supriya Das   Roll:301910501008
/*Write a function void f(int) that prints “inside f(int)”.
Call the function with actual argument of type: i) int, ii) char, iii) float and iv) double.
Add one more function f(float) that prints “inside f(float)”.  Repeat the calls again. */
#include<iostream>
using namespace std;
void f(int a)
{
	cout<<"\ninside f(int)";
}
void f(float a)
{
	cout<<"\ninside f(float)";
}

int main()
{
	int i;
	float fl; 
	char c;
	double d;
	f(i);
	f(c);
	f(fl);
//	f(d);
	return 0;
}
