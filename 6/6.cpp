#include <iostream>

using namespace std;

int main()
{
    setlocale(0, "");
    cout << "[+]Календарь\n\n[1]Январь\n[2]Февраль\n[3]Март\n[4]Апрель\n[5]Май\n[6]Июнь\n";
    cout << "[7]Июль\n[8]Август\n[9]Сентябрь\n[10]Октябрь\n[11]Ноябрь\n[12]Декабрь\n\n";
    cout << "[+]Выберите месяц: ";
    string monthName;
    int chsenMonth, chsenNum; cin >> chsenMonth;
    cout << "\n";
    system("cls");

    switch (chsenMonth) {
    case 1:
        monthName = "Января";
        cout << "Выбран месяц: \"Январь\"\nВведите день месяца: ";
        break;
    case 2:
        monthName = "Февраля";
        cout << "Выбран месяц: \"Февраль\"\nВведите день месяца: ";
        break;
    case 3:
        monthName = "Марта";
        cout << "Выбран месяц: \"Март\"\nВведите день месяца: ";
        break;
    case 4:
        monthName = "Апреля";
        cout << "Выбран месяц: \"Апрель\"\nВведите день месяца: ";
        break;
    case 5:
        monthName = "Мая";
        cout << "Выбран месяц: \"Май\"\nВведите день месяца: ";
        break;
    case 6:
        monthName = "Июня";
        cout << "Выбран месяц: \"Июнь\"\nВведите день месяца: ";
        break;
    case 7:
        monthName = "Июля";
        cout << "Выбран месяц: \"Июль\"\nВведите день месяца: ";
    case 8:
        monthName = "Августа";
        cout << "Выбран месяц: \"Август\"\nВведите день месяца: ";
        break;
    case 9:
        monthName = "Сентября";
        cout << "Выбран месяц: \"Сентябрь\"\nВведите день месяца: ";
        break;
    case 10:
        monthName = "Октября";
        cout << "Выбран месяц: \"Октябрь\"\nВведите день месяца: ";
        break;
    case 11:
        monthName = "Ноября";
        cout << "Выбран месяц: \"Ноябрь\"\nВведите день месяца: ";
        break;
    case 12:
        monthName = "Декабря";
        cout << "Выбран месяц: \"Декабрь\"\nВведите день месяца: ";
        break;
    default:
        cout << "По циферкам меньше промахиваться надо, давай по новой, нажимай Enter\n\n";
        exit(1);
        break;
    }

    cin >> chsenNum;
    cout << "\n";

    switch (chsenMonth) {
    case 4:
    case 6:
    case 9:
    case 11:

        switch (chsenNum) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
            cout << "\nКалендарь: " << chsenNum << " " << monthName;
            break;
        default:
            cout << "Некорретное значение для данного месяца";
            break;
        }
        break;
    case 2:
        switch (chsenNum) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
            cout << "\nКалендарь: " << chsenNum << " " << monthName;
            break;
        default:
            cout << "Некорретное значение для данного месяца";
            break;
        }
        break;
    default:
        switch (chsenNum) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
        case 27:
        case 28:
        case 29:
        case 30:
        case 31:
            cout << "\nКалендарь: " << chsenNum << " " << monthName;
            break;
        default:
            cout << "Некорретное значение для данного месяца";
            break;
        }
        break;
    }
}