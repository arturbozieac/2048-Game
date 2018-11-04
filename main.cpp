#include <iostream>

using namespace std;

int board[4][4]; // our board
int dirLine[] = { 1, 0, -1, 0 };		//controls {down, right, up, left}, increases column or lines, to move on board
int dirColumn[] = { 0, 1, 0, -1 };


// function to initialise a new game
void newGame() {
	for (int i = 0; i < 4; i++)  //scaning all the matrix and initialise it with 0
		for (int j = 0; j < 4; j++)
			board[i][j] = 0; 
}

void printUI() {			//User Interface implementation
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (board[i][j] == 0) //to not show 0, in cells will be printed a "space"
				cout << " ";
			else
				cout << board[i][j] << endl; //printing cell value
	cout << "n : New Game, w : Up, s : Down, d: Right, a: Left, q : Quit" << endl;
}





int main(int argc, char const *argv[])
{
	char commandToDir[128]; //initialising the buttons for direction
	commandToDir['s'] = 0;
	commandToDir['d'] = 1;
	commandToDir['w'] = 2;
	commandToDir['a'] = 3;

	while (true) {
		printUI(); //printing User Interface
		char command;
		cin >> command;		//gets the command
		if (command == 'n')  //if you press n, it will start a new game
			newGame();
		else if (command == 'q') // press q to exit
			break;
		else {
			int currentDirection = commandToDir[command];	//gets direction from your input
			cout << currentDirection << endl; //test
		
		}

	}

	return 0;
}
