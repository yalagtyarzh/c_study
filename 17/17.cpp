#include <iostream>
#include <cmath>

using namespace std;

float calc(float a, float b, char operation) {
    if (b == 0 && operation == '/') {
        return 0;
    }

    switch (operation) {
    case '+': return a + b;
    case '-': return a - b;
    case '/': return a / b;
    case '*': return a * b;
    case '%': return int(a) % int(b);
    case 'p': return pow(a, 2) * pow(b, 2);
    case 'f': return 2019;
    case '^': return  pow(a, b);
    default:
        cout << "Вы ввели некорректное значение. Вывод по умолчанию: ";
        return 0;
    }

}

int main()
{
    setlocale(0, "");

    cout << "Введите первое число ";
    float a;
    cin >> a;
    cout << "Введите второе число ";
    float b;
    cin >> b;
    cout << "Введите операцию ";
    char operation;
    cin >> operation;

    int result = calc(a, b, operation);

    cout << result;

    return 0;
}

