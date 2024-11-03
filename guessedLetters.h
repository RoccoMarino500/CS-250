#ifndef GUESSEDLETTERS_H
#define GUESSEDLETTERS_H

#include <string>
#include <vector>

using namespace std;

class GuessedLetters {
    private:
        vector<char> m_guessed;

    public:
        GuessedLetters();
        string getLetters();
        void addLetter(char ch);
};

#endif