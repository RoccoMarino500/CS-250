#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <string>
#include <list>

using namespace std;

class GameState {
    private:
        list<string> m_state;
        list<string> m_allStates;
        int m_nextState;

    public:
        GameState();
        string getState();
        void addState();
        bool gameOver();
};

#endif