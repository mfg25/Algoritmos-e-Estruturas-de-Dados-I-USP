#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


// ######### ESCREVA O NROUSP AQUI
char* nroUSP() {
    return("");
}


// ######### ESCREVA SEU NOME AQUI
char* nome() {
    return("");
}

// elemento da lista
typedef struct estr {
        int valor;
        struct estr* prox;
} NO;

NO* ultimoElemLista(NO* inicio){
    NO* p = inicio;
    if(p){
        while(p->prox != NULL){
            p = p->prox;
        }
    }
    return p;
}

void anexarElemLista(int ch, NO* *resp) {
    NO* novo;
    NO* ant = NULL;
    if(*resp != NULL){
        ant = ultimoElemLista(*resp);
    }
    novo = (NO*) malloc(sizeof(NO));
    novo->valor = ch;
    novo->prox = NULL;
    if(ant == NULL){
        (*resp) = (NO*) malloc(sizeof(NO));
        (*resp)->valor = ch;
        (*resp)->prox = NULL;
    }
    else {
        ant->prox = novo;
    }
}

int buscaSeqOrd(NO* p, int ch){
    NO* inicio = p;
    while(p){
        if(p->valor >= ch){
            break;
        }
        p = p->prox;
    }
    if(p){
        if(p->valor == ch){
            return 1;
        }
    }
    else -1;
}

NO* uniao(NO* p1, NO* p2) {

	NO* resp = NULL;


    NO* inicioLista1 = p1;
    NO* inicioLista2 = p2;
    int inicio;
    int ultimoElem;
    if(inicioLista1->valor > inicioLista2->valor){
        inicio = inicioLista2->valor;
    }else{
        inicio = inicioLista1->valor;
    }

    NO* ultimoLista1 = ultimoElemLista(p1);
    NO* ultimoLista2 = ultimoElemLista(p2);

    if(ultimoLista1->valor > ultimoLista2->valor){
        ultimoElem = ultimoLista1->valor;
    }else{
        ultimoElem = ultimoLista2->valor;
    }

    int i;
    for(i = inicio; i <= ultimoElem; i++){
        int existeNaLista1 = buscaSeqOrd(p1, i);
        int existeNaLista2 = buscaSeqOrd(p2, i);
        if(existeNaLista1 == 1 || existeNaLista2 == 1){
            anexarElemLista(i, &resp);
        }
    }
	return resp;
}

void exibirLista(NO* inicio) {
    NO* p = inicio;
    while (p) {
        printf("%d ",p->valor);
        p = p->prox;
    }
}

int main() {

    NO* p1 = (NO*) malloc(sizeof(NO));
    NO* p2 = (NO*) malloc(sizeof(NO));
    NO* p3 = (NO*) malloc(sizeof(NO));
    NO* p4 = (NO*) malloc(sizeof(NO));

    p1->valor = 1;
    p1->prox = p2;
    p2->valor = 10;
    p2->prox = p3;
    p3->valor = 121;
    p3->prox = p4;
    p4->valor = 130;
    p4->prox = NULL;

    NO* j1 = (NO*) malloc(sizeof(NO));
    NO* j2 = (NO*) malloc(sizeof(NO));
    NO* j3 = (NO*) malloc(sizeof(NO));

    j1->valor = 1;
    j1->prox = j2;
    j2->valor = 5;
    j2->prox = j3;
    j2->valor = 88;
    j2->prox = NULL;

	NO* teste = NULL;
	teste = uniao(p1,j1);

    exibirLista(teste);
}

// por favor nao inclua nenhum código abaixo deste ponto
