#ifndef STACK_H
#define STACK_H

//operations stack
class Stack {
private:
	/*Linked List Node*/
	struct node{
		int number;
		node* next;

	};

	typedef struct node* nodePtr; //just makes a prefix to create a node pointer so you dont have to type struct all the time

	nodePtr head;		//First node in the linked list.
	int totalSize;		//Size of the linked list.
public: 

	Stack(); //makes a stack and sets the private node variables
	void push(int number); //Creates a new node using the passed in integer at the top of the stack.
	void clear();	//removes all nodes from the stack.
	int pop();	//returns int at top of stack and removes the node from the top of the stack.
	void printStack(); //prints the stack.
	int size();	//returns size of stack.
	int peek();	//returns int at top of stack.
};

#endif
