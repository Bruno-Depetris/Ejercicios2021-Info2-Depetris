#include <stdio.h>
#include <stdlib.h>
#define t 50;
typedef struct personas{
    char nombre[50];
    int edad;
    int dni;
    int telefono;

}datos;

int main(){
    datos* pers1 = malloc(sizeof(datos));
    datos* pers2 = malloc(sizeof(datos));
    datos* pers3 = malloc(sizeof(datos));
    datos* pers4 = malloc(sizeof(datos));
    datos* pers5 = malloc(sizeof(datos));

    printf("ingrese los datos de la persona N1");
    printf("\nNombre :");
    scanf("%s",pers1->nombre);
    printf("\nEdad :");
    scanf("%i",&pers1->edad);
    printf("\nDni :");
    scanf("%i",&pers1->dni);
    printf("\nTelefono :");
    scanf("%i",&pers1->telefono);
 
    printf("ingrese los datos de la persona N2");
    printf("\nNombre :");
    scanf("%s",&pers2->nombre);
    printf("\nEdad :");
    scanf("%i",&pers2->edad);
    printf("\nDni :");
    scanf("%i",&pers2->dni);
    printf("\nTelefono :");
    scanf("%i",&pers2->telefono);

    printf("ingrese los datos de la persona N3");
    printf("\nNombre :");
    scanf("%s",&pers3->nombre);
    printf("\nEdad :");
    scanf("%i",&pers3->edad);
    printf("\nDni :");
    scanf("%i",&pers3->dni);
    printf("\nTelefono :");
    scanf("%i",&pers3->telefono);
    
    printf("ingrese los datos de la persona N4");
    printf("\nNombre :");
    scanf("%s",pers4->nombre);
    printf("\nEdad :");
    scanf("%i",&pers4->edad);
    printf("\nDni :");
    scanf("%i",&pers4->dni);
    printf("\nTelefono :");
    scanf("%i",&pers4->telefono);

    printf("ingrese los datos de la persona N5");
    printf("\nNombre :");
    scanf("%s",pers5->nombre);
    printf("\nEdad :");
    scanf("%i",&pers5->edad);
    printf("\nDni :");
    scanf("%i",&pers5->dni);
    printf("\nTelefono :");
    scanf("%i",&pers5->telefono);


  



}