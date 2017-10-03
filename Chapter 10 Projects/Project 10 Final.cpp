
#include "Project 10 Final.h"

int main() {
	
	SetConsoleTitle(TEXT("Chapter 10 Projects"));
	while (true) {
		Game FCH;
		switch (getChoice()) {
		case 0: {return 0; }break;
		case 1: {;
			FCH.DisplayInstruct();
			char again;
			do
			{
				FCH.Play();
				cout << "Play Again? (y/n): ";
				cin >> again;
				cout << endl;
			} while (again != 'n'); }break;
		case 2: {
			Game otherGame;
			otherGame.DisplayInstruct(FCH);
			char again;
			do
			{
				otherGame.Play();
				cout << "Play Again? (y/n): ";
				cin >> again;
				cout << endl;
			} while (again != 'n');
		}break;
		case 3: { 
			Stack stack1;
			Stack stack2;
			Stack stack3;
			playStacks(stack1, stack2, stack3);
		}break;
		case 4: {
			Stack stack1;
			Stack stack2;
			Stack stack3;
			playHanoi(stack1, stack2, stack3);
		}break;
		case 5: {
			Stack stack1;
			Stack stack2;
			Stack stack3;
			playHanoiMod(stack1, stack2, stack3);
		}break;
		}
	}
}