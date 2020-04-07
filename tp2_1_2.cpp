#include <stdio.h>
#include <stdlib.h>
#define N 4
#define M 5

int main(){
    int f,c;
    double mt[N][M] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20}};
    double *punt;
    punt = &mt[0][0];
    for(f=0;f<(N*M);f++){
        printf("%lf\n", *(punt+f));
    }
    getchar();
    return 0;
}


