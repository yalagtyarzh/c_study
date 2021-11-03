#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

//playing fields
string field3x3[9]{" 1 "," 2 "," 3 "," 4 "," 5 "," 6 "," 7 "," 8 "," 9 "};

string field4x4[16]{" 1 "," 2 "," 3 "," 4 "," 5 "," 6 "," 7 "," 8 "," 9 "," 10"," 11"," 12"," 13"," 14"," 15"," 16"};

string field5x5[25]{" 1 "," 2 "," 3 "," 4 "," 5 "," 6 "," 7 "," 8 "," 9 "," 10"," 11"," 12"," 13"," 14"," 15"," 16"," 17"," 18"," 19"," 20"," 21"," 22"," 23"," 24"," 25"};

//color codes
const string standart = "0";
const string lightGray = "89";
const string gray = "90";
const string red = "91";
const string green = "92";
const string yellow = "93";
const string darkBlue = "94";
const string violet = "95";
const string blue = "96";
const string white = "97";

//variable for choosen field
int chsField = 1;

//colors for X and O
string colorX = "0";
string colorO = "0";

//first turn symbol
string firstTurn = "X";

string selectFirstTurn(int chs) {
	switch (chs) {
	case 1:
		return "X";
	case 2:
		return "O";
	default:
		cin.clear();
		cin.ignore();
		cout << "Incorrect symbol, returning standart first turn\n\n";
		return "X";
	}
}

string selectColor(int chs) {
	switch (chs) {
	case 1:
		return standart;
	case 2:
		return lightGray;
	case 3:
		return gray;
	case 4:
		return red;
	case 5:
		return green;
	case 6:
		return yellow;
	case 7:
		return darkBlue;
	case 8:
		return violet;
	case 9:
		return blue;
	case 10:
		return white;
	default:
		cin.clear();
		cin.ignore();
		cout << "Incorrect color, returning standart color\n\n";
		return standart;
	}
}

void waitingForInput() {
	system("pause");
	cin.get();
}

void handleChosenColor() {
	system("cls");

	int chs;

	cout << "[+]Choosing color\n\n\x1b[0m[1]Standart\x1b[0m\n\x1b[89m[2]Light gray\x1b[0m\n\x1b[90m[3]Gray\x1b[0m\n";
	cout << "\x1b[91m[4]Red\x1b[0m\n\x1b[92m[5]Green\x1b[0m\n\x1b[93m[6]Yellow\x1b[0m\n\x1b[94m[7]Dark blue\x1b[0m\n";
	cout << "\x1b[95m[8]Violet\x1b[0m\n\x1b[96m[9]Blue\n\x1b[0m\x1b[97m[10]White\x1b[0m\n\n";

	cout << "Choose color for X: ";

	cin >> chs;
	colorX = selectColor(chs);

	cout << "\n\nChoose color for O: ";

	cin >> chs;
	colorO = selectColor(chs);

	waitingForInput();

	system("cls");
}

void handleChosenTurn() {
	system("cls");

	int chs;

	cout << "[+]Choosing first turn\n\n[1]X\n[2]O\n\nChoose first turn: ";

	cin >> chs;
	firstTurn = selectFirstTurn(chs);

	waitingForInput();

	system("cls");
}

void handleChosenField() {
	system("cls");

	cout << "[+]Choosing field size\n\n[1]3x3\n[2]4x4\n[3]5x5\n\nChoose field size: ";
	cin >> chsField;

	if (chsField < 1 || chsField > 3) {
		cin.clear();
		cin.ignore();
		cout << "Incorrect input, returning standart field size\n\n";
		chsField = 1;
	}

	waitingForInput();

	system("cls");
}

void handleRules() {
	system("cls");

	cout << "The game is played on a grid. Players take turns putting their marks in empty squares.\n";
	cout << " The first player to get 3 of her marks in a row is the winner. When all squares are full\n";
	cout << "the game is over. If no player has 3 marks in a row, the game ends in a tie.\n\n";

	waitingForInput();

	system("cls");
}

void handleExit() {
	cout << "\n\nBye bye!";
	exit(0);
}

void handleError() {
	cin.clear();
	cin.ignore();
	system("cls");
	cout << "BREAK ME COMPLETELY!!!\n\n";
}

string switchTurn(string turn) {
	if (turn == "X") {
		return "O";
	}
	else {
		return "X";
	}
}

void showField(string field[], int arrayLen) {
	int flagDelimeter = int(sqrt(arrayLen));

	for (int i = 0; i < arrayLen; i++) {
		if (field[i] == "X") {
			cout << "|\x1b[" << colorX << "m" << "  " << field[i]  << "\x1b[0m  ";
		}
		else if (field[i] == "O") {
			cout << "|\x1b[" << colorO << "m" << "  " << field[i] << "\x1b[0m  ";
		}
		else {
			cout << "| " << field[i] << "  ";
		}

		if ((i + 1) % flagDelimeter == 0) {
			cout << "|\n";
		}
	}
	cout << "\n\n";
}

bool checkWin3(string field[], int arrayLen) {
	if (field[0] == field[1] && field[1] == field[2])		return true;
	else if (field[3] == field[4] && field[4] == field[5])  return true;
	else if (field[6] == field[7] && field[7] == field[8])  return true;

	else if (field[0] == field[3] && field[3] == field[6])  return true;
	else if (field[1] == field[4] && field[4] == field[7])  return true;
	else if (field[2] == field[5] && field[5] == field[8])  return true;

	else if (field[0] == field[4] && field[4] == field[8])  return true;
	else if (field[2] == field[4] && field[4] == field[6])  return true;
	else return false;
}

bool checkWin4(string field[], int arrayLen) {
	if (field[0] == field[1] && field[1] == field[2]) return true;
	else if (field[1] == field[2] && field[2] == field[3]) return true;
	else if (field[4] == field[5] && field[5] == field[6]) return true;
	else if (field[5] == field[6] && field[6] == field[7]) return true;
	else if (field[8] == field[9] && field[9] == field[10]) return true;
	else if (field[9] == field[10] && field[10] == field[11]) return true;
	else if (field[12] == field[13] && field[13] == field[14]) return true;
	else if (field[13] == field[14] && field[14] == field[15]) return true;

	else if (field[0] == field[4] && field[4] == field[8]) return true;
	else if (field[4] == field[8] && field[8] == field[12]) return true;
	else if (field[1] == field[5] && field[5] == field[9]) return true;
	else if (field[5] == field[9] && field[9] == field[13]) return true;
	else if (field[2] == field[6] && field[6] == field[10]) return true;
	else if (field[6] == field[10] && field[10] == field[14]) return true;
	else if (field[3] == field[7] && field[7] == field[11]) return true;
	else if (field[7] == field[11] && field[11] == field[15]) return true;

	else if (field[0] == field[5] && field[5] == field[10]) return true;
	else if (field[5] == field[10] && field[10] == field[15]) return true;
	else if (field[3] == field[6] && field[6] == field[9]) return true;
	else if (field[6] == field[9] && field[9] == field[12]) return true;
	else if (field[1] == field[6] && field[6] == field[11]) return true;
	else if (field[4] == field[9] && field[9] == field[14]) return true;
	else return false;
}

bool checkWin5(string field[], int arrayLen) {

	if (field[0] == field[1] && field[1] == field[2]) return true;
	else if (field[1] == field[2] && field[2] == field[3]) return true;
	else if (field[2] == field[3] && field[3] == field[4]) return true;
	else if (field[5] == field[6] && field[6] == field[7]) return true;
	else if (field[6] == field[7] && field[7] == field[8]) return true;
	else if (field[7] == field[8] && field[8] == field[9]) return true;
	else if (field[10] == field[11] && field[11] == field[12]) return true;
	else if (field[11] == field[12] && field[12] == field[13]) return true;
	else if (field[12] == field[13] && field[13] == field[14]) return true;
	else if (field[15] == field[16] && field[16] == field[17]) return true;
	else if (field[16] == field[17] && field[17] == field[18]) return true;
	else if (field[17] == field[18] && field[18] == field[19]) return true;
	else if (field[20] == field[21] && field[21] == field[22]) return true;
	else if (field[21] == field[22] && field[22] == field[23]) return true;
	else if (field[22] == field[23] && field[23] == field[24]) return true;

	else if (field[0] == field[5] && field[5] == field[10]) return true;
	else if (field[5] == field[10] && field[10] == field[15]) return true;
	else if (field[10] == field[15] && field[15] == field[20]) return true;
	else if (field[1] == field[6] && field[6] == field[11]) return true;
	else if (field[6] == field[11] && field[11] == field[16]) return true;
	else if (field[11] == field[16] && field[16] == field[21]) return true;
	else if (field[2] == field[7] && field[7] == field[12]) return true;
	else if (field[7] == field[12] && field[12] == field[17]) return true;
	else if (field[12] == field[17] && field[17] == field[22]) return true;
	else if (field[3] == field[8] && field[8] == field[13]) return true;
	else if (field[8] == field[13] && field[13] == field[18]) return true;
	else if (field[13] == field[18] && field[18] == field[23]) return true;
	else if (field[4] == field[9] && field[9] == field[14]) return true;
	else if (field[9] == field[14] && field[14] == field[19]) return true;
	else if (field[14] == field[19] && field[19] == field[24]) return true;

	else if (field[0] == field[6] && field[6] == field[12]) return true;
	else if (field[1] == field[7] && field[7] == field[13]) return true;
	else if (field[2] == field[8] && field[8] == field[14]) return true;
	else if (field[5] == field[11] && field[1] == field[17]) return true;
	else if (field[6] == field[12] && field[12] == field[18]) return true;
	else if (field[7] == field[13] && field[13] == field[19]) return true;
	else if (field[10] == field[16] && field[16] == field[22]) return true;
	else if (field[11] == field[17] && field[17] == field[23]) return true;
	else if (field[12] == field[18] && field[18] == field[24]) return true;
	else if (field[2] == field[6] && field[6] == field[10]) return true;
	else if (field[3] == field[7] && field[7] == field[11]) return true;
	else if (field[4] == field[8] && field[8] == field[12]) return true;
	else if (field[7] == field[11] && field[11] == field[15]) return true;
	else if (field[8] == field[12] && field[12] == field[16]) return true;
	else if (field[9] == field[13] && field[13] == field[17]) return true;
	else if (field[10] == field[16] && field[16] == field[22]) return true;
	else if (field[11] == field[17] && field[17] == field[23]) return true;
	else if (field[12] == field[18] && field[18] == field[24]) return true;
	else if (field[12] == field[16] && field[16] == field[20]) return true;
	else if (field[13] == field[17] && field[17] == field[21]) return true;
	else if (field[14] == field[18] && field[18] == field[22]) return true;
	else return false;
}


void handlePeopleGame(string field[], int arrayLen) {
	int fullCheck = 0;
	string turn = firstTurn;
	int cell;

	bool isWinnerKnown = false;

	while (!isWinnerKnown) {
		system("cls");

		showField(field, arrayLen);

		cout << "The player playing for the " << turn << " selects the cell: ";
		cin >> cell;
		cell--;
		if (cell < 0 || cell > arrayLen - 1 || field[cell] == "X" || field[cell] == "O") {
			cin.clear();
			cin.ignore();
			cout << "Incorrect value, try again\n\n";
			waitingForInput();
		}
		else {
			field[cell] = turn;
			switch (chsField) {
			case 1:
				isWinnerKnown = checkWin3(field, arrayLen);
				break;
			case 2:
				isWinnerKnown = checkWin4(field, arrayLen);
				break;
			case 3:
				isWinnerKnown = checkWin5(field, arrayLen);
				break;
			}
			fullCheck++;
			if (isWinnerKnown) {
				system("cls");

				showField(field, arrayLen);

				cout << "The player " << turn << " wins!\n";
				waitingForInput();
				exit(0);
			}
			if (fullCheck == arrayLen) {
				system("cls");

				showField(field, arrayLen);

				cout << "Draw!\n";
				waitingForInput();
				exit(0);
			}
			turn = switchTurn(turn);
		}
	}
}

void handleBotGame(string field[], int arrayLen) {
	int fullCheck = 0;
	string turn = firstTurn;
	int cell;
	int botTurn;

	bool isWinnerKnown = false;

	while (!isWinnerKnown) {
		if (turn == firstTurn) {
			system("cls");

			showField(field, arrayLen);

			cout << "The player playing for the " << turn << " selects the cell: ";
			cin >> cell;
			cell--;
			if (cell < 0 || cell > arrayLen - 1 || field[cell] == "X" || field[cell] == "O") {
				cin.clear();
				cin.ignore();
				cout << "Incorrect value, try again\n\n";
				waitingForInput();
			}
			else {
				field[cell] = turn;
				switch (chsField) {
				case 1:
					isWinnerKnown = checkWin3(field, arrayLen);
					break;
				case 2:
					isWinnerKnown = checkWin4(field, arrayLen);
					break;
				case 3:
					isWinnerKnown = checkWin5(field, arrayLen);
					break;
				}
				fullCheck++;
				if (isWinnerKnown) {
					system("cls");

					showField(field, arrayLen);

					cout << "The player " << turn << " wins!\n";
					waitingForInput();
					exit(0);
				}
				if (fullCheck == arrayLen) {
					system("cls");

					showField(field, arrayLen);

					cout << "Draw!\n";
					waitingForInput();
					exit(0);
				}
				turn = switchTurn(turn);
			}
		}
		else {
			while (true) {
				botTurn = rand() % arrayLen;
				botTurn--;
				if (botTurn < 0 || botTurn > arrayLen - 1 || field[botTurn] == "X" || field[botTurn] == "O")
				{
					system("cls");
					continue;
				}
				else {
					field[botTurn] = turn;
					break;
				}
			}
			switch (chsField) {
			case 1:
				isWinnerKnown = checkWin3(field, arrayLen);
				break;
			case 2:
				isWinnerKnown = checkWin4(field, arrayLen);
				break;
			case 3:
				isWinnerKnown = checkWin5(field, arrayLen);
				break;
			}
			fullCheck++;
			if (isWinnerKnown) {
				system("cls");

				showField(field, arrayLen);

				cout << "The player " << turn << " wins!\n";
				waitingForInput();
				exit(0);
			}
			if (fullCheck == arrayLen) {
				system("cls");

				showField(field, arrayLen);

				cout << "Draw!\n";
				waitingForInput();
				exit(0);
			}
			turn = switchTurn(turn);
		}
	}
}

int main() {
	srand(static_cast<unsigned int>(time(0)));
	int mainMenu;
	
	while (true) {
		cout << "[+]Tic-tac-toe\n\n[1]Start\n[2]Options\n[3]Rules\n[4]Exit\n\n[-]Choose action: ";
		cin >> mainMenu;

		switch (mainMenu)
		{
			case 1: {
				system("cls");

				int gameMenu;

				while (true) {
					cout << "[+]Start the game\n\n[1]PvP\n[2]PvE\n[3]Exit\n\n[-]Choose action: ";

					cin >> gameMenu;

					if (gameMenu == 1) {
						switch (chsField) {
							case 1: {
								int arrayLen = sizeof(field3x3) / sizeof(field3x3[0]);
								handlePeopleGame(field3x3, arrayLen);
							}
							case 2: {
								int arrayLen = sizeof(field4x4) / sizeof(field4x4[0]);
								handlePeopleGame(field4x4, arrayLen);
							}
							case 3: {
								int arrayLen = sizeof(field5x5) / sizeof(field5x5[0]);
								handlePeopleGame(field5x5, arrayLen);
							}
						}
					}
					else if (gameMenu == 2) {
						switch (chsField) {
							case 1: {
								int arrayLen = sizeof(field3x3) / sizeof(field3x3[0]);
								handleBotGame(field3x3, arrayLen);
							}
							case 2: {
								int arrayLen = sizeof(field4x4) / sizeof(field4x4[0]);
								handleBotGame(field4x4, arrayLen);
							}
							case 3: {
								int arrayLen = sizeof(field5x5) / sizeof(field5x5[0]);
								handleBotGame(field5x5, arrayLen);
							}
						}
					}
					else if (gameMenu == 3) {
						system("cls");
						break;
					}
					else {
						handleError();
					}
				}
				break;
			}
			case 2: {
				system("cls");

				int optionMenu;

				while (true) {
					cout << "[+]Options\n\n[1]Color\n[2]First turn\n[3]Field size\n[4]Exit\n\n[-]Choose action: ";

					cin >> optionMenu;

					if (optionMenu == 1) {
						handleChosenColor();
					}
					else if (optionMenu == 2) {

						handleChosenTurn();
					} 
					else if (optionMenu == 3) {
						handleChosenField();
					}
					else if (optionMenu == 4) {
						system("cls");
						break;
					}
					else {
						handleError();
					}
				}
				break;
			}
			case 3: {			
				handleRules();
				break;
			}
			case 4: {	
				handleExit();
			}
			default: {
				handleError();
			}
		}
	}
}



