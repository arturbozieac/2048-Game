#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;

int board[4][4];						// our board
int dirLine[] = { 1, 0, -1, 0 };		//controls {down, right, up, left}, increases column or lines, to move on board
int dirColumn[] = { 0, 1, 0, -1 };
//functio to generate Unoccupied Position 
pair<int, int> generateUnoccupiedPosition() { 
	int occupied = 1, line, column;
	while (occupied) { 
		 line = rand() % 4;    //generates a random coordinates on the board
		 column = rand() % 4;
		if (board[line][column] == 0) //if generated coordinates are empty, fucntion stops and return make_pair
			occupied = 0;
	}
	return make_pair(line, column);
}
// function to initialise a new game
void newGame() {
	for (int i = 0; i < 4; i++)  //scaning all the matrix and initialise it with 0
		for (int j = 0; j < 4; ++j)
			board[i][j] = 0; 
	pair<int, int> pos = generateUnoccupiedPosition();
	board[pos.first][pos.second] = 2; //asigns 2 to a empty position on board
}

void printUI() {			//User Interface implementation
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; ++j)
			if (board[i][j] == 0) //to not show 0, in cells will be printed a "dots"
				cout << ".";
			else
				cout << board[i][j];  //printing cell value
	cout << "\n";
		}
	cout << "\n \n n : New Game, w : Up, s : Down, d: Right, a: Left, q : Quit" << endl;
}
	
bool canDoMove(int line, int column, int nextLine, int nextColumn) {
	if (nextLine < 0 || nextColumn < 0 || nextLine >= 4 || nextColumn >= 4 || board[line][column] != board[nextLine][nextColumn] && board[nextLine][nextColumn] != 0)
		return false;
	return true;
}

void aplyMove(int direction) {
	int startLine = 0, startColumn = 0, lineStep = 1, columnStep = 1;
	if (direction == 0) {
		startLine = 3;
		lineStep = -1;
	}
	if (direction == 1) {
		startColumn = 3;
		columnStep = -1;
	}
	int movePossible = 0;
		for (int i = startLine; i >= 0 && i < 4; i += lineStep)  
			for (int j = startColumn; j >= 0 && j < 4; j += columnStep) {
				int nextI = i + dirLine[direction], nextJ = j + dirColumn[direction];
				if (canDoMove(i, j, nextI, nextJ)) {
					board[nextI][nextJ] += board[i][j];
					board[i][j] = 0;
					movePossible = 1;
				}
			}

}



int main(int argc, char const *argv[])
{
	srand(time(0)); // random generator depending on time
	char commandToDir[128]; //initialising the buttons for direction
	commandToDir['s'] = 0;
	commandToDir['d'] = 1;
	commandToDir['w'] = 2;
	commandToDir['a'] = 3;
	newGame();
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
			aplyMove(currentDirection);
		}

	}

	return 0;
}
