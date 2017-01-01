#include "StudentWorld.h"
#include "Actor.h"
#include <string>
using namespace std;

GameWorld* createStudentWorld(string assetDir)
{
	return new StudentWorld(assetDir);
}

int StudentWorld::init()
{
    m_FrackMan = new FrackMan(this);
    for (int i = 0; i < 60; i++) {
        for (int h = 0; h < 60; h++) {
            m_Dirt[i][h] = new Dirt(h, i, this);
        }
    }
    return GWSTATUS_CONTINUE_GAME;
}

int StudentWorld::move()
{
    m_FrackMan->doSomething();
    return GWSTATUS_CONTINUE_GAME;
    
}
void StudentWorld::destroyDirt(int x, int y)
{
        m_Dirt[y][x] = nullptr;
}



// Students:  Add code to this file (if you wish), StudentWorld.h, Actor.h and Actor.cpp
