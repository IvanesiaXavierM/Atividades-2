#include <stdio.h>
#define MAX_SIZE 20

typedef struct {
    int elementos[MAX_SIZE];
    int tamanho;
   } Conjunto;

void comecarConjunto(Conjunto *conjunto) {
    conjunto->tamanho = 0;
}

void adicionarElemento(Conjunto *conjunto, int elemento) {
    if (conjunto->tamanho < MAX_SIZE) {
        int i;
        for (i = 0; i < conjunto->tamanho; i++) {
            if (conjunto->elementos[i] == elemento) {
                return;
            }
        }
        conjunto->elementos[conjunto->tamanho] = elemento;
        conjunto->tamanho++;
    }
}

void lerConjunto(Conjunto *conjunto) {
    int n;
    printf("Digite o tamanho do conjunto: ");
    scanf("%d", &n);

    printf("Digite os elementos do conjunto:\n");
    for (int i = 0; i < n; i++) {
        int elemento;
        scanf("%d", &elemento);
        adicionarElemento(conjunto, elemento);
    }
}

Conjunto uniao(Conjunto conjunto1, Conjunto conjunto2) {
    Conjunto resultado;
    comecarConjunto(&resultado);

    for (int i = 0; i < conjunto1.tamanho; i++) {
        adicionarElemento(&resultado, conjunto1.elementos[i]);
    }

    for (int i = 0; i < conjunto2.tamanho; i++) {
        adicionarElemento(&resultado, conjunto2.elementos[i]);
    }

    return resultado;
}

Conjunto intersecao(Conjunto conjunto1, Conjunto conjunto2) {
    Conjunto resultado;
    comecarConjunto(&resultado);

    for (int i = 0; i < conjunto1.tamanho; i++) {
        for (int j = 0; j < conjunto2.tamanho; j++) {
            if (conjunto1.elementos[i] == conjunto2.elementos[j]) {
                adicionarElemento(&resultado, conjunto1.elementos[i]);
                break;
            }
        }
    }

    return resultado;
}

int verificarConjunto(Conjunto conjunto1, Conjunto conjunto2) {
    if (conjunto1.tamanho != conjunto2.tamanho) {
        return 0;
    }

    for (int i = 0; i < conjunto1.tamanho; i++) {
        int encontrado = 0;
        for (int j = 0; j < conjunto2.tamanho; j++) {
            if (conjunto1.elementos[i] == conjunto2.elementos[j]) {
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            return 0;
        }
    }

    return 1;
}

void imprimirConjunto(Conjunto conjunto) {
    printf("Conjunto: { ");
    for (int i = 0; i < conjunto.tamanho; i++) {
        printf("%d ", conjunto.elementos[i]);
    }
    printf("}\n");
}

int main() {
    Conjunto conjunto1, conjunto2;
    comecarConjunto(&conjunto1);
    comecarConjunto(&conjunto2);

    printf("Digite o conjunto 1:\n");
    lerConjunto(&conjunto1);

    printf("Digite o conjunto 2:\n");
    lerConjunto(&conjunto2);

    Conjunto conjuntoUniao = uniao(conjunto1, conjunto2);
    Conjunto conjuntoIntersecao = intersecao(conjunto1, conjunto2);

    printf("Conjunto União:\n");
    imprimirConjunto(conjuntoUniao);

    printf("Conjunto Interseção:\n");
    imprimirConjunto(conjuntoIntersecao);

    if (verificarConjunto(conjunto1, conjunto2)) {
        printf("Os conjuntos são iguais.\n");
    } else {
        printf("Os conjuntos são diferentes.\n");
    }

    return 0;
}
