// Five.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
int main()
{
    setlocale(0, "");
    cout << "[+]Переводчик\n\n[1]Русские слова\n[2]Английские слова\n\n[3]Выйти\n";
    int choice;
    cin >> choice;
    switch (choice)
    {

    case 1:
        system("cls");
        cout << "Переводчик \"Список русских слов\"\n\n[1]Дом\n[2]Дорога\n[3]Есть\n[4]Табуретка\n";
        cout << "[5]Сыр\n[6]Приложение\n[7]Наушники\n[8]Клавиатура\n[9]Лягушка\n[10]Цель\n[11]Танцевать\n";
        cout << "[12]Казахский\n[13]Облако\n[14]Тигр\n[15]Короткий\n\n";
        cout << "Выберите номер слова: ";
        int rusWord;
        cin >> rusWord;
        switch (rusWord)
        {

        case 1:
            cout << "Дом -> House";
            break;
        case 2:
            cout << "Дорога -> Road";
            break;
        case 3:
            cout << "Есть -> Eat";
            break;
        case 4:
            cout << "Табуретка -> Stool";
            break;
        case 5:
            cout << "Сыр -> Cheese";
            break;
        case 6:
            cout << "Приложение -> Application";
            break;
        case 7:
            cout << "Наушники -> Headphones";
            break;
        case 8:
            cout << "Клавиатура -> Keyboard";
            break;
        case 9:
            cout << "Лягушка -> Frog";
            break;
        case 10:
            cout << "Цель -> Target";
            break;
        case 11:
            cout << "Танцевать -> Dance";
            break;
        case 12:
            cout << "Казахский -> Kazakh";
            break;
        case 13:
            cout << "Облако -> Cloud";
            break;
        case 14:
            cout << "Тигр -> Tiger";
            break;
        case 15:
            cout << "Короткий -> Short";
            break;
        default:
            cout << "Вы ввели неверный номер";
            break;
        }
        break;

    case 2:
        system("cls");
        cout << "Переводчик \"Список английских слов\"\n\n[1]House\n[2]Road\n[3]Eat\n[4]Stool\n";
        cout << "[5]Cheese\n[6]Application\n[7]Headphones\n[8]Keyboard\n[9]Frog\n[10]Target\n[11]Dance\n";
        cout << "[12]Kazakh\n[13]Cloud\n[14]Tiger\n[15]Short\n\n";
        cout << "Выберите номер слова: ";
        int engWord;
        cin >> engWord;
        switch (engWord)
        {
        case 1:
            cout << "House -> Дом";
            break;
        case 2:
            cout << "Road -> Дорога";
            break;
        case 3:
            cout << "Eat -> Есть";
            break;
        case 4:
            cout << "Stool -> Табуретка";
            break;
        case 5:
            cout << "Cheese -> Сыр";
            break;
        case 6:
            cout << "Application -> Приложение";
            break;
        case 7:
            cout << "Headphones -> Наушники";
            break;
        case 8:
            cout << "Keyboard -> Клавиатура";
            break;
        case 9:
            cout << "Frog -> Лягушка";
            break;
        case 10:
            cout << "Target -> Цель";
            break;
        case 11:
            cout << "Dance -> Танцевать";
            break;
        case 12:
            cout << "Kazakh -> Казахский";
            break;
        case 13:
            cout << "Cloud -> Облако";
            break;
        case 14:
            cout << "Tiger -> Тигр";
            break;
        case 15:
            cout << "Short -> Короткий";
            break;
        default:
            cout << "Вы ввели неверный номер";
            break;
        }
        break;
    case 3:
        system("cls");
        return 0;
    default:
        cout << "\nВы ввели некорректное число, попробуйте еще раз!\n\n";
        main();
    }
    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
