
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

bool esPar(int cualculo);

int main (){
    srand(time(NULL));
    int i, rand1;
    rand1 = (rand() % (15 - 5)) + 5;
    printf("%d\n", rand1);
    int matriz[15][rand1];
    int *punt;
    punt = &matriz[0][0];
    for(i =0; i<(15*rand1);i++){
        *(punt+i) = (rand() % (999 - 100))+100;
    }
    for(i =0; i<15;i++){
        int k, cont =0;
        for(k = 0; k<(rand1);k++){ 
            printf("%d ", matriz[i][k]);
            if(esPar(matriz[i][k])){
                cont++;
            }
        }
         printf("La cantidad de nuemeros pares en la fila %d fueron: %d\n", i, cont);
    }
   
    getchar();
    return 0;
}

bool esPar(int calculo){
    if(calculo % 2 == 0){
        return true;
    }
    else{
        return false;
    }
}