/* 
 * File:   NodoDispersa.h
 * Author: AlexelBro
 *
 * Created on 16 de junio de 2019, 18:22
 */

#ifndef NODODISPERSA_H
#define NODODISPERSA_H
#include <iostream>

class NodoDispersa {
    
public:
    
    int posx, posy;
    std::string color;
    NodoDispersa* arriba;
    NodoDispersa* abajo;
    NodoDispersa* izquierda;
    NodoDispersa* derecha;
   
    NodoDispersa(int x, int y, std::string color){
       posx = x;
       posy = y;
       this->color = color;
       arriba = NULL;
       abajo = NULL;
       izquierda = NULL;
       derecha = NULL;
    }
    

};

#endif /* NODODISPERSA_H */

