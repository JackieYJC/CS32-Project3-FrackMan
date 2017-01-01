#include "Actor.h"
#include "StudentWorld.h"

void FrackMan:: clearDirt() const
{
    int x = getX();
    int y = getY();
    int a = 0;
    if ((StudentWorld()->dirtExist(x, y))) {
        StudentWorld()->destroyDirt(x, y);
        a = 1;
    }
    if ((StudentWorld()->dirtExist(x+1, y))) {
        StudentWorld()->destroyDirt(x+1, y);
        a = 1;
    }
    if ((StudentWorld()->dirtExist(x+2, y))) {
        StudentWorld()->destroyDirt(x+2, y);
        a = 1;
    }
    if ((StudentWorld()->dirtExist(x+3, y))) {
        StudentWorld()->destroyDirt(x+3, y);
        a = 1;
    }
    if ((StudentWorld()->dirtExist(x, y+1))) {
        StudentWorld()->destroyDirt(x, y+1);
        a = 1;
    }
    if ((StudentWorld()->dirtExist(x+1, y+1))) {
        StudentWorld()->destroyDirt(x+1, y+1);
        a = 1;
    }
    if ((StudentWorld()->dirtExist(x+2, y+1))) {
        StudentWorld()->destroyDirt(x+2, y+1);
        a = 1;
    }
    if ((StudentWorld()->dirtExist(x+3, y+1))) {
        StudentWorld()->destroyDirt(x+3, y+1);
        a = 1;
    }
    if ((StudentWorld()->dirtExist(x, y+2))) {
        StudentWorld()->destroyDirt(x, y+2);
        a = 1;
    }
    if ((StudentWorld()->dirtExist(x+1, y+2))) {
        StudentWorld()->destroyDirt(x+1, y+2);
        a = 1;
    }
    if ((StudentWorld()->dirtExist(x+2, y+2))) {
        StudentWorld()->destroyDirt(x+2, y+2);
        a = 1;
    }
    if ((StudentWorld()->dirtExist(x+3, y+2))) {
        StudentWorld()->destroyDirt(x+3, y+2);
        a = 1;
    }
    if ((StudentWorld()->dirtExist(x, y+3))) {
        StudentWorld()->destroyDirt(x, y+3);
        a = 1;
    }
    if ((StudentWorld()->dirtExist(x+1, y+3))) {
        StudentWorld()->destroyDirt(x+1, y+3);
        a = 1;
    }
    if ((StudentWorld()->dirtExist(x+2, y+3))) {
        StudentWorld()->destroyDirt(x+2, y+3);
        a = 1;
    }
    if ((StudentWorld()->dirtExist(x+3, y+3))) {
        StudentWorld()->destroyDirt(x+3, y+3);
        a = 1;
    }
    if (a == 1) {
        StudentWorld()->playSound(SOUND_DIG);
    }

}

void FrackMan:: doSomething()
{
    if (!isAlive()) {
        return;
    }


    
    int x = getX();
    int y = getY();
    int dir;
    StudentWorld()->getKey(dir);
    if (dir == KEY_PRESS_LEFT) {
        moveTo(x-1,y);
    }
    else if (dir == KEY_PRESS_RIGHT) {
        moveTo(x+1,y);
    }
    else if (dir == KEY_PRESS_UP) {
        moveTo(x,y+1);
    }
    else if (dir == KEY_PRESS_DOWN) {
        moveTo(x,y-1);
    }
    clearDirt();
    
}

