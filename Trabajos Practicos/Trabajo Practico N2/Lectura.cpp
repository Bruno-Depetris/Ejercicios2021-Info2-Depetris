#include <stdio.h>			//
#include <string.h>			//Incluimos las librerias
#include <conio.h>			//
#include <stdint.h>			//

struct Edatos{    			//Estructura Tipo E datos
	uint32_t tiempo;
	uint16_t valor;
	char nombre;
}TamLect;		//nombre TamLect utilizado para pasar datos

FILE *DatoS;					//Puntero tipo DatoS
int ocupa=0;					//variable utilizada para guardar el tamaño de la etructura 

int main(){
	char CaracterB1, CaracterB2;
	
	if((DatoS=fopen("SENSORES.txt","r"))==NULL)
	{
		printf("\nERROR - No se puede abrir archivo especificado\n");
	}
	else
	{
		ocupa = sizeof(TamLect);										//Si el archivo existe,le guarda el tamaño
		printf("Dimencion de la estructura: %d \n",ocupa);
		
		while ( !feof( DatoS ) ){											
			fread((uint8_t*)&TamLect,ocupa,1,DatoS);	//Se lee el archivo
			
			CaracterB2 = TamLect.nombre;
			
			if(CaracterB2 == CaracterB1){
				break;
			}
			else{
				CaracterB1 = CaracterB2;
				printf("-Nombre: %c\n",TamLect.nombre);
				printf("-Medicio: %d\n",TamLect.valor);					//imprecion de datos de los sensores
				printf("-Tiempo; %d\n",TamLect.tiempo);
			}
		}
		fclose(DatoS);															//cerramos archivo
	}
	
	return(0);
}
