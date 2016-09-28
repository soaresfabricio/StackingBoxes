//
//  main.cpp
//  BoxStacking
//
//  Created by Fabrício Soares on 28/09/16.
//  Copyright © 2016 Fabrício Soares. All rights reserved.
//

#include <iostream>


struct Caixa {
    int altura, largura, profundidade;
};

/* 
  Necessário para qsort, mais infos em:
 http://www.cplusplus.com/reference/cstdlib/qsort/ */

int compare(const void * a, const void * b){
    return ( (*(Caixa *)b).profundidade * (*(Caixa *)b).largura ) -
    ( (*(Caixa *)a).profundidade * (*(Caixa *)a).largura);
}

// Maior e menor de dois inteiros
int max (int x, int y) { return (x > y) ? x : y; }
int min (int x, int y) { return (x < y) ? x : y; }

int maiorTamanhoPilha(Caixa a[], int n){
    
    Caixa rotacoes[3*n];
    int indice = 0;
    
    for(int i = 0; i < n; i++){
        rotacoes[indice] = a[i];
        indice++;
        
        rotacoes[indice].altura = a[i].largura;
        rotacoes[indice].profundidade = max(a[i].altura, a[i].profundidade);
        rotacoes[indice].largura = min(a[i].altura, a[i].profundidade);
        indice++;
        
        rotacoes[indice].altura = a[i].profundidade;
        rotacoes[indice].profundidade = max(a[i].altura, a[i].largura);
        rotacoes[indice].largura = min(a[i].altura, a[i].largura);
        indice++;
    }
    
    // Quantidade de caixas agora é 3n
    n *= 3;
    
    qsort(rotacoes,n,sizeof(rotacoes[0]),compare);
    
    // Maior altura possível para uma pilha
    int maiorAlturaPilha[n];
    
    for (int i = 0; i < n; i++) {
        maiorAlturaPilha[i] = rotacoes[i].altura;
    }
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++){
            if (rotacoes[i].largura < rotacoes[j].largura and
                rotacoes[i].profundidade < rotacoes[j].profundidade and
                maiorAlturaPilha[i] < maiorAlturaPilha[j] + rotacoes[i].altura)
            {
                maiorAlturaPilha[i] = maiorAlturaPilha[j] + rotacoes[i].altura;
            }
        }
    }
    
    int max = -1;
    
    for (int i = 0; i < n; i++) {
        if (max < maiorAlturaPilha[i]) {
            max = maiorAlturaPilha[i];
        }
    }
    return max;
}




int main(int argc, const char * argv[]) {

    Caixa a[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
    int n = sizeof(a)/sizeof(a[0]);
    
    printf("The maximum possible height of stack is %d\n", maiorTamanhoPilha(a, n) );
    
    return 0;

}
