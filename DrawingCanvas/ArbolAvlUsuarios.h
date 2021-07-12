/* 
 * File:   ArbolAvlUsuarios.h
 * Author: AlexelBro
 *
 * Created on 16 de junio de 2019, 21:37
 */

#ifndef ARBOLAVLUSUARIOS_H
#define ARBOLAVLUSUARIOS_H
#include <iostream>
#include <fstream>
#include <windows.h>
#include "ListaSimpleImagenes.h"

using namespace std;

class NodoAvlUsuario{
public:
    
    string usuario;
    NodoAvlUsuario* izdo;
    NodoAvlUsuario* dcho;
    int fe;
    ListaSimpleImagenes* listaimagenes;
    
    NodoAvlUsuario(string valor){
    usuario = valor;
    izdo = dcho = NULL;
    fe = 0;
    listaimagenes = new ListaSimpleImagenes();
    }
    
    string valorNodo(){
        return usuario; 
    }
    NodoAvlUsuario* subarbolIzdo(){
        return izdo;
    }
    NodoAvlUsuario* subarbolDcho(){
        return dcho; 
    }
    void nuevoValor(string d){
        usuario = d;
    }
    void ramaIzdo(NodoAvlUsuario* n){
        izdo = n;
    }
    void ramaDcho(NodoAvlUsuario* n){
        dcho = n; 
    }
    void visitar(){
        std::cout << "-" << usuario << std::endl;
    }
    
    void imprimir(){
        std::cout << usuario << std::endl;
    }
    
    void Pfe(int vfe){
        fe = vfe;
    }
    int Ofe(){
        return fe;
    }

};


class ArbolAvlUsuarios {
public:
    NodoAvlUsuario* raiz;
    
    ArbolAvlUsuarios(){
        raiz = NULL;
    }
    
    NodoAvlUsuario* Oraiz();
    void Praiz(NodoAvlUsuario *r);
    void preorden();
    void arbolespejo();
    void insertarAvl(NodoAvlUsuario* nuevo);
    void inorden();
    void postorden();
    void generarGrafica();
    NodoAvlUsuario* buscarUsuario(NodoAvlUsuario* r,NodoAvlUsuario* usuarionulo,string user);
    int NumeroUsuarios();
private:
    NodoAvlUsuario* rotacionII(NodoAvlUsuario * n, NodoAvlUsuario* n1);
    NodoAvlUsuario* rotacionDD(NodoAvlUsuario* n, NodoAvlUsuario* n1);
    NodoAvlUsuario* rotacionDI(NodoAvlUsuario* n, NodoAvlUsuario* n1);
    NodoAvlUsuario* rotacionID(NodoAvlUsuario* n, NodoAvlUsuario* n1);
    NodoAvlUsuario* insertarAvl(NodoAvlUsuario* raiz, NodoAvlUsuario* nuevo, bool &hc);
    void preorden(NodoAvlUsuario* r);
    void inorden(NodoAvlUsuario* r);
    void arbolespejo(NodoAvlUsuario* r);
    void escribirDot(NodoAvlUsuario* r);
    void escribirImagenes(NodoAvlUsuario *r);
    void postorden(NodoAvlUsuario* r);
    int NumeroUsuarios(NodoAvlUsuario* r,int numusuarios);
    string dotarbolavl = "";
    string dotimg = "";
};

#endif /* ARBOLAVLUSUARIOS_H */

