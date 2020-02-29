//Name:Supriya Das   Roll:301910501008
//10.	Create an APPLICANT class with application id (auto generated as last id +1), name and score. Support must be there to receive applicant data, show applicant details and to find out number of applicants
#include<iostream>
#include<string.h>
using namespace std;
class application
{
	int id, score;
	char name[10];
	public:
		application(int i,int s,char *p)
		{
			id=i;
			score=s;
			strcpy(name,p);
		}
		void put()
		{
			cin>>score;
			cin>>name;
			id=id+1;
		}
		int show()
		{
			cout<<"\n Details you Entered: ";			
			cout<<"ID No.: "<<id<<"\n"<<"NAME : "<<name<<"\n"<<"SCORE : "<<score<<"\n";
			return id;
			
		}
};

int main()
{
	int i,s,j,temp;
	cout<<"Enter ID and SCORE Respectively:\t"; 
	cin>>i>>s;
	char arr[10];
	cout<<"NAME : \t";
	cin>>arr;
temp=i;
	application a(i,s,arr);
	cout<<"\n";

	a.show();
	for(i=0;i<5;i++)
	{
		cout<<"Enter SCORE and NAME Respectively : ";
		a.put();
		j=a.show();
		cout<<"Number of Aplicant : "<<(j-temp)<<"\n";
		
	}
	
}
