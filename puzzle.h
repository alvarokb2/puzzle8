/* 
 * File:   puzzle.h
 * Author: alvarokb2
 *
 * Created on 13 de mayo de 2015, 21:32
 */

#ifndef PUZZLE_H
#define	PUZZLE_H

using namespace std;
#include "array.h"


class puzzle{
private:
    Array<int> arreglo;
public:
    puzzle();
    shuffle();
    moveLeft();
    moveTop();
    moveRight();
    moveBottom();
    solve();
};


#endif	/* PUZZLE_H */

