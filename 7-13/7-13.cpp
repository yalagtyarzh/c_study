#include <iostream>

using namespace std;

//Данная программа предназначена для вывода фигуры, параметры которой задает пользователь
int main()
{
	setlocale(0, "");
	int menu;

	while (true) {
		cout << "[+]Геометрические фигуры\n\n[+]Выберите фигуру:\n\n[1]Линия\n[2]Квадрат\n";
		cout << "[3]Прямоугольник\n[4]Треугольник\n[5]Решетка\n[6]Крестик\n[7]Плюс\n[8]Выход\n\n[-]Выберите действие : ";
		cin >> menu;

		if (menu < 1 || menu > 8) {
			cin.clear();
			cin.ignore();
			cout << "ЛОМАЙ МЕНЯ ПОЛНОСТЬЮ!\n\n";
		}
		else {
			break;
		}
	}

	char texture;

	system("cls");

	switch (menu)
	{
		case 1: {

			int size;
			int dimension;

			cout << "[+]Фигура \"линия\"";

			while (true) {
				cout << "Укажите направление линии\n\n[1]Горизонтальная\n[2]Вертикальная\n\nНаправление линии: ";
				cin >> dimension;

				if (dimension != 1 && dimension != 2) {
					cin.clear();
					cin.ignore();
					cout << "\nМолодец, сломал программу, красава, давай по новой\n\n";
				}
				else {
					break;
				}
			}

			while (true) {
				cout << "Укажите размер линии\n\nРазмер линии: ";
				cin >> size;

				if (size < 1) {
					cin.clear();
					cin.ignore();
					cout << "\nЛови ошибку в лицо, некорректные размеры он тут пишет...\n\n";
				}
				else {
					break;
				}
			}

			cout << "\nУкажите текстуру линии\n\nТекстура линии: ";
			cin >> texture;

			system("cls");

			switch (dimension)
			{
				case 1: {
					for (int i = 0; i < size; i++)
					{
						cout << texture << " ";
					}
					break;
				}

				case 2: {
					for (int i = 0; i < size; i++)
					{
						cout << texture << " \n";
					}
					break;
				}
			}
			break;
		}

		case 2: {
			int size;

			cout << "[+]Фигура \"квадрат\"";

			while (true) {
				cout << "Укажите размер квадрата.\n\nРазмер квадрата: ";
				cin >> size;

				if (size < 1) {
					cin.clear();
					cin.ignore();
					cout << "\nЛови ошибку в лицо, некорректные размеры он тут пишет...\n\n";
				}
				else {
					break;
				}
			}

			cout << "\nУкажите текстуру квадрата.\n\nТекстура квадрата: ";
			cin >> texture;

			int isFull;

			while (true) {
				cout << "\nПолный ли квадрат?\n\n[1]Да\n[2]Нет\n\nВвод: ";
				cin >> isFull;

				if (isFull < 1 || isFull > 2) {
					cin.clear();
					cin.ignore();
					cout << "ЛОМАЙ МЕНЯ ПОЛНОСТЬЮ!\n\n";
				}
				else {
					break;
				}
			}

			system("cls");

			switch (isFull) {
				case 1: {
					for (int i = 0; i < size; i++) {
						for (int j = 0; j < size; j++) {
							cout << texture << " ";
						}
						cout << "\n";
					}
					break;
				}

				case 2: {
					for (int i = 0; i < size; i++) {
						for (int j = 0; j < size; j++) {
							if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
								cout << texture << " ";
							}
							else {
								cout << "  ";
							}
						}
						cout << "\n";
					}
					break;
				}
			}
			break;
		}

		case 3: {
			cout << "[+]Фигура \"прямоугольник\"";

			int xSize;
			int ySize;

			while (true) {
				cout << "Укажите размеры прямоугольник через пробел.\n\nРазмер прямоугольника: ";
				cin >> xSize;
				cin >> ySize;

				if (xSize < 1 || ySize < 1) {
					cin.clear();
					cin.ignore();
					cout << "\nЛови ошибку в лицо, некорректные размеры он тут пишет...\n\n";
				}
				else {
					break;
				}
			}

			cout << "\nУкажите текстуру прямоугольника\n\nТекстура прямоугольника: ";
			cin >> texture;

			int isFull;

			while (true) {
				cout << "\nПолный ли прямоугольник?\n\n[1]Да\n[2]Нет\n\nВвод: ";
				cin >> isFull;
				if (isFull < 1 || isFull > 2) {
					cin.clear();
					cin.ignore();
					cout << "ЛОМАЙ МЕНЯ ПОЛНОСТЬЮ!\n\n";
				}
				else {
					break;
				}
			}

			system("cls");

			switch (isFull) {
				case 1: {	
					for (int i = 0; i < ySize; i++) {
						for (int j = 0; j < xSize; j++) {
							cout << texture << " ";
						}
						cout << "\n";
					}
					break;
				}
	
				case 2: {
					for (int i = 0; i < ySize; i++) {
						for (int j = 0; j < xSize; j++) {
							if (i == 0 || i == ySize - 1 || j == 0 || j == xSize - 1) {
								cout << texture << " ";
							}
							else {
								cout << "  ";
							}
						}
						cout << "\n";
					}
					break;
				}
			}
			break;
		}

		case 4: {
			int height;

			cout << "[+]Фигура \"треугольник\"";

			while (true) {
				cout << "Укажите высоту треугольника.\n\nВысота треугольника: ";
				cin >> height;
				if (height < 1) {
					cin.clear();
					cin.ignore();
					cout << "\nЛови ошибку в лицо, некорректные размеры он тут пишет...\n\n";
				}
				else {
					break;
				}
			}

			int size = 2 * (height - 1) + 1;

			cout << "\nУкажите текстуру треугольника\n\nТекстура треугольника: ";
			cin >> texture;

			int isFull;

			while (true) {
				cout << "\nПолный ли треугольник?\n\n[1]Да\n[2]Нет\n\nВвод: ";
				cin >> isFull;
				if (isFull < 1 || isFull > 2) {
					cin.clear();
					cin.ignore();
					cout << "ЛОМАЙ МЕНЯ ПОЛНОСТЬЮ!\n\n";
				}
				else {
					break;
				}
			}

			system("cls");

			switch (isFull) {
				case 1: {
					for (int i = 1; i <= height; i++) {
						for (int j = 0; j < size; j++) {
							if (j <= size / 2 - i || j >= size / 2 + i) {
								cout << "  ";
							}
							else {
								cout << texture << " ";
							}
						}
						cout << "\n";
					}
					break;
				}

				case 2: {
					for (int i = 0; i < height; i++) {
						for (int j = 0; j < size; j++) {
							if (j == size / 2 - i || j == size / 2 + i || i == height - 1) {
								cout << texture << " ";
							}
							else {
								cout << "  ";
							}
						}
						cout << "\n";
					}
					break;
				}
			}
			break;
		}
		case 5: {
			int size;

			cout << "[+]Фигура \"решетка\"";

			while (true) {
				cout << "Укажите НЕЧЕТНЫЙ размер решетки.\n\nРазмер решетки: ";
				cin >> size;

				if (size < 1 || size % 2 == 0) {
					cin.clear();
					cin.ignore();
					cout << "\nЛови ошибку в лицо, некорректные размеры он тут пишет...\n\n";
				}
				else {
					break;
				}
			}

			cout << "\nУкажите текстуру решетки.\n\nТекстура квадрата: ";
			cin >> texture;

			system("cls");

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (i % 2 == 1 || j % 2 == 1) {
						cout << texture << " ";
					}
					else {
						cout << "  ";
					}
				}
				cout << "\n";
			}

			break;

		}
		case 6: {
			int size;

			cout << "[+]Фигура \"крестик\"";

			while (true) {
				cout << "Укажите размер крестика.\n\nРазмер крестика: ";
				cin >> size;

				if (size < 1) {
					cin.clear();
					cin.ignore();
					cout << "\nЛови ошибку в лицо, некорректные размеры он тут пишет...\n\n";
				}
				else {
					break;
				}
			}

			cout << "\nУкажите текстуру крестика.\n\nТекстура крестика: ";
			cin >> texture;

			system("cls");

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (i == j || size  - 1 - j == i) {
						cout << texture << " ";
					}
					else {
						cout << "  ";
					}
				}
				cout << "\n";
			}
			break;
		}
		case 7: {
			int size;

			cout << "[+]Фигура \"плюс\"";

			while (true) {
				cout << "Укажите НЕЧЕТНЫЙ размер плюса.\n\nРазмер плюса: ";
				cin >> size;

				if (size < 1 || size % 2 == 0) {
					cin.clear();
					cin.ignore();
					cout << "\nЛови ошибку в лицо, некорректные размеры он тут пишет...\n\n";
				}
				else {
					break;
				}
			}

			cout << "\nУкажите текстуру плюса.\n\nТекстура плюса: ";
			cin >> texture;

			system("cls");

			for (int i = 0; i < size; i++) {
				for (int j = 0; j < size; j++) {
					if (size / 2 == i || size / 2 == j) {
						cout << texture << " ";
					}
					else {
						cout << "  ";
					}
				}
				cout << "\n";
			}
			break;
		}
		case 8: {
			cout << "Ня, пока!";
			break;
		}
	}
}