/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Grafo.h
 * Author: Rafaela Martins
 *
 * Created on 10 de Maio de 2016, 14:19
 */

#ifndef GRAFO_H
#define GRAFO_H

typedef struct ares ARESTA;
typedef struct grafo *Grafo;

Grafo GGcriaGrafo(int MaximoVertice, int MaximoAresta);
Grafo GGdestroiGrafo (Grafo G);
int GVcriaVertice(Grafo G);
int GAcriaAresta (Grafo G, int v1, int v2 );
int GBexisteIdVertice(Grafo G, int vertice) ;
int GBexisteIdAresta (Grafo G, int Aresta);
int GBexisteArestaDir (Grafo G,int v2,int v1 );
int GBexisteAresta (Grafo G,int v2,int v1 );
int GApegaArestaDir(Grafo G,int v2,int v1);
int GApegaAresta (Grafo G,int v2,int v1 );
int GVprimeiroVertice(Grafo G);
int GVproximoVertice(Grafo G,int v1);
int GAprimeiraAresta(Grafo G);
int GAproximaAresta(Grafo G,int IDVertice);
int  GInumeroVertices(Grafo G);
int GInumeroArestas(Grafo G);
int GInumeroArestasMax(Grafo G);
int GInumeroVerticesMax(Grafo G);
Grafo GGcarregaGrafo (char *p);
int GIpegaGrau (Grafo G,int vertice);
int GAprimaAresta(Grafo G, int vertice);
int GAproxAresta(Grafo G,int IDAresta,int vertice);
int GAprimaEntrada(Grafo G,int vertice);
int GAproxEntrada (Grafo G,int vertice,int aresta);
int GAprimaSaida(Grafo G, int vertice);
int GAproxSaida(Grafo G,int vertice,int IDaresta);
int GBarestaLaco(Grafo G,int idAresta);
int GValfa(Grafo G,int idAresta);
int GVomega(Grafo G,int idAresta);
Grafo GBsalvaGrafo(Grafo G);
int GVvizinho (Grafo G,int v1,int idAresta);





#endif /*GRAFO_H */

