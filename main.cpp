/* 
 * File:   main.cpp
 * Author: alvarokb2
 *
 * Created on 13 de mayo de 2015, 19:49
 */

#include <cstdlib>
#include "puzzle.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    puzzle a;

    a.Shuffle();
    a.solve();
    a.Mostrar();
    return 0;
}

