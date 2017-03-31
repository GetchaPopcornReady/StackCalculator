//Tester File

#include <cstdlib>
#include "stack.h"
#include <iostream>
#include <string>


using namespace std;


int main()
{
	//Variable declaration.
	int runningTotal = 0;
	int undoNumber = 0;
	string stringInput = "aaaa";
	Stack answerStack;
	Stack undoStack;

	// Print instructions
	cout << "Please enter one of the following:\n\n - an arithmetic operator followed by a number to be calculated \n - 'C' to Clear\n - 'U' to Undo\n - 'R' to Redo\n - 'Q' to quit\n";

	// Continuously read data from the user
	int count = 0;
	while(count != 1)
	{
		cout << ">";
		cin >> stringInput;

	if(stringInput.length() > 1) //If not single character command.
	{
		string value = stringInput.substr(1,stringInput.length());

		int number = atoi(value.c_str());
		char charOperator = stringInput[0];

		switch(charOperator){ //Perform arithmetic operation.

			case '+': //ADD
					runningTotal = runningTotal + number;
			break;

			case '-': //SUBTRACT
					runningTotal = runningTotal - number;
			break;

			case '*': //MULTIPLY
					runningTotal = runningTotal * number;
			break;

			case '/': //DIVIDE
					runningTotal = runningTotal / number;
			break;

			case '%': //MODULUS
					runningTotal = runningTotal % number;
			break;

			deafult: //INVALID OPERATOR
					cout << "Invalid Operator!" << endl;
			break;

		}

		answerStack.push(runningTotal); //Push new result of operation.
		cout << runningTotal << endl; //Print result.
		undoStack.clear(); //Clear the undo stack.
	}

	//If string length is 1.
	if(stringInput.length() == 1) //If command is a single character.
	{
		char charInput = stringInput[0];

		switch(charInput){
			case 'U': //UNDO
			case 'u':
					if (answerStack.size() > 0) { //Undo last operation if stack not empty.
						undoNumber = answerStack.pop(); //Remove from answer stack.
						undoStack.push(undoNumber); //Push into undo stack.
						runningTotal = answerStack.peek(); //Update running total
						cout << runningTotal << endl; //Print result.
					} else { //If stack empty, do nothing.
						cout << "Nothing to Undo" << endl;
					}
			break;

			case 'R': //REDO
			case 'r':
					if(undoStack.size() < 1) //If undo stack empty, do nothing.
					{
						cout << "Nothing to Redo" << endl;
					}
					else //Redo last undone operation if stack not empty.
					{
						undoNumber = undoStack.pop(); //Remove from undo stack.
						runningTotal = undoNumber; //Update running total.
						answerStack.push(runningTotal); //Push to answer stack.
					}

					cout << runningTotal << endl; //Print result.
			break;

			case 'C': //CLEAR
			case 'c':
				runningTotal = 0; //Clear the running total.
				answerStack.push(runningTotal); //Push the new running total.
				undoStack.clear(); //Clear the undo stack.
				cout << runningTotal << endl; //Print result.
			break;

			case 'Q': //QUIT
			case 'q':
				count = 1;	//Exit the while loop.
				cout << runningTotal << endl; //Print result.
				cout << "Program Terminated" << endl;
			break;

			default: //INVALID COMMAND.

			cout << "COMMAND UNKNOWN. Please enter a valid command." << endl;
			cout << runningTotal << endl;
		}
	}
}

return 0;
}
