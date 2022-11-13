#include<iostream>

using namespace std;
class Node {
	public:
	int data;
	Node* next;
	
	
	//constructor
	Node(int data){
	    this -> data = data;
	    this -> next = NULL;
	}
};
void InsertAtHead(Node* &head,int d){
    
    //new node create 
    Node* temp = new Node(d);
    temp-> next=head;
    head = temp;
}
void print(Node* &head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout<< temp ->data <<" ";
        temp = temp -> next;
    }
    cout<< endl;
}
void InsertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail->next;
    
}
void InsertAtPosition(Node* &head ,int position, int d){
    Node* temp = head;
    int cnt = 1; // at first node
    while(cnt < position - 1){
        temp = temp->next;
        cnt++;
    }
    
    //creatin a node for d
    Node* nodeToInsert = new Node(d);
    
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
    
}
int main(){
    
    //created a new node
	Node* node1 = new Node(10);
	cout<< node1 -> data<<endl;
    cout<<node1 ->next<<endl;
    
    // head pointed to node1
    Node* head = node1;
    Node* tail = node1;
    print(head);
    
    InsertAtHead(head,12);
     InsertAtHead(head,15);
      InsertAtHead(head,11);
      cout<<"Inset at beginning: \n";
    print(head);
    
    InsertAtTail(tail,14);
    cout<< "Insert at end: \n";
    print(head);

    InsertAtPosition(head,3,22);
    cout<< "Insert at specific position: \n";
    print(head);
	return 0;
}