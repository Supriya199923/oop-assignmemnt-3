//Name:Supriya Das   Roll:301910501008
//9.	Create a STACK class with operation for initialization, push and pop. Support for checking underflow and overflow condition are also to be provided
#include<iostream>
using namespace std;
class stack
{
	int top,i,j,k,n,r,arr[4],temp;
	public:
		void init(int x,int u,int v,int y)
		{
			top=x;
			i=u;
			j=v;
			k=y;
		}
		void push()
		{	
			cout<<"\nEnter the element: ";
			cin>>n;
			k++;
			if(k<4)
			{	top=top+1;
				arr[i]=n;
				i=i+1;
				
			}
			else
			{
				cout<<"\nOVERFLOW occured";
			}
		 }
		 
		 void display()
		 {
			temp=top;
			while(temp>=0)
			{
				cout<<arr[temp]<<"\n";
				temp--;
			}
		 }
		 
		 void pop()
		 {	r=top;
		 	
		 	if(r>=0)
		 	{
		 		top=top-1;
		 		cout<<"Popped element is: "<<arr[i-1];
		 		i=i-1;
			 }
			 else 
			 {
			 	cout<<"\nUNDERFLOW occured";
			 }
			 r=r-1;
		  } 
};

int main()
{
	stack s;
	s.init(-1,0,0,-1);
	int i;
	while(1)
	{	cout<<"\nEnter 1 to PUSH.\nEnter 2 to POP.\nEnter 3 to DISPLAY.\nEnter 4 to Exit.";
		cout<<"\nEnter choice: ";
		cin>>i;
		switch(i)
		{
			case 1:	s.push();
					break;
			case 2: s.pop();
					break;
			case 3:
					s.display();
					break;
			case 4:
					return 0;
			default:
				cout<<"invalid entry";
		}
	
	}
}
