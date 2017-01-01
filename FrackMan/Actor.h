#ifndef ACTOR_H_
#define ACTOR_H_

#include "GraphObject.h"
#include "StudentWorld.h"

// Students:  Add code to this file, Actor.cpp, StudentWorld.h, and StudentWorld.cpp


//TWO BIG PROBLEMS: 1. BELOW THAT INVOLVE "CLASS STUDENTWORLD", 2. CHANGED THE PARAMETER OF GETKEY FROM GAMEWORLD TO CONST INT

class StudentWorld;
class Actor: public GraphObject
{
public:
    Actor(int imageID, int startX, int startY, Direction dir, double size, unsigned int depth, StudentWorld* StudentWorld): GraphObject(imageID, startX, startY, dir, size, depth), m_isAlive(true), m_StudentWorld(StudentWorld){
        setVisible(true);
    };
    virtual ~Actor() {};
    virtual void doSomething() = 0;
    bool isAlive () const
    {
        return m_isAlive;
    };
    StudentWorld* StudentWorld() const
    {
        return m_StudentWorld;
    }
    
private:
    bool m_isAlive;
    class StudentWorld* m_StudentWorld;
    
    
    
};

class Human: public Actor
{
public:
    Human(int imageID, int startX, int startY, Direction dir, int hitPoint, class StudentWorld* StudentWorld):
    Actor(imageID, startX, startY, dir, 1.0, 0, StudentWorld), m_move(false), m_hitPoint(hitPoint) {};
    virtual ~Human() {};
    virtual void doSomething() = 0;

private:
    bool m_move;
    int m_hitPoint;
    
};

class FrackMan: public Human
{
public:
    FrackMan(class StudentWorld* StudentWorld): Human(IID_PLAYER, 30, 60, right, 10, StudentWorld), m_water(5), m_sonar(1), m_gold(0) {};
    virtual ~FrackMan(){};
    virtual void doSomething();
    void clearDirt() const;
    
private:
    int m_water;
    int m_sonar;
    int m_gold;
    

    
};

class Dirt: public Actor
{
public:
    Dirt(int startX, int startY, class StudentWorld* StudentWorld):
    Actor(IID_DIRT, startX, startY, right, .25, 3, StudentWorld) {};
    virtual ~Dirt(){};
    virtual void doSomething() {};
    
    
private:
    
    
};





#endif // ACTOR_H_
