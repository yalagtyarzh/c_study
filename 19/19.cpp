#include <iostream>

using namespace std;

const string inputTimer = "[+]Choosing timer duration (in minutes)\n\n[1]1\n[2]2\n[3]3\n[4]4\n[5]5\n\n Choose: ";
const string inputAmount = "[+]Choosing amount of questions\n\n[1]5\n[2]10\n[3]15\n\nChoose: ";
const string inputHint = "[+]Choosing 50/50 enable\n\n[1]Yes\n[2]No\n\nChoose: ";
const string inputUp = "[+]Choosing amount of UP\n\n[1]1\n[2]2\n[3]3\n[4]4\n[5]5\n\nChoose: ";

const string victorina[15][5] = {
    {"Состав пиццы?", "Моцарелла", "Грузовик", "Конохахаххаха", "Жмых"},
    {"Сколько будет 1+1?", "2", "1", "5", "10"},
    {"Какой пол у Паши Кириченко?", "ATTACK HELICOPTER", "Женский", "Мужской", "Плитка"},
    {"Кто?", "Корбен921", "Хрюша", "Шнырью", "Правша"},
    {"Сколько сундуков у Кати в SW?", "32", "228", "79", "69"},
    {"Какой ранг у Влада в доте?", "1680", "0","5000", "2100"},
    {"Третий персонаж, которого встречает колобок?", "Волк", "Заяц", "Лиса", "Колобок"},
    {"Вопрос?", "Ответ", "Какой?", "?сорпоВ", "私はこの気持ちを決して手放すことはありません"},
    {"Кто такой дед", "Даня Соколов","КС(НЕПРАВИЛЬНО)", "Миша", "Я"},
    {"Когда у Миши днюха?", "Сегодня","Завтра", "12 июля", "шиш"},
    {"Как какать?", "Сидя", "Лежа", "Стоя", "Лежа пузом"},
    {"Какого дистрибутива Linux не существует?", "Lesbian", "Ubuntu", "CentOS", "RedHat"},
    {"В какой день недели Дима валяется в ванной?", "Выходные", "Пятница", "Понедельник", "Четверг"},
    {"Какой Полина хлеб?", "Бородинский", "Хлебец", "Батон", "С маком"},
    {"Как зовут кота Кати?", "Кнопа", "Мурзик", "Курсед", "Раилаг"}
};

int questions[15];
int answers[4];

int up = 3; //default for UP points
int isHintEnable = 0; //default for 50/50 option
int amountOfQuestions = 15; //default amount of questions
int timer = 5; //default timer for game (in mintues)

int choose; //var for choosing

int checkQuestion(int question, int arraySize) {
    for (int i = 0; i < arraySize; i++) {
        if (questions[i] == question) {
            question = rand() % 15;
            i = 0;
        }
    }
    return question;
}

int checkAnswer(int answer) {
    for (int i = 0; i < 4; i++) {
        if (answers[i] == answer) {
            answer = rand() % 4;
            i = 0;
        }
    }
    return answer;
}

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

void handleGame(int arraySize) {
    srand(static_cast<unsigned int>(time(0)));
    int answer;
    int score = 0;
    int lives = up;
    
    for (int i = 0; i < arraySize; i++) {
        system("cls");
        int question = rand() % 15;
        question = checkQuestion(question, arraySize);
        questions[i] = question;
        cout << victorina[question][0] << endl;

        for (int j = 0; j < 4; j++) {
            int answer = (rand() % 4) + 1;
            answer = checkAnswer(answer);
            answers[j] = answer;
            cout <<  "[" << j + 1 << "]" " " << victorina[question][answer] << endl;
        }

        cout << "Введите вариант ответа: ";
        cin >> answer;
        answer--;

        while (answer < 0 || answer > 3) {
            cout << "Введи корректное значение, пожалуйста!\n\nВведите вариант ответа: ";
            cin >> answer;
            answer--;
        }

        if (answers[answer] == 1) {
            score++;
            cout << "Ответ верный. Вы получаете +1 балл. У вас " << score << " баллов\n";
            system("pause");
            system("cls");
        }
        else {
            cout << "Ответ не верный, вы теряете 1 жизнь. У вас осталось " << lives << " жизней\n";
            system("pause");
            system("cls");
        }

        if (lives < 0) {
            system("cls");
            cout << "Вы ошиблись максимальное колличество раз. Игра закончена\n\m";
            break;
        }
    }
    cout << "Итоговый счет: " << score << endl;
    system("pause");
}

void handleOption(int f(int), int* value, string txt) {
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
        system("cls");

        setlocale(0, "");

        bool isRunning = true;
        while (isRunning) {
            cout << up << " " << isHintEnable << " " << amountOfQuestions << " " << timer;
            cout << "[+]Quiz\n\n[1]Start\n[2]Options\n[3]Rules\n[4]Exit\n\n[-]Choose action: ";
            cin >> choose;

            switch (choose)
            {
            case 1: {
                handleGame(amountOfQuestions);
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