#include "gameState.h"

using namespace std;

GameState::GameState() : m_nextState(0) {}

string GameState::getState() {
    string result;
    for (auto it = m_state.begin(); it != m_state.end(); ++it) {
        if (it != m_state.begin()) result += ", ";
        result += *it;
    }
    return result;
}

void GameState::addState() {
    if (m_nextState < 7) {
        m_state.push_back(m_allStates[m_nextState]);
        m_nextState++;
    }
}

bool GameState::gameOver() {
    return m_nextState == 7;
}