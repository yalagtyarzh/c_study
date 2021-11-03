#include <iostream>

using namespace std;

//playing fields
string field3x3[9]{"#", "#", "#", "#", "#", "#", "#", "#", "#" };

string field4x4[16]{"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"};

string field5x5[25]{"#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#", "#"};

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

//variable for chosen field
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
		cout << "Incorrect color, returning standart first turn\n\n";
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

	cout << "The game is played on a grid. You are X, your friend (or the computer in this case) is O.\n";
	cout << "Players take turns putting their marks in empty squares. The first player to get 3 of her\n";
	cout << "marks in a row is the winner. When all squares are full the game is over. If no player has\n";
	cout << "3 marks in a row, the game ends in a tie.\n\n";

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

void handlePeopleGame(string field[]) {
	while (true) {

	}
}

void handleBotGame(string field[]) {
	while (true) {

	}
}


int main() {
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
								handlePeopleGame(field3x3);
							}
							case 2: {
								handlePeopleGame(field4x4);
							}
							case 3: {
								handlePeopleGame(field4x4);
							}
						}
					}
					else if (gameMenu == 2) {
							switch (chsField) {
							case 1: {
								handleBotGame(field3x3);
							}
							case 2: {
								handleBotGame(field4x4);
							}
							case 3: {
								handleBotGame(field4x4);
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
