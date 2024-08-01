/* Мини-игра "Взлом терминала" из Fallout.
Реализация: Просвиркин Никита 
Telegram: @fetteser
VK: vk.com/schwertfeger
Discord: fetteser */

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <windows.h>

using namespace std;

class Terminal {
private:
    vector<string> words;   // База слов
    string password;    // Пароль
    int attempts;   // Количество попыток

    // Метод для подсчета совпадений с паролем
    int countMatches(const string& guess) const {
        int matches = 0;
        for (size_t i = 0; i < guess.size(); ++i) {
            if (guess[i] == password[i]) {
                matches++;
            }
        }
        return matches;
    }

public:
    Terminal() {
        int difficulty;
        cout << "Выберите сложность:\n1 - Легко\n2 - Средне\n3 - Сложно\n";
        cin >> difficulty;
        if(difficulty < 1 || difficulty > 3) {
            cout << "Неправильный ввод данных.";
        }
        switch(difficulty) {
            case 1:
                words = {"meal", "face", "each", "earn", "real", "head", "pace",
                "safe"};
                break;
            case 2:
                words = {"broke", "plane", "jelly", "based", "cabin", "eagle",
                "jacks", "label"};
                break;
            case 3:
                words = {"stupid", "busted", "bubble", "banana", "fabric",
                "habits", "katana", "rabbit"};
                break;
        }

        srand(static_cast<unsigned>(time(0)));
        password = words[rand() % words.size()];  // Случайный выбор пароля
        attempts = 4; // Количество попыток
    }

    void Game() {
        cout << "Добро пожаловать в игру 'Взлом терминала' из Fallout!" << "\n";
        cout << "Ваше задание - угадать пароль из предложенных ниже слов." << "\n";
        cout << "Слова на выбор:" << "\n";
        
        //Вывод слов на выбор
        int tab = 0;
        for (const string& word : words) {
            if(tab == 4) {
                cout << "\n";
            }
            cout << "- " << word << "\t";
            tab++;
        }

        while (attempts > 0) {
            cout << "\nВведите ваше слово: ";
            string guess;
            cin >> guess;

            if (guess.size() != password.size()) {
                cout << "Длина слова должна быть " << password.size() << " символов. Попробуйте снова." << "\n";
                continue;
            }

            int matches = countMatches(guess);

            if (guess == password) {
                cout << "Поздравляем! Вы успешно взломали терминал!" << "\n";
                break;
            } else {
                attempts--;
                cout << "Неправильно. Совпадений: " << matches << ". У вас осталось " << attempts << " попыток." << "\n";
            }

            if (attempts == 0) {
                cout << "Вы исчерпали все попытки. Правильное слово было: " << password << "." << "\n";
            }
        }
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);    //Локализация 
    Terminal terminal;  // Создание объекта класса Terminal
    terminal.Game();   // Запуск игры
    system("pause");
    return 0;
}