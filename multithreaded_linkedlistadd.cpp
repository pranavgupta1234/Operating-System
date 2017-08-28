#include <iostream>
#include <thread>

using namespace std;

struct node{
	int data;
	node* link;
};

node* newNode(int data){
	node* newnode = new node();
	newnode -> data = data;
	newnode -> link = NULL;
	return newnode;
}

void insert(node** head,int data){

	if(*head == NULL){
		*head = newNode(data);
		return;
	}

	node* newnode = newNode(data);
	newnode -> link = *head;
	*head = newnode;
}

void print(node* head){

	if(head == NULL){
		return;
	}else{

		while(head!=NULL){
			cout<<head -> data<<" ";
			head = head -> link;
		}
	}
	cout<<endl;
}

int main(){

	node* list = NULL;
	insert(&list,1);

	thread t1(insert,&list,3);

	//t1.join();										//output 2 3 1

	insert(&list,2);

	//it is necessary to call either join or detach on the created thread to decide its future
	t1.join();									// output 3 2 1

	print(list);

	return 0;
}