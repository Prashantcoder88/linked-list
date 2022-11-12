#include<iostream>
using namespace std;

	class node {
		public:
			int data;
			node* next;
	};
	
	void printlist(node* a){
		
		while(a !=NULL)
		{
			cout<<a-> data<<endl;
			a = a -> next;
		}
	}
	int main()
	{
		node* head = NULL;
		node* n1 = NULL;
		node* n2 = NULL;
		node* tail = NULL;
		head = new node();
		n1 = new node();
		n2 = new node();
		tail = new node();
		
		head-> data = 2; // given value to first node
		head-> next = n1; // given address of next node
		
		n1 -> data = 3;
		n1 -> next = n2;
		
		n2 -> data = 5;
		n2 -> next = tail;
		
		tail -> data = 7;
		n2 -> next = NULL;
		printlist(head);
		
		return 0;
		
	}
		