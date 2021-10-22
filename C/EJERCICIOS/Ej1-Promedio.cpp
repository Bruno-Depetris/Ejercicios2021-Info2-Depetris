#include <stdio.h>
#include <math.h>


int main (){
	int enteros[100], x, suma, i;
	float promedio;
	
	suma = -9999; 
	i = 0;
	
	printf("Ingrese los numeros deseados uno a uno\n"
		   "Cuandno finalice ingrese el numero 9999 para obtener el promedio\n");
	
	for(x=0;x<=100;x++){
		printf(":");
		scanf("%i", &enteros[x]);
		i++;
		suma += enteros[x];
		if(enteros[x] == 9999){
			i = i - 1;
			promedio = suma/i;
			printf ("el promedio es:%f", promedio);
			return 0;
		}
	}
	
}
