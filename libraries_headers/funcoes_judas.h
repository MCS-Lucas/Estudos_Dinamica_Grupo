//Aqui serão declaradas as funções feitas pelo Guilherme Yago
#ifndef FUNCOES_JUDAS_H
#define FUNCOES_JUDAS_H
#include <elementos.h>
#include <tgmath.h>
#endif
#define TAM 10
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

// Comandos de terminal:
inline void limparTela() {
    #ifdef __linux__
        system("clear");
    #elif _WIN32
        system("cls");
    #else

    #endif
}
inline void pausarExecucao(int segundos) {
    #ifdef _WIN32 // Caso WIN
        Sleep(segundos * 1000); // Função converte milisegundos -> segundos
    #else // Caso genérico
        sleep(seconds);
    #endif
}

//  Funções auxiliares:
inline void swap(int *vetor, int indexN1, int indexN2) { // Função que troca dois elementos de um vetor
    if (vetor != NULL) {
        int aux = vetor[indexN1]; // aux recebe o valor apontado por indexN1
        vetor[indexN1] = vetor[indexN2]; // valor do indexN1 recebe o valor do indexN2
        vetor[indexN2] = aux; // o valor do indexN2 recebe auxiliar
    }
}

inline int * preencherArray() { // Função que retorna o endereço de um array preenchido
    int i, input;
    int * numeros = calloc(TAM, sizeof(int)); /* 'calloc' aloca memória de acordo com o tamanho passado e
                                                        * retorna um ponteiro para o local onde houve a alocação,
                                                        * zerando o espaço alocado.
                                                        * 'zerar' significa colocar o byte 0 em todas as posições
                                                        * de memória alocada */

    wprintf(L"\n\tEntre com dez números para preencher o array,\n\te pressione enter após digitar cada um:\n");
    for (i = 0; i <= TAM-1; i++) {
        scanf("\t%d", &input);
        *(numeros + i) = input; // "Insere o valor ao endereço de números + i
    }
    return numeros;
}
inline void imprimirArray(int *v, int opcao) {
    char string[50];
    if (opcao == 1) {
        strcpy(string, "Elementos de array em ordem crescente:");
    }else {
        strcpy(string, "Ordem atual dos elementos do array:");
    }
    printf("\n\t%s\n", string);
    for(int i = 0; i < TAM; i++) {
        if(i == 0) {printf("\t");}
        printf("%d ", v[i]);
    }
}

// Métodos de ordenação:
inline void bubbleSort(int *v) {
    int *numeros;
    int i, aux;

    numeros = v; // Ponteiro para inteiro 'numeros' passa a apontar para v[0]
    printf("\n\tOrdem atual dos itens no array:\n");

    imprimirArray(numeros, 0);

    // Algoritimo de ordenação Bubblesort:
    for (int contador = 0; contador < TAM-1; contador++) { // "10-1" Se justifica pois contador[10] não tem comparativo
        for (i = 0; i < TAM - 1; i++) {
            if(numeros[i] > numeros[i+1]) { // Condição e swap
                aux = numeros[i];
                numeros[i] = numeros[i+1];
                numeros[i+1] = aux;
            }
        }
    }

    imprimirArray(numeros, 1);


    free(numeros);
}

inline int particionamento(int *v, int inicio, int fim) {
    int pivot = (v[inicio] + v[fim] + v[(inicio + fim)/2])/3; // Define pivot à partir da média de 3 elementos aleatórios
    while(inicio < fim) {
        while(inicio <= fim && v[inicio] <= pivot)
            inicio = inicio + 1;
        while(inicio < fim && v[fim] > pivot)
            fim = fim -1;
        swap(v, inicio, fim);
    }
    return inicio;
}
inline void quickSort(int *v, int inicio, int fim) {
    if(inicio < fim) {
        int pos = particionamento(v, inicio, fim); // 'pos' recebe o índice do elemento correto que está no meio
        quickSort(v, inicio, pos-1); // Chama 'quickSort' de forma recursiva para ordernar n < elemento central
        quickSort(v, pos, fim); // Chama 'quickSort' de forma recursiva para ordernar n >= elemento central
    }
}
inline void chamadaQuickSort(int *v, int inicio, int fim) {
    int *numeros = v;
    imprimirArray(numeros, 0);
    printf("\n\tPrimeiro elemento     : %d", numeros[0]);
    printf("\n\tElemento central      : %d", numeros[TAM/2]);
    wprintf(L"\n\tÚltimo elemento       : %d", numeros[TAM-1]);
    wprintf(L"\n\n\tAlgorítimo de ordenação:");
    quickSort(numeros, inicio, fim);
    printf("\n\tPrimeiro elemento     : %d", numeros[0]);
    printf("\n\tElemento central      : %d", numeros[TAM/2]);
    wprintf(L"\n\tÚltimo elemento       : %d", numeros[TAM-1]);
    imprimirArray(numeros, 1);
}

inline void merge(int *v, int indexInicio, int meio, int indexFim) {

    int isFimP1 = 0, isFimP2 = 0;
    int i;
    int tamanho = indexFim-indexInicio+1;
    int p1 = indexInicio;
    int p2 = meio + 1;

    int j, k;

    int *temp = (int *)malloc(tamanho*sizeof(int));
    if(temp != NULL) {
        for(i = 0; i < tamanho; i++) { // Percorre o vetor alocado 'temp'
            if(!isFimP1 && !isFimP2) {
                if(v[p1] < v[p2])
                    temp[i] = v[p1++];
                else
                    temp[i] = v[p2++];

                if(p1 > meio)       /* Verificação boleana para saber se um dos subconjuntos chegou ao fim */
                    isFimP1 = 1;
                if(p2 > indexFim)
                    isFimP2 = 1;
            } else {
                if (!isFimP1)
                    temp[i] = v[p1++];
                /* Caso o p1 ainda tiver valores não comparados
                 * o temp [i] recebe o último valor não lido.
                 * Como 'v' é separdado pelo meio, eles sempre tem no máximo 1 elemento de diferença*/
                else
                    temp[i] = v[p2++];
            }
        }
        for (j = 0, k = indexInicio; j < tamanho; j++, k++) {
            v[k] = temp[j];
        }
        free(temp);
    }
}
inline void mergeSort(int *v, int indexInicio, int indexFim) {
    int meio;
    if (indexInicio < indexFim) {
        meio = (indexInicio + indexFim)/ 2; // Calculando o elemento central dinamicamente
        mergeSort(v, indexInicio, meio); // Ordenando primeira metade
        mergeSort(v, meio+1, indexFim); // Ordenando segunda metade
        merge(v, indexInicio, meio, indexFim); // Mergeando metades ordenadas
    }
}
inline void chamadaMergeSort(int *v, int indexInicio, int indexFim) {
    imprimirArray(v, 0);
    mergeSort(v, indexInicio, indexFim);
    imprimirArray(v, 1);
}

inline void insertionSort(int *v, int indexInicio, int indexFim) {
    int i, j, aux;
    int tamanho = indexFim - indexInicio + 1;
    for(i = 1; i < tamanho; i++) { // 'i' começa em 1 já que 'j' começará em 0
        aux = v[i]; // 'aux' guarda um valor reserva de 'i'
        j = i - 1; // 'j' guarda a posicão anterior ao i

        while(j >= 0 && aux < v[j]) {
            v[j+1] = v[j]; /* Primeira execução: A posição 1 do vetor recebe o valor
                            * armazenado na posição 0.
                            * Como -1 < 0 == 1, o programa sai do while e v[j+1] = aux.;   */
            j--;
        }

        v[j+1] = aux;
    }
}
inline void selectionSort(int *v, int indexInicio, int indexFim) {
    int tamanho = indexFim - indexInicio + 1;
    for (int i = 0; i < tamanho-1; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if(v[i] > v[j]) {
                swap(v, i, j);
            }
        }
    }
}

inline NoPilha * empilhar(NoPilha *topo, int valor) {
    NoPilha * novo = malloc(sizeof(NoPilha));
    if (novo) {
        novo->valor = valor;
        novo->proximo = topo; // O Nó que representava o topo agora está sendo apontado pelo último nó inserido.
        return novo; // Retorna o novo Nó para representar o início da nossa pilha.
    }
    else
        printf("\nErro ao alocar memória.");
}

inline void inserirFila(NoFila **fila, int num) {
    NoFila *aux ,*novo = malloc(sizeof(NoFila));
    if(novo) {
        novo->valor = num;
        novo->proximo = NULL; // Garante que o nó representa o final da fila.
        if(*fila == NULL) { // O conteúdo apontado pelo ponteiro é NULL? Ou seja: a fila está vazia?
            *fila = novo;
        } else {
            aux = *fila;
            while (aux->proximo != NULL)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }else
        printf("\n\tErro ao alocar memória.");
}

inline void imprimirFila(NoFila **fila) {
    NoFila *aux;
    if(*fila != NULL) { // Caso a fila não esteja vazia
        aux = *fila; // Aux recebe o conteudo desreferenciado de fila
        while(aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->proximo;
        }
    }
    else
        printf("\n\tA fila está vazia.");
}


inline void inserirFimLista(NoLista **lista, int valor) {
    NoLista *aux, *novo = malloc(sizeof(NoLista));
    if(novo) {
        novo->valor = valor;
        novo->proximo = NULL;
        if(*lista==NULL)
            *lista = novo;
        else {
            aux = *lista;
            while(aux->proximo!=NULL)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }else
        printf("\n\tErro ao alocar memória");
}

inline void imprimirLista(NoLista **lista) {
    NoLista *aux;
    if(*lista != NULL) { // Caso a fila não esteja vazia
        aux = *lista; // Aux recebe o conteudo desreferenciado de fila
        while(aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->proximo;
        }
    }
    else
        printf("\n\tA lista está vazia.");
}

inline void inserirInicioListaDupla(NoListaDupla **lista_dupla, int valor) {
    NoListaDupla *novo = malloc(sizeof(NoListaDupla));
    if (novo) {
        novo->valor = valor;
        novo->proximo = *lista_dupla;
        novo->anterior = NULL;
        if (*lista_dupla)
            (*lista_dupla)->anterior = novo;
        *lista_dupla = novo;

    }else
        printf("\n\tErro ao alocar memória.");

}


inline void imprimirListaDupla(NoListaDupla **lista_dupla) {
    NoListaDupla *aux;
    if(*lista_dupla != NULL) { // Caso a fila não esteja vazia
        aux = *lista_dupla; // Aux recebe o conteudo desreferenciado de fila
        while(aux != NULL) {
            printf("%d ", aux->valor);
            aux = aux->proximo;
        }
    }
    else
        printf("\n\tA lista-duplamente-encadeada está vazia.");
}

inline NoArv* inserirNaArvoreBinaria(NoArv *raiz, int num)  {
    if (raiz == NULL)   {
        NoArv *aux = malloc(sizeof(NoArv));
        aux->valor = num;
        aux->esquerda = NULL;
        aux->direita = NULL;
        return aux;
    }
    else {
        if(raiz->valor > num)
             raiz->esquerda = inserirNaArvoreBinaria(raiz->esquerda, num);
        else
            raiz->direita = inserirNaArvoreBinaria(raiz->direita, num);
        return raiz;
    }
}
inline void imprimirArvoreBinaria_ordem(NoArv *raiz) {
    if(raiz) {
        imprimirArvoreBinaria_ordem(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimirArvoreBinaria_ordem(raiz->direita);
    }
}
inline void imprimirArvoreBinaria_preOrdem(NoArv *raiz) {
    if (raiz) {
        printf("%d ", raiz->valor);
        imprimirArvoreBinaria_preOrdem(raiz->esquerda);
        imprimirArvoreBinaria_preOrdem(raiz->direita);
    }
}
inline void imprimirArvoreBinaria_posOrdem(NoArv *raiz) {
    if (raiz) {
        imprimirArvoreBinaria_posOrdem(raiz->esquerda);
        imprimirArvoreBinaria_posOrdem(raiz->direita);
        printf("%d ", raiz->valor);
    }
}

// Métodos de busca:
inline NoArv* buscaBinariaRecursiva(NoArv *raiz, int num) {
    while(raiz) {
        if (num < raiz->valor)
            raiz = raiz->esquerda;
        else if (num > raiz->valor)
            raiz = raiz->direita;
        else
            return raiz;
    }
    wprintf(L"\n\tValor não encontrado.");
    return NULL;
}

inline NoLista* buscaSequencial(NoLista *lista, int valor) {
    NoLista *aux = NULL;
    if(lista) {
        aux = lista;
    }
    else {
        wprintf(L"\n\tValor não encontrado.");
    }
    while(aux->proximo) {
        if(aux->valor == valor)
            return aux;

        aux = aux->proximo;
    }
    wprintf(L"\n\tValor não encontrado.");
    return NULL;
}


// Menu de operações:

inline void menuFuncoes() {
    int opc;
    int *vetor;
    NoArv *raiz = NULL;
    NoLista *lista = NULL;
    int input;

    do {
        pausarExecucao(1);
        printf("\n\n");
        wprintf(L"\n\t----------- FUNÇÕES -----------");
        wprintf(L"\n\tMétodos de ordenação:");
        wprintf(L"\n\tBubble-Sort ------------------- 1");
        wprintf(L"\n\tQuick-Sort -------------------- 2");
        wprintf(L"\n\tMerge-Sort -------------------- 3");
        wprintf(L"\n\tInsertion-Sort ---------------- 4");
        wprintf(L"\n\tSelection-Sort ---------------- 5");
        wprintf(L"\n\n\tMétodos de busca:");
        wprintf(L"\n\tÁrvore-de-busca-binária ------- 6");
        wprintf(L"\n\tBusca-sequencial -------------- 7");
        wprintf(L"\n\tBusca-binária-recursiva ------- 8");
        wprintf(L"\n\n\tMétodos de alocação dinâmica:");
        wprintf(L"\n\tPilha ------------------------ 9");
        wprintf(L"\n\tFila ------------------------- 10");
        wprintf(L"\n\tLista-encadeada -------------- 11");
        wprintf(L"\n\tLista-duplamente-encadeada --- 12");
        wprintf(L"\n\n\tSair -------------------------- 0");
        wprintf(L"\n\n\tEscolha:");
        scanf("\n\t%d", &opc);

        switch (opc) {
            case 1: // Bubble Sort
                pausarExecucao(1/2); // Conversão implícita de int -> double
                vetor = preencherArray();
                bubbleSort(vetor);
                free(vetor);
            break;
            case 2: // Quick Sort
                pausarExecucao(1/2);
                vetor = preencherArray();
                chamadaQuickSort(vetor, 0, TAM-1);
                free(vetor);
            break;
            case 3: // Merge Sort
                pausarExecucao(1/2);
                vetor = preencherArray();
                chamadaMergeSort(vetor, 0, TAM-1);
                free(vetor);
            break;
            case 4: // Insertion Sort
                pausarExecucao(1/2);
                vetor = preencherArray();
                imprimirArray(vetor, 0);
                insertionSort(vetor, 0, TAM-1);
                imprimirArray(vetor, 1);
                free(vetor);
            break;
            case 5: // Selection Sort
                pausarExecucao(1/2);
                vetor = preencherArray();
                imprimirArray(vetor, 0);
                selectionSort(vetor, 0, TAM-1);
                imprimirArray(vetor, 1);
                free(vetor);
            break;
            case 6: // Árvore de Busca Binária
                pausarExecucao(1/2);
                vetor = preencherArray();
                for (int i = 0; i < TAM; i++)
                    raiz = inserirNaArvoreBinaria(raiz, vetor[i]);

                wprintf(L"\n\tElementos da árvore em ordem:\n\t");
                imprimirArvoreBinaria_ordem(raiz);
                wprintf(L"\n\tElementos da árvore em  pré-ordem:\n\t");
                imprimirArvoreBinaria_preOrdem(raiz);
                wprintf(L"\n\tElementos da árvore em  pos-ordem:\n\t");
                imprimirArvoreBinaria_posOrdem(raiz);
                free(vetor);
            break;
            case 7:
                pausarExecucao(1/2);
                NoLista *elemento = NULL;
                vetor = preencherArray();
                printf("\n\tValores da lista encadeada:\n\t");
                for(int i = 0; i < TAM; i++)
                    inserirFimLista(&lista, vetor[i]);
                imprimirLista(&lista);
                printf("\n\tProcure um valor:");
                scanf("%d", &input);
                elemento = buscaSequencial(lista, input);
                wprintf(L"\n\tElemento seguinte: %d", elemento->proximo->valor);
                free(lista);
                free(vetor);
            break;
            case 8:
                pausarExecucao(1/2);
                vetor = preencherArray();
                for (int i = 0; i < TAM; i++)
                    raiz = inserirNaArvoreBinaria(raiz, vetor[i]);
                wprintf(L"\n\tElementos da árvore em  pré-ordem:\n\t");
                imprimirArvoreBinaria_preOrdem(raiz);
                wprintf(L"\n\tDigite o elemento à ser buscado: ");
                scanf("%d", &input);
                NoArv *escolhido = buscaBinariaRecursiva(raiz, input);
                wprintf(L"Nó esquerdo:");
                if(escolhido->esquerda == NULL) {printf("\n\tInexistente.");}
                else{printf("\n\t%d ", escolhido->esquerda->valor);}
                wprintf(L"Nó direito:");
                if(escolhido->direita == NULL) {printf("\n\tInexistente.");}
                else{printf("\n\t%d ", escolhido->direita->valor);}
                free(raiz);
                free(vetor);
            break;
            case 9: // Pilha
                pausarExecucao(1/2);
                NoPilha *topo = NULL;
                vetor = preencherArray();
                printf("\n\tValores da pilha:\n\t");
                for(int i = 0; i < TAM; i++) {
                    topo = empilhar(topo, vetor[i]);
                    printf("%d ", topo->valor);
                }
                free(topo);
                free(vetor);
            break;
            case 10: // Fila
                pausarExecucao(1/2);
                NoFila *fila = NULL;
                vetor = preencherArray();
                printf("\n\tValores da fila:\n\t");
                for(int i = 0; i < TAM; i++)
                    inserirFila(&fila, vetor[i]);
                imprimirFila(&fila);
                free(fila);
                free(vetor);
            break;
            case 11: // Lista
                pausarExecucao(1/2);
                NoLista *lista = NULL;
                vetor = preencherArray();
                printf("\n\tValores da lista encadeada:\n\t");
                for(int i = 0; i < TAM; i++)
                    inserirFimLista(&lista, vetor[i]);
                imprimirLista(&lista);
                free(lista);
                free(vetor);
            break;
            case 12:
                pausarExecucao(1/2);
                NoLista *lista_dupla = NULL;
                vetor = preencherArray();
                printf("\n\tValores da lista duplamente encadeada:\n\t");
                for(int i = 0; i < TAM; i++)
                    inserirInicioListaDupla(&lista_dupla, vetor[i]);
                imprimirLista(&lista_dupla);
                free(lista_dupla);
            free(vetor);
            break;
            default:
                if(opc == 0) {
                    printf("Encerrando Programa...");
                    break;
                }
                wprintf(L"\n\tOpção inválida.");
            }
    } while (opc != 0);
}


