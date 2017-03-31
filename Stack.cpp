#include <cstdlib>
#include <iostream>
#include "stack.h"

using namespace std;

/*Stack constructor*/
Stack::Stack(){
	head = NULL;
	totalSize = 0;
}

/*Creates a new node at the top of the stack with the passed in integer.*/
void Stack::push(int addData){
	nodePtr n = new node;
	n->next = NULL; //value subject to change later.
	n->number = addData;

	if (head == NULL || totalSize == 0) { //If stack empty.
		head = n;
	} else { //New head created pointing to the old head.
		nodePtr temp = head;
		head = n;
		head->next= temp;
	}
	
	totalSize++; //Increment size.
	return;
}

/*Removes all nodes from the stack.*/
void Stack::clear(){
	if (head == NULL) { //If stack empty, do nothing.
		return;
	}
	while (head->next != NULL) {
		nodePtr temp = NULL;
		temp = head;
		head = temp->next;
		delete temp;
	}

	head = NULL;
	totalSize = 0;
}


/*Removes the node at the top of the stack and returns its integer value.*/
int Stack::pop(){
	int value = 0;
	nodePtr temp = NULL;
	
	if (head == NULL || totalSize == 0) { //If stack empty, return 0.
		return value;
	} else { //return value of head, replace head with next node, delete old head.
		value = head->number;
		temp = head;
		head = temp->next;
		delete temp;
	}
	totalSize--; //Decrement size.
	return value;
}

/*Returns the totalSize variable.*/
int Stack::size(){
	return totalSize;
}

/*Prints the stack (for testing purposes)*/
void Stack::printStack(){

	nodePtr current = head;	//Starts at head.

	while(current != NULL) //Cycles through entire stack.
	{
		cout << current->number << endl;
		current = current->next;

	}

}

/*Returns the integer at the top of the stack.*/
int Stack::peek() {
	if (head == NULL || totalSize == 0) { //If stack empty, return 0;
		return 0;
	}
	int value = head->number; //Get value of head.

	return value;
}

