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
    struct no *anterior;
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
    wprintf(L"\nNome de Usuário: %hs",pessoa.Github);
    printf("Email: %s",pessoa.Email);

}
typedef struct {

    No *Lista;
    No *Fila;
    No *Pilha;

}ListasEx;

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
/*void armazenar_pilha(No **topo, ListasEx **Pilha) {
    No *aux = *topo;
    ListasEx *p = malloc(sizeof(ListasEx));
    if(p) {
        p->Pilha = NULL;
        while(aux) {
            p->Pilha = empilhar_push(p->Pilha);
            p->Pilha->pessoa = aux->pessoa;
            aux = aux->proximo;
        }
        *Pilha = p;
    }else {
        wprintf(L"\nErro ao alocar memória");
    }
}*/

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
/*void armazenar_fila(No **fila, ListasEx **Fila) {
    No *aux = *fila;
    ListasEx *f = malloc(sizeof(ListasEx));
    if(f) {
        f->Fila = NULL;
        while(aux) {
            enfileirar_enqueue(&(f->Fila));
            f->Fila->pessoa = aux->pessoa;
            aux = aux->proximo;
        }
        *Fila = f;
    }else {
        wprintf(L"\nErro ao alocar memória");
    }
}*/

//Funções para estrutura Lista Encadeada

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
No* remover_da_lista(No **lista) {

    No *aux, *auxAnt = NULL, *remover = NULL;
    char github[30];

    wprintf(L"Removendo Usuário\n");
    wprintf(L" Insira o nome de usuário do GitHub: ");
    getchar();
    fgets(github, 29, stdin);

    if(*lista) {
        aux = *lista;
        while(aux->proximo && _stricmp(github,aux->pessoa.Github) != 0) {
            auxAnt = aux;
            aux = aux->proximo;
        }
        if(aux == NULL){
            wprintf("\nUsuário não encontrado.\n");
        }else {
            remover = aux;  // remover = *lista
            if(auxAnt == NULL) {
                *lista = remover->proximo; //*lista->proximo
            }else {
                auxAnt->proximo = remover->proximo;
            }
        }
    }else {
        printf("Lista vazia.\n");
    }
    return remover;
}
No* buscar_lista(No **lista) {
    No *aux = NULL;
    char github[30];

    wprintf(L"Buscando Usuário\n");
    wprintf(L" Insira o nome de usuário do GitHub: ");
    getchar();
    fgets(github, 29, stdin);

    if(*lista == NULL) {
        wprintf(L"\nSem usuários cadastrados.");
    }else {
        aux = *lista;
        while(aux->proximo && _stricmp(github,aux->pessoa.Github) != 0) {
            aux = aux->proximo;
        }
    }
    return aux;
}
void imprimir_lista(No *lista) {

    printf("\n-------------Inseridos na Lista-----------\n");
    while(lista) {
        imprimirPessoa(lista->pessoa);
        printf("-------------------------------------------\n");
        lista = lista->proximo;
    }

}
/*void armazenar_Lista(No **lista, ListasEx **Lista) {
    No *aux = *lista;
    ListasEx *l = malloc(sizeof(ListasEx));
    if(l) {
        l->Lista = NULL;
        while(aux) {
            inserir_lista_inicio(&(l->Lista));
            l->Lista->pessoa = aux->pessoa;
            aux = aux->proximo;
        }
        *Lista = l;
    }else {
        wprintf(L"\nErro ao alocar");
    }
}*/

//Funções para estrutura de Lista Duplamente Encadeada

void inserir_listaDE_inicio(No **lista) {
    No *novo = malloc(sizeof(No));

    if(novo) {
        novo->pessoa = cadastrarPessoa();
        if(*lista == NULL) {
            novo->anterior = NULL;
            *lista = novo;
        }else {
            novo->proximo = *lista;
            novo->anterior= NULL;
            (*lista)->anterior = novo;
        }
        *lista = novo;
    }else {
        wprintf(L"\nErro ao alocar memória");
    }
}
void inserir_listaDE_idade(No **lista) {
    No *aux, *novo = malloc(sizeof(No));

    if (novo) {
        novo->pessoa = cadastrarPessoa();

        if(*lista == NULL) {
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        }else {
            aux = *lista;       //aux->proximo = (*lista)->proximo  aux->anterior = (*lista)->anterior
            while(aux->proximo && novo->pessoa.Idade > aux->pessoa.Idade) {
                aux = aux->proximo;
            }
            if(aux == *lista) {
                novo->proximo = *lista;
                novo->anterior = NULL;
                (*lista)->anterior = novo;
                *lista = novo;
            }else {
                novo->proximo = aux;
                novo->anterior = aux->anterior;
                aux->anterior->proximo = novo;
                aux->anterior = novo;
            }
        }
    }else {
        wprintf(L"Erro ao alocar memória");
    }
}
void inserir_listaDE_nome(No **lista) {

    No *aux,*novo = malloc(sizeof(No));

    if(novo) {
        novo->pessoa = cadastrarPessoa();
        if(*lista == NULL) {
            novo->proximo = NULL;
            novo->anterior = NULL;
            *lista = novo;
        }else {
            aux = *lista;
            while(aux->proximo && _stricmp(novo->pessoa.Nome,aux->pessoa.Nome) > 0){
                aux = aux->proximo;
            }
            if(aux == *lista) {
                novo->proximo = *lista;
                novo->anterior = NULL;
                (*lista)->anterior = novo;
                *lista = novo;
            }else {
                novo->proximo = aux;
                novo->anterior = aux->anterior;
                aux->anterior->proximo = novo;
                aux->anterior = novo;
            }
        }
    }else {
        wprintf(L"Erro ao alocar memória");
    }
}
No* remover_da_listaDE(No **lista) {

    No *aux, *remover = NULL;
    char github[30];

    wprintf(L"Removendo Usuário\n");
    wprintf(L" Insira o nome de usuário do GitHub: ");
    getchar();
    fgets(github, 29, stdin);

    if(*lista) {
        aux = *lista;
        while(aux->proximo && _stricmp(github,aux->pessoa.Github) != 0) {
            aux = aux->proximo;
        }
        if(aux == NULL){
            wprintf("\nUsuário não encontrado.\n");

        }else {
            remover = aux;   // remover->anterio ou remover->proximo = aux->anterior ou aux->proximo
            if(aux->anterior == NULL) {
                remover->proximo->anterior = NULL;
                *lista = remover->proximo;
            }else {
                aux->anterior->proximo = remover->proximo;
                remover->proximo->anterior = aux->anterior;
            }
        }
    }else {
        printf("Lista vazia.\n");
    }
    return remover;
}

//Metodos de ordenação para as estruturas (BubbleSort)

void bubbleSortPilhaIdade(No **topo) {

    ListasEx pilha;
    pilha.Pilha = NULL;
    No *aux, *i, *j;
    Pessoa temp;

    while(*topo) {
        aux = *topo;
        *topo = (*topo)->proximo;
        aux->proximo = pilha.Pilha;
        pilha.Pilha = aux;
    }
    for(i = pilha.Pilha; i!= NULL; i = i->proximo) {
        for(j = pilha.Pilha; j != NULL && j->proximo != NULL; j = j->proximo) {
            if(j->pessoa.Idade < j->proximo->pessoa.Idade) {
                temp = j->pessoa;
                j->pessoa = j->proximo->pessoa;
                j->proximo->pessoa = temp;
            }
        }
    }

    while(pilha.Pilha) {
        aux = pilha.Pilha;
        pilha.Pilha = pilha.Pilha->proximo;
        aux->proximo = *topo;
        *topo = aux;
    }
}
void bubbleSortPilhaNome(No **topo) {
    ListasEx pilha;
    pilha.Pilha = NULL;
    No *aux,*i,*j;
    Pessoa temp;

    while(*topo) {
        aux = *topo;
        *topo = (*topo)->proximo;
        aux->proximo = pilha.Pilha;
        pilha.Pilha = aux;
    }
    for(i = pilha.Pilha; i != NULL; i = i->proximo) {
        for(j = pilha.Pilha; j != NULL && j->proximo != NULL; j = j->proximo) {
            if(_stricmp(j->pessoa.Nome,j->proximo->pessoa.Nome) < 0) {
                temp = j->pessoa;
                j->pessoa = j->proximo->pessoa;
                j->proximo->pessoa = temp;
            }

        }
    }
    while(pilha.Pilha) {
        aux = pilha.Pilha;
        pilha.Pilha = pilha.Pilha->proximo;
        aux->proximo = *topo;
        *topo = aux;
    }

}
void bubbleSortFilaIdade(No **fila) {

    int troca;
    No *prox;
    No *aux;
    No *temp;
    No *laux = NULL;
    No *ultimo = NULL;
    ListasEx f;
    Pessoa auxP;
    temp = *fila;

    f.Fila = NULL;

    while (temp) {
        prox = temp->proximo;
        temp->proximo = f.Fila;
        f.Fila = temp;
        temp = prox;
    }

    do {
        troca = 0;
        aux = f.Fila;

        while(aux && aux->proximo != laux) {
            if(aux->pessoa.Idade < aux->proximo->pessoa.Idade){
                auxP = aux->pessoa;
                aux->pessoa = aux->proximo->pessoa;
                aux->proximo->pessoa = auxP;
                troca = 1;
            }
            aux = aux->proximo;
        }
        laux = aux;

    }while(troca);

    aux = f.Fila;

    while (f.Fila) {
        prox = aux->proximo;
        aux->proximo = NULL;
        if(ultimo) {
            ultimo->proximo = aux;
        }else {
            *fila = aux;
        }
        ultimo = aux;
        aux = prox;
    }
}
void bubbleSortFilaNome(No **fila){
int troca;
No *prox;
No *aux;
No *temp;
No *laux = NULL;
No *ultimo = NULL;
ListasEx f;
Pessoa auxP;
temp = *fila;

f.Fila = NULL;

while (temp) {
    prox = temp->proximo;
    temp->proximo = f.Fila;
    f.Fila = temp;
    temp = prox;
}

do {
    troca = 0;
    aux = f.Fila;

    while(aux && aux->proximo != laux) {
        if(_stricmp(aux->pessoa.Nome,aux->proximo->pessoa.Nome) < 0) {
            auxP = aux->pessoa;
            aux->pessoa = aux->proximo->pessoa;
            aux->proximo->pessoa = auxP;
            troca = 1;
        }
        aux = aux->proximo;
    }
    laux = aux;

}while(troca);

aux = f.Fila;

while (f.Fila) {
    prox = aux->proximo;
    aux->proximo = NULL;
    if(ultimo) {
        ultimo->proximo = aux;
    }else {
        *fila = aux;
    }
    ultimo = aux;
    aux = prox;
}
}
void bubbleSortListaIdade(No **lista) {
    int troca;
    No *aux;
    No *laux = NULL;
    Pessoa temp;

        do {
            troca = 0;
            aux = *lista;
            while(aux->proximo != laux) {
                if(aux->pessoa.Idade < aux->proximo->pessoa.Idade) {
                    temp = aux->pessoa;
                    aux->pessoa = aux->proximo->pessoa;
                    aux->proximo->pessoa = temp;
                    troca = 1;
                }
                aux = aux->proximo;
            }
            laux = aux;
        }while(troca);

}
void bubbleSortListaNome(No **lista) {

    int troca;
    No *aux;
    No *laux = NULL;
    Pessoa temp;
    do {
        troca = 0;
        aux = *lista;
        while(aux->proximo != laux) {
            if(_stricmp(aux->pessoa.Nome,aux->proximo->pessoa.Nome) < 0) {
                temp = aux->pessoa;
                aux->pessoa = aux->proximo->pessoa;
                aux->proximo->pessoa = temp;
                troca = 1;
            }
            aux = aux->proximo;
        }
        laux = aux;
    }while(troca);
}

//Metodos de ordenação para as estruturas(SelectionSort)

void selectionSortPilhaIdade(No **topo) {

    ListasEx pilha;
    pilha.Pilha = NULL;
    No *aux,*i, *j, *menor, troca;

    while(*topo) {
        aux = *topo;
        *topo = (*topo)->proximo;
        aux->proximo = pilha.Pilha;
        pilha.Pilha = aux;
    }

    for(i = pilha.Pilha; i ; i = i->proximo) {
        menor = i;
        for(j = i->proximo; j ; j = j->proximo) {
            if(j->pessoa.Idade < menor->pessoa.Idade) {
                menor = j;
            }
        }

        if(menor != i) {
            troca.pessoa = i->pessoa;
            i->pessoa = menor->pessoa;
            menor->pessoa = troca.pessoa;
        }
    }
    while(pilha.Pilha) {
        aux = pilha.Pilha;
        pilha.Pilha = pilha.Pilha->proximo;
        aux->proximo = *topo;
        *topo = aux;
    }
}
void selectionSortPilhaNome(No **topo) {

    ListasEx pilha;
    pilha.Pilha = NULL;
    No *aux, *i,*j, *menor, troca;

    while (*topo) {
        aux = *topo;
        *topo = (*topo)->proximo;
        aux->proximo = pilha.Pilha;
        pilha.Pilha = aux;
    }

    for(i = pilha.Pilha; i ; i = i->proximo) {
        menor = i;
        for(j = i->proximo; j ; j = j->proximo) {
            if(_stricmp(j->pessoa.Nome, menor->pessoa.Nome) < 0) {
                menor = j;
            }
        }

        if(menor != i) {
            troca.pessoa = i->pessoa;
            i->pessoa = menor->pessoa;
            menor->pessoa = troca.pessoa;
        }
    }

    while(pilha.Pilha) {
        aux = pilha.Pilha;
        pilha.Pilha = pilha.Pilha->proximo;
        aux->proximo = *topo;
        *topo = aux;
    }
}
void selectionSortFilaIdade(No **fila) {

    ListasEx f;
    f.Fila = NULL;
    No *aux,*i, *j, *menor, troca, *ultimo = NULL;

    while(*fila) {
        aux = *fila;
        *fila = (*fila)->proximo;
        aux->proximo = f.Fila;
        f.Fila = aux;
    }

    for(i = f.Fila; i ; i = i->proximo) {
        menor = i;
        for(j = i->proximo; j ; j = j->proximo) {
            if(j->pessoa.Idade < menor->pessoa.Idade) {
                menor = j;
            }
        }

        if(menor != i) {
            troca.pessoa = i->pessoa;
            i->pessoa = menor->pessoa;
            menor->pessoa = troca.pessoa;
        }
    }
    while(f.Fila) {
        aux = f.Fila;
        f.Fila = f.Fila->proximo;
        aux->proximo = *fila;
        *fila = aux;

        if (*fila == NULL) {
            *fila = aux;
            ultimo = aux;  // Manter o controle do fim da fila
        } else {
            ultimo->proximo = aux;
            ultimo = aux;
        }
    }
}
void selectionSortFilaNome(No **fila) {
    ListasEx f;
    f.Fila = NULL;
    No *aux, *i,*j, *menor, troca,*ultimo = NULL;

    while (*fila) {
        aux = *fila;
        *fila = (*fila)->proximo;
        aux->proximo = f.Fila;
        f.Fila = aux;
    }

    for(i = f.Fila; i ; i = i->proximo) {
        menor = i;
        for(j = i->proximo; j ; j = j->proximo) {
            if(_stricmp(j->pessoa.Nome, menor->pessoa.Nome) < 0) {
                menor = j;
            }
        }

        if(menor != i) {
            troca.pessoa = i->pessoa;
            i->pessoa = menor->pessoa;
            menor->pessoa = troca.pessoa;
        }
    }

    while(f.Fila) {
        aux = f.Fila;
        f.Fila = f.Fila->proximo;
        aux->proximo = *fila;
        *fila = aux;

        if (*fila == NULL) {
            *fila = aux;
            ultimo = aux;  // Manter o controle do fim da fila
        } else {
            ultimo->proximo = aux;
            ultimo = aux;
        }
    }
}
void selectionSortListaIdade(No **lista) {

    ListasEx l;
    l.Lista = NULL;
    No *aux,*i, *j, *menor, troca;

    while(*lista) {
        aux = *lista;
        *lista = (*lista)->proximo;
        aux->proximo = l.Lista;
        l.Lista = aux;
    }

    for(i = l.Lista; i ; i = i->proximo) {
        menor = i;
        for(j = i->proximo; j ; j = j->proximo) {
            if(j->pessoa.Idade < menor->pessoa.Idade) {
                menor = j;
            }
        }

        if(menor != i) {
            troca.pessoa = i->pessoa;
            i->pessoa = menor->pessoa;
            menor->pessoa = troca.pessoa;
        }
    }
    while(l.Lista) {
        aux = l.Lista;
        l.Lista = l.Lista->proximo;
        aux->proximo = *lista;
        *lista = aux;
    }
}
void selectionSortListaNome(No **lista) {

    ListasEx l;
    l.Lista = NULL;
    No *aux,*i, *j, *menor, troca;

    while(*lista) {
        aux = *lista;
        *lista = (*lista)->proximo;
        aux->proximo = l.Lista;
        l.Lista = aux;
    }

    for(i = l.Lista; i ; i = i->proximo) {
        menor = i;
        for(j = i->proximo; j ; j = j->proximo) {
            if(_stricmp(j->pessoa.Nome, menor->pessoa.Nome) < 0) {
                menor = j;
            }
        }

        if(menor != i) {
            troca.pessoa = i->pessoa;
            i->pessoa = menor->pessoa;
            menor->pessoa = troca.pessoa;
        }
    }
    while(l.Lista) {
        aux = l.Lista;
        l.Lista = l.Lista->proximo;
        aux->proximo = *lista;
        *lista = aux;
    }
}

//Metodos de ordenação para as estruturas (InsertionSort)

void insertionSortPilhaIdade(No **topo) {
    ListasEx pilha;
    No *aux, *i, *auxAnt;

    pilha.Pilha = NULL;

    while(*topo) {
        aux = *topo;
        *topo = (*topo)->proximo;
        aux->proximo = pilha.Pilha;
        pilha.Pilha = aux;
    }
    while(pilha.Pilha) {
        aux = pilha.Pilha;
        pilha.Pilha = pilha.Pilha->proximo;

    if(*topo == NULL || aux->pessoa.Idade <= (*topo)->pessoa.Idade) {
        aux->proximo = *topo;
        *topo = aux;
    }else {
        auxAnt = *topo;
        i = auxAnt->proximo;
        while(i && aux->pessoa.Idade > i->pessoa.Idade) {
            auxAnt = i;
            i = i->proximo;
        }
        aux->proximo = i;
        auxAnt->proximo = aux;
        }
    }
}
void insertionSortPilhaNome(No **topo) {

    ListasEx pilha;
    No *aux, *auxAnt, *i;
    pilha.Pilha = NULL;

    while(*topo) {
        aux = *topo;
        *topo = (*topo)->proximo;
        aux->proximo = pilha.Pilha;
        pilha.Pilha = aux;
    }
    while(pilha.Pilha) {

        aux = pilha.Pilha;
        pilha.Pilha = pilha.Pilha->proximo;

        if(*topo == NULL || _stricmp(aux->pessoa.Nome, (*topo)->pessoa.Nome) < 0) {
            aux->proximo = *topo;
            *topo = aux;
        }else {
            auxAnt = *topo;
            i = auxAnt->proximo;
            while(i && _stricmp(aux->pessoa.Nome, i->pessoa.Nome) > 0) {
                auxAnt = i;
                i = i->proximo;
            }
            aux->proximo = i;
            auxAnt->proximo = aux;
        }
    }
}
void insertionSortFilaIdade(No **fila) {

    ListasEx f;
    No *aux, *auxAnt, *i, *temp;
    temp = *fila;

    f.Fila = NULL;

    while (temp) {
        aux = temp->proximo;
        temp->proximo = f.Fila;
        f.Fila = temp;
        temp = aux;
    }
    while(f.Fila) {
        aux = f.Fila;
        f.Fila = f.Fila->proximo;
        if(*fila == NULL || aux->pessoa.Idade <= (*fila)->pessoa.Idade) {
            aux->proximo = *fila;
            *fila = aux;
        }else {
            auxAnt = *fila;
            i = auxAnt->proximo;
            while(i && aux->pessoa.Idade > i->pessoa.Idade) {
                auxAnt = i;
                i = i->proximo;
            }
            aux->proximo = i;
            auxAnt->proximo = aux;
        }
    }

}
void insertionSortFilaNome(No **fila) {

    ListasEx f;
    No *aux, *auxAnt, *i, *temp;
    temp = *fila;

    f.Fila = NULL;

    while (temp) {
        aux = temp->proximo;
        temp->proximo = f.Fila;
        f.Fila = temp;
        temp = aux;
    }
    while(f.Fila) {
        aux = f.Fila;
        f.Fila = f.Fila->proximo;
        if(*fila == NULL || _stricmp(aux->pessoa.Nome, (*fila)->pessoa.Nome) < 0) {
            aux->proximo = *fila;
            *fila = aux;
        }else {
            auxAnt = *fila;
            i = auxAnt->proximo;
            while(i && _stricmp(aux->pessoa.Nome,i->pessoa.Nome) > 0) {
                auxAnt = i;
                i = i->proximo;
            }
            aux->proximo = i;
            auxAnt->proximo = aux;
        }
    }
}
void insertionSortListaIdade(No **lista) {

    ListasEx l;
    No *aux, *auxAnt, *i;
    l.Lista = NULL;

    while(*lista) {
        aux = *lista;
        *lista = (*lista)->proximo;
        aux->proximo = l.Lista;
        l.Lista = aux;
    }
    while(l.Lista) {
        aux = l.Lista;
        l.Lista = l.Lista->proximo;
        if(*lista == NULL || aux->pessoa.Idade <= (*lista)->pessoa.Idade) {
            aux->proximo = *lista;
            *lista = aux;
        }else {
            auxAnt = *lista;
            i = auxAnt->proximo;
            while(i && aux->pessoa.Idade > i->pessoa.Idade) {
                auxAnt = i;
                i = i->proximo;
            }
            aux->proximo = i;
            auxAnt->proximo = aux;
        }
    }
}
void insertionSortListaNome(No **lista) {

    ListasEx l;
    No *aux, *auxAnt, *i;
    l.Lista = NULL;

    while(*lista) {
        aux = *lista;
        *lista = (*lista)->proximo;
        aux->proximo = l.Lista;
        l.Lista = aux;
    }
    while(l.Lista) {
        aux = l.Lista;
        l.Lista = l.Lista->proximo;
        if(*lista == NULL || _stricmp(aux->pessoa.Nome,(*lista)->pessoa.Nome) < 0) {
            aux->proximo = *lista;
            *lista = aux;
        }else {
            auxAnt = *lista;
            i = auxAnt->proximo;
            while(i && _stricmp(aux->pessoa.Nome,i->pessoa.Nome) > 0){
                auxAnt = i;
                i = i->proximo;
            }
            aux->proximo = i;
            auxAnt->proximo = aux;
        }
    }
}

//Metodos de ordenação para as estruturas (QuickSort)

No* concatenar(No *menores, No *pivo, No *maiores) {

    if(menores == NULL) {
        pivo->proximo = maiores;
        return pivo;
    }
    No *atual = menores;

    while(atual->proximo) {
        atual = atual->proximo;
    }
    atual->proximo = pivo;
    pivo->proximo = maiores;
    return menores;
}
No* particionaIdade(No *topo,No **menores,No **maiores) {

    No *pivo = topo;
    topo = topo->proximo;
    pivo->proximo = NULL;

    while(topo) {
        No *aux = topo->proximo;
        if(topo->pessoa.Idade < pivo->pessoa.Idade) {
            topo->proximo = *menores;
            *menores = topo;
        }else {
            topo->proximo = *maiores;
            *maiores = topo;
        }
        topo = aux;
    }
    return pivo;
}
No* particionaNome(No *topo,No **menores,No **maiores) {

    No *pivo = topo;
    topo = topo->proximo;
    pivo->proximo = NULL;

    while(topo) {
        No *aux = topo->proximo;
        if(_stricmp(topo->pessoa.Nome, pivo->pessoa.Nome) < 0) {
            topo->proximo = *menores;
            *menores = topo;
        }else {
            topo->proximo = *maiores;
            *maiores = topo;
        }
        topo = aux;
    }
    return pivo;
}
No* quickSortPilhaIdade(No **topo) {

    if(*topo == NULL || (*topo)->proximo == NULL) {
        return *topo;
    }
    No *menores = NULL;
    No *maiores = NULL;
    No *pivo = particionaIdade(*topo,&menores,&maiores);

    menores = quickSortPilhaIdade(&menores);
    maiores = quickSortPilhaIdade(&maiores);

    return concatenar(menores, pivo, maiores);

}
No* quickSortPilhaNome(No **topo) {

    if(*topo == NULL || (*topo)->proximo == NULL) {
        return *topo;
    }
    No *menores = NULL;
    No *maiores = NULL;
    No *pivo = particionaNome(*topo,&menores,&maiores);

    menores = quickSortPilhaNome(&menores);
    maiores = quickSortPilhaNome(&maiores);

    return concatenar(menores, pivo, maiores);

}
No* quickSortFilaIdade(No **fila) {

    if(*fila == NULL || (*fila)->proximo == NULL) {
        return *fila;
    }
    No *menores = NULL;
    No *maiores = NULL;
    No *pivo = particionaIdade(*fila,&menores,&maiores);

    menores = quickSortPilhaIdade(&menores);
    maiores = quickSortPilhaIdade(&maiores);

    return concatenar(menores, pivo, maiores);

}
No* quickSortFilaNome(No **fila) {

    if(*fila == NULL || (*fila)->proximo == NULL) {
        return *fila;
    }
    No *menores = NULL;
    No *maiores = NULL;
    No *pivo = particionaNome(*fila,&menores,&maiores);

    menores = quickSortPilhaNome(&menores);
    maiores = quickSortPilhaNome(&maiores);

    return concatenar(menores, pivo, maiores);

}
No* quickSortListaIdade(No **lista) {

    if(*lista == NULL || (*lista)->proximo == NULL) {
        return *lista;
    }
    No *menores = NULL;
    No *maiores = NULL;
    No *pivo = particionaIdade(*lista,&menores,&maiores);

    menores = quickSortListaIdade(&menores);
    maiores = quickSortListaIdade(&maiores);

    return concatenar(menores, pivo, maiores);

}
No* quickSortListaNome(No **lista) {

    if(*lista == NULL || (*lista)->proximo == NULL) {
        return *lista;
    }
    No *menores = NULL;
    No *maiores = NULL;
    No *pivo = particionaNome(*lista,&menores,&maiores);

    menores = quickSortListaNome(&menores);
    maiores = quickSortListaNome(&maiores);

    return concatenar(menores, pivo, maiores);

}

//Metodos de ordenação para as estruturas (MergeSort)

//FUNÇÃO EXTRA! MISTURAR AS LISTAS, PILHAS E FILAS(WIP)
/*void mesclar_Listas_Nome(ListasEx **Tipolista, No **Novalista) {
    ListasEx *aux = *Tipolista;
    No *aux2;
    while(aux) {
        aux2 = aux->Fila;
        while(aux2) {
            inserir_lista_nome(Novalista);
            aux2 = aux2->proximo;
        }
        aux2 = aux->Pilha;
        while(aux2) {

            inserir_lista_nome(Novalista);
            aux2 = aux2->proximo;
        }
        aux2 = aux->Lista;
        while(aux2) {
            inserir_lista_nome(Novalista);
            aux2 = aux2->proximo;
        }
        aux = NULL;
    }
}
*/
//MENUS
void listaDE_exe() {

    No *remover,*buscar, *lista = NULL;
   // ListasEx *Lista = NULL;
    int opLista;

    do {
        printf("===== MENU LISTA DUPLAMENTE ENCADEADA =====\n");
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
                inserir_listaDE_inicio(&lista);
                printf("\nEnfileirando...\n\n");
                break;

            case 2:
                inserir_listaDE_idade(&lista);
                printf("\nEnfileirando...\n\n");
                break;

            case 3:
                inserir_listaDE_nome(&lista);
                printf("\nEnfileirando...\n\n");
                break;

            case 4:
                remover = remover_da_listaDE(&lista);
                if(remover) {
                    printf("\nO cadastro: \n");
                    printf("--------------------\n");
                    imprimirPessoa(remover->pessoa);
                    printf("\n--------------------\n");
                    printf("Foi removido da lista com sucesso!\n\n");
                    free(remover);
                }else {
                    printf("\nLista vazia");
                }
                break;

            case 5:
                imprimir_lista(lista);
                break;

            case 6:
                buscar = buscar_lista(&lista);
                if(buscar) {
                    printf("\nO cadastro: \n");
                    printf("--------------------\n");
                    imprimirPessoa(buscar->pessoa);
                    printf("\n--------------------\n");
                    printf("Foi da encontrado com sucesso!\n\n");
                }else {
                    wprintf(L"\nUsuário não encontrado");
                }

                break;

            default:

                if(opLista == 0) {
                    printf("\nEncerrando Programa...");
                   // armazenar_Lista(&lista,&Lista);
                    break;
                }
            wprintf(L"Opção inválida");
        }
    }while(opLista != 0);
}
void lista_exe() {

    No *remover,*buscar, *lista = NULL;
   // ListasEx *Lista = NULL;
    int opLista;

    do {
        printf("===== MENU LISTA =====\n");
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
                remover = remover_da_lista(&lista);
                if(remover) {
                    printf("\nO cadastro: \n");
                    printf("--------------------\n");
                    imprimirPessoa(remover->pessoa);
                    printf("\n--------------------\n");
                    printf("Foi removido da lista com sucesso!\n\n");
                    free(remover);
                }else {
                    printf("\nLista vazia");
                }
                break;

            case 5:
                imprimir_lista(lista);
                break;

            case 6:
                buscar = buscar_lista(&lista);
                if(buscar) {
                    printf("\nO cadastro: \n");
                    printf("--------------------\n");
                    imprimirPessoa(buscar->pessoa);
                    printf("\n--------------------\n");
                    printf("Foi da encontrado com sucesso!\n\n");
                }else {
                    wprintf(L"\nUsuário não encontrado");
                }

                break;

            default:

                if(opLista == 0) {
                    printf("\nEncerrando Programa...");
                   // armazenar_Lista(&lista,&Lista);
                    break;
                }
            wprintf(L"Opção inválida");
        }
    }while(opLista != 0);
}
void fila_exe(){
    int opFila;
    No *remover, *fila = NULL;
   // ListasEx *Fila = NULL;

    do {
        printf("===== MENU FILA =====\n");
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
                    printf("\nEncerrando Programa...");
                    //armazenar_fila(&fila,&Fila);
                    break;
                }
            wprintf(L"Opção inválida");
        }
    }while(opFila != 0);
}
void pilha_exe() {
    int opPilha;
    No *remover, *topo = NULL, *ordenar = NULL;
    // ListasEx *Pilha;

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

            case 4:
                ordenar = quickSortPilhaIdade(&topo);
                imprimir_pilha(topo);
                break;

                default:

                    if(opPilha == 0) {
                        printf("\nEncerrando Programa...");
                        //armazenar_pilha(&topo,&Pilha);
                        break;
                    }
            wprintf(L"Opção inválida");
        }
    }while(opPilha != 0);
}

void menuCarvas() {

    int opCarvas;
   // ListasEx *ListasSeparadas = NULL;
   // No *ListasMescladas = NULL;

    do{

        printf("======= MENU CARVAS =======\n");
        printf("1. Menu Pilha\n");
        printf("2. Menu Fila\n");
        printf("3. Menu Lista\n");
        printf("4. Menu Lista Duplamente Encadeada\n");
        wprintf(L"5. Métodos de Ordenação\n");
        wprintf(L"6. Métodos de Busca\n");
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
                listaDE_exe();
                break;

         /*   case 5:
                mesclar_Listas_Nome(ListasSeparadas, ListasMescladas);
                imprimir_lista(ListasMescladas);
                break;
        */
            case 5:

                break;

            case 6:

                break;
            default:

                if(opCarvas == 0) {
                    printf("\nEncerrando Programa...");
                    break;
                }
            wprintf(L"Opção inválida\n");

        }
    }while(opCarvas != 0);
}
#endif
