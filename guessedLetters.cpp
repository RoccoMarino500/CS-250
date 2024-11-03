#include "guessedLetters.h"

using namespace std;

GuessedLetters::GuessedLetters() {}

string GuessedLetters::getLetters() {
    string guessedLetters;
    for (char ch : m_guessed) {
        guessedLetters += ch;
    }
    return guessedLetters;
}

void GuessedLetters::addLetter(char ch) {
    m_guessed.push_back(ch);
}