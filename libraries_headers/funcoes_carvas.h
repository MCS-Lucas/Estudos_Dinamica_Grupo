//Aqui serão declaradas as funções feitas pelo Lucas Carvalho
#ifndef FUNCOES_CARVAS_H
#define FUNCOES_CARVAS_H

#include "elementos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {  //Criação da estrutura nó para implementar nas estruturas pilha, fila, lista encadeada e duplamente encadeada
    Pessoa pessoa;
    struct no *proximo;
}No;

Pessoa cadastrarPessoa() {   //Função para cadastrar

    Pessoa p;

    printf("Cadastrando Programador\n\n");
    printf(" Insira o nome: ");
    getchar();
    fgets(p.Nome, 49, stdin);
    printf("Insira a idade: ");
    scanf("%d",&p.Idade);
    getchar();
    wprintf(L"Insira o nome de usuário do Github: ");
    fgets(p.Github, 29, stdin);
    printf("Insira o email para contato: ");
    fgets(p.Email, 49, stdin);

    return p;
}
void imprimirPessoa(Pessoa pessoa) {

    printf("Nome: %s",pessoa.Nome);
    printf("idade: %d",pessoa.Idade);
    wprintf(L"\nNome de Usuário: %s",pessoa.Github);
    printf("Email: %s",pessoa.Email);

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
        printf("-------------------------------------------\n");
        topo = topo->proximo;  //apos imprimir o topo da pilha, o ponteiro topo vai receber o endereço do ponteiro topo o onde o ponteiro do tipo No é referenciado, buscando seu conteudo que por consequencia é outro endereço que aponta para outro nó e assim segue até que o ponteiro "proximo" aponte para NULL

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
                topo = empilhar_push(topo); //Por empilhar_push() retornar o endereço do novo topo é necessario atribuir seu valor ao ponteiro topo  ( (topo)passa uma copia do ponteiro topo para a função) para adicionar um novo elemento no topo da pilha
                printf("\nEmpilhando...\n\n");
                break;

            case 2:
                remover = desempilhar_pop(&topo);   //Por desempilhar_pop() retornar um endereço é necessario atribuir o seu valor ao ponteiro remover, porém desta vez o parametro é o ENDEREÇO do ponteiro topo, não uma copia do ponteiro, pois remover precisa alterar o valor do ponteiro original

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

//Funções para estrutura fila

void enfileirar_enqueue(No **fila) { //Utilizamos void e ponteiro para ponteiro em enfileirar pois alteraremos diretamente a fila, pois *fila armazena o inicio da fila, ao contrario da pilha que alteramos apenas o topo dela, por isso em pilha é No* e não void,

    No *aux,*novo = malloc(sizeof(No)); //O nó auxiliar serve para armazenar o o inicio da fila e por ser um ponteiro também tem acesso ao ponteiro proximo que aponta para outro nó que seria a proxima posição da fila

    if(novo) {                      //verificando se a fila ta vazia
        novo->pessoa = cadastrarPessoa(); //armazenando os dados no novo nó
        novo->proximo = NULL;             //por ser o primeiro nó, definimos o proximo nó como nulo ja que não há outra posição na fila
        if(*fila == NULL) {               //*fila armazena o inicio da fila, como o primeiro nó declarado (proximo = NULL) como vazio, então é como se não houvesse ninguem na fila, então o "novo" que foi o "primeiro elemento" declarado vai assumir o lugar de primeira posição
            *fila = novo;                 // atribuimos o endereço de "novo" que criamos como o conteúdo de *fila, ou seja, tudo o que novo apontar estará armazendado em *fila
        }else {                           //Mas se a primeira posição não estiver vazia
            aux = *fila;                  //O ponteiro auxiliar vai receber o conteudo da primeira posição
            while(aux->proximo) {         //A como o aux é um ponteiro para a estrutura No, ao apontar "proximo" ele está verificando se este ponteiro está indicando outro nó, por ser uma fila o proximo é o ultimo elemento inserido então o loop irá parar quando proximo for nulo, ou seja, quando for o ultimo elemento DA FILA.
                aux = aux->proximo;       //Sempre que o ponteiro proximo apontar para algum endereço o ponteiro auxiliar vai receber o endereço que o ponteiro proximo aponta
            }
            aux->proximo = novo;          //Quando o ponteiro proximo, endereçado na auxiliar, for nulo significa que é o ultimo elemento da lista, então o novo nó criado sera adicionado como a ultima posição.
        }

    }else {
        wprintf(L"Erro ao alocar memória");
    }
}

No* desenfileirar_dequeue(No **fila) {  //Aqui retornamos um ponteiro, ao contrario da enfileirar, pois iremos retornar o endereço do nó que será removido
    No *remover = NULL;                 //Declaramos como nulo pois caso a fila não tenha mais elementos será retornado nulo
    if(*fila) {                         //Se existir elementos dentro de *fila
        remover = *fila;                //O ponteiro remover vai endereçar o conteudo de *fila, que será o primeiro elemento da fila (por isso é importante declararmos os parametros de enfileirar e desenfileirar como ponteiro para ponteiro, para que seja possivel acessar o primeiro elemento da fila e não o ultimo como em pilha por exemplo)
        *fila = remover->proximo;       //O conteudo de *fila se tornará o endereço do ponteiro proximo nó apontado por remover, ou seja, o primeiro elemento se tornará o nó que o primeiro elemento apontava em seu ponteiro "proximo"
    }else {
        printf("fila vazia");     //Se não tiver nada printa que a fila ta vazia e como *fila precisa estar nulo para isso acontecer, o remover terá seu conteúdo nulo
    }
    return remover;                     //Caso não seja nulo a função irá retornar o endereço do nó que foi removido, caso seja nulo irá apenas o endereço de remover mas que terá seu conteudo nulo, ou seja, não terá nada.
}

void imprimir_fila(No *fila) {
    printf("\n-------------Inseridos na Pilha-----------\n");
    while(fila) { // serve funciona verificando se o ponteiro fila ainda está apontando para algum endereço, se não houver nenhum endereço sendo apontado então fila == NULL e a condição de parada do While é atendida
        imprimirPessoa(fila->pessoa);  //imprime de cima para baixo começando no topo da pilha
        printf("-------------------------------------------\n");
        fila = fila->proximo;  //apos imprimir o primeiro elemento da fila, o ponteiro fila vai receber o endereço do ponteiro fila o onde o ponteiro do tipo No é referenciado, buscando seu conteudo que por consequencia é outro endereço que aponta para outro nó e assim segue até que o ponteiro "proximo" aponte para NULL

    }

}

void fila_exe(){
    int opFila;
    No *remover, *fila = NULL;

    do {
        printf("===== MENU PILHA =====\n");
        printf("1. Enfileirar\n");
        printf("2. Desenfileirar\n");
        printf("3. Imprimir Fila\n");
        printf("0. Sair\n");
        printf("==========================\n");
        wprintf(L"Qual função deseja escolher: ");
        scanf("%d",&opFila);

        switch(opFila){

            case 1:
                enfileirar_enqueue(&fila);//Por enfileirar_enqueue() ser do tipo void não é necessario atribui-la a nenhum ponteiro, por ser uma fila o primeiro inserido tem que ser o primeiro a sair então passamos o endereço do ponteiro fila para que a função possa alterar o valor do ponteiro original caso esteja vazia mas de modo que o ponteiro fila sempre continue apontando para o primeiro elemento
                printf("\nEnfileirando...\n\n");
                break;

            case 2:
                remover = desenfileirar_dequeue(&fila); //Por desenfileirar_dequeue() retornar um endereço é necessario atribuir o seu valor ao ponteiro remover,o parametro é o endereço do ponteiro fila pois por ser uma estrutura do tipo FIFO(first in First Out) é necessário alterar diretamente no ponteiro original, lembrando q o ponteiro fila irá apontar para o primeiro elemento da fila


            if(remover) {
                printf("\nO cadastro: \n");
                printf("--------------------\n");
                imprimirPessoa(remover->pessoa);
                printf("\n--------------------\n");
                printf("Foi removido da fila com sucesso!\n\n1");
                free(remover);
            }else {
                printf("fila vazia");
            }
                break;

            case 3:
                imprimir_fila(fila);
                break;

            default:

                if(opFila == 0) {
                    printf("Encerrando Programa...");
                    break;
                }
            wprintf(L"Opção inválida");
        }
    }while(opFila != 0);
}

//Funções para estrutura Lista Encadeada e Duplamente Encadeada

void inserir_lista_inicio(No **lista) {
    No *aux, *novo = malloc(sizeof(No));

    if(novo) {

        novo->pessoa = cadastrarPessoa();

        if(*lista == NULL) {
            novo->proximo = NULL;
            *lista = novo;
        }else {
            aux = *lista;
            novo->proximo = aux;
        }
        *lista = novo;
    }else {
        wprintf(L"\nErro ao alocar memória");
    }
}

void inserir_lista_idade(No **lista) {
    No *aux,*auxAnt = NULL, *novo = malloc(sizeof(No));

    if (novo) {
        novo->pessoa = cadastrarPessoa();

        if(*lista == NULL) {
            novo->proximo = NULL;
            *lista = novo;
        }else {
            aux = *lista;
            while(aux->proximo && novo->pessoa.Idade > aux->pessoa.Idade) {
                auxAnt = aux;
                aux = aux->proximo;
            }
            if(auxAnt == NULL) {
                novo->proximo = *lista;
                *lista = novo;
            }else {
                novo->proximo = aux;
                auxAnt->proximo = novo;
            }
        }
    }else {
        wprintf(L"Erro ao alocar memória");
    }
}

void inserir_lista_nome(No **lista) {

    No *aux, *auxAnt = NULL,*novo = malloc(sizeof(No));
    int i, ordem;

    if(novo) {
        novo->pessoa = cadastrarPessoa();
        if(*lista == NULL) {
            novo->proximo = NULL;
            *lista = novo;
        }else {
            aux = *lista;
            while(aux->proximo && _stricmp(novo->pessoa.Nome,aux->pessoa.Nome) > 0){
                auxAnt = aux;
                aux = aux->proximo;
            }
            if(auxAnt != NULL) {
                novo->proximo = aux;
                auxAnt->proximo = novo;
            }else {
                novo->proximo = *lista;
                *lista = novo;
            }
        }
    }else {
        wprintf(L"Erro ao alocar memória");
    }
}

void imprimir_lista(No *lista) {

    printf("\n-------------Inseridos na Lista-----------\n");
    while(lista) {
        imprimirPessoa(lista->pessoa);
        printf("-------------------------------------------\n");
        lista = lista->proximo;
    }

}

void lista_exe() {

    No *remover,*lista = NULL;
    int opLista;

    do {
        printf("===== MENU PILHA =====\n");
        printf("1. Inserir na lista\n");
        printf("2. Inserir na lista (ordenado por idade)\n");
        printf("3. Inserir na lista (ordenado por nome)\n");
        printf("4. Remover da lista\n");
        printf("5. Imprimir lista \n");
        printf("6. Buscar na lista\n");
        printf("0. Sair\n");
        printf("==========================\n");
        wprintf(L"Qual função deseja escolher: ");
        scanf("%d",&opLista);

        switch(opLista){

            case 1:
                inserir_lista_inicio(&lista);
                printf("\nEnfileirando...\n\n");
                break;

            case 2:
                inserir_lista_idade(&lista);
                printf("\nEnfileirando...\n\n");
                break;

            case 3:
                inserir_lista_nome(&lista);
                printf("\nEnfileirando...\n\n");
                break;

            case 4:

                if(remover) {
                    printf("\nO cadastro: \n");
                    printf("--------------------\n");
                    imprimirPessoa(remover->pessoa);
                    printf("\n--------------------\n");
                    printf("Foi removido da fila com sucesso!\n\n1");
                    free(remover);
                }else {
                    printf("Lista vazia");
                }
                break;

            case 5:

                imprimir_lista(lista);
                break;

            case 6:

                break;

            default:

                if(opLista == 0) {
                    printf("Encerrando Programa...");
                    break;
                }
            wprintf(L"Opção inválida");
        }
    }while(opLista != 0);
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
                fila_exe();
                break;

            case 3:
                lista_exe();
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
