#ifndef VOLLEYBALL_H
#define VOLLEYBALL_H

#include "Athlete.h"
#include <string>

class VolleyBall : public Athlete {
private:
    std::string m_position;
    float m_reactionTime;

public:
    VolleyBall(); 
    VolleyBall(std::string position, float reactionTime); 

    std::string getPosition();
    void setPosition(const std::string& position);
    
    float getReactionTime();
    void setReactionTime(float reactionTime);
};

#endif