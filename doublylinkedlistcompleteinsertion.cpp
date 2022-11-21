#include<iostream>
using namespace std;

class Node {
	public:
	int data;
	Node* prev;
	Node* next;
	
	// constructor
	Node(int d)
	{
		this -> data = d;
		this -> prev = NULL;
		this -> next = NULL;
    }

};
// finding length
int getLength(Node* head)
{
    int len = 0;
    Node* temp = head;
    while(temp != NULL)
    {
        len++;
        temp = temp ->next;
    } 
    return len;
}
// printing nodes of linked list using traversal
 void print(Node* head)
 {
	 Node* temp = head;
	 while(temp != NULL)
	 {
		 cout<< temp ->data<<" ";
		 temp = temp ->next;
	 }
	 cout<<endl;
 }
void insertAtHead(Node* &tail,Node* &head, int d)
{   //empty list
    if(head == NULL){
        Node * temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
       
    Node* temp = new Node(d);
    temp -> next = head;
    head -> prev = temp;
    head = temp;
    }
}
void insertAtTail(Node* &tail,Node* &head, int d)
{
    if(tail == NULL)
    {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
    Node* temp = new Node(d);
    tail -> next = temp;
    temp -> prev = tail;
    tail = temp;
    }
}
void insertAtPosition(Node* tail,Node* &head, int position, int d)
{
    if(position == 1)   // insert at start
    {
        insertAtHead(tail,head, d);
        return;
    }
    
    Node* temp = head;
    int cnt = 1;
    while(cnt<position-1){
        temp = temp ->next;
        cnt++;
    }
    
    // inserting at last position
    if(temp -> next == NULL)
    {
        insertAtTail(tail,head,d);
        return;
    }
    // inserting at middle position
    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}
int main()
{
	//Node* node1 = new Node(10);
	Node* head  = NULL;
	Node* tail = NULL;
	print(head);
	cout<< getLength(head)<< endl;

    insertAtHead(tail,head, 11);
    print(head);
    insertAtHead(tail,head, 13);
    print(head);
    insertAtHead(tail,head, 15);
    print(head);
    insertAtTail(tail,head, 16);
    print(head);
    insertAtPosition(tail,head, 2, 24);
    print(head);
    insertAtPosition(tail,head, 6, 34);
    print(head);
}