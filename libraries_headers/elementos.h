#ifndef ELEMENTOS_H
#define ELEMENTOS_H

typedef struct{

    char Nome[50];
    int Idade;
    char Github[30];
    char Email[50];

}Pessoa;

<<<<<<< HEAD
typedef struct noPilha{
    int valor;
    struct noPilha *proximo;
}NoPilha;
=======
typedef struct no {
    int valor;
    struct no *direita, *esquerda;
}NoArv;
>>>>>>> arvore-binaria

typedef struct noFila{
    int valor;
    struct noFila *proximo;
}NoFila;

typedef struct noLista {
    int valor;
    struct noLista *proximo;
}NoLista;

typedef struct noListaDupla {
    int valor;
    struct noListaDupla *proximo;
    struct noListaDupla *anterior;
}NoListaDupla;
#endif

