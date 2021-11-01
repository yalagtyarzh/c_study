#include <iostream>

using namespace std;

void cleanConsole() {
    system("cls");
}

void changeConsoleBackground() {
    system("color 57");
}

void changeConsoleText() {
    system("color 06");
}

void printSizeOfInt() {
    cout << "[+]Размер типа данных int - " << sizeof(int) << endl;
}


void printSizeOfChar() {
    cout << "[+]Размер типа данных char - " << sizeof(char) << endl;
}

void printSizeOfDouble() {
    cout << "[+]Размер типа данных double - " << sizeof(double) << endl;
}

void printSizeOfFloat() {
    cout << "[+]Размер типа данных float - " << sizeof(float) << endl;
}

void printSizeOfBool() {
    cout << "[+]Размер типа данных bool - " << sizeof(bool) << endl;
}

void printHello() {
    cout << "Привет я функция" << endl;
}

void printLogo() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << "# ";
        }
        cout << "\n";
    }
}



int main()
{
    setlocale(0, "");
    cleanConsole();
    changeConsoleBackground();
    changeConsoleText();
    printSizeOfInt();
    printSizeOfChar();
    printSizeOfDouble();
    printSizeOfFloat();
    printSizeOfBool();
    printLogo();
    return 0;
}

