#include "guessedLetters.h"

using namespace std;

GuessedLetters::GuessedLetters() {}

string GuessedLetters::getLetters() {
    string guessedLetters = "";
    for (int i = 0; i < m_guessed.size(); i++) {
        guessedLetters += m_guessed[i];
    }
    return guessedLetters;
}

void GuessedLetters::addLetter(char ch) {
    bool alreadyGuessed = false;
    for (int i = 0; i < m_guessed.size(); i++) {
        if (m_guessed[i] == ch) {
            alreadyGuessed = true;
            break;
        }
    }

    if (!alreadyGuessed) {
        m_guessed.push_back(ch); 
    }
}