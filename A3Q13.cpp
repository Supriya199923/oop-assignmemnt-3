//Name:Supriya Das   Roll:301910501008
/*13.	Design  the class(es) for the following scenario:
"	An item list contains item code, name, rate, and quantity for several items.
"	Whenever a new item is added in the list uniqueness of item code is to be checked. 
"	Time to time rate of the items may change. 
"	Whenever an item is issued or received existence of the item is checked and quantity is updated. 
"	In case of issue, availability of quantity is also to be checked.
"	User may also like to know price/quantity available for an item.
*/
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;


class item
{
	item* next;
	string name,code;
	int quantity;
	float rate;
	public:
	friend class list;
	//friend istream& operator >>(istream& ,item&);
	//friend ostream& operator <<(ostream& ,item&);
};
class list
{
	public:
	item* head; 
	//item* next;	
	friend class Menu;
	list()
	{
		head=NULL;
	}
	item* getNode(string c,string n,int q,float r)
	{
		item* cur=new item;
		cur->code=c;
		cur->name=n;
		cur->quantity=q;
		cur->rate=r;
		cur->next=NULL;
		return cur;
	}
	void deleteNode(string s)
	{
		item* cur = head;
		if(head->code == s)
		{
			cur=head->next;
			head=cur;
		}
		while(cur->next!=NULL)
		{
			if(cur->next->code==s)
			{
				cur->next=cur->next->next;
				return;
			}
			cur=cur->next;
		}
	}
	void addItem(string c,string n,int q,float r)
	{
		item* x = getNode(c,n,q,r);
		item *cur = head;
		bool check=1;
		if(head == NULL)head=x;
		else
		{x->next=head;
		head=x;}		
	}
	void updateRate(string s,float r)
	{
		item* cur = head;
		while(cur!=NULL)
		{
			if(cur->code==s)
				cur->rate=r;
			cur=cur->next;
		}
	}
	void updateQuantity(string s,int r)
	{
		item* cur = head;
		while(cur!=NULL)
		{
			if(cur->code==s)
				cur->quantity=r;
			cur=cur->next;
		}
	}
	void knowRate(string s)
	{
		bool check = 0;
		item* cur = head;
		while(cur!=NULL)
		{
			if(cur->code==s)
			{
				check=1;
				cout<<"Rate of "<<s<<" is :\n"<<cur->rate<<endl;
			}
			cur=cur->next;
		}
		if(check==0)
		cout<<"Unavailable"<<endl;
	}
	void knowQuantity(string s)
	{
		bool check = 0;
		item* cur = head;
		while(cur!=NULL)
		{
			if(cur->code==s)
			{
				check=1;
				cout<<"Quantity of "<<s<<" is :\n"<<cur->quantity<<endl;
			}
			cur=cur->next;
		}
		if(check==0)
		cout<<"Unavailable"<<endl;
	}
	void sellItem(string s,int q)
	{
		bool check = 0;
		item* cur = head;
		while(cur!=NULL)
		{
			if(cur->code==s) 
			{
				if(cur->quantity>q)
					cur->quantity-=q;
				else if(cur->quantity==q)
					deleteNode(s);
				else if(cur->quantity<q)
					cout<<"Desired quantity of the item is unavailable\n";
				check=1;
			}
			cur=cur->next;
		}
		if(check==0)
		cout<<"Unavailable"<<endl;
	}
	bool isAvailable(string s)
	{
		bool check = 0;
		item* cur = head;
		while(cur!=NULL)
		{
			if(cur->code==s)
				check=1;
			cur=cur->next;
		}
		return check;
	}
	void printList()
	{
		item* cur = head;
		if(cur==NULL)
		{
		cout<<"no item is their";
		}
		while(cur!=NULL)
		{
			cout<<"Name: "<<(cur->name)<<"\nCode: "<<(cur->code)<<"\nQuantity: "<<(cur->quantity)<<"\nRate: "<<(cur->rate)<<endl<<endl;		
			cur=cur->next;
		}	
		cout<<endl;
	}	
};
class Menu
{
	public:
	list ilis;
	int menu;
	Menu():menu(0){}
	void getMenu()
	{
		cout<<"Enter the manu option\n";
		cin>>menu;
	}
	void displayMenu()
	{
		cout<<"Press the following numerals to get the stated services:\n1.Add new item in the list\n2.Update rate of an item\n3.Update quantity of an item\n4.Sell an item\n5.Know rate of any item\n6.Know quantity of any item\n7.An item is available or not\n8.Print the condition of the list\n10.To stop using the program\n";
	     cout<<"****************************************************************"<<"\n";
	}
	
	void menuFunc()
	{
		
			if(menu==1)//addItem
			{
				string c,n;
				int q;
				float r;
				cout<<"CODE:";
				cin>>c;
				bool mask = ilis.isAvailable(c),check = 0;
				if(!mask)
				{
					cout<<"NAME:";
					cin>>n;
					cout<<"QUANTITY:";
					cin>>q;
					cout<<"RATE:";
					cin>>r;
					ilis.addItem(c,n,q,r);
				}
				else
				{
					cout<<"Item already available.\nIf you want to update through given data\nPress 1\nPress 2 for not updating\n";
					int m;
					cin>>m;
					if(m==1)
					{
						check=1;
						ilis.deleteNode(c);
						cout<<"NAME:";
						cin>>n;
						cout<<"QUANTITY:";
						cin>>q;
						cout<<"RATE:";
						cin>>r;
						ilis.addItem(c,n,q,r);
					}
					else if(m==2)
						check=0;
				}
				
			}
			if(menu==2)//updateRate
			{
				string c;
				float r;
				cout<<"CODE:";
				cin>>c;
				bool check = ilis.isAvailable(c);
				if(!check)
				{
					cout<<"Item is unavailable"<<endl;
				}
				else
				{	
					cout<<"RATE:";
					cin>>r;
					ilis.updateRate(c,r);
				}
			}
			if(menu==3)//updateQuantity
			{
				string c;
				int r;
				cout<<"CODE:";
				cin>>c;
				bool check = ilis.isAvailable(c);
				if(!check)
				{
					cout<<"Item is unavailable"<<endl;
				}
				else
				{
					cout<<"QUANTITY:";
					cin>>r;
					ilis.updateQuantity(c,r);
				}
			}
			if(menu==4)//sellItem
			{
				string c;
				int r;
				cout<<"CODE:";
				cin>>c;
				bool check = ilis.isAvailable(c);
				if(!check)
				{
					cout<<"Item is unavailable"<<endl;
				}
				else
				{
					cout<<"QUANTITY:";
					cin>>r;
					ilis.sellItem(c,r);
				}
			}
			if(menu==5)//knowRate
			{
				string c;
				cout<<"CODE:";
				cin>>c;
				ilis.knowRate(c);
			}
			if(menu==6)//knowQuantity
			{
				string c;
				cout<<"CODE:";
				cin>>c;
				ilis.knowQuantity(c);
			}
			if(menu==7)//isAvailable
			{
				string c;
				cout<<"CODE:";
				cin>>c;
				bool check = ilis.isAvailable(c);
				if(check)
					cout<<"Available"<<endl;
				else
					cout<<"Unavailable"<<endl;
			}
			if(menu==8)//printItem
			{
				ilis.printList();
			}
			else
				exit(1);
		
	}	
};
int main()
{
	Menu m;
	m.displayMenu();
	do
	{
		m.getMenu();		
		m.menuFunc();
	}while(m.menu!=0);	
	return 0;
}
