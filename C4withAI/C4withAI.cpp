#include<iomanip>
#include <iostream>
#include <string>

using namespace std;
const int MAXSIZE = 20;
int sum = 0;
bool winner1 = false;
bool winner2 = false;
//template<int row,int column>
string board[MAXSIZE][MAXSIZE] = {};
void InitMatrix(int r, int c) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			board[i][j] = "*";
		}
	}
	return;
}
void PrintMatrix(int r, int c) {
	int j = 0;
	cout << "//////////////////////////////////////////////////" << endl;
	for (j = 0; j < c; j++) {
		cout << setfill('0') << setw(2) << j + 1 << " ";
	}
	cout << endl;
	for (int i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			cout << board[i][j] << "  ";
		}
		cout << endl;
		j = 0;
	}
	return;
}
int PlayChess(int i, bool wP, int r) {
	int j = r;
	for (j; j >= 0; j--) {
		if (board[j][i] == "*") {
			if (wP == true) {
				board[j][i] = "X";
			}
			else {
				board[j][i] = "O";
			}
			int a = j;
			sum--;
			return a;
			break;
		}
	}
}
void DropChess(int r, int c) {
	int j = r;
	for (j; j >= 0; j--) {
		board[j][c] = board[j - 1][c];
	}
	board[0][c] = "*";
	sum++;
}
bool cheackWin(int r, int c, int ws) {
	int i, j = 0;
	bool hW = true, vW = true, dW1 = true, dW2 = true;
	winner1 = false;
	winner2 = false;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			if (board[i][j] != "*") {
				for (int a = 1; a <= ws; a++) {
					if (board[i][j] != board[i + a][j]) {
						vW = false;
						break;
					}
				}
				if (vW == true) {
					if (board[i][j] == "X") {
						winner1 = true;
					}
					else if (board[i][j] == "O") {
						winner2 = true;
					}
					
					
				}
				vW = true;
				for (int a = 1; a <= ws; a++) {
					if (board[i][j] != board[i][j + a]) {
						hW = false;
						break;
					}
				}
				if (hW == true) {
					if (board[i][j] == "X") {
						winner1 = true;
					}
					else if (board[i][j] == "O") {
						winner2 = true;
					}
					
					
				}
				hW = true;
				for (int a = 1; a <= ws; a++) {
					if (board[i][j] != board[i + a][j + a]) {
						dW1 = false;
						break;
					}
				}
				if (dW1 == true) {
					if (board[i][j] == "X") {
						winner1 = true;
					}
					else if (board[i][j] == "O") {
						winner2 = true;
					}
					
					
				}
				dW1 = true;
				for (int a = 1; a <= ws; a++) {
					if (board[i][j] != board[i - a][j + a]) {
						dW2 = false;
						break;
					}
				}
				if (dW2 == true) {
					if (board[i][j] == "X") {
						winner1 = true;
					}
					else if (board[i][j] == "O") {
						winner2 = true;
					}
					
					
				}
				dW2 = true;
			}
		}
	}
	if (winner1 == true || winner2 == true) {
		return true;
	}
	else {

		return false;
	}
}
int PieceCheck(int r, int c, string a) {
	int count = 0;
	for (int j = 0; j < c; j++) {
		if (board[r - 1][j] == a) {
			count++;
		}
	}
	return count;
}
bool cheackWrapWin(int r, int c, int ws) {
	int i, j = 0;
	winner1 = false;
	winner2 = false;
	bool hW = true, vW = true, dW1 = true, dW2 = true;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			if (board[i][j] != "*") {
				for (int a = 1; a <= ws; a++) {
					if (board[i][j] != board[i + a][j]) {
						vW = false;
						break;
					}
				}
				if (vW == true) {
					if (board[i][j] == "X") {
						winner1 = true;
					}
					else if (board[i][j] == "O") {
						winner2 = true;
					}
		
					
				}
				vW = true;
				for (int a = 1; a <= ws; a++) {
					if (board[i][j] != board[i][(j + a) % c]) {
						hW = false;
						break;
					}
				}
				if (hW == true) {
					if (board[i][j] == "X") {
						winner1 = true;
					}
					else if (board[i][j] == "O") {
						winner2 = true;
					}
					
					
				}
				hW = true;
				for (int a = 1; a <= ws; a++) {
					if (board[i][j] != board[i + a][(j + a) % c]) {
						dW1 = false;
						break;
					}
				}
				if (dW1 == true) {
					if (board[i][j] == "X") {
						winner1 = true;
					}
					else if (board[i][j] == "O") {
						winner2 = true;
					}
					
				
				}
				dW1 = true;
				for (int a = 1; a <= ws; a++) {
					if (board[i][j] != board[i - a][(j + a) % c]) {
						dW2 = false;
						break;
					}
				}
				if (dW2 == true) {
					if (board[i][j] == "X") {
						winner1 = true;
					}
					else if (board[i][j] == "O") {
						winner2 = true;
					}
					
				
				}
				dW2 = true;
			}
		}
	}
	if (winner1 == true || winner2 == true) {
		return true;
	}
	else {

		return false;
	}
}

void simpleAI(int r, int c, int mode, bool wP) {
	int choice[MAXSIZE] = {};
	int score = 0, deciC = 0;
	for (int i = 0; i < c; i++) {
		for (int j = r; j > 0; j--) {
			if (board[0][i] != "*") {
				choice[i] = -1;
				break;
			}
			if (board[j][i] == "*") {
				choice[i] = j;
				break;
			}
		}
	}
	for (int i = 0; i < c; i++) {
		if(choice[i] != -1) {
			int temp = score;
			score = 0;
			board[choice[i]][i] = "O";
			if (mode == 1) {
				bool sureWin = cheackWrapWin(r, c, 3);
				if (sureWin == true) {
					deciC = i;
					board[choice[i]][i] = "*";
					break;
				}
			}
			else if (mode != 1) {
				bool sureWin = cheackWin(r, c, 3);
				if (sureWin == true) {
					deciC = i;
					board[choice[i]][i] = "*";
					break;
				}
			}
			board[choice[i]][i] = "X";
			if (mode == 1) {
				bool sureLose = cheackWrapWin(r, c, 3);
				if (sureLose == true) {
					deciC = i;
					board[choice[i]][i] = "*";
					break;
				}
			}
			else if (mode != 1) {
				bool sureLose = cheackWin(r, c, 3);
				if (sureLose == true) {
					deciC = i;
					board[choice[i]][i] = "*";
					break;
				}
			}
			board[choice[i]][i] = "O";
			if (board[choice[i]][i] == board[choice[i]][i + 1] && board[choice[i]][i] == board[choice[i]][i + 2]) {
				score += 10000;
			}
			if (board[choice[i]][i] == board[choice[i]][i - 1] && board[choice[i]][i] == board[choice[i]][i - 2]) {
				score += 10000;
			}
			if (board[choice[i]][i] == board[choice[i] +1][i + 1] && board[choice[i]][i] == board[choice[i] +2][i + 2]) {
				score += 10000;
			}
			if (board[choice[i]][i] == board[choice[i] -1][i + 1] && board[choice[i] -1][i] == board[choice[i]][i + 2]) {
				score += 10000;
			}
			if (board[choice[i]][i] == board[choice[i] + 1][i] && board[choice[i]][i] == board[choice[i] + 2][i]) {
				score += 10000;
			}
			if (board[choice[i]][i] == board[choice[i] - 1][i] && board[choice[i]][i] == board[choice[i] - 2][i]) {
				score += 10000;
			}
			if (board[choice[i]][i] == board[choice[i] + 1][i - 1] && board[choice[i]][i] == board[choice[i] + 2][i - 2]) {
				score += 10000;
			}
			if (board[choice[i]][i] == board[choice[i] - 1][i - 1] && board[choice[i]][i] == board[choice[i] - 2][i - 2]) {
				score += 10000;
			}
			if (board[choice[i]][i] == board[choice[i]][i + 1]) {
				score += 1000;
			}
			if (board[choice[i]][i] == board[choice[i]][i - 1]) {
				score += 1000;
			}
			if (board[choice[i]][i] == board[choice[i] + 1][i + 1]) {
				score += 1000;
			}
			if (board[choice[i]][i] == board[choice[i] - 1][i + 1]) {
				score += 1000;
			}
			if (board[choice[i]][i] == board[choice[i] + 1][i]) {
				score += 1000;
			}
			if (board[choice[i]][i] == board[choice[i] - 1][i]) {
				score += 1000;
			}
			if (board[choice[i]][i] == board[choice[i] + 1][i - 1]) {
				score += 1000;
			}
			if (board[choice[i]][i] == board[choice[i] - 1][i - 1]) {
				score += 1000;
			}
			board[choice[i]][i] = "X";
			if (board[choice[i]][i] == board[choice[i]][i + 1] && board[choice[i]][i] == board[choice[i]][i + 2]) {
				score += 10000;
			}
			if (board[choice[i]][i] == board[choice[i]][i - 1] && board[choice[i]][i] == board[choice[i]][i - 2]) {
				score += 10000;
			}
			if (board[choice[i]][i] == board[choice[i] + 1][i + 1] && board[choice[i]][i] == board[choice[i] + 2][i + 2]) {
				score += 10000;
			}
			if (board[choice[i]][i] == board[choice[i] - 1][i + 1] && board[choice[i] - 1][i] == board[choice[i]][i + 2]) {
				score += 10000;
			}
			if (board[choice[i]][i] == board[choice[i] + 1][i] && board[choice[i]][i] == board[choice[i] + 2][i]) {
				score += 10000;
			}
			if (board[choice[i]][i] == board[choice[i] - 1][i] && board[choice[i]][i] == board[choice[i] - 2][i]) {
				score += 10000;
			}
			if (board[choice[i]][i] == board[choice[i] + 1][i - 1] && board[choice[i]][i] == board[choice[i] + 2][i - 2]) {
				score += 10000;
			}
			if (board[choice[i]][i] == board[choice[i] - 1][i - 1] && board[choice[i]][i] == board[choice[i] - 2][i - 2]) {
				score += 10000;
			}
			if (board[choice[i]][i] == board[choice[i]][i + 1]) {
				score += 1000;
			}
			if (board[choice[i]][i] == board[choice[i]][i - 1]) {
				score += 1000;
			}
			if (board[choice[i]][i] == board[choice[i] + 1][i + 1]) {
				score += 1000;
			}
			if (board[choice[i]][i] == board[choice[i] - 1][i + 1]) {
				score += 1000;
			}
			if (board[choice[i]][i] == board[choice[i] + 1][i]) {
				score += 1000;
			}
			if (board[choice[i]][i] == board[choice[i] - 1][i]) {
				score += 1000;
			}
			if (board[choice[i]][i] == board[choice[i] + 1][i - 1]) {
				score += 1000;
			}
			if (board[choice[i]][i] == board[choice[i] - 1][i - 1]) {
				score += 1000;
			}
			board[choice[i]][i] = "*";
			if (score > temp) {
				deciC = i;
			}
			else {
				score = temp;
			}
		}
	}
	//board[choice[deciC]][deciC] = "O";
	//cout << choice[deciC] << "///" << deciC << endl;
	PlayChess(deciC, wP, r);
}
int main()
{
	bool gameOver = false;
	bool player1 = true;
	int i = 0, j = 0;
	int r = 0, c = 0;
	int wStreak = 4;
	int mode = 0;
	int drop = 0;
	int columnInput = 0;
	int aiMode = 0;
	while (true) {
		cout << "Please input the rows of the board(4 to 20): " << endl;
		cin >> r;
		if (cin.good() == 1) {
			if (r <= MAXSIZE && r >= 4) {
				break;
			}
		}
		else {
			cout << "Input an integer" << endl;
			cin.clear();
			cin.ignore();
		}
	}
	while (true) {
		cout << "Please input the columns of the board(4 to 20): " << endl;
		cin >> c;
		if (cin.good()) {
			if (c <= MAXSIZE && c >= 4) {
				break;
			}
		}
		else {
			cout << "Input an integer" << endl;
			cin.clear();
			cin.ignore();
		}
	}
	sum = r * c;
	while (true) {
		cout << "How many pieces in straight to win? (3 to 20): " << endl;
		cin >> wStreak;
		if(cin.good()){
			if (wStreak <= MAXSIZE && wStreak >= 3) {
				int tem = c;
				if (r > c) {
					tem = r;
				}
				if (wStreak <= tem) {
					break;
				}
				else {
					cout << "The number you input is too larger, try a new one" << endl;
				}
			}
		}
		else {
			cout << "Input an integer" << endl;
			cin.clear();
			cin.ignore();
		}
	}
	while (true) {
		cout << "Do you want to play wrap mode? Type 1 for yes" << endl;
		cin >> mode;
		if (cin.good()) {
			break;
		}
		else {
			mode = 0;
			cin.clear();
			cin.ignore();
			break;
		}
	}
	while (true) {
		cout << "Do you want to enable drop mode? Type 1 for yes" << endl;
		cin >> drop;
		if (cin.good()) {
			break;
		}
		else {
			drop = 0;
			cin.clear();
			cin.ignore();
			break;
		}
	}
	while (true) {
		cout << "Do you want to play against AI(this will automatically ban drop mode and win streak will be set to 4) Type 1 for yes" << endl;
		cin >> aiMode;
		if (cin.good()) {
			break;
		}
		else {
			aiMode = 0;
			cin.clear();
			cin.ignore();
			break;
		}
	}
	if (aiMode == 1) {
		drop = 0;
	}
	InitMatrix(r, c);
	PrintMatrix(r, c);
	while (!gameOver) {
		if (drop != 1) {
			if (aiMode == 1) {
				if (player1) {
					cout << "Player1 Please input which column you want to play: ";
					cin >> columnInput;
					while (true) {
						if (cin.good()) {
							if (columnInput <= c && columnInput > 0) {
								int a = columnInput - 1;
								if (board[0][a] != "*") {
									cout << "Please input a valid number (Current column is full): ";
									cin >> columnInput;
								}
								else {
									cout << "You want to play at column " << columnInput << endl;
									break;

								}
							}
							else {
								cout << "Please input a valid number (1 to " << c << "):";
								cin >> columnInput;
							}
						}
						else {
							cout << "Input an integer" << endl;
							cin.clear();
							cin.ignore();
						}
					}
					int m = PlayChess(columnInput - 1, player1, r);
					PrintMatrix(r, c);
					player1 = !player1;
				}
				if (!player1) {
					simpleAI(r, c, mode, player1);
					PrintMatrix(r, c);
					player1 = !player1;
				}
			}
			else {
				if (player1) {
					cout << "Player1 Please input which column you want to play: ";
					cin >> columnInput;
				}
				else {
					cout << "Player2 Please input which column you want to play: ";
					cin >> columnInput;
				}
				while (true) {
					if (cin.good()) {
						if (columnInput <= c && columnInput > 0) {
							int a = columnInput - 1;
							if (board[0][a] != "*") {
								cout << "Please input a valid number (Current column is full): ";
								cin >> columnInput;
							}
							else {
								cout << "You want to play at column " << columnInput << endl;
								break;

							}
						}
						else {
							cout << "Please input a valid number (1 to " << c << "):";
							cin >> columnInput;
						}
					}
					else {
						cout << "Input an integer" << endl;
						cin.clear();
						cin.ignore();
					}
				}
				int m = PlayChess(columnInput - 1, player1, r);
				PrintMatrix(r, c);
				player1 = !player1;
			}
		}
		if (drop == 1) {
			cout << "Do you want to play or withdraw a piece of chess? Type 1 for play, 2 for withdraw" << endl;
			int a = 1;
			cin >> a;
			while (true) {
				if (cin.good()) {
					if (a == 1) {
						break;
					}
					else if (a == 2) {
						if (player1) {
							int count = PieceCheck(r, c, "X");
							if (count > 0) {
								break;
							}
							else {
								cout << "You don't have any piece to withdraw, you need to play" << endl;
								a = 1;
							}
						}
						if (!player1) {
							int count = PieceCheck(r, c, "O");
							if (count > 0) {
								break;
							}
							else {
								cout << "You don't have any piece to withdraw, you need to play" << endl;
								a = 1;
							}
						}
					}
					else {
						cout << "Invalid input, please input again" << endl;
						cin >> a;
					}
				}
				else {
					cout << "Input an integer" << endl;
					cin.clear();
					cin.ignore();
				}
			}
			if (a == 2) {
				if (player1) {
					while (true) {
						cout << "Player1 Please input which column you want withdraw: ";
						cin >> columnInput;
						if (cin.good()) {
							if (board[r - 1][columnInput - 1] == "X") {
								break;
							}
							else {
								cout << "invalid Input, please input again: " << endl;
							}
						}
						else {
							cout << "Input an integer" << endl;
							cin.clear();
							cin.ignore();
						}
					}
				}
				if (!player1) {
					while (true) {
						cout << "Player2 Please input which column you want to withdraw: ";
						cin >> columnInput;
						if (cin.good()) {
							if (board[r - 1][columnInput - 1] == "O") {
								break;
							}
							else {
								cout << "invalid Input, please input again" << endl;
								cin >> columnInput;
							}
						}
						else {
							cout << "Input an integer" << endl;
							cin.clear();
							cin.ignore();
						}
					}
				}

				DropChess(r, columnInput - 1);
				PrintMatrix(r, c);
				player1 = !player1;
			}
			if (a == 1) {
				if (player1) {
					cout << "Player1 Please input which column you want to play: ";
					cin >> columnInput;
				}
				else {
					cout << "Player2 Please input which column you want to play: ";
					cin >> columnInput;
				}
				while (true) {
					if (cin.good()) {
						if (columnInput <= c && columnInput > 0) {
							int a = columnInput - 1;
							if (board[0][a] != "*") {
								cout << "Please input a valid number (Current column is full): ";
								cin >> columnInput;
							}
							else {
								cout << "You want to play at column " << columnInput << endl;
								break;

							}
						}
						else {
							cout << "Please input a valid number (1 to " << c << "):";
							cin >> columnInput;
						}
					}
					else {
						cout << "Input an integer" << endl;
						cin.clear();
						cin.ignore();
					}
				}
				int m = PlayChess(columnInput - 1, player1, r);
				PrintMatrix(r, c);
				player1 = !player1;
			}
		}
		if (mode != 1) {
			gameOver = cheackWin(r, c, wStreak - 1);
		}
		else if (mode == 1) {
			gameOver = cheackWrapWin(r, c, wStreak - 1);
		}
		if (sum == 0) {
			gameOver = true;
			cout << "It's a draw" << endl;
		}
		if (gameOver) {
			int answer = 0;
			if (winner1 == true && winner2 == true) {
				cout << "It's a draw" << endl;
			}
			else if (winner1 == true && winner2 == false) {
				cout << "Player 1 has won" << endl;
			}
			else if (winner1 == false && winner2 == true) {
				if (aiMode == 1) {
					cout << "You lose" << endl;
				}
				else {
					cout << "Player 2 has won" << endl;
				}
			}
			while (true) {
				cout << "Do you want to play again? Type 1:Yes  other:No " << endl;
				cin >> answer;
				if (cin.good()) {
					if (answer == 1) {
						gameOver = false;
						sum = r * c;
						InitMatrix(r, c);
						PrintMatrix(r, c);
						break;
					}
					else {
						break;
					}
				}
				else {
					cin.clear();
					cin.ignore();
					answer = 0;
					break;
				}
			}
		}
	}
	system("pause");
	return 0;
}
