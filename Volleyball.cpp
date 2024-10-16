#include "Volleyball.h"

VolleyBall::VolleyBall() : m_position("Unknown"), m_reactionTime(0.0) {}

VolleyBall::VolleyBall(std::string position, float reactionTime)
    : m_position(position), m_reactionTime(reactionTime) {}

std::string VolleyBall::getPosition() {
    return m_position;
}

void VolleyBall::setPosition(const std::string& position) {
    m_position = position;
}

float VolleyBall::getReactionTime() {
    return m_reactionTime;
}

void VolleyBall::setReactionTime(float reactionTime) {
    m_reactionTime = reactionTime;
}