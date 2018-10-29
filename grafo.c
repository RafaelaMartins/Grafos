/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.c
 * Author: Rafaela Martins
 *
 * Created on 10 de Maio de 2016, 14:15
 */

#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

/*
 *
 */

 struct ares {
    int id;
    int v1;
    int v2;
};
struct grafo{
int MaximoAresta;
int MaximoVertice;
int QuantidadeAresta;
int QuantidadeVertice;
ARESTA *VETORARESTA;

};

Grafo GGcriaGrafo(int MaximoVertice, int MaximoAresta) {
//Passa Quantidade Maxima de Vertice Aresta
    if (MaximoVertice>0 && MaximoAresta>0 ) {
        Grafo G = (Grafo)malloc((sizeof(struct grafo))); //Aloca no endereço de G a estrutura
              G->VETORARESTA=(ARESTA *)malloc(MaximoAresta*sizeof(ARESTA));//Cria um vetor de estrutura aresta no ponteiro dentro do grafo
              G->MaximoAresta=MaximoAresta; //o ponteiro recebe maxix de aresta
              G->MaximoVertice=MaximoVertice;//recebe maximo de vertice
              G->QuantidadeAresta=0;
              G->QuantidadeVertice=0;
              return (G);
    }
    else return NULL;
};
Grafo GGdestroiGrafo (Grafo G){

    free(G->VETORARESTA);
    free(G);
    return NULL;

};
int GVcriaVertice(Grafo G) {
    G->QuantidadeVertice++;
    return (G->QuantidadeVertice);
};
int GAcriaAresta (Grafo G, int v1, int v2 ) {
        //fazer verificação aqui
int i;
    if (i<G->MaximoAresta && v1<=G->QuantidadeVertice && v2<=G->QuantidadeVertice){

        i=G->QuantidadeAresta;
        G->VETORARESTA[i].v1=v1;
        G->VETORARESTA[i].v2=v2;
        G->QuantidadeAresta++;
        G->VETORARESTA[i].id = (G->QuantidadeAresta);
        return ( G->VETORARESTA[i].id);
    }


};
int GBexisteIdVertice(Grafo G, int vertice) {

       if (G->QuantidadeVertice >= vertice){
           return(1);
       }
       else
           return (0);
 };
int GBexisteIdAresta (Grafo G, int Aresta) {
    int i,encontrei;
    encontrei=0;
    i=0;
        if (Aresta <= G->QuantidadeAresta){
            while (i <= G->QuantidadeAresta){
                i++;
                    if (Aresta==G->VETORARESTA[i].id){
                        encontrei=1;
                        return (1);
                    }
            }

        }

    if (encontrei ==0){
        return (0);
    }
};
int GBexisteArestaDir (Grafo G,int v2,int v1 ){
    int i;
    i=0;
        while (i<=G->QuantidadeAresta){
            i++;
                if (v2==G->VETORARESTA[i].v2 && v1==G->VETORARESTA[i].v1 ){
                    return (1);
            }
                else return (0);
        }
};
int GBexisteAresta (Grafo G,int v2,int v1 ) {
    int i;
    i=0;
        while (i<= G->QuantidadeAresta){
            i++;
                if (((v2==G->VETORARESTA[i].v2) && (v1==G->VETORARESTA[i].v1))|| ((G->VETORARESTA[i].v1==v2) &&(G->VETORARESTA[i].v2==v1)))
                {
                    return (1);
                }
                else return (0);
        }
};
int GApegaArestaDir(Grafo G,int v2,int v1) {
    int i;
    i=0;
        while (i<= G->QuantidadeAresta){
            i++;
                if (v2==G->VETORARESTA[i].v2 && v1==G->VETORARESTA[i].v1 ){
                    return (G->VETORARESTA[i].id);
                }
        }
};
int GApegaAresta (Grafo G,int v2,int v1 ) {
    int i;
    i=0;
        while (i<= G->QuantidadeAresta){
             i++;
                if (v2==G->VETORARESTA[i].v2 && v1==G->VETORARESTA[i].v1 || G->VETORARESTA[i].v1==v2 && G->VETORARESTA[i].v2==v1)
                {
                    return (G->VETORARESTA[i].id);
                }
        }
};
int GVprimeiroVertice(Grafo G){
    if (G->QuantidadeVertice == 0) {
        return (0);
    }
    else {
          return (1);
    }
};
int GVproximoVertice(Grafo G,int v1){
    int v2;
    v2=v1+1;
    if (v2<= G->QuantidadeVertice){
        return (v2);
    }
    else
        return (0);
};
int GAprimeiraAresta(Grafo G){
    if (G->QuantidadeAresta!=0){
        return (G->VETORARESTA[0].id);
    }
    else
        return (0);
};
int GAproximaAresta(Grafo G,int IDVertice){
    if (G->QuantidadeAresta > IDVertice ){
    return (G->VETORARESTA[IDVertice].id);
    }
    else {
        return (0);
    }
};
int GInumeroVertices(Grafo G){
    if (G->QuantidadeVertice!= 0){
       return (G->QuantidadeVertice);
    }
    else {
        return (0);}
                          };
int GInumeroArestas(Grafo G) {
   if (G->QuantidadeAresta!=0) {
       return (G->QuantidadeAresta);
   }
   else {
       return (0);
      }
};
int GInumeroArestasMax(Grafo G){
    if (G->MaximoAresta!=0){
        return (G->MaximoAresta);
    }
    else
        return (0);
};
int GInumeroVerticesMax(Grafo G){
   if (G->MaximoAresta!=0){
        return (G->MaximoAresta);
    }
    else
        return (0);
};
/*Grafo GGcarregaGrafo (char *p) {

    FILE *arquivo = fopen(p,"r");
    return *arquivo;
    //MUITO BAD
};*/
int GIpegaGrau (Grafo G,int vertice) {
    int i;
    int grau;
     grau=0;
     i=0;
     while (G->QuantidadeAresta>=i) {
        if (G->VETORARESTA[i].v1 == vertice || G->VETORARESTA[i].v2 == vertice){
        grau =grau+1;
        }
        i++;        //OBSERVAR
    };
    if (G->QuantidadeVertice != 0){
        return (grau);
    }
    else {
        return (0);
    }
};
int GAprimaAresta(Grafo G, int vertice){
    int aresta,i;
    i=0;
    aresta=0;
    while (G->QuantidadeAresta>=i) {
        if (vertice==G->VETORARESTA[i].v1 && aresta<1 || vertice==G->VETORARESTA[i].v2 && aresta<1 ){
            aresta=1;
            return (G->VETORARESTA[i].id);
        }                   //2
        i++;
    }
    if ((aresta==0)||(G->QuantidadeAresta == 0))  {
        return (0);
    }
};
int GAproxAresta(Grafo G,int IDAresta,int vertice){

    int i;
    i=IDAresta;

        if (GAprimaAresta(G,vertice)<IDAresta){
            while (G->VETORARESTA[i].v1!=vertice ||G->VETORARESTA[i].v2!=vertice){
                i++;
                                //2
        }
            return (G->VETORARESTA[i].id);
    }
        else return(GAprimaAresta(G,vertice));

};
int GAprimaEntrada(Grafo G,int vertice){
    int i=0;
    int cont;
    cont=0;
    if (GBexisteIdVertice(G,vertice)!=0 ){

        while(i <= G->QuantidadeAresta && cont!=1) {
            if (G->VETORARESTA[i].v1==vertice){
                cont=cont+1;
                return (G->VETORARESTA[i].id);
            }
            i++;
        }
    }
    if (cont==0){return (0);
    };
};
int GAproxEntrada (Grafo G,int vertice,int aresta){
    int i,achou;
    achou=0;

    if (GAprimaEntrada(G,vertice)!=0){
       i=GAprimaEntrada(G,vertice);
       while (i<=G->QuantidadeAresta && achou!=0){
           if (G->VETORARESTA[i].v1==vertice){
               achou=achou+1;
               return G->VETORARESTA[i].id;
           }
           i++;
       }
    }
    if (achou==0){
        return(0);
    }
};
int GAprimaSaida(Grafo G, int vertice){
    int i=0;
    int cont;
    cont=0;


        while(i <= G->QuantidadeAresta && cont!=1) {
            if (G->VETORARESTA[i].v2==vertice){
                cont=cont+1;
                return (G->VETORARESTA[i].id);
            }
            i++;
        }

    if (cont==0){return (0);
    }
};
int GAproxSaida(Grafo G,int vertice,int IDVertice){
int i=0;
int cont=0;

            while(i<= (G->QuantidadeAresta) && cont!=2) {
                if (G->VETORARESTA[i].v1==vertice && G->VETORARESTA[i].id==IDVertice){
                    cont=cont+1;

            }
                    i++;
        }

    if (cont==0){
        return (0);
    }
    else {
        return (G->VETORARESTA[i].id);
    }
};
int GBarestaLaco(Grafo G,int idAresta){
    int i=0;
    int P=0;
        while (i <= G->QuantidadeAresta){
            if (idAresta==G->VETORARESTA[i].id){
                P=G->VETORARESTA[i].v2;
                return (P);
            }
            i++;
        }
        if (P==0)
        {
        return (P);
        }
};
int GValfa(Grafo G,int idAresta){
int i=0;
 int P=0;
 while (i <= G->QuantidadeAresta){
    if (idAresta==G->VETORARESTA[i].id){

        P=G->VETORARESTA[i].v1;
        return (P);
    }
    i++;
 }

 if (P==0){
    return (0);
 }
};
int GVomega(Grafo G,int idAresta){
int i=0;
int P=0;
 while (i <= G->QuantidadeAresta){
    if (idAresta==G->VETORARESTA[i].id){
        int P=0;
        P=G->VETORARESTA[i].v2;
        return (P);
    }
    i++;
 }

 if (P==0){
    return (0);
 }
};
Grafo GBsalvaGrafo(Grafo G){
	int i;
	FILE *f ;

	f = fopen("Grafo.txt", "w");

	fputc(G->QuantidadeVertice,f);
	fputc(' ',f);
	fputc(G->QuantidadeAresta,f);
	fputc('\n',f);

	for(i=0;i<G->QuantidadeAresta;i++){
		fputc(G->VETORARESTA[i].id,f);
		fputc(' ',f);
		fputc(G->VETORARESTA[i].v1,f);
		fputc(' ',f);
		fputc(G->VETORARESTA[i].v2,f);
		fputc('\n',f);
	}

	fclose(f);
}
int GVvizinho (Grafo G,int v1,int idAresta){
int i=0;
int P=0;
    while (i <= G->QuantidadeAresta){
        if (v1==G->VETORARESTA[i].v1 && G->VETORARESTA[i].id==idAresta ||v1==G->VETORARESTA[i].v2 && G->VETORARESTA[i].id==idAresta){
            P=G->VETORARESTA[i].v2;
            return (P);
        }

        i++;
    }

        if (P==0){
            return(0);
        }
}; //VERIFICAR SE TEM Q SER BILATERAL



int main
(int argc, char** argv) {

int MaxV,MaxA,V1,Aresta1,V2,Aresta2,EV,V3,EV2,A3,EA,EA2;
MaxA=5;
MaxV=5;
printf("%d%d\n",MaxA,MaxV);
V3=5;
A3=8;
Grafo T=GGcriaGrafo(MaxV,MaxA);
V1=GVcriaVertice(T);
V2=GVcriaVertice(T);
printf("Vertice1:%d CRIADO \n",V1);
printf("Vertice2:%d CRIADO\n",V2);
Aresta1=GAcriaAresta (T,V1,V2);
printf("Aresta:%d CRIADO\n",Aresta1);
Aresta2=GAcriaAresta (T,V2,V1);
printf("Aresta:%d CRIADO\n",Aresta2);
EV2=GBexisteIdVertice(T,V3);
EV=GBexisteIdVertice(T,V1);
    if (EV)
    {
    printf("Existe %d o vertice \n",V1);
    }
    else
    {
    printf("Nao Existe o vertice %d \n",V1);
    }
    if (EV2){
        printf("O Vertice %d Existe \n",V3);
    }
    else {
    printf("O Vertice %d Nao Existe \n",V3);
    }
    EA=GBexisteIdAresta(T,Aresta2);
    EA2=GBexisteIdAresta (T,A3);
    if (EA){
    printf("A Aresta %d Existe \n",Aresta1);
    }
    else{
    printf("A Aresta %d Nao Existe \n",Aresta1);
    }

     if (EA2){
    printf("%d Existe \n",A3);
    }
    else{
    printf("%d Nao Existe \n",A3);
    }



T=GGdestroiGrafo (T);





    return (EXIT_SUCCESS);
}

