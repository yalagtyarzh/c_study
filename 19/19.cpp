#include <iostream>
#include <time.h>

using namespace std;

//Текст для вывода меню настройки таймера
const string inputTimer = "[+]Choosing timer duration (in minutes)\n\n[1]1\n[2]2\n[3]3\n[4]4\n[5]5\n\n Choose: "; 
//Текст для вывода меню настройки количества вопроосов
const string inputAmount = "[+]Choosing amount of questions\n\n[1]5\n[2]10\n[3]15\n\nChoose: ";
//Текст для вывода меню настройки включения подсказок
const string inputHint = "[+]Choosing 50/50 enable\n\n[1]Yes\n[2]No\n\nChoose: ";
//Текст для вывода меню настройки количества жизнец
const string inputUp = "[+]Choosing amount of UP\n\n[1]1\n[2]2\n[3]3\n[4]4\n[5]5\n\nChoose: ";

//Дефолтные параметры для массивов структур, отвечающих за размер массива вопросов и ответов
const int questionSize = 15;
const int answersSize = 4;

//Структура вопроса, которая хранит в себе сам вопрос, количество ответов на него, массив из двух двух подсказок
//и правильного ответа
struct Question {
    string question; //Вопрос
    string answer[answersSize]; //Ответы
    string hint[2]; //Подсказки
    string correctAnswer; //Правильный ответ
};

//Создания массива из экземляров структур question с последующим заполнением
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

int up = 3; //Значение для количества жизней (по умолчанию 3)
int isHintEnable = 0; //Значения для подсказки (0 - включено, 1 - выключено) (по умолчанию выключено)
int amountOfQuestions = 15; //Количество вопросов (по умолчанию 15)
int timer = 5; //Время, которое работает таймер (в минутах) (по умолчанию 5)

int choose; //Переменная для выбора, которую осуществляет пользотель, вводя число с клавитуры

//Функция, которая мешает вопросы (или, иначе говоря, мешает всё содержимое массива)
void randomizeQuestions() {
    for (int i = 0; i < questionSize; i++) {
        swap(question[i], question[rand() % 15]);
    }
}

//Функция, которая мешает ответы на вопрос (иначе говоря, рандомится содержимое поля answer внутри структуры question)
void randomizeAnswers() {
    for (int i = 0; i < questionSize; i++) {
        for (int j = 0; j < answersSize; j++) {
            swap(question[i].answer[j], question[i].answer[rand() % 4]);
        }
    }
}

//Функция, генерирующая подсказку внутри экземляра вопроса
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

//Функция для обработки некорректного вывода
void handleError() {
    cin.clear();
    cin.ignore();
    cout << "\nIncorrect input\n\n";
}

//Функция для ожидания ввода пользователя
void waitingForInput() {
    system("pause");
    cin.get();
}

//Функция, возвращающее количество вопросов викторины, размер которого зависит от параметра, которая 
//прокидывается в эту функцию (chs)
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

//Функция, возвращающее количество жизней, размер которого зависит от параметра, которая 
//прокидывается в эту функцию (chs)
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

//Функция, возвращающее число, которое регулирует настройки подсказки, значение которого зависит от параметра, которая 
//прокидывается в эту функцию (chs)
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

//Функция, возвращающее длительность таймера (в минутах), размер которого зависит от параметра, которая 
//прокидывается в эту функцию (chs)
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

//Функция, отвечающее за очистку и вывод текста на экран, который передается в функцию, с дальнейшим ожиданием
//ввода выбора от пользователя
void display(string txt) {
    system("cls");
    cout << txt;
    cin >> choose;
}

//Функция, отвечающее за саму игру, в нее передается переменная, которая отвечает за количество вопрос в викторине
void handleGame(int arraySize) {
    srand(static_cast<unsigned int>(time(0))); //Генерация рандома

    int answer; //Переменная для хранения выбора пользователя
    int score = 0; //Переменная для хранения количества очков
    int lives = up; //Переменная для количества жизней

    //Если настройка лдя подсказок включена - сгенерировать подсказки
    if (isHintEnable) {
        generateHint();
    }

    //Рандом вопросов
    randomizeQuestions();

    //Рандом ответов
    randomizeAnswers();

    //Инициалация таймера, который из себя представляет время, в которое началась игра + количество секунд, в течении
    //которого пользователь может находиться в игре
    int deadline = static_cast<unsigned int>(time(0)) + 60 * timer;

    //Непосредственное начало игры
    for (int i = 0; i < arraySize; i++) {
        system("cls");

        cout << "У тебя осталось: " << deadline - static_cast<unsigned int>(time(0)) << " секунд.\nВсего жизней: " << lives << "\n\n";

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

        //Проверка на ввод корректного значения пользователем.
        //Если у игрока включена подсказка и было нажато "5", то вместо ошибки о некорректном вводе он
        //получает подсказку
        while (answer < 0 || answer > 3) {
            //Получение подсказки
            if (isHintEnable && answer == 4) {
                cin.clear();
                cin.ignore();
                cout << "\n\nПравильный вариант ответа:\n\n" << question[i].hint[0] << "\n\nИЛИ\n\n" << question[i].hint[1];
                cout << "\n\nВведите вариант ответа: ";
                cin >> answer;
                answer--;
                continue;

            }
            //Обработка некорректного ввода
            handleError();
            cout << "Введите вариант ответа: ";
            cin >> answer;
            answer--;
        }
        //Если не осталось времени - закончить игру
        if (static_cast<unsigned int>(time(0)) > deadline) {
            system("cls");
            cout << "Вы не успели ответить на все вопросы викторины. Игра закончена.\n\n";
            waitingForInput();
            break;
        }

        //Если ответ является верным, то начислить пользователю 1 очко
        if (question[i].answer[answer] == question[i].correctAnswer) {
            score++;
            cout << "Ответ верный. Вы получаете +1 балл. У вас " << score << " баллов\n";
            waitingForInput();
        }
        //Иначе снимается 1 жизнь
        else {
            lives--;
            cout << "Ответ не верный, вы теряете 1 жизнь. У вас осталось " << lives << " жизней\n";
            waitingForInput();
        }

        //Если жизней не осталось - закончить игру
        if (lives < 1) {
            system("cls");
            cout << "Вы ошиблись максимальное колличество раз. Игра закончена.\n\n";
            waitingForInput();
            break;
        }
    }
    //Вывод результатов игры
    system("cls");
    cout << "Итоговый счет: " << score << endl;
    waitingForInput();
}

//Функция, выводящая текст на экран, осуществляющий выбор от пользователя, и уже в зависимости от выбора пользователя - 
//- вызывающее функцию, отвечающее уже за непосредственную работу с определенной настройкой
//f(int) - функция настроек
//value - непосредственно сама настройка, которую мы меняем (использован указатель (*), которая обращается
//непосредтсвенно к значению, которое хранится в аргументе (иначе говоря переменной), а не лишь к копии самого значения
//txt - текст, которую мы передаем в функцию display
void handleOption(int f(int), int* value, string txt) {
    display(txt);
    *value = f(choose);
    waitingForInput();
}

//Функция, отвечающее за вывод меню настроек пользователю и уже непосредственный выбор вопроса
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

//Функция, отвечающая за вывод правил
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
