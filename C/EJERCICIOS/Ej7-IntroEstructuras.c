#include <stdio.h>
#include <stdlib.h>

struct productos{
	int d, p, c;
	char *descripcion;
	float *precio;
	int *codigo;
	
}prod;


int main () {
	prod.descripcion = (char*)malloc(prod.d*sizeof(int));
	prod.precio = (float*)malloc(prod.p*sizeof(int));
	prod.codigo = (int*)malloc(prod.c*sizeof(int));
	
	FILE *productos;
	int cantidad;
	int i = 0;
	
	if(productos != NULL){
		printf("\nIngrese la cantidad de productos");
		scanf("%d",&cantidad);
		
		for(i = 0;i <= cantidad; i++){
			printf("Ingrese producto N %d",i);
			float t = fwrite(&prod.descripcion, sizeof(int),1,productos);
			fclose(productos);
		}
		
		float t = fwrite(&cantidad, sizeof(int),1,productos);
		fclose(productos);
	}else{
		printf("\nERROR ");   
	}
	
}

