#include <stdio.h>
#include <stdlib.h>
#define t 50;
typedef struct personas{
    char nombre[50];
    long edad;
    long dni;
    long telefono;

}datos;
void almacenartos();
void Almacenar_datos();
void Lectura_datos();
int main(){
    datos* pers = malloc(sizeof(datos));
    almacenartos();
    Almacenar_datos();
    Lectura_datos();

    system("pause");      
	system ("cls");

    free(pers);                                                              
	pers=NULL;                                                             
	                                                                        
	return 0;
}
void almacenartos(){

    int i = 0;
    datos* pers = (datos*)malloc(sizeof(datos));
    pers[i];
    for(i = 1;i <= 5;i++){
        printf("ingrese los datos de la persona N%i",i);
        printf("\nNombre :");
        scanf("%s",pers[i].nombre);
        printf("\nEdad :");
        scanf("%i",&pers[i].edad);
        printf("\nDni :");
        scanf("%i",&pers[i].dni);
        printf("\nTelefono :");
        scanf("%i",&pers[i].telefono);
    }

    printf("los datos ingresados son:");
    for(i = 1;i <= 5;i++){
        printf("\nNombre :%s", pers[i].nombre);
        printf("\nEdad :%i",pers[i].edad);
        printf("\nDni :%i",pers[i].dni);
        printf("\nTelefono:%i",pers[i].telefono);

    }   
}
void Almacenar_datos(){
		FILE *archivo;                                                                    
		int i;
        datos* pers = malloc(sizeof(datos));
		if( (archivo=fopen("Personas.txt","w") ) == NULL){
			printf("\nError al abrir el archivo para escritura");
		}else{
            for(i = 1; i <= 5; i++){
			fwrite(&pers[i], sizeof (struct personas), 1, archivo);                   
			fclose(archivo);
            }
        }
}
void Lectura_datos(){
		int i;
		FILE *archivo;
		datos* pers = malloc(sizeof(datos));
		if( (archivo=fopen("Personas.txt","r") ) == NULL){
			printf("Error al abrir el archivo de lectura");
		}else{
				
			printf("\nlISTA DE DATOS INGRESADOR\n");
			fread(pers,sizeof(datos),1,archivo);
				
		while ( !feof(archivo)) {
            for(i = 1;i <= 5;i++){

                printf("\nNombre :%s", pers[i].nombre);
                printf("\nEdad :%i",pers[i].edad);
                printf("\nDni :%i",pers[i].dni);
                printf("\nTelefono:%i",pers[i].telefono);
			    fread(pers,sizeof(datos),1,archivo);    
            }                                                 
		}
	}
			fclose(archivo);
		}	