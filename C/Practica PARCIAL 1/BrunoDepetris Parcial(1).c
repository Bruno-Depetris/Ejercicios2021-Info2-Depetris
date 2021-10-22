#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct Enteros{
    int velocidad;
    int aceleracion;
}datos;

 int valorG(int *x);
 int MetrosSegundo (int *a);
 void crear();
 void continuar();
 void cargadatos(); 
 void listado();

 int main(){
    int opciones;
    int x,a;
    printf("\n******Menu de opciones*******");
    printf("\n******Que desea hacer?*******\n\n");

    printf("\n1.Calcular aceleracion(g) y Velocidad (M/S))");
    printf("\n2.Mpstrar lista resultados");
    printf("\n3.Salir");
    scanf("%i",&opciones);

    switch(opciones){
        case 1:
            printf("ingrese el valor de la Aceleracion(0 - 1023):");
            scanf("%i",&x);

            valorG(&x);

            printf("\ningrese el valor de la Velocidad(0 - 1023):");
            scanf("%i",&a);

            MetrosSegundo(&a);
            crear();
            cargadatos();
        break;
        case 2:
        listado();
        break;
        case 3:
        system("cls");
        break;
    }

    return(0);

 }
int valorG(int *x){
    datos Resultados;

    Resultados.aceleracion = (5 * *x)/1023; 
    printf("El valor de la Aceleracion es de:%i G", Resultados.aceleracion);
}
int MetrosSegundo (int *a){
    datos Resultados;

    Resultados.velocidad = (1000 * *a)/1023;
    printf("El valor de la Velocidad es de %i M/S", Resultados.velocidad);
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
    printf("\nprecione una tecla para continuar\n");
    getch();
}
void cargadatos(){
    datos Resultados;
    FILE *archivo;
    archivo = fopen("Datos de sensor.txt","w");
    if(archivo == NULL){
        exit(1);
    }
    fwrite(&Resultados, sizeof(datos),1,archivo);

    int valorG(int *x);
    int  MetrosSegundo(int *a);
 
    fclose(archivo);
    continuar();

}
void listado(){
    FILE *archivo;
    archivo = fopen ("Datos de sensor.txt","r+");
    if(archivo == NULL){
        exit(1);
    }
    datos Resultados;
    fread(&Resultados, sizeof(datos),1,archivo);

   while(!feof(archivo)){
    printf("\nEl valor de la Aceleracion es de %i G\n", Resultados.aceleracion);
    printf("\nEl valor de la Velocidad es de %i M/S\n", Resultados.velocidad);
    fread(&Resultados, sizeof(datos),1,archivo);

}
fclose(archivo);
continuar();


}