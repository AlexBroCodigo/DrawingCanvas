/* 
 * File:   ArbolAvlUsuarios.cpp
 * Author: AlexelBro
 * 
 * Created on 16 de junio de 2019, 21:37
 */

#include "ArbolAvlUsuarios.h"

NodoAvlUsuario* ArbolAvlUsuarios :: Oraiz(){
    return raiz;
}

void ArbolAvlUsuarios :: Praiz (NodoAvlUsuario* r){
    raiz = r;
}

void ArbolAvlUsuarios::preorden()
{
    preorden(raiz);
}

void ArbolAvlUsuarios::preorden(NodoAvlUsuario* r){
    if (r != NULL){
        r->imprimir();
        preorden (r->subarbolIzdo());
        preorden (r->subarbolDcho());
    }
}

void ArbolAvlUsuarios ::inorden(){
    inorden(raiz);
}

void ArbolAvlUsuarios :: inorden(NodoAvlUsuario* r){
    if (r != NULL){
        inorden (r->subarbolIzdo());
        r->imprimir();
        inorden (r->subarbolDcho());
    }
}

void ArbolAvlUsuarios ::postorden(){
    postorden(raiz);
}

void ArbolAvlUsuarios :: postorden(NodoAvlUsuario* r){
    if (r != NULL){
        postorden(r->subarbolIzdo());
        postorden(r->subarbolDcho());
        r->imprimir();
    }
}

int ArbolAvlUsuarios :: NumeroUsuarios(){
    int numusuarios = 0;
    numusuarios = NumeroUsuarios(raiz,numusuarios);
    return numusuarios;
}

int ArbolAvlUsuarios :: NumeroUsuarios(NodoAvlUsuario* r,int numusuarios){
    if(r!=NULL){
        numusuarios++;
        numusuarios = NumeroUsuarios(r->subarbolIzdo(),numusuarios);
        numusuarios = NumeroUsuarios(r->subarbolDcho(),numusuarios);
    }
    return numusuarios;
}



void ArbolAvlUsuarios :: arbolespejo(){
    arbolespejo(raiz);
}

void ArbolAvlUsuarios :: arbolespejo(NodoAvlUsuario* r){
    if (r != NULL){
        arbolespejo(r->subarbolDcho());
        r->imprimir();
        arbolespejo(r->subarbolIzdo());
    }
}





NodoAvlUsuario* ArbolAvlUsuarios :: buscarUsuario(NodoAvlUsuario* r,NodoAvlUsuario* usuarionulo,string user){
    if (r != NULL){
        if(r->usuario == user){
            usuarionulo = r;
            return usuarionulo;
        } else {
            if(r->subarbolIzdo()!= NULL && usuarionulo==NULL){
                usuarionulo = buscarUsuario(r->subarbolIzdo(),usuarionulo,user);
            }
            if(r->subarbolDcho()!= NULL && usuarionulo==NULL){
                usuarionulo = buscarUsuario(r->subarbolDcho(),usuarionulo,user);
            }
            return usuarionulo;
        }
        
    }
}


NodoAvlUsuario* ArbolAvlUsuarios :: rotacionII(NodoAvlUsuario* n, NodoAvlUsuario* n1){
    n->ramaIzdo(n1->subarbolDcho());
    n1->ramaDcho(n);
    if(n1->Ofe()==-1){
        n->Pfe(0);
        n1->Pfe(0);
    }
    else{
    n->Pfe(-1);
    n1->Pfe(1);
    }
    return n1;
}

NodoAvlUsuario* ArbolAvlUsuarios :: rotacionDD(NodoAvlUsuario* n, NodoAvlUsuario* n1){
    n->ramaDcho(n1->subarbolIzdo());
    n1->ramaIzdo(n);
    if(n1->Ofe()==+1)
    {
        n->Pfe(0);
        n1->Pfe(0);
    }
    else
    {
        n->Pfe(+1);
        n1->Pfe(-1);
    }
    return n1;
}

NodoAvlUsuario* ArbolAvlUsuarios :: rotacionDI(NodoAvlUsuario* n, NodoAvlUsuario* n1){
    NodoAvlUsuario* n2;
    n2 = n1->subarbolIzdo();
    n->ramaDcho(n2->subarbolIzdo());
    n2->ramaIzdo(n);
    n1->ramaIzdo(n2->subarbolDcho());
    n2->ramaDcho(n1);
    if (n2->Ofe() == +1)
    n->Pfe(-1);
    else
    n->Pfe(0);
    if (n2->Ofe() == -1)
    n1->Pfe(+1);
    else
    n1->Pfe(0);
    n2->Pfe(0);
    return n2;
}

NodoAvlUsuario* ArbolAvlUsuarios::rotacionID(NodoAvlUsuario* n, NodoAvlUsuario* n1){
    NodoAvlUsuario* n2;
    n2 = n1->subarbolDcho();
    n->ramaIzdo(n2->subarbolDcho());
    n2->ramaDcho(n);
    n1->ramaDcho(n2->subarbolIzdo());
    n2->ramaIzdo(n1);
    if (n2->Ofe() == +1)
    n1->Pfe(-1);
    else
    n1->Pfe(0);
    if (n2->Ofe() == -1)
    n->Pfe(1);
    else
    n->Pfe(0);
    n2->Pfe(0);
    return n2;
}

void ArbolAvlUsuarios::insertarAvl(NodoAvlUsuario* nuevo){
    bool hc = false;
    raiz = insertarAvl(raiz,nuevo,hc);
}



NodoAvlUsuario* ArbolAvlUsuarios::insertarAvl(NodoAvlUsuario* raiz,NodoAvlUsuario* nuevo, bool &hc){
    NodoAvlUsuario *n1;
    if (raiz == NULL)
    {
        raiz = nuevo;
        hc = true;
    }
    else if (nuevo->usuario < raiz->valorNodo())
    {
        NodoAvlUsuario *iz;
        iz = insertarAvl(raiz->subarbolIzdo(),nuevo, hc);
        raiz->ramaIzdo(iz);
        if (hc)
        {
            switch (raiz->Ofe())
            {
                case 1:
                    raiz->Pfe(0);
                    hc = false;
                    break;
                case 0:
                    raiz->Pfe(-1);
                    break;
                case -1:
                    n1 = raiz->subarbolIzdo();
                    if (n1->Ofe() == -1)
                        raiz = rotacionII(raiz, n1);
                else
                    raiz = rotacionID(raiz, n1);
                    hc = false;
            }
        }
    }
    else if (nuevo->usuario > raiz->valorNodo())
    {
        NodoAvlUsuario *dr;
        dr = insertarAvl(raiz->subarbolDcho(),nuevo, hc);
        raiz->ramaDcho(dr);
        if (hc)
        {
            switch (raiz->Ofe())
            {
                case 1:
                    n1 = raiz->subarbolDcho();
                    if (n1->Ofe() == +1)
                        raiz = rotacionDD(raiz, n1);
                    else
                        raiz = rotacionDI(raiz,n1);
                        hc = false;
                        break;
                case 0:
                    raiz->Pfe(+1);
                    break;
                case -1:
                    raiz->Pfe(0);
                    hc = false;
            }
        }
    }
    else
        throw "No puede haber claves repetidas " ;
    return raiz;
}

void ArbolAvlUsuarios:: generarGrafica(){

    escribirDot(raiz);
    ofstream archivo;
    string textodot = "digraph Usuarios{\n node [shape = record, color=blue3, height=0.1];\n";
    textodot += dotarbolavl;
    textodot += "node[shape=box, color=crimson, height=0.1];\n";
    escribirImagenes(raiz);
    textodot += dotimg;
    dotarbolavl = "";
    dotimg="";
    archivo.open("ArbolUsuariosAvl.dot",ios::out); 
    
    if(archivo.fail()){
        cout << "No se pudo abrir el archivo";
    }
    
    archivo << textodot + "\n}";
    archivo.close();
    system("dot ArbolUsuariosAvl.dot -Tpng -o ArbolUsuariosAvl.png");
    ShellExecute(NULL,"open","ArbolUsuariosAvl.png","","",0);

}

void ArbolAvlUsuarios::escribirDot(NodoAvlUsuario *r){
    
    if (r != NULL)
    {
    dotarbolavl += "nodeAU" + r->usuario + "[label = \"<f0> | <f1> " + r->usuario + " | <f2>\"];\n";
    escribirDot(r->subarbolIzdo());
    if(r->subarbolIzdo() != NULL){
        dotarbolavl+= "\"nodeAU" + r->usuario+"\":f0 -> \"nodeAU" + r->subarbolIzdo()->usuario + "\":f1;\n";
    }
    escribirDot(r->subarbolDcho());
    if(r->subarbolDcho() != NULL){
        dotarbolavl+= "\"nodeAU" + r->usuario+"\":f2 -> \"nodeAU" + r->subarbolDcho()->usuario + "\":f1;\n";
    }
    }
}

void ArbolAvlUsuarios:: escribirImagenes(NodoAvlUsuario *r){
    if (r != NULL){
        if(r->listaimagenes->primero!=NULL){
            Img* actual = r->listaimagenes->primero;
            dotimg += "\"nodeAU"+r->usuario + "\":f1 -> nodoimg"+r->usuario+actual->idimagen+";\n";
            while(actual!=NULL){
                dotimg += "nodoimg"+r->usuario+actual->idimagen+" [label = \"img"+actual->idimagen+"\"];\n";
                if(actual->siguiente!=NULL){
                    dotimg += "nodoimg"+r->usuario+actual->idimagen+" -> nodoimg"+r->usuario+actual->siguiente->idimagen+" [constraint=true];\n";
                }
                actual = actual->siguiente;
            }
        }
        escribirImagenes(r->subarbolIzdo());
        escribirImagenes(r->subarbolDcho());
    }
}

