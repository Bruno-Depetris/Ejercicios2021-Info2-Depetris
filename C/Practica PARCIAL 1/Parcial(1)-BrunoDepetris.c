#include <stdio.h>
#include <stdlib.h>

typedef struct Enteros{
    int velocidad;
    int aceleracion;
}datos;
 void valorG();
 void MetrosSegundo ();
 void crear();
 void continuar();
 void cargadatos(); 
 int main(){
    int opciones;
    printf("\n******Menu de opciones*******");
    printf("\n******Que desea hacer?*******\n\n");
    printf("\nCalcular aceleracion(g)---------(pulse 1)");
    printf("\nCalcular velocidad(M/S)---------(pulse 2)");
    printf("\nSalir---------------------------(pulse 3)");
    scanf("%i",&opciones);

    switch(opciones){
        case 1:valorG;
        break;
        case 2:MetrosSegundo;
        break;
    }
    void crear();

 }
 void valorG(){
    datos Resultados;
    int x;

    printf("ingrese el valor de la aceleracion");
    scanf("%i",&x);
    Resultados.aceleracion = (5 * x)/1023;

    printf("El valor de la aceleracion en G es de:%i",Resultados.aceleracion);
}
void MetrosSegundo (){

    datos Resultados;
    int x;

    printf("\ningrese el valor del sensor:");
    scanf("%i",&x);
    Resultados.velocidad = (1000 * x)/1023;
    printf("El valor de la aceleracion es de %i M/S", Resultados.velocidad);
}
void crear(){
    FILE *archivo;
    archivo = fopen("Datos de sensor.txt","w");
    if(archivo == NULL){
        exit(1);
    }
    fclose(archivo);
    continuar();

}
void continuar(){
    printf("precione una tecla para continuar");
    getch();
}
void cargadatos(){
    FILE *archivo;
    archivo = fopen("Datos de sensor.txt","a");
    if(archivo == NULL){
        exit(1);
    }
    datos Resultados;
    valorG();
    MetrosSegundo();
    fwrite(&Resultados, sizeof(datos),1,archivo);
    fclose(archivo);
    continuar();

}