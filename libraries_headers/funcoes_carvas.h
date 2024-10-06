//Aqui serão declaradas as funções feitas pelo Lucas Carvalho
#ifndef FUNCOES_CARVAS_H
#define FUNCOES_CARVAS_H

#include "elementos.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no {  //Criação da estrutura nó para implementar nas estruturas pilha, fila, lista encadeada e duplamente encadeada
    Pessoa pessoa;
    struct no *proximo;
}No;

Pessoa cadastrarPessoa() {   //Função para cadastrar

    Pessoa p;

    printf("Cadastrando Programador\n\n");
    printf(" Insira o nome: ");
    scanf("%s",&p.Nome);
    printf("Insira a idade: ");
    scanf("%d",&p.Idade);
    wprintf(L"Insira o nome de usuário do Github: ");
    scanf("%s",&p.Github);
    printf("Insira o email para contato: ");
    scanf("%s",&p.Email);

    return p;
}
void imprimirPessoa(Pessoa pessoa) {

    printf("Nome: %s",pessoa.Nome);
    printf("\nidade: %d",pessoa.Idade);
    wprintf(L"\nNome de Usuário: %s",pessoa.Github);
    printf("\nEmail: %s",pessoa.Email);

}

//Funções para a estrutura pilha

No* empilhar_push(No *topo) {    //Função recebe como parâmetro um ponteiro que referencia a estrutura No para que seja possivel acessar a estrutura No, lembrando que No* é porque a função retorna um PONTEIRO para um nó

    No *novo = malloc(sizeof(No));  //Declarei uma variável do tipo ponteiro para No (estrutura No) que recebe a alocação de memória do tamanho No (o numero de bytes que a estrutura No ocupa)

    if(novo) {                       //Verificação pra saber se a alocação de memória no ponteiro foi bem sucedida, ou seja, novo tem q existir e estar vazio
        novo->pessoa = cadastrarPessoa();  //Como novo é um ponteiro para a estrutura No, utilizamos ele para apontar a variável do tipo Pessoa(estrutura Pessoa) presente dentro da estrutura No, onde receberá os dados retornados pela função cadastrarPessoa
        novo->proximo = topo; //Utilizamos o mesmo ponteiro porém agora apontando para o PONTEIRO do tipo No que está presente na propria estrutura No (um tipo de ponteiro recursivo, onde a estrutura tem um dado do mesmo tipo da estrutura em que se encontra) para indicar onde está o topo da nossa pilha
        return novo;  //retorna o endereço de memória para qual novo aponta, ou seja, onde este "novo nó" foi alocado
    }else {
        wprintf(L"Erro ao alocar memória");
    }
    return NULL;  //se houver erro na alocação de memória nós retornamos nulo
}
No* desempilhar_pop(No **topo) {  //A utilização de um ponteiro para ponteiro aqui se faz necessária para que o parametro recebido seja o ENDEREÇO de topo, ou seja, onde o ponteiro original está, acessando o conteúdo da estrutura No

    if(*topo != NULL){      // Se o CONTEUDO armazenado no endereço de topo não for nulo ele executa
        No *remover = *topo; //o ponteiro remover armazena o conteudo apontado pelo ponteiro topo
        *topo = remover->proximo; //o conteúdo do ponteiro topo se torna o conteudo do ponteiro proximo
        return remover;     //retorna o endereço de memória para qual remover aponta, ou seja, onde o no "topo" anterior estava
    }else {
        printf("pilha vazia");
    }
    return NULL; //se a pilha estiver vazia não ha o que retornar, então retornamos nulo
}

void imprimir_pilha(No *topo) {
    printf("\n-------------Inseridos na Pilha-----------\n");
    while(topo) { // serve funciona verificando se o ponteiro topo ainda está apontando para algum endereço, se não houver nenhum endereço sendo apontado então topo == NULL e a condição de parada do While é atendida
        imprimirPessoa(topo->pessoa);  //imprime de cima para baixo começando no topo da pilha
        printf("\n-------------------------------------------\n");
        topo = topo->proximo;  //apos imprimir o topo da pilha, o ponteiro topo vai receber o endereço do ponteiro topo o onde o ponteiro do tipo No é referenciado, buscando seu conteudo que por consequencia aponta para outro nó e assim segue até que o ponteiro "proximo" aponte para NULL

    }

}

void pilha_exe() {
    int opPilha;
    No *remover, *topo = NULL;

    do {
        printf("===== MENU PILHA =====\n");
        printf("1. Empilhar\n");
        printf("2. Desempilhar\n");
        printf("3. Imprimir Pilha\n");
        printf("0. Sair\n");
        printf("==========================\n");
        wprintf(L"Qual função deseja escolher: ");
        scanf("%d",&opPilha);

        switch(opPilha){

            case 1:
                topo = empilhar_push(topo);
            printf("\nEmpilhando...\n\n");
                break;

            case 2:
                remover = desempilhar_pop(&topo);

                if(remover) {
                    printf("\nO cadastro: \n");
                    printf("--------------------\n");
                    imprimirPessoa(remover->pessoa);
                    printf("\n--------------------\n");
                    printf("Foi removido da pilha com sucesso!\n\n1");
                    free(remover);
                }else {
                    printf("pilha vazia");
                }
                break;

            case 3:
                imprimir_pilha(topo);
                break;

            default:

                if(opPilha == 0) {
                    printf("Encerrando Programa...");
                    break;
                }
            wprintf(L"Opção inválida");
        }
    }while(opPilha != 0);
}

void menuCarvas() {

    int opCarvas;

    do{

        printf("======= MENU CARVAS =======\n");
        printf("1. Menu Pilha\n");
        printf("2. Menu Fila\n");
        printf("3. Menu Lista\n");
        wprintf(L"4. Métodos de Ordenação");
        wprintf(L"5. Métodos de Busca\n");
        printf("0. Sair\n");
        printf("==========================\n");
        wprintf(L"Qual menu de funções deseja escolher: ");
        scanf("%d",&opCarvas);

        switch(opCarvas){

            case 1:
                pilha_exe();
            break;


            case 2:

                break;

            case 3:

                break;

            case 4:

                break;

            default:

                if(opCarvas == 0) {
                    printf("Encerrando Programa...");
                    break;
                }
            wprintf(L"Opção inválida");
        }
    }while(opCarvas != 0);
}
#endif
