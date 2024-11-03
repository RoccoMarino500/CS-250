#include "gameState.h"

using namespace std;

GameState::GameState() : m_nextState(0) {
    string states[] = {"Platform", "Head", "Body", "Left Arm", "Right Arm", "Left Leg", "Right Leg"};
    for (int i = 0; i < 7; i++) {
        m_allStates.push_back(states[i]);
    }
}

string GameState::getState() {
    string result = "";
    int index = 0;
    for (auto it = m_state.begin(); it != m_state.end(); ++it) {
        if (index > 0) result += ", ";
        result += *it;
        index++;
    }
    return result;
}

void GameState::addState() {
    auto it = m_allStates.begin();
    advance(it, m_nextState);
    if (it != m_allStates.end()) {
        m_state.push_back(*it);
        m_nextState++;
    }
}

bool GameState::gameOver() {
    return m_nextState == m_allStates.size();
}