#ifndef WORD_H
#define WORD_H

#include <string>

using namespace std;

class Word {
    private:
        string m_word;
        string m_currentWord;

    public:
        Word(string word);
        string getWord();
        void addLetter(char ch);
        bool findLetter(char ch);
        bool solved();
};

#endif