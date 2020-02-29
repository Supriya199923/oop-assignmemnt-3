//Name:Supriya Das   Roll:301910501008
//12.	Create a class for linked list. Consider a separate class NODE for basic node activities and use it in class for linked list.
#include<iostream>
#define loop(i,a,b) for(int i=a;i<b;i++)
using namespace std;
class node{		// class for node
    public:
    int key;
    node* prev,*next;
};
node* newnode(int val){
    node* n=new node;
    n->key=val;
    n->prev=n->next=NULL;
    return n;
}
class list		// class for the linked list
{
    node* head;
    static int size;
    public:
    list(){
        head=NULL;
    }
    void insert(){
        cout<<"\n Enter the Value to add in Node : "<<endl;
        int val;
        size++;		// size of the list is calculated
        cin>>val;
                if(head==NULL){
            head=newnode(val);	//inserting node in an empty list
           
        }
        else {
            node*n=newnode(val);
            head->next=n;
            n->prev=head;
            head=n;		//inserting node at the top 
            // top=head;

        }
    }
    static int get_size(){	//function to find size
        return size;
    }
    void pop(int val){		// function to delete any node in the list
        node* temp=head;
        while(temp!=NULL){
            if(temp->key==val){
                size--;
                if(temp==head){
                    if(head->prev==NULL){
                        head=NULL;
                    }
                    else {head->prev->next=head->next;
                    head=head->prev;
                    }
                    delete temp;
                }
                else
                    {   if(temp->prev!=NULL){
                      temp->prev->next=temp->next;
                      temp->next->prev=temp->prev;}
                      else temp->next->prev=NULL;
                      delete temp;
                    }
                    
            }
            temp=temp->prev;
        }
    }
    void display(){			// function to display the list
            node*temp=head;
            while(temp!=NULL){
                cout<<temp->key<<" ";
                temp=temp->prev;
            }
        }
    };
    int list::size=0;
int main(int argc, char const *argv[])
{
    list l;
do{
    cout<<"Enter choice to\n1:ADD\n2.DELETE\n3:LENGTH OF NODE\n4.DISPLAY\n5.EXIT\n";
    int choice;
    cin>>choice;
    if(choice==1){
        l.insert();
        cout<<"node inserted"<<endl;
    }
    if(choice==2){
        int key;
        cin>>key;
        l.pop(key);
    }
    if(choice==3)
    cout<<"total node : "<<list::get_size()<<endl;
    if(choice==4)
    l.display();
    if(choice==5)
    break;
    cout<<"-----------------------------------"<<endl;

}while(1);



return 0;
}
