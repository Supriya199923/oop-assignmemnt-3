//Name:Supriya Das   Roll:301910501008
//14.	Design a BALANCE class with account number, balance and date of last update. Consider a TRANSACTION class with account number, date of transaction, amount and transaction type. If it is a withdrawal check whether the amount is available or not. Transaction object will make necessary update in the BALANCE class
#include<iostream>
#include<ctime>
#include<string>
using namespace std;

class balance{
	private:
		int acc_no;
		int acc_bal;
		time_t t;
		struct tm* now;
		int flag;
		int amt;
	public:
		balance(){
			acc_no=0;
			acc_bal=0;
			t=time(0);
			amt=0;
			flag=0;
		}
		void date(){
			if(now!=NULL){
				cout<<"Last update made on "<<now->tm_mday<<'/'<<now->tm_mon<<'/'<<now->tm_year<<" at "<<now->tm_hour<<':'<<now->tm_min<<':'<<now->tm_sec<<endl;
				if(flag==1) cout<<"Withdrawal of Rs."<<amt<<endl;
				else if(flag==2) cout<<"Deposit of Rs."<<amt<<endl;
			}
		}
		void update(int a1,int a2){
			now=localtime(&t);
			now->tm_year=now->tm_year+1900;
			now->tm_mon=now->tm_mon+1;
			flag=a1;
			amt=a2;
		}
		void bal(){
			cout<<"Account balance is Rs."<<acc_bal<<endl;
		}	
		friend class transaction;
};

class transaction{
	public:
	
		void withdrawal(balance& k,int x){
			if(k.acc_bal>=x){
				k.acc_bal=k.acc_bal-x;
				cout<<"Withdrawal of Rs."<<x<<" successful"<<endl;
				k.update(1,x);
			}
			else{
				cout<<"Insufficient balance for withdrawal"<<endl;
			}
		}
		void account(balance& k){
			cout<<"Enter the 4 digit account number:\n";
			cin>>k.acc_no;
		}
		void deposit(balance& k,int x){
			k.acc_bal=k.acc_bal+x;
			cout<<"Deposit of Rs."<<x<<" successful"<<endl;
			k.update(2,x);
		}
};

int main(){
	balance b;
	transaction t;
	int choice,m;
	char cont='Y';
	cout<<"Bank Account"<<endl;
	t.account(b);
	while(cont=='Y'||cont=='y'){
		cout<<"Enter 1 to Deposit\nEnter 2 to Withdraw\nEnter 3 to check Balance\nEnter 4 to check for Last update"<<endl;
		cin>>choice;
		switch(choice){
			case(1): cout<<"Enter amount to deposit:\n";
					 cin>>m;
					 t.deposit(b,m);
					 break;
			case(2): cout<<"Enter amount to withdraw:\n";
					 cin>>m;
					 t.withdrawal(b,m);
					 break;
			case(3): b.bal();
					 break;
			case(4): b.date();
			  		 break;
			default: cout<<"INVALID CHOICE"<<endl;
		}
		cout<<"Enter 'Y' to continue, 'N' to stop"<<endl;
		cin>>cont;
	}
}
