#include "gameState.h"

using namespace std;

GameState::GameState() : m_nextState(0) {
    m_allStates[0] = "Platform";
    m_allStates[1] = "Head";
    m_allStates[2] = "Body";
    m_allStates[3] = "Left Arm";
    m_allStates[4] = "Right Arm";
    m_allStates[5] = "Left Leg";
    m_allStates[6] = "Right Leg";
}

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