#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include <string>

// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class FrackMan;
class Dirt;

class StudentWorld : public GameWorld
{
public:
	StudentWorld(std::string assetDir)
	 : GameWorld(assetDir)
	{
        m_FrackMan = nullptr;
	}
    
    ~StudentWorld()
    {
        cleanUp();
    }
    virtual int init();
    virtual int move();

	virtual void cleanUp()
	{
        if (m_FrackMan != nullptr) {
            delete m_FrackMan;
        }
        for (int i = 0; i < 60; i++) {
            for (int h = 0; h < 60; h++) {
                if (m_Dirt[i][h] != nullptr) {
                    delete m_Dirt[i][h];
                }
            }
        }
	}
    
    void destroyDirt(int x, int y);
    bool dirtExist(int x, int y) const
    {
        if (m_Dirt[y][x] == nullptr) {
            return false;
        }
        return true;
    }

private:
    FrackMan* m_FrackMan;
    Dirt* m_Dirt[60][60];
    
    
};

#endif // STUDENTWORLD_H_
