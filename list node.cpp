#include <cstdlib>
#include <iostream>
//#include "list.h"

using namespace std;

class list{
	private:
		struct node{
			int data;
			node* next;
		};
		
		node* head;
		node* curr;
		node* temp;
		
	public:
		list();
		void addnode(int adddata);
		void deletenode(int deldata);
		void printlist();		
};


list::list(){
	head = NULL;
	curr = NULL;
	temp = NULL;
}

void list::addnode(int adddata){
	node* n= new node;
	n->next=NULL;
	n->data=adddata;

	if(head !=NULL){
		curr = head;
		while(curr->next != NULL){
			curr = curr->next;
		}
		curr->next = n;
	}else{
		head = n;	
	}

}

void list::deletenode(int deldata){
	node* delnode = NULL;
	temp = head;
	curr = head;
	while(curr != NULL && curr->data != deldata){
		temp = curr;
		curr = curr->next;
	}
	if(curr == NULL){
		cout<<deldata<<"was not on the list"<<endl;
		delete delnode;
	}
	else{
		delnode = curr;
		curr = curr->next;
		temp->next = curr;
		if(delnode == head){
			head = head->next;
			temp=NULL;
		}
		
		delete delnode;
		cout<<"the value"<<deldata<<"was deletd"<<endl;
	}
	
}

void list::printlist(){
	curr = head;
	while(curr != NULL){
		cout<<curr->data;
		curr = curr->next;
	}
}

int main(){
	list n;
	n.addnode(3);
	n.addnode(5);
	n.addnode(7);
	n.printlist();
	n.printlist();
	
	n.deletenode(7);
	n.printlist();
	

	
	return 0;


}