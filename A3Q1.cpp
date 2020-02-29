//Name:Supriya Das   Roll:301910501008
//1.	Write a macro to find the maximum of two numbers. Call the macro with i) two integers as the arguments and ii) two string as the arguments. Repeat the same by replacing the macro with an inline function. Observe the outcomes.


#include<iostream>
#include<string.h>
#include<stdlib.h>
#define MAX(a,b) (a>b)?a:b
using namespace std;
inline void maximum(char a[],char b[])
{
	if(strcmp(a,b)==1)
		cout<<"Maximum of two strings: "<<a;
	else 
		cout<<"Maximum of two strings: "<<b;	
}
inline int maximum(int a,int b)
{
	return(a>b)?a:b;
}
int main()
{
	int choice;	
	while(1)
	{
		cout<<"\n1.Pass Integer as Arguement(for macro)";
		cout<<"\n2.Pass String as Arguement(for macro)";
		cout<<"\n3.Pass Integer as Arguement(for inline)";
		cout<<"\n4.Pass String as Argument(for inline)";
		cout<<"\nOther to exit";
		cout<<"\n\nEnter Your Choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
			
			int a,b,c;
			cout<<"\nEnter Two Numbers : ";
			cin>>a>>b;
			c=MAX(a,b);
			cout<<"\nMaximum Of The Two Numbers Is : "<<c<<endl;
			break;
			case 2:
			
			char a2[10],b2[10],c2[10];
			cout<<"\nEnter Two Strings : ";
			cin>>a2>>b2;
			strcpy(c2,MAX(a2,b2));
			cout<<"\nMaximum Of The Two Strings Is : "<<c2<<endl;
			break;
			
			case 3:
			
			int a3,b3,c3;
			cout<<"\nEnter Two Numbers : ";
			cin>>a3>>b3;
			c3=maximum(a3,b3);
			cout<<"\nMaximum Of The Two Numbers Is : "<<c3<<endl;
			break;
			case 4:
			
				char a4[10],b4[10];
				cout<<"\nEnter two strings:";
				cin>>a4>>b4;
				maximum(a4,b4);
			break;
			default: exit(1);
	
		}
	}


	return 0;
}


