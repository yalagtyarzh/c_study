﻿

#include <iostream>

using namespace std;

int main()
{
	setlocale(0, "");
	int menu = 0;

	while (true) {
		cout << "[+]Лабиринты\n\n[+]Выберите размер лабиринта:\n\n[1]15x15\n[2]20x20\n[3]30x30\n[4]Выход\n\n[-]Выберите действие : ";
		cin >> menu;

		if (menu < 1 || menu > 4) {
			cin.clear();
			cin.ignore();
			cout << "ЛОМАЙ МЕНЯ ПОЛНОСТЬЮ!\n\n";
		}
		else {
			break;
		}
	}

	switch (menu) {
		case 1: {
			int const SIZEX = 15;
			int const SIZEY = 15;
			int arr[SIZEY][SIZEY]{
				{1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
				{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1},
				{1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1},
				{1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
				{1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
				{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
				{1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
				{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1},
				{1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1},
				{1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1},
				{1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1},
				{1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1},
				{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
				{1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1},
			};
			for (int i = 0; i < SIZEY; i++) {
				for (int j = 0; j < SIZEX; j++) {
					if (arr[i][j] == 1) {
						cout << "# ";
					}
					else {
						cout << "  ";
					}
				}
				cout << "\n";
			}
			break;
		}
		case 2: {
			int const SIZEX = 20;
			int const SIZEY = 20;
			int arr[SIZEY][SIZEY]{
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
				{1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
				{1, 0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1},
				{1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1},
				{1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1},
				{1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
				{1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1},
				{1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1},
				{1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1},
				{1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1},
				{1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1},
				{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1},
				{1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1},
				{1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1},
				{1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1},
				{1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1},
				{1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1},
				{1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1},
				{1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1},
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
			};
			for (int i = 0; i < SIZEY; i++) {
				for (int j = 0; j < SIZEX; j++) {
					if (arr[i][j] == 1) {
						cout << "# ";
					}
					else {
						cout << "  ";
					}
				}
				cout << "\n";
			}
			break;
		}
		case 3: {
			int const SIZEX = 30;
			int const SIZEY = 30;
			int arr[SIZEY][SIZEY]{
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,0,0,0,0,0,0,0,0,0,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,0,0,1,1,1,0,1,1,1,0,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,1,0,1},
				{1,1,1,1,1,1,1,1,0,0,0,0,0,1,1,0,1,0,0,0,0,0,1,1,1,1,1,1,0,1},
				{1,1,1,1,1,1,1,1,0,1,1,1,0,0,0,0,1,0,1,1,1,0,1,0,0,0,0,0,0,1},
				{1,1,1,0,0,0,0,0,0,1,0,1,1,1,1,0,1,0,0,1,1,0,1,0,1,1,1,1,1,1},
				{1,1,1,0,1,1,1,1,1,1,0,0,0,0,0,0,1,1,0,1,1,0,1,0,1,1,1,1,0,1},
				{1,1,1,0,0,1,1,0,0,0,0,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,1,0,1},
				{1,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,0,0,1,1,1,1,1,1,1,1,0,1,0,1},
				{1,1,1,1,0,0,1,0,0,0,0,0,0,1,1,1,0,1,1,1,1,1,1,0,1,1,0,1,0,1},
				{1,1,1,1,1,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,0,0,0,1,1,0,0,0,1},
				{1,1,1,1,1,0,1,1,1,1,0,1,0,0,0,0,0,1,1,0,0,0,1,1,1,1,1,1,0,1},
				{1,1,0,0,0,0,0,0,0,1,0,0,0,1,1,1,1,1,1,0,1,0,0,0,0,0,1,1,0,1},
				{1,1,0,1,1,1,1,1,0,1,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,1},
				{1,1,0,0,0,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
				{1,1,0,1,1,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1},
				{1,1,0,1,1,1,1,1,1,1,1,0,1,0,1,0,1,1,0,1,1,1,1,1,1,1,1,0,1,1},
				{1,1,0,1,0,0,0,0,0,0,1,0,1,0,1,0,1,1,0,1,0,0,0,1,1,1,1,0,1,1},
				{1,1,0,1,0,1,1,1,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,0,0,0,1,1},
				{1,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,1,1,1,1},
				{1,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,1,1,1,1},
				{1,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,1,1,1,1},
				{1,1,0,1,0,1,1,0,1,0,1,0,1,0,1,0,1,1,0,1,0,1,0,1,0,1,1,1,1,1},
				{1,1,0,1,0,1,1,0,1,0,1,0,1,1,1,0,1,1,0,1,0,1,0,1,0,1,0,0,0,1},
				{1,1,0,1,0,1,1,0,1,0,1,0,0,0,0,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1},
				{1,1,0,1,0,0,0,0,1,0,1,1,1,1,1,1,1,1,0,1,1,1,0,1,0,1,0,1,0,1},
				{1,1,0,1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,1,0,1},
				{1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
				{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0},

			};
			for (int i = 0; i < SIZEY; i++) {
				for (int j = 0; j < SIZEX; j++) {
					if (arr[i][j] == 1) {
						cout << "# ";
					}
					else {
						cout << "  ";
					}
				}
				cout << "\n";
			}
		}
		case 4: {
			cout << "Ня, пока!";
			break;
		}
	}
}
