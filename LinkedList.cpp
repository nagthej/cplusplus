#include <iostream>
using namespace std;

//insert_front = push, insert_end = append
void insert_front(struct Node **headref, int newdata);
void insert_end(struct Node **headref, int newdata);
void insert_after(struct Node *prevnode, int newdata);
void deletenode(struct Node **headref, int key);
void deletenode_pos(struct Node **headref, int pos);


void PrintList(struct Node *node);

struct Node
{
	int data;
	Node *next;
};


void insert_front(Node **headref, int newdata)
{
	Node *newnode = new Node;
	newnode -> data = newdata;

	//if list is empty, make newnode as head
	if(*headref==NULL)
	{
		*headref=newnode;
		newnode->next = NULL;
		return;
	}

	//if list is not empty
	newnode->next = *headref;
	*headref=newnode;

}

/*
 * 1. 1, 2, 3, 4
 * 2. Create a new node dynamically
 * 3. check if head is not empty, if it is throw error
 * 4. Insert newdata and init next to NULL
 * 4. Traverse through the list... until you find last->next != NULL and then last->next = newnode
 * 5. return
 */


void insert_end(struct Node **headref, int newdata)
{
	Node *newnode = new Node;

	if(*headref==NULL)
	{
		cout << "List cannot be empty first create atleast one node by insert_front" << endl;
		return;
	}

	newnode->data = newdata;
	newnode->next = NULL;

	struct Node *last = *headref; //Temp copy of headref to last
	//Traverse till last node of current list
	while(last->next != NULL)
	{
		last=last->next;
	}

	last->next = newnode;
	return;
}

/*
 * 2,6,7,1,4
 * Insert after 7: After insertion 2,6,7,8,1,4
 * create a new node dynamically
 * insert newdata to newnode
 * Prevnode is given:
 * newnode->next = prevnode->next
 * prevnode->next = newnode;
 */


void insert_after(struct Node *prevnode, int newdata)
{

	Node *newnode = new Node;
	newnode->data = newdata;
	newnode->next = prevnode->next;
	prevnode->next = newnode;
}

void deletenode(struct Node **headref, int key)
{
	Node *temp = *headref;
	Node *prev;

	if(temp!=NULL && temp->data==key)
	{
		*headref = temp->next;
		delete temp;
		return;
	}

	while(temp!=NULL && temp->data!=key)
	{
		prev = temp;
		temp=temp->next;
	}

	//if element not in List
	if(temp==NULL) return;

	prev->next = temp->next;
	delete temp;

}


void deletenode_pos(struct Node **headref, int pos)
{
	if(*headref==NULL)
		return;

	Node *temp=*headref;

	//if list is empty
	if(pos==0)
	{
		*headref=temp->next;
		delete temp;
		return;
	}

	//else traverse till pos
	for(int i=0; (temp!=NULL && i<pos-1) ;i++)
	{
		temp=temp->next;
	}

	//if pos is more than the count of list
	if(temp==NULL && temp->next==NULL)
		return;

	struct Node *next = temp->next->next;

	delete temp->next;

	temp=temp->next;

}




void PrintList(struct Node *node)
{
	while(node!=NULL)
	{
		cout << node->data << " ";
		node = node->next;
	}
}


int main()
{
	Node *head = NULL;

	insert_front(&head, 2);
	insert_end(&head, 6);

	insert_front(&head, 7);
	insert_front(&head, 1);
	insert_end(&head, 4);

	insert_after(head->next, 8);
	insert_after(head->next, 11);

	//deletenode(&head, 11);
	deletenode(&head, 8);

	//deletenode_pos(&head, 1);

	PrintList(head);

return 0;
}
