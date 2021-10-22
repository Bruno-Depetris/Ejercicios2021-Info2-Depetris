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
    FILE *archivo;
    int i = 0;
    datos* pers = malloc(sizeof(datos));
    pers[i];
    for(i = 1;i <= 5;i++){
        printf("ingrese los datos de la persona N%i",i);
        printf("\nNombre :");
        fscanf("%s",pers[i].nombre);
        printf("\nEdad :");
        fscanf("%i",&pers[i].edad);
        printf("\nDni :");
        fscanf("%i",&pers[i].dni);
        printf("\nTelefono :");
        fscanf("%i",&pers[i].telefono);
    }

    printf("los datos ingresados son:");
    for(i = 1;i <= 5;i++){
        printf("\nNombre :", pers[i].nombre);
        printf("\nEdad :",pers[i].edad);
        printf("\nDni :",pers[i].dni);
        printf("\nTelefono :",pers[i].telefono);

    }
    archivo =  fopen("Personas.txt","w");
    if(archivo != NULL){
        frite(pers,sizeof(struct personas),100,archivo);
        fclose(archivo);
    }else{
        printf("ERROR");
    }
    


}