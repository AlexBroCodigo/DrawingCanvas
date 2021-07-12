/* 
 * File:   MatrizDispersa.cpp
 * Author: AlexelBro
 * 
 * Created on 17 de junio de 2019, 0:55
 */

#include "MatrizCapa.h"

void MatrizCapa :: agregarPixel(int x, int y, string color){
    bool encontrado = false;
    if(laterales->primero!=NULL){
         NodoLateral* lat = laterales->primero;
         while(lat!=NULL  && encontrado!=true){
            NodoDispersa* nodoverificacion = lat->fila->primero;
            while(nodoverificacion!=NULL){
                if(nodoverificacion->posx==x && nodoverificacion->posy==y){
                    nodoverificacion->color = color;
                    encontrado = true;
                    break;
                }
                nodoverificacion = nodoverificacion->derecha;
            }
            lat = lat->siguiente;
        }
    }
    
    if(encontrado==false){
        NodoDispersa* nuevo = new NodoDispersa(x,y,color);
    
        NodoCabecera* cabecera = cabeceras->buscarCabecera(x);
    
        if(cabecera!=NULL){
            cabecera->columna->insertarDispersa(nuevo);
        } else {
            cabecera = new NodoCabecera(x);
            cabecera->columna->insertarDispersa(nuevo);
            cabeceras->ingresarCabecera(cabecera);
        }
    
        NodoLateral* lateral = laterales->buscarLateral(y);
    
        if(lateral!=NULL){
            lateral->fila->insertarDispersa(nuevo);
        } else {
            lateral = new NodoLateral(y);
            lateral->fila->insertarDispersa(nuevo);
            laterales->ingresarLateral(lateral);
        }
    }
    
}

void MatrizCapa :: generarLienzo(){
    ofstream archivo;
    archivo.open("LienzoMatriz.dot",ios::out);
    
    if(archivo.fail()){
        cout << "No se pudo abrir el archivo";
    }
    archivo << escribirLienzo() << "\n}";
    archivo.close();
    
    system("dot LienzoMatriz.dot -Tpng -o LienzoMatriz.png");
    ShellExecute(NULL,"open","LienzoMatriz.png","","",0);
}

string MatrizCapa :: escribirLienzo(){
    string textodot = "digraph Lienzo{\n tabla[\n shape=plaintext\n label=<\n <table border='0' cellborder='1' cellspacing='0' color='black'>\n";
    bool titulo = true;
    int columnafinal = cabeceras->ultimo->x;
    int filafinal = laterales->ultimo->y;
    
    NodoLateral* lateral = laterales->primero;
    for(int i=-1;i<=filafinal;i++){
        textodot += "   <tr>\n";
        if(titulo == true){
            textodot += "       <td width=\"50\" height=\"50\" bgcolor=\"#FFFFFF\">Matriz</td>\n";
            titulo = false;
        }
        NodoDispersa* nodocolor = lateral->fila->primero;
        for(int j=-1;j<=columnafinal;j++){
            if(i==-1 && j<columnafinal){
                textodot+= "        <td width=\"50\" height=\"50\" bgcolor=\"#FFFFFF\">"+castear(j+1)+"</td>\n";
            } else{
                if(j==-1){
                    textodot+= "        <td width=\"50\" height=\"50\" bgcolor=\"#FFFFFF\">"+castear(i)+"</td>\n";
                } else{
                    if(nodocolor->posy==i && nodocolor->posx==j){
                        textodot += "       <td width=\"50\" height=\"50\" bgcolor=\""+nodocolor->color+"\"></td>\n";
                        if(nodocolor->derecha!=NULL){
                            nodocolor = nodocolor->derecha;
                        }
                    } else{
                        if(i==-1 && j==columnafinal){
                            
                        } else{
                            textodot+= "        <td width=\"50\" height=\"50\" bgcolor=\"#FFFFFF\"></td>\n";
                        }
                            
                    }
                }
            }
        }
        textodot += "   </tr>\n";
        if(lateral->y==i){
            lateral = lateral->siguiente;
        }
    }
    textodot+=" </table>\n >];\n";
    
    return textodot;
    
}


void MatrizCapa :: generarGrafica(){
    
    ofstream archivo;
    archivo.open("GraficaMatrizCapa.dot",ios::out);
    
    if(archivo.fail()){
        cout << "No se pudo abrir el archivo";
    }
    archivo << escribirMatrizCapa() + "\n}";
    archivo.close();
    
    system("neato -Tsvg -O GraficaMatrizCapa.dot");
    ShellExecute(NULL,"open","GraficaMatrizCapa.dot.svg","","",0);
}

string MatrizCapa :: castear(int i){
    std::string cadenai = static_cast<std::ostringstream*>(&(std::ostringstream() << i))->str();
    return cadenai;
}


string MatrizCapa :: escribirMatrizCapa(){
    int columna = 1;
    int fila = 1;
    string textodot = "digraph MatrizDispersa{\n nodesep = 0.5;\n node[shape=box, width=0.5, fontsize=11, color=turquoise4, fillcolor=white, style=filled];\n edge[color=tomato];\n";
    
    textodot+= "m[label=\"Matriz\"; pos = \"0,-0!\"];\n";
    
    NodoCabecera* cabecera = cabeceras->primero;
    textodot+= "m -> nodeC"+castear(cabecera->x)+";\n";
    while(cabecera!=NULL){
        textodot += "nodeC"+castear(cabecera->x)+" [label=\"x: "+castear(cabecera->x)+"\", pos=\""+castear(columna)+",-0!\"];\n";
        if(cabecera->siguiente!=NULL){
            textodot += "nodeC"+castear(cabecera->x)+" -> nodeC"+castear(cabecera->siguiente->x)+" -> nodeC"+castear(cabecera->x)+";\n";
        }
        ++columna;
        cabecera = cabecera->siguiente;
    }
    
    NodoLateral* lateral = laterales->primero;
    textodot+= "m -> nodeL"+castear(lateral->y)+";\n";
    while(lateral!=NULL){
        textodot+="nodeL"+castear(lateral->y)+" [label=\"y: "+castear(lateral->y)+"\"; pos=\"0,-"+castear(fila)+"!\"];\n";
        if(lateral->siguiente!=NULL){
            textodot+= "nodeL"+castear(lateral->y)+" -> nodeL"+castear(lateral->siguiente->y)+" -> nodeL"+castear(lateral->y)+";\n"; 
        }
        ++fila;
        lateral = lateral->siguiente;
    }
    
    columna = 1;
    fila = 1;
    cabecera = cabeceras->primero;
    lateral = laterales->primero;
    NodoDispersa* nodocolor;
    
    while(cabecera!=NULL){
        nodocolor = cabecera->columna->primero;
        lateral = laterales->primero;
        while(nodocolor!=NULL){
            if(lateral->y==nodocolor->posy){
                textodot+= "nodeColor"+castear(nodocolor->posy)+"l"+castear(nodocolor->posx)+"c"+" [label=\""+nodocolor->color+"\", pos=\""+castear(columna)+",-"+castear(fila)+"!\"];\n";
                if(nodocolor->arriba==NULL){
                    textodot+="nodeC"+castear(cabecera->x)+" -> nodeColor"+castear(nodocolor->posy)+"l"+castear(nodocolor->posx)+"c"+" -> nodeC"+castear(cabecera->x)+";\n";
                    if(nodocolor->abajo!=NULL){
                        textodot+= "nodeColor"+castear(nodocolor->posy)+"l"+castear(nodocolor->posx)+"c"+" -> nodeColor"+castear(nodocolor->abajo->posy)+"l"+castear(nodocolor->abajo->posx)+"c"+" -> nodeColor"+castear(nodocolor->posy)+"l"+castear(nodocolor->posx)+"c;\n";
                    }
                } else if(nodocolor->abajo==NULL){
                
                } else{
                    textodot+= "nodeColor"+castear(nodocolor->posy)+"l"+castear(nodocolor->posx)+"c -> nodeColor"+castear(nodocolor->abajo->posy)+"l"+castear(nodocolor->abajo->posx)+"c -> nodeColor"+castear(nodocolor->posy)+"l"+castear(nodocolor->posx)+"c;\n";
                }
                ++fila;
                lateral = lateral->siguiente;
                nodocolor = nodocolor->abajo;
            } else{
                ++fila;
                lateral = lateral->siguiente;
                
            }
        }
        ++columna;
        fila=1;
        cabecera = cabecera->siguiente;
    }
    
    lateral = laterales->primero;
    while(lateral!=NULL){
        nodocolor = lateral->fila->primero;
        while(nodocolor!=NULL){
            if(nodocolor->izquierda==NULL){
                textodot+= "nodeL"+castear(lateral->y)+" -> nodeColor"+castear(nodocolor->posy)+"l"+castear(nodocolor->posx)+"c -> nodeL"+castear(lateral->y)+";\n";
                if(nodocolor->derecha!=NULL){
                    textodot += "nodeColor"+castear(nodocolor->posy)+"l"+castear(nodocolor->posx)+"c -> nodeColor"+castear(nodocolor->derecha->posy)+"l"+castear(nodocolor->derecha->posx)+"c -> nodeColor"+castear(nodocolor->posy)+"l"+castear(nodocolor->posx)+"c;\n";
                }
            } else if(nodocolor->derecha==NULL){
                
            } else{
                textodot += "nodeColor"+castear(nodocolor->posy)+"l"+castear(nodocolor->posx)+"c -> nodeColor"+castear(nodocolor->derecha->posy)+"l"+castear(nodocolor->derecha->posx)+"c -> nodeColor"+castear(nodocolor->posy)+"l"+castear(nodocolor->posx)+"c;\n"; 
            }
            nodocolor = nodocolor->derecha;
        }
        lateral = lateral->siguiente;
    }
    
    
    return textodot;
}
