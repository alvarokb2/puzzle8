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
    void LlenarAleatorio();
    void MostrarFL();

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
void Array<T>::LlenarAleatorio() {
    srand(time(NULL));
    int i = 0;
    while (i < nElementos) {
        int t = 1 + rand() % 100;
        pt[i] = t;
        i++;
    }
}

template <class T>
void Array<T>::MostrarFL(){
    cout << "Primer elemento: "<< pt[0] << endl;
    cout << "Elemento en el medio: "<< pt[nElementos/2] << endl;
    cout << "Ultimo elemento: "<< pt[nElementos -1] << endl;
    
}
#endif	/* ARRAY_H */