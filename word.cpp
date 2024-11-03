#include "word.h"

using namespace std;

Word::Word(string word) : m_word(word) {
    for (int i = 0; i < m_word.length(); i++) {
        m_currentWord.push_back('_');
    }
}

string Word::getWord() {
    string currentWordString;
    for (char ch : m_currentWord) {
        currentWordString += ch;
    }
    return currentWordString;
}

void Word::addLetter(char ch) {
    int index = 0;
    for (auto it = m_currentWord.begin(); it != m_currentWord.end(); ++it, ++index) {
        if (m_word[index] == ch && *it == '_') {
            *it = ch;
        }
    }
}

bool Word::findLetter(char ch) {
    for (char wordChar : m_word) {
        if (wordChar == ch) {
            return true;
        }
    }
    return false;
}

bool Word::solved() {
    return getWord() == m_word;
}