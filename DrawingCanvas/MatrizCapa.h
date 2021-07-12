/* 
 * File:   MatrizDispersa.h
 * Author: AlexelBro
 *
 * Created on 17 de junio de 2019, 0:55
 */

#ifndef MATRIZCAPA_H
#define MATRIZCAPA_H

#include <iostream>
#include "ListaCabeceras.h"
#include "ListaLaterales.h"
#include <fstream>
#include <windows.h>
#include <sstream>

using namespace std;

class MatrizCapa{
public:
    ListaCabeceras* cabeceras;
    ListaLaterales* laterales;
    
    MatrizCapa(){
        cabeceras = new ListaCabeceras();
        laterales = new ListaLaterales();
    }
    
    
    
    void agregarPixel(int x, int y, string color);
    void generarGrafica();
    void generarLienzo();
private:
    string escribirMatrizCapa();
    string escribirLienzo();
    string castear(int i);
    
};

#endif /* MATRIZCAPA_H */

