#pragma once
#include "LinkListGame.h"
#include "Stack.h"
int getChoice() {
	cout << "\n\t\tChapter 10 Projects" << endl;
	cout << "\n1: [Project 10.1] Bear, Evans, Beer" << endl;
	cout << "2: [Project 10.2] B.E.B. Cheat Version" << endl;
	cout << "3: [Project 10.3] Stack Program" << endl;
	cout << "4: [Project 10.4] Tower of Hanoi" << endl;
	cout << "5: [Project 10.5] Modified Tower of Hanoi" << endl;

	cout << "0: Quit" << endl;
	cout << "Please make a choice: ";
	int something;
	cin >> something;
	system("CLS");
	return something;
}
void stackOps(Stack &stack) {
	system("CLS");
	typedef short unsigned int choice;
	choice num;
	do
	{
	cout << "\nStack Options: " << endl;
	cout << "\n1: Count items in stack" << endl;
	cout << "2: Display stack" << endl;
	cout << "3: Display item on top of stack" << endl;
	cout << "4: Add number to stack" << endl;
	cout << "5: Pop number out of stack" << endl;
	cout << "6: Do nothing/Quit stack" << endl;
	cin >> num;
	system("CLS");
	switch (num)
	{
	default:
		break;
	case 1: {stack.Count(); }break;
	case 2: {stack.Display(); }break;
	case 3: {stack.Top(); }break;
	case 4: {
		cout << "\nNumber to add: ";
		int temp;
		cin >> temp;
		stack.Push(temp); 
	}break;
	case 5: {stack.Pop(); }break;
	}
	} while (num != 6);

}

void init(Stack &stack) {
	for (int i = 4; i > 0; i--)
	{
		stack.Push(i);
	}
}
//Current progress
void initMod(Stack &stack) {
	string star1 = "\t*";
	string star2 = "\t**";
	string star3 = "\t***";
	string star4 = "\t****";
	string star5 = "\t*****";
	stack.PushMod(star5);
	stack.PushMod(star4);
	stack.PushMod(star3);
	stack.PushMod(star2);
	stack.PushMod(star1);

}

void playStacks(Stack &stack1, Stack &stack2, Stack &stack3) {
	bool  quit = false;
	while (quit != true)
	{
		cout << "Pick a stack to manipulate " << endl;
		cout << "\nStack 1:" << endl;
		stack1.Display();
		cout << endl;
		cout << "Stack 2:" << endl;
		stack2.Display();
		cout << endl;
		cout << "Stack 3:" << endl;
		stack3.Display();
		cout << endl;
		cout << "Stack number: ";
		int choice;
		cin >> choice;
		switch (choice) {
		case 1: {stackOps(stack1); }break;
		case 2: {stackOps(stack2); }break;
		case 3: {stackOps(stack3); }break;
		case 4: {quit = true; }break;
		}
	}
	Sleep(2000);
	system("CLS");
}
void playHanoi(Stack &stack1, Stack &stack2, Stack &stack3) {
	init(stack1);
	bool  quit = false;
	bool won = false;
	int transfer = 0;
	system("CLS");
	cout << "\nYou must move the numbers around so that all of them end up in the correct order on the last stack.\nIf you put a larger number on top of a smaller one, you lose." << endl;
	do
	{
		cout << "Pick a stack to move a number from " << endl;
		cout << "\nStack 1:" << endl;
		stack1.Display();
		cout << endl;
		cout << "Stack 2:" << endl;
		stack2.Display();
		cout << endl;
		cout << "Stack 3:" << endl;
		stack3.Display();
		cout << endl;
		cout << "Stack number: ";
		int choice;
		cin >> choice;
		while (choice > 3 || choice < 1) {
			cout << "\nIllegal input. Please select a stack" << endl;
			cout << "\nStack number: ";
			cin >> choice;
		}
		switch (choice) {
		case 1: { 
			if (stack1.WinCount() == 0) {
			cout << "\nIllegal move." << endl;
		}
				else {
					transfer = stack1.Pop();
				} 
		}break;
		case 2: {
			if (stack2.WinCount() == 0) {
			cout << "\nIllegal move." << endl;
		}
			else {
				transfer = stack2.Pop();
			}
		}break;
		case 3: {
			if (stack3.WinCount() == 0) {
				cout << "\nIllegal move." << endl;
			}
			else {
				transfer = stack3.Pop();
			}
		}break;
		}
		while (transfer != 0 && won == false) {
			cout << "\nWhich stack do you want to move the number to? " << endl;
			cin >> choice;
			while (choice > 3 || choice < 1) {
				cout << "\nIllegal input. Please select a stack" << endl;
				cout << "\nStack number: ";
				cin >> choice;
			}
			switch (choice)
			{
			default:
				break;
			case 1: {
				if (stack1.GetTop() == 0) {
					stack1.Push(transfer);
					transfer = 0;
				}
				else if (transfer < stack1.GetTop())
				{
					stack1.Push(transfer);
					transfer = 0;
				}
				else {
					system("CLS");
					cout << "\nYou Lose!" << endl;
					system("pause");
					won = true;
					break;
				}
			}break;
			case 2: {
				if (stack2.GetTop() == 0) {
					stack2.Push(transfer);
					transfer = 0;
				}
				else if (transfer < stack2.GetTop())
				{
					stack2.Push(transfer);
					transfer = 0;
				}
				else {
					system("CLS");
					cout << "\nYou Lose!" << endl;
					system("pause");
					won = true;
					break;
				}
			}break;
			case 3: {
				if (stack3.GetTop() == 0) {
					stack3.Push(transfer);
					transfer = 0;
				}
				else if (transfer < stack3.GetTop())
				{
					stack3.Push(transfer);
					transfer = 0;
				}
				else {
					system("CLS");
					cout << "\nYou Lose!" << endl;
					system("pause");
					won = true;
					break;
				}
			}break;
			}
		}
		system("CLS");
		if (stack3.WinCount() == 4) {
			system("CLS");
			cout << "\nYou won!!!" << endl;
			system("pause");
			won = true;
		}
	} while (won == false);
	system("CLS");
}
void playHanoiMod(Stack &stack1, Stack &stack2, Stack &stack3) {
	initMod(stack1);
	bool  quit = false;
	bool won = false;
	string transfer = "";
	system("CLS");
	cout << "\nYou must move the 'discs' around so that all of them end up in the correct order on the last stack.\nIf you put a larger disc on top of a smaller one, you lose." << endl;
	do
	{
		cout << "Pick a stack to move a disc from " << endl;
		cout << "\nStack 1:" << endl;
		stack1.DisplayMod();
		cout << endl;
		cout << "Stack 2:" << endl;
		stack2.DisplayMod();
		cout << endl;
		cout << "Stack 3:" << endl;
		stack3.DisplayMod();
		cout << endl;
		cout << "Stack number: ";
		int choice;
		cin >> choice;
		while (choice > 3 || choice < 1) {
			cout << "\nIllegal input. Please select a stack" << endl;
			cout << "\nStack number: ";
			cin >> choice;
		}
		switch (choice) {
		case 1: {
			if (stack1.WinCount() == 0) {
				cout << "\nIllegal move." << endl;
			}
			else {
				transfer = stack1.PopMod();
			}
		}break;
		case 2: {
			if (stack2.WinCount() == 0) {
				cout << "\nIllegal move." << endl;
			}
			else {
				transfer = stack2.PopMod();
			}
		}break;
		case 3: {
			if (stack3.WinCount() == 0) {
				cout << "\nIllegal move." << endl;
			}
			else {
				transfer = stack3.PopMod();
			}
		}break;
		}
		while (transfer != "" && won == false) {
			cout << "\nWhich stack do you want to move the disc to? " << endl;
			cin >> choice;
			while (choice > 3 || choice < 1) {
				cout << "\nIllegal input. Please select a stack" << endl;
				cout << "\nStack number: ";
				cin >> choice;
			}
			switch (choice)
			{
			default:
				break;
			case 1: {
				if (stack1.GetTopMod() == "") {
					stack1.PushMod(transfer);
					transfer = "";
				}
				else if (transfer.size() < stack1.GetTopMod().size())
				{
					stack1.PushMod(transfer);
					transfer = "";
				}
				else {
					system("CLS");
					cout << "\nYou Lose!" << endl;
					system("pause");
					won = true;
					break;
				}
			}break;
			case 2: {
				if (stack2.GetTopMod() == "") {
					stack2.PushMod(transfer);
					transfer = "";
				}
				else if (transfer.size() < stack2.GetTopMod().size())
				{
					stack2.PushMod(transfer);
					transfer = "";
				}
				else {
					system("CLS");
					cout << "\nYou Lose!" << endl;
					system("pause");
					won = true;
					break;
				}
			}break;
			case 3: {
				if (stack3.GetTopMod() == "") {
					stack3.PushMod(transfer);
					transfer = "";
				}
				else if (transfer.size() < stack3.GetTopMod().size())
				{
					stack3.PushMod(transfer);
					transfer = "";
				}
				else {
					system("CLS");
					cout << "\nYou Lose!" << endl;
					system("pause");
					won = true;
					break;
				}
			}break;
			}
		}
		system("CLS");
		if (stack3.WinCount() == 5) {
			system("CLS");
			cout << "\nYou won!!!" << endl;
			system("pause");
			won = true;
		}
	} while (won == false);
	system("CLS");
}
