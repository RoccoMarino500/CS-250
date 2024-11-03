#include "word.h"

using namespace std;

Word::Word(string word) : m_word(word) {
    for (int i = 0; i < m_word.length(); i++) {
        m_currentWord += '_';
    }
}

string Word::getWord() {
    return m_currentWord; 
}

void Word::addLetter(char ch) {
    for (int i = 0; i < m_word.length(); i++) {
        if (m_word[i] == ch && m_currentWord[i] == '_') {
            m_currentWord[i] = ch;
        }
    }
}

bool Word::findLetter(char ch) {
    for (int i = 0; i < m_word.length(); i++) {
        if (m_word[i] == ch) {
            return true;
        }
    }
    return false;
}

bool Word::solved() {
    return m_currentWord == m_word;
}