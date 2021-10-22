#include <stdio.h>
#include <stdlib.h>
#define t 500

struct productos{
    char *descripcion[50];
    float precio;
    int codigo;
    
}producto, *ptr_producto;  

void cargadatos();
void Almacenar_datos();
void Lectura_datos();
void Mostrar_datos_codigo();

void cargardatos (){

	int cant,i;
	printf("Cuantos productos tiene?:");
	scanf("%i",&cant);

	for(i = 1; i <= cant ; i++){
		ptr_producto =(struct productos *) calloc (cant,sizeof(struct productos) );  
		ptr_producto=&producto; 
		
		printf("\nIngrese su producto: ");
		scanf("%s",ptr_producto->descripcion);
		printf("Ingrese el c%cdigo: ",162);
		scanf("%d",&ptr_producto->codigo);
		printf("Ingrese el precio: "); 
		scanf("%f",&ptr_producto->precio);
	
		Almacenar_datos();                                                               
		free(ptr_producto);                                                              
		ptr_producto=NULL;   
	}
		
	ptr_producto=( struct productos *) calloc (cant,sizeof(struct productos) );
	ptr_producto=&producto;
}
void Almacenar_datos(){
		FILE *archivo;                                                                    
		
		if( (archivo=fopen("PRODUCTOS.dat","ab") ) == NULL){
			printf("\nError al abrir el archivo para escritura");
		}
		else{
			fwrite(&producto, sizeof (struct productos), 1, archivo);                   
			fclose(archivo);
		}
	}
void Lectura_datos(){
			
		ptr_producto=&producto;
		FILE *archivo;
			
		if( (archivo=fopen("PRODUCTOS.dat","rb") ) == NULL){
			printf("Error al abrir el archivo de lectura");
		}
			
		else{
				
			printf("\nlISTA DE DATOS INGRESADOR\n");
			fread(ptr_producto,sizeof(producto),1,archivo);
				
		while ( !feof(archivo)) {
			printf("\nProductos: %s\n", ptr_producto->descripcion);
			printf("Codigo: %i\n", ptr_producto->codigo);
			printf("Precio: %.2f\n",ptr_producto->precio);
			fread(ptr_producto,sizeof(producto),1,archivo);                                                     
		}
		}
			fclose(archivo);
		}
void Mostrar_datos_codigo(){
			
	int valor;	
	FILE *archivo;
	ptr_producto=&producto;
			
	printf("\nIngrese el codigo: ");
	scanf("%d",&valor);
				
	if( (archivo=fopen("SUPERMERCADO.dat","r") ) == NULL){
			printf("Error al abrir el archivo de lectura");
		}
				
		fread(ptr_producto,sizeof(producto),1,archivo);                     
				
		while ( !feof(archivo)) {
					
			if(valor==(ptr_producto->codigo)){                                  
				printf("\nProductos: %s\n", ptr_producto->descripcion);
				printf("Codigo: %i\n",ptr_producto->codigo);
				printf("Precio: %.2f\n",ptr_producto->precio);
			}
					
			fread(ptr_producto,sizeof(producto),1,archivo);	                 //Para que no me tome 2 veces un valor del archivo
				}
				fclose(archivo);
			}
	
int main (){
	int dato;
	
	do{
		printf("COLOCAR EL NUMERO DE LA OPCION A SELECCIONAR");
		printf("\n\nCargar producto: 1");
		printf("\nMostarar listado de productos cargados: 2");
		printf("\nMostrar producto por codigo: 3 ");
		printf("\nSalir: 4");
		printf("\n\nNumero: ");
		scanf("%d",&dato);
		
		switch(dato){
			
		case 1:cargardatos();break;
		case 2:Lectura_datos();break;
		case 3:Mostrar_datos_codigo();break;
		}
		
		printf("\n");
		system("pause");      
		system ("cls");
		
	} while( (0<=dato) && (dato<=3) );
	
	free(ptr_producto);                                                              
	ptr_producto=NULL;                                                               
	                                                                        
	return 0;
}
