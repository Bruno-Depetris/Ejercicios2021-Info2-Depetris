#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "rs232.h"
#include <string.h>			
#include <stdint.h>			
	
struct sensores{           
	uint32_t tiempo;     
	uint16_t valor;      
	char nombre;           
};
	
union Datos{
	struct sensores dato;
	byte a[sizeof(struct sensores)];
}DatosSen;
	
int main (){
	int puertoCOM=2;                 //N�mero de puerto. 2 es para el COM3 en windows
	int baudios=9600;                
	char modo[]={'8','N','1',0};     
	
	char letra;
	int cantidadBytes;
	
	if(RS232_OpenComport(puertoCOM, baudios, modo, 0)){
		printf("No se puede abrir el puerto COM\n");
		return(0);
	}
	
	while(1){
		printf("---------MENU------\n\n");
		printf("Ingrese la letra caracteristica para obtener datos del sensor\n\n");
		printf("Temperatura: 'T'\n");
		printf("Distancia: 'D'\n");
		printf("Letra ingresada: ");
		scanf("%s",&letra);
		
		RS232_SendByte(puertoCOM, letra);  //Se manda letra por letra por el puerto seria
		
		cantidadBytes = RS232_PollComport(puertoCOM, DatosSen.a, sizeof(struct sensores)-1);   //Devuelve la cantidad de bytes leidos
		
		if(cantidadBytes > 0){     //Comprueba que se haya leido byte
			DatosSen.a[cantidadBytes] = 0;  
		}  
			
			//Se muestra valores almacenados en la estructura
			printf("-Nombre: %c\n",DatosSen.dato.nombre);        
			printf("Valor: %d\n",DatosSen.dato.valor);
			printf("Valor: %lu milisegundos\n",DatosSen.dato.tiempo);
			
		}
		
		system ("cls");        //Se limpia la pantalla
	}

