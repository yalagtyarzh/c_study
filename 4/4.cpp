#include <iostream>
using namespace std;
int main() {
	setlocale(0, "");

	int number;
	cout << "[+] Месяца года\n[1]Январь\n[2]Февраль\n[3]Март\n[4]Апрель\n[5]Май\n[6]Июнь\n";
	cout << "[7]Июль\n[8]Август\n[9]Сентябрь\n[10]Октябрь\n[11]Ноябрь\n[12]Декабрь\n";
	cout << "Ввеkите значение:";
	cin >> number;

	switch (number) {
	case 1:
		cout << "Январь? Хороший выбор";
		break;
	case 2:
		cout << "Февраль? сочуствую...";
		break;
	case 3:
		cout << "Март? котики красивые, да";
		break;
	case 4 :
		cout << "Апрель весёлый месяц, да";
		break;
	case 5:
		cout << "Май тоже месяц хороший, да";
		break;
	case 6:
		cout << "Июнь, жарунь, угунь";
		break;
	case 7:
		cout << "Июль, без комментариев...";
		break;
	case 8:
		cout << "Август, ялта, в этом мире только мы одни";
		break;
	case 9:
		cout << "Сентябрь , учёба вот эта вот ваша да";
		break;
	case 10:
		cout << "Октябрь - выбор настоящего гурмана";
		break;
	case 11:
		cout << "Ноябрь - ну ни чё такой месяц, как бы да";
		break;
	case 12:
		cout << "Декабрь - ...";
		break;
	default:
		cout << "тебе же сказали, от 1 до 12, цыфры в школе не учил?";
	}

	return 0;
}