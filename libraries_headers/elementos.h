#ifndef ELEMENTOS_H
#define ELEMENTOS_H

typedef struct{

    char Nome[50];
    int Idade;
    char Github[30];
    char Email[50];

}Pessoa;

typedef struct no {
    int valor;
    struct no *direita, *esquerda;
}NoArv;

#endif

