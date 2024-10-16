#ifndef ATHLETE_H
#define ATHLETE_H

class Athlete {
private:
    int m_height;
    int m_weight;
    char m_gender;

public:
    Athlete(); 
    Athlete(int height, int weight, char gender); 
    
    int getHeight();
    void setHeight(int height);
    
    int getWeight();
    void setWeight(int weight);
    
    char getGender();
    void setGender(char gender);

};

#endif // I forgot to add this line of code and it ...
    //... wouldnt work for the longest time and I couldn't figure out why