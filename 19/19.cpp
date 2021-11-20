#include <iostream>
#include <time.h>

using namespace std;

const string inputTimer = "[+]Choosing timer duration (in minutes)\n\n[1]1\n[2]2\n[3]3\n[4]4\n[5]5\n\n Choose: ";
const string inputAmount = "[+]Choosing amount of questions\n\n[1]5\n[2]10\n[3]15\n\nChoose: ";
const string inputHint = "[+]Choosing 50/50 enable\n\n[1]Yes\n[2]No\n\nChoose: ";
const string inputUp = "[+]Choosing amount of UP\n\n[1]1\n[2]2\n[3]3\n[4]4\n[5]5\n\nChoose: ";

const int answersSize = 4;
const int questionSize = 15;

struct Question {
    string question;
    string answer[answersSize];
    string hint[2];
    string correctAnswer;
};

Question question[questionSize] = {
    {"Состав пиццы?", {"Моцарелла", "Грузовик", "Конохахаххаха", "Жмых"}, {}, "Моцарелла"},
    {"Сколько будет 1+1?", {"2", "1", "5", "10"}, {}, "2"},
    {"Какой пол у Паши Кириченко?", {"ATTACK HELICOPTER", "Женский", "Мужской", "Плитка"}, {}, "ATTACK HELICOPTER"},
    {"Кто?", {"Корбен921", "Хрюша", "Шнырью", "Правша"}, {}, "Корбен921"},
    {"Сколько сундуков у Кати в SW?", {"32", "228", "79", "69"}, {}, "32"},
    {"Какой ранг у Влада в доте?", {"1680", "0","5000", "2100"}, {}, "1680"},
    {"Вопрос?", {"Ответ", "Какой?", "?сорпоВ", "私はこの気持ちを決して手放すことはありません"}, {}, "Ответ"},
    {"Кто такой дед?", {"Даня Соколов","КС(НЕПРАВИЛЬНО)", "Миша", "Я"}, {}, "Даня Соколов"},
    {"Когда у Миши днюха?", {"Сегодня","Завтра", "12 июля", "шиш"}, {}, "Сегодня"},
    {"Как какать?", {"Сидя", "Лежа", "Стоя", "Лежа пузом"}, {}, "Сидя"},
    {"Какого дистрибутива Linux не существует?", {"Lesbian", "Ubuntu", "CentOS", "RedHat"}, {}, "Lesbian"},
    {"В какой день недели Дима валяется в ванной?", {"Выходные", "Пятница", "Понедельник", "Четверг"}, {},  "Выходные"},
    {"Какой Полина хлеб?", {"Бородинский", "Хлебец", "Батон", "Сухарики"}, {}, "Бородинский"},
    {"Как зовут кота Кати?", {"Кнопа", "Мурзик", "Курсед", "Раилаг"}, {}, "Кнопа"},
    {"Третий зверь на пути колобка", {"Волк", "Заяц", "Лиса", "Колобок"}, {}, "Волк"},
};

int up = 3; //default for UP points
int isHintEnable = 0; //default for 50/50 option
int amountOfQuestions = 15; //default amount of questions
int timer = 5; //default timer for game (in mintues)

int choose; //var for choosing

void randomizeQuestions() {
    for (int i = 0; i < questionSize; i++) {
        swap(question[i], question[rand() % 15]);
    }
}

void randomizeAnswers() {
    for (int i = 0; i < questionSize; i++) {
        for (int j = 0; j < answersSize; j++) {
            swap(question[i].answer[j], question[i].answer[rand() % 4]);
        }
    }
}

void generateHint() {
    for (int i = 0; i < questionSize; i++) {
        string incorrectAnswer = question[i].correctAnswer;

        question[i].hint[0] = question[i].correctAnswer;

        while (incorrectAnswer == question[i].correctAnswer) {
            incorrectAnswer = question[i].answer[rand() % 4];
        }

        question[i].hint[1] = incorrectAnswer;

        for (int j = 0; j < 2; j++) {
            swap(question[i].hint[j], question[i].hint[rand() % 2]);
        }
    }
}

void handleError() {
    cin.clear();
    cin.ignore();
    cout << "\nIncorrect input\n\n";
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

    if (isHintEnable) {
        generateHint();
    }

    randomizeQuestions();

    randomizeAnswers();

    int deadline = static_cast<unsigned int>(time(0)) + 60 * timer;

    for (int i = 0; i < arraySize; i++) {
        system("cls");

        cout << "У тебя осталось: " << deadline - static_cast<unsigned int>(time(0)) << " секунд.\n\n";

        cout << "[" << i + 1 << "]" << question[i].question << "\n\n";

        for (int j = 0; j < 4; j++) {
            cout << "[" << j + 1 << "]" << question[i].answer[j] << "\n\n";
        }

        if (isHintEnable) {
            cout << "Для вывода подсказки нажмите 5\n\n";
        }

        cout << "Введите номер ответа: ";
        cin >> answer;
        answer--;

        while (answer < 0 || answer > 3) {
            if (isHintEnable && answer == 4) {
                cin.clear();
                cin.ignore();
                cout << "\n\nПравильный вариант ответа:\n\n" << question[i].hint[0] << "\n\nИЛИ\n\n" << question[i].hint[1];
                cout << "\n\nВведите вариант ответа: ";
                cin >> answer;
                answer--;
                continue;

            }
            handleError();
            cout << "Введите вариант ответа: ";
            cin >> answer;
            answer--;
        }

        if (question[i].answer[answer] == question[i].correctAnswer) {
            score++;
            cout << "Ответ верный. Вы получаете +1 балл. У вас " << score << " баллов\n";
            waitingForInput();
        }
        else {
            lives--;
            cout << "Ответ не верный, вы теряете 1 жизнь. У вас осталось " << lives << " жизней\n";
            waitingForInput();
        }

        if (lives < 1) {
            system("cls");
            cout << "Вы ошиблись максимальное колличество раз. Игра закончена.\n\n";
            waitingForInput();
            break;
        }

        if (static_cast<unsigned int>(time(0)) > deadline) {
            system("cls");
            cout << "Вы не успели ответить на все вопросы викторины. Игра закончена.\n\n";
            waitingForInput();
            break;
        }
    }
    system("cls");
    cout << "Итоговый счет: " << score << endl;
    waitingForInput();
}

void handleOption(int f(int), int* value, string txt) {
    display(txt);
    *value = f(choose);
    waitingForInput();
}

void handleOptions() {
    system("cls");

    bool isRunning = true;

    while (isRunning) {
        display("[+]Options\n\n[1]Timer\n[2]Amount of questions\n[3]Enable/Disable 50/50\n[4]UP Points\n[5]Exit\n\n[-]Choose action: ");

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
    setlocale(0, "");

    bool isRunning = true;
    while (isRunning) {
        display("[+]Quiz\n\n[1]Start\n[2]Options\n[3]Rules\n[4]Exit\n\n[-]Choose action: ");

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