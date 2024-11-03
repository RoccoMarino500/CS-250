#ifndef WORD_H
#define WORD_H

#include <string>
#include <list>

using namespace std;

class Word {
    private:
        list<char> m_currentWord;
        string m_word;

    public:
        Word(string word);
        string getWord();
        void addLetter(char ch);
        bool findLetter(char ch);
        bool solved();
};

#endif