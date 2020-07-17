#include<iostream>
using namespace std;

struct node
{
public:
	int data;
	node *next;

	node(int data)
	{
		this->data=data;
		this->next=NULL;
	}
};
class singlelinkedlist
{
public:
	node *head;

	singlelinkedlist()
	{
		this->head=NULL;
	}
	void insertatend(int data)
	{
		node *nd=new node(data);
		if(!this->head)
			this->head=nd;
		else
		{
			node *temp=this->head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=nd;
		}
	}

	void insertatmiddle(int data, int pos)
	{
		node *temp=this->head;
		int c=1;
		node *nd = new node(data);
		node *prev;
		if(pos==1)
		{
			nd->next=this->head;
			this->head=nd;
		}
		else
		{
			while(temp!=NULL and pos!=c)
			{	
				prev=temp;
				temp=temp->next;
				c+=1;
			}	
			if(temp)
			{
				prev->next=nd;
				nd->next=temp;
			}
			else
				cout<<"out of range";
		}
	}

	void insertatmiddlevalue(int data,int value)
	{
		node *nd = new node(data);
		node *temp= this->head;
		node *prev;
		while(temp!=NULL and temp->data!=value)
		{
			prev=temp;
			temp=temp->next;
		}
		if(temp)
		{
			prev->next=nd;
			nd->next=temp;
		}
		else
			cout<<"NOT FOUND"<<endl;
	}

	void deletion(int data)
	{
		node *nd= new node(data);
		node *ptr=this->head;
		node *cpt;
		if(this->head->data==data)
			this->head=this->head->next;
		else
		{
			while(ptr!=NULL and ptr->data!=data)
			{
				cpt=ptr;
				ptr=ptr->next;
			}
			if(ptr)
			{
				cpt->next=ptr->next;	
			}
			else
				cout<<"NOT FOUND"<<endl;
		}
	}

	void display()
	{
		node *temp=this->head;

		while(temp!=NULL)
		{
			cout<<temp->data<<endl;
			temp=temp->next;
		}
	}
};

int main()
{
	singlelinkedlist *lst= new singlelinkedlist();
	lst->insertatend(1);
	lst->insertatend(2);
	lst->insertatend(3);
	lst->insertatend(4);
	lst->insertatmiddle(5,4);
	lst->insertatmiddlevalue(-3,6);
	lst->deletion(5);
	lst->deletion(1);
	
	lst->display();
}