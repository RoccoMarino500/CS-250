#ifndef GUESSEDLETTERS_H
#define GUESSEDLETTERS_H

#include <list>
#include <string>

using namespace std;

class GuessedLetters {
    private:
        list<char> m_guessed;

    public:
        GuessedLetters();
        string getLetters();
        void addLetter(char ch);
};

#endif