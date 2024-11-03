#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <list>
#include <string>

using namespace std;

class GameState {
    private:
        list<string> m_state;
        string m_allStates[7];
        int m_nextState;

    public:
        GameState();
        string getState();
        void addState();
        bool gameOver();
};

#endif