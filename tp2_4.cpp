#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct compu
{
    int velocidad;//entre 1 y 3 Gherz
    int anio;//entre 2000 y 2017
    int cantidad;//entre 1 y 4
    char *tipo_cpu;//valores del arreglo tipos
}PC;

char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};

void CargaC(PC *carga, int cant);
void Mostrar(PC *muestre, int cant);
void MasAntigua(PC *antiguedad, int cant);
void MasVeloz(PC *Veloc, int cant);

int main ()
{
    srand(time(NULL));
    int cant;
    printf("Ingrese un valor, menor o igual a 10: ");
    scanf("%d", &cant);
    PC *computadoras = (PC*)malloc(cant*sizeof(PC));
    CargaC(computadoras, cant);
    Mostrar(computadoras, cant);
    MasAntigua(computadoras, cant);
    MasVeloz(computadoras, cant);
    return 0;
}

void CargaC(PC *carga, int cant)
{   
    int aux,i;
    for(i=0; i<cant;i++)
    {
        (*(carga+i)).velocidad = rand()%3 + 1;
        (*(carga+i)).anio = rand()%18 + 2000;
        (*(carga+i)).cantidad = rand()%4 + 1;
        aux = rand()%6;
        (*(carga+i)).tipo_cpu = *(tipos+aux);
    }
}

void Mostrar(PC *muestre, int cant)
{
    int j;
    for(j=0;j<cant;j++)
    { 
        printf("La velocidad es: %d\n", (*(muestre+j)).velocidad);
        printf("El año es: %d\n", (*(muestre+j)).anio);
        printf("La cantidad de nucleos es: %d\n", (*(muestre+j)).cantidad);
        printf("El cpu es: %s\n", (*(muestre+j)).tipo_cpu);
        printf("#############\n");
    }
}

void MasAntigua(PC *antiguedad, int cant)
{
    int k;
    PC aux;
    for(k=0;k<cant;k++)
    {
        if(k == 0)
        {
            aux = *(antiguedad+k);
        }
        else
        {
            if((*(antiguedad+k)).anio < aux.anio){
                aux = *(antiguedad+k);
            }
        }
    }
    printf("\n-----\nLa computadora mas antigua es:\n");
    Mostrar(&aux, 1);
}

void MasVeloz(PC *Veloc, int cant)
{
    int l;
    PC aux1;
    for(l=0;l<cant;l++)
    {
        if(l == 0)
        {
            aux1 = *(Veloc+l);
        }
        else
        {
            if((*(Veloc+l)).velocidad > aux1.velocidad){
                aux1 = *(Veloc+l);
            }
        }
    }
    printf("\n-----\nLa computadora mas Veloz es:\n");
    Mostrar(&aux1, 1);
}