#include <iostream>

using namespace std;

const string inputTimer = "[+]Choosing timer duration (in minutes)\n\n[1]1\n[2]2\n[3]3\n[4]4\n[5]5\n\n Choose: ";
const string inputAmount = "[+]Choosing amount of questions\n\n[1]5\n[2]10\n[3]15\n\nChoose: ";
const string inputHint = "[+]Choosing 50/50 enable\n\n[1]Yes\n[2]No\n\nChoose: ";
const string inputUp = "[+]Choosing amount of UP\n\n[1]1\n[2]2\n[3]3\n[4]4\n[5]5\n\nChoose: ";

int up = 3; //default for UP points
int isHintEnable = 0; //default for 50/50 option
int amountOfQuestions = 5; //default amount of questions
int timer = 5; //default timer for game (in mintues)

int choose; //var for choosing

void handleError() {
    cin.clear();
    cin.ignore();
    cout << "Incorrect input\n\n";
}

void waitingForInput() {
    system("pause");
    cin.get();
}

int setAmountOfQuestions(int chs) {
    switch (chs) {
    case 1:
        return 5;
    case 2:
        return 10;
    case 3:
        return 15;
    default:
        handleError();
        return 15;
    }
}

int setUp(int chs) {
    switch (chs) {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    default:
        handleError();
        return 3;
    }
}

int setEnableHint(int chs) {
    switch (chs) {
    case 1:
        return 1;
    case 2:
        return 0;
    default:
        handleError();
        return 0;
    }
}

int setTimer(int chs) {
    switch (chs) {
    case 1:
        return 1;
    case 2:
        return 2;
    case 3:
        return 3;
    case 4:
        return 4;
    case 5:
        return 5;
    default:
        handleError();
        return 5;
    }
}

void display(string txt) {
    system("cls");
    cout << txt;
    cin >> choose;
}

void handleOption(int f(int), int *value, string txt) {
    display(txt);
    *value = f(choose);
    waitingForInput();
}

void handleOptions() {
    bool isRunning = true;

    while (isRunning) {
        system("cls");
        cout << "[+]Options\n\n[1]Timer\n[2]Amount of questions\n[3]Enable/Disable 50/50\n[4]UP Points\n[5]Exit\n\n[-]Choose action: ";

        cin >> choose;
        switch (choose) {
            case 1: {
                handleOption(setTimer, &timer, inputTimer);
                break;
            }
            case 2: {
                handleOption(setAmountOfQuestions, &amountOfQuestions, inputAmount);
                break;
            }
            case 3: {
                handleOption(setEnableHint, &isHintEnable, inputHint);
                break;
            }
            case 4: {
                handleOption(setUp, &up, inputUp);
                break;
            }
            case 5: {
                system("cls");
                isRunning = false;
                break;
            }
            default: {
                handleError();
                break;
            }
        }
    }
}

void handleRules() {
    system("cls");

    cout << "Sera was never an agreeble girl\n";
    cout << "Her tongue tell tales of rebellion\n";
    cout << "But she was so fast, And quick with her bow,\n";
    cout << "No one quite knew when she came from\n\n";

    waitingForInput();

    system("cls");
}

int main()
{
    bool isRunning = true;
    while (isRunning) {
        cout << up << " " << isHintEnable << " " << amountOfQuestions << " " << timer;
        cout << "[+]Quiz\n\n[1]Start\n[2]Options\n[3]Rules\n[4]Exit\n\n[-]Choose action: ";
        cin >> choose;

        switch (choose)
        {
            case 1: {
                system("cls");
                break;
            }
            case 2: {
                handleOptions();
                break;
            }
            case 3: {
                handleRules();
                break;
            }
            case 4: {
                cout << "BYE BYE!";
                isRunning = false;
                break;
            }
            default: {
                handleError();
                break;
            }
        }
    }
    return 0;
}
