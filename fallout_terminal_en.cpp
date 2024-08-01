/* Mini-game "Terminal hack" from Fallout.
Made by: Nikita Prosvirkin
Telegram: @fetteser
VK: vk.com/schwertfeger
Discord: fetteser */

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

class Terminal {
private:
    vector<string> words;
    string password;  
    int attempts;

    // Method that compares matches of letters
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
        cout << "Choose the difficulty:\n1 - Easy\n2 - Medium\n3 - Hard\n";
        cin >> difficulty;
        if(difficulty < 1 || difficulty > 3) {
            cout << "Wrong data input.";
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
        password = words[rand() % words.size()];  // Random word from a base is password
        attempts = 4; // Amount of attempts
    }

    void Game() {
        cout << "Welcome to the game 'Terminal hack' from Fallout!" << "\n";
        cout << "Your task is to guess a password from the words below." << "\n";
        cout << "Words:" << "\n";
        
        // Word base printout
        int tab = 0;
        for (const string& word : words) {
            if(tab == 4) {
                cout << "\n";
            }
            cout << "- " << word << "\t";
            tab++;
        }

        while (attempts > 0) {
            cout << "\nInput your word: ";
            string guess;
            cin >> guess;

            if (guess.size() != password.size()) {
                cout << "Lenght of word must be " << password.size() << " letters. Try again." << "\n";
                continue;
            }

            int matches = countMatches(guess);

            if (guess == password) {
                cout << "Congratulations! You hacked terminal successfully!" << "\n";
                break;
            } else {
                attempts--;
                cout << "Wrong answer. Matches: " << matches << ". You have " << attempts << " attempts left." << "\n";
            }

            if (attempts == 0) {
                cout << "You've exhausted all the attempts. The password is: " << password << "." << "\n";
            }
        }
    }
};

int main() {
    Terminal terminal;  // Initialization of object
    terminal.Game();   // Start the game
    system("pause");
    return 0;
}