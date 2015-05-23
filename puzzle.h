/* 
 * File:   puzzle.h
 * Author: alvarokb2
 *
 * Created on 13 de mayo de 2015, 21:32
 */

#ifndef PUZZLE_H
#define	PUZZLE_H

#include <iostream>
#include <time.h>
using namespace std;

class puzzle {
private:
    int arreglo[9];
    int zero; // variable con la posicion del 0
    int token; // variable para identificar el ultimo movimiento;
public:

    // constructor

    puzzle();

    // interfaz

    int getIndex(int _value); // retorna el indice del elemento _value
    void Mostrar(); // muestra el puzzle

    // movimientos    

    void Shuffle(); // mezcla el puzzle
    bool canLeft(); // puede moverse a la izquierda el 0?
    void moveLeft(); // mueve el cero a la izquierda
    bool canRight(); // puede moverse a la derecha el 0?
    void moveRight(); // mueve el cero a la derecha
    bool canTop(); // puede moverse arriba el 0?
    void moveTop(); // mueve el cero arriba
    bool canBottom(); // puede moverse abajo el 0?
    void moveBottom(); // mueve el cero abajo

    // resolucion

    bool solved(); // esta resuelto el puzzle?
    void getNext(); // obtiene el movimiento siguiente (menor distancia posible)
    int distance(int _value); // mide distancia del valor a su indice ideal
    int distanceS(); // suma las distancias de cada indice
    void solve(); //resuelve el puzzle
};

// constructor

puzzle::puzzle() {
    int i = 0;
    zero = 8;
    while (i < 8) {
        arreglo[i] = i + 1;
        i++;
    }
    arreglo[zero] = 0;
    token = 0;
}
// interfaz

int puzzle::getIndex(int value) {
    for (int i = 0; i < 9; i++) {
        if (arreglo[i] == value)
            return i;
    }
}

void puzzle::Mostrar() {
    for (int i = 0; i < 9; i++) {
        cout << arreglo[i] << " ";
        if (i % 3 == 2) cout << endl;
    }
    cout << endl;
}

// movimiento

void puzzle::Shuffle() {
    srand(time(NULL));
    int random;
    int aux;
    for (int i = 0; i < 200; i++) {
        random = 1 + rand() % 4;
        switch (random) {
            case 1:
                if (canLeft()) {
                    moveLeft();
                } else {
                    i--;
                }
                break;
            case 2:
                if (canRight()) {
                    moveRight();
                } else {
                    i--;
                }
                break;
            case 3:
                if (canTop()) {
                    moveTop();
                    ;
                } else {
                    i--;
                }
                break;
            case 4:
                if (canBottom()) {
                    moveBottom();
                } else {
                    i--;
                }
                break;
        }
    }
    token = 0;
}

bool puzzle::canLeft() {
    if (zero % 3 != 0 && token != 1) {
        return true;
    }
    return false;
}

void puzzle::moveLeft() {
    arreglo[zero] = arreglo[zero - 1];
    arreglo[zero - 1] = 0;
    zero--;
    token = 2;
}

bool puzzle::canRight() {
    if (zero % 3 != 2 && token != 2) {
        return true;
    }
    return false;
}

void puzzle::moveRight() {
    arreglo[zero] = arreglo[zero + 1];
    arreglo[zero + 1] = 0;
    zero++;
    token = 1;
}

bool puzzle::canTop() {
    if (zero / 3 != 0 && token != 3) {
        return true;
    }
    return false;
}

void puzzle::moveTop() {
    arreglo[zero] = arreglo[zero - 3];
    arreglo[zero - 3] = 0;
    zero = zero - 3;
    token = 4;
}

bool puzzle::canBottom() {
    if (zero / 3 != 2 && token != 4) {
        return true;
    }
    return false;
}

void puzzle::moveBottom() {
    arreglo[zero] = arreglo[zero + 3];
    arreglo[zero + 3] = 0;
    zero = zero + 3;
    token = 3;

}

// resolucion

bool puzzle::solved() {
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (arreglo[i] == i + 1) {
            count++;
        }
    }
    if (count == 8) {
        return true;
    } else {
        return false;
    }
}

void puzzle::solve() {
    int count = 0;
    while (!solved()) {
        getNext();
        count++;
    }
    cout << count << " movimientos"<<endl;
    
}

void puzzle::getNext() {
    int decision = 3 * distanceS();
    int distancia = decision;
    int aux = 0;
    int tkn = token;
    int response = 0;
    cout << "llamada con: " << endl;
    Mostrar();
    cout << "posibles movimientos:"<< endl;
    if (canLeft()) {
        moveLeft();
        Mostrar();
        aux = distanceS();
        if (aux <= decision) {
            decision = aux;
            response = 1;
        }
        moveRight();
        token = tkn;
    }
    if (canRight()) {
        moveRight();
        Mostrar();
        aux = distanceS();
        if (aux <= decision) {
            decision = aux;
            response = 2;
        }
        moveLeft();
        token = tkn;
    }
    if (canTop()) {
        moveTop();
        Mostrar();
        aux = distanceS();
        if (aux <= decision) {
            decision = aux;
            response = 3;
        }
        moveBottom();
        token = tkn;
    }
    if (canBottom()) {
        moveBottom();
        Mostrar();
        aux = distanceS();
        if (aux <= decision) {
            decision = aux;
            response = 4;
        }
        moveTop();
        token = tkn;
    }
    switch (response) {
        case 1:
            if(canLeft())
            moveLeft();
            break;
        case 2:
            if(canRight())
            moveRight();
            break;
        case 3:
            if(canTop())
            moveTop();
            break;
        case 4:
            if(canBottom())
            moveBottom();
            break;
        default:
            
            break;
    }
}

int puzzle::distance(int _value) {
    int dx = 0;
    int dy = 0;
    int aux = 0;
    int i = getIndex(_value);
    dx = (i / 3 - (_value - 1) / 3);
    dy = (i % 3 - (_value - 1) % 3);
    if (dx < 0) dx *= -1;
    if (dy < 0) dy *= -1;
    aux = dx + dy;
    if (aux != 0) {
        i = getIndex(0);
        dx = (i / 3 - (_value - 1) / 3);
        dy = (i % 3 - (_value - 1) % 3);
        if (dx < 0) dx *= -1;
        if (dy < 0) dy *= -1;
        aux = (3 * aux) + dx + dy;
    }
    return aux;
}

int puzzle::distanceS() {
    int d = 0;
    for (int i = 0; i < 8; i++) {
        d = d + (8-i)*distance(i + 1);
    }
    return d;
}

#endif	/* PUZZLE_H */

