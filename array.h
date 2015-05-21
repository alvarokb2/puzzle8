/* 
 * File:   array.h
 * Author: alvarokb2
 *
 * Created on 9 de mayo de 2015, 16:50
 */

#ifndef ARRAY_H
#define	ARRAY_H
#include <iostream>

#include <time.h>

using namespace std;

template <class T>
class Array {
public:
    Array(int nElem);
    ~Array();
    Mostrar();
    
    T& operator[](int index) {
        return pt[index];
    }

private:
    T *pt;
    int nElementos;
};

template <class T>
Array<T>::Array(int nElem) : nElementos(nElem) {
    pt = new T[nElementos];
}

template <class T>
Array<T>::~Array() {
    delete [] pt;
}

template <class T>
Array<T>::Mostrar() {
    for(int i = 0; i < nElementos; i++){
        cout << pt[i]<< " ";
        if(i%3 = 2)
            cout <<endl;        
    }
}


#endif	/* ARRAY_H */