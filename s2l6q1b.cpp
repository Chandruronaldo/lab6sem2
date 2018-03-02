
#include <iostream>
using namespace std;

//Creating the structure for node
struct node
{
	int data;//stores data of the node
	node *next;//stores address of the next element in the list
};

//class definition for carrying out operations on the list
class list
{
	private:
	node *head, *tail;//declaring head and tail of the list
	
	public:
	list()
	{
		head=NULL;
		tail=NULL;
	}
	
	void insert(int val)
	{
		node *temp=new node;
		temp->data=val;
		temp->next=NULL;//a single unliked node has been created
		if(tail==NULL)//case of an empty list
		{
			head=temp;
			tail=temp;
		}
		else
		{
			tail->next=temp;
			tail=temp;
		}
	}
	
	// The move function is a replacement for the expression a[i] in case of arrays
	// It just moves to our desired location
	node *move(int c)
	{
		node *tmp=new node;
		tmp=head;
		for(int i=1;i<c;i++)
		tmp=tmp->next;
		return tmp;
	}
	
    int binarysearch(int bet,int gamma,int del)
          {
	int k=(bet+gamma)/2; // Middle element of the list
	
	while(bet<=gamma) // comparing the end indices
	{
	//If alp[k] is greater than k, then k lies in the left sublist
	if(move(k)->data>del)
	binarysearch(0,k,del);
	//If alp[k] is less than k, then k lies in the right sublist
	else if(move(k)->data<del)
	binarysearch(k,gamma,del);
            else if(move(k)->data==del)//The equality condition
            return k;//The index of searched elemnt is returned
           
	}

	return -1;// If the func reaches here the del is not presnt in the array, so -1 is returned
	
}


	void display()
	{
		node *temp=new node;
		temp=head;
		while(temp->next!=NULL)
		{
			cout<<temp->data<<"->";
			temp=temp->next;
					}
		cout<<temp->data<<"->NULL";
	}


int countitems()
{	
	int i=0;
	node *temp=new node;
	temp=head;
	while(temp->next!=NULL)
	{i=i+1;
	temp=temp->next;}
	return i+1;//since the tail element is not counted, i is incremented by 1
}
};

int main() {
	list a;
	int c=0,val=0,b=0,d=0;
	cout<<"\n Enter the no of elements in the list";
	cin>>b;
	for(int i=0;i<b;i++)
	{
		cout<<"\n Enter the #"<<i+1<<"th entry :";
		cin>>val;
		a.insert(val);
	}
	cout<<"\n enter the element to be searched\n";
	cin>>c;
	cout<<"\n The original list is:";
	a.display();
	d=a.binarysearch(0,b,c);
	if(d!=-1)
	cout<<"\n The number is present in position "<<d+1<<" the list";
	else
	cout<<"\n The number is absent in position the array";
	cout<<"\n The sorted list is:";
	a.display();
	return 0;
}