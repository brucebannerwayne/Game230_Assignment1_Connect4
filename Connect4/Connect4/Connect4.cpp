
#include <iostream>
#include <string>

using namespace std;
const int MAXSIZE = 100;
int sum = 0;
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
		cout << j + 1 << " ";
	}
	cout << endl;
	for (int i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			cout << board[i][j] << " ";
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
}
bool cheackWin(int r, int c, int ws) {
	int i, j = 0;
	bool hW = true, vW = true, dW1 = true, dW2 = true;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			if (board[i][j] != "*") {
				for (int a = 1; a <= ws; a++) {
					if (board[i][j] != board[i + a][j]) {
						vW = false;
					}
				}
				if (vW == true) {
					if (board[i][j] == "X") {
						cout << "Player 1 has won" << endl;
					}
					else if (board[i][j] == "O") {
						cout << "Player 2 has won" << endl;
					}
					return true;
					break;
				}
				vW = true;
				for (int a = 1; a <= ws; a++) {
					if (board[i][j] != board[i][j + a]) {
						hW = false;
					}
				}
				if (hW == true) {
					if (board[i][j] == "X") {
						cout << "Player 1 has won" << endl;
					}
					else if (board[i][j] == "O") {
						cout << "Player 2 has won" << endl;
					}
					return true;
					break;
				}
				hW = true;
				for (int a = 1; a <= ws; a++) {
					if (board[i][j] != board[i + a][j + a]) {
						dW1 = false;
					}
				}
				if (dW1 == true) {
					if (board[i][j] == "X") {
						cout << "Player 1 has won" << endl;
					}
					else if (board[i][j] == "O") {
						cout << "Player 2 has won" << endl;
					}
					return true;
					break;
				}
				dW1 = true;
				for (int a = 1; a <= ws; a++) {
					if (board[i][j] != board[i - a][j + a]) {
						dW2 = false;
					}
				}
				if (dW2 == true) {
					if (board[i][j] == "X") {
						cout << "Player 1 has won" << endl;
					}
					else if (board[i][j] == "O") {
						cout << "Player 2 has won" << endl;
					}
					return true;
					break;
				}
				dW2 = true;
			}
		}
	}
	return false;
}

bool cheackWrapWin(int r, int c, int ws) {
	int i, j = 0;
	bool hW = true, vW = true, dW1 = true, dW2 = true;
	for (i = 0; i < r; i++) {
		for (j = 0; j < c; j++) {
			if (board[i][j] != "*") {
				for (int a = 1; a <= ws; a++) {
					if (board[i][j] != board[(i + a) % r][j]) {
						vW = false;
					}
				}
				if (vW == true) {
					if (board[i][j] == "X") {
						cout << "Player 1 has won" << endl;
					}
					else if (board[i][j] == "O") {
						cout << "Player 2 has won" << endl;
					}
					return true;
					break;
				}
				vW = true;
				for (int a = 1; a <= ws; a++) {
					if (board[i][j] != board[i][(j + a) % c]) {
						hW = false;
					}
				}
				if (hW == true) {
					if (board[i][j] == "X") {
						cout << "Player 1 has won" << endl;
					}
					else if (board[i][j] == "O") {
						cout << "Player 2 has won" << endl;
					}
					return true;
					break;
				}
				hW = true;
				for (int a = 1; a <= ws; a++) {
					if (board[i][j] != board[i + a][j + a]) {
						dW1 = false;
					}
				}
				if (dW1 == true) {
					if (board[i][j] == "X") {
						cout << "Player 1 has won" << endl;
					}
					else if (board[i][j] == "O") {
						cout << "Player 2 has won" << endl;
					}
					return true;
					break;
				}
				dW1 = true;
				for (int a = 1; a <= ws; a++) {
					if (board[i][j] != board[i - a][j + a]) {
						dW2 = false;
					}
				}
				if (dW2 == true) {
					if (board[i][j] == "X") {
						cout << "Player 1 has won" << endl;
					}
					else if (board[i][j] == "O") {
						cout << "Player 2 has won" << endl;
					}
					return true;
					break;
				}
				dW2 = true;
			}
		}
	}
	return false;
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
	while (true) {
		cout << "Please input the rows of the board(0 to 100): " << endl;
		cin >> r;
		if (r <= MAXSIZE && r >= 0) {
			break;
		}
	}
	while (true) {
		cout << "Please input the columns of the board(0 to 100): " << endl;
		cin >> c;
		if (c <= MAXSIZE && c >= 0) {
			break;
		}
	}
	sum = r * c;
	while (true) {
		cout << "How many pieces in straight to win? (0 to 100): " << endl;
		cin >> wStreak;
		if (c <= MAXSIZE && c >= 0) {
			break;
		}
	}
	cout << "Do you want to play wrap mode? Type 1 for yes" << endl;
	cin >> mode;
	cout << "Do you want to enable drop mode? Type 1 for yes" << endl;
	cin >> drop;
	InitMatrix(r, c);
	PrintMatrix(r, c);
	while (!gameOver) {
		
		if (player1) {
			cout << "Player1 Please input which column you want to play: ";
			cin >> columnInput;
		}
		else {
			cout << "Player2 Please input which column you want to play: ";
			cin >> columnInput;
		}
		while (true) {
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
		int m = PlayChess(columnInput - 1, player1, r);
		PrintMatrix(r, c);
		player1 = !player1;
		if (mode != 1) {
			gameOver = cheackWin(r, c, wStreak - 1);
		}
		else if (mode == 1){
			gameOver = cheackWrapWin(r, c, wStreak - 1);
		}
		if (sum == 0) {
			gameOver = true;
			cout << "It's a draw" << endl;
		}
		if (gameOver) {
			int answer = 0;
			cout << "Do you want to play again? Type 1:Yes  other:No " << endl;
			cin >> answer;
			if (answer == 1) {
				gameOver = false;
				InitMatrix(r, c);
				PrintMatrix(r, c);
			}
		}
	}
	system("pause");
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
