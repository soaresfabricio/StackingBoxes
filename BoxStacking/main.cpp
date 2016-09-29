//
//  main.cpp
//  BoxStacking
//
//  Created by Fabrício Soares on 28/09/16.
//  Copyright © 2016 Fabrício Soar  es. All rights reserved.
//

#include <iostream>
#include <vector>
#include <iterator>


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

int maiorTamanhoPilha(const std::vector<Caixa> & a, unsigned long n){
    
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




int main() {

    int quantosTestes;
    
    std::cin >> quantosTestes;
    
    //std::cout << quantosTestes << std::endl;
    //std::cout << quantasCaixas << std::endl;


    std::vector<Caixa> a;
    
    
    while (quantosTestes > 0) {
        
        a.clear();
        
        int quantasCaixas;
        std::cin >> quantasCaixas;

        
        for (int i = 0; i < quantasCaixas; i++){
            std::vector<int> dimensoesCaixa;
            for(int i = 0; i < 3; i++){
                int tmp;
                std::cin >> tmp;
                dimensoesCaixa.push_back(tmp);
            }
            a.push_back({ dimensoesCaixa[0], dimensoesCaixa[1], dimensoesCaixa[2] } );
        }

        
        std::cout << maiorTamanhoPilha(a, a.size()) << std::endl;

        
        --quantosTestes;
        
    }
    

    
//    a.push_back({ dimensoesCaixa[0], dimensoesCaixa[1], dimensoesCaixa[2] } );
//    a.push_back({ 1, 2, 3} );
//    a.push_back({ 4, 5, 6 } );
//    a.push_back({ 10, 12, 32} );
    
    
    //Caixa a[] = { {411, 110, 72}, {13, 204, 553}, {144, 12, 16}, {110, 12, 136} };
    
    //printf("%d", maiorTamanhoPilha(a, a.size()) );
    
    return 0;

}
