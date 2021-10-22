#include <stdio.h>
#include <math.h>

int main () {
	
	double monto;
	double principal = 1000.0;
	double tasa[5]={.05,.06,.08,.09,.10};
	int anio;
	int opcion;
	
	
	printf("\tSeleccione la tasa de interes\n\n"
		   "........5 porciento........(presione 1)\n"
		   "........6 porciento........(presione 2)\n"
		   "........8 porciento........(presione 3)\n"
		   "........9 porciento........(presione 4)\n"
		   "........10 porciento.......(presione 5)\n"
		   "Al finalizar presione la tecla ENTER\n");
	
	scanf("%i", &opcion);
	
	switch(opcion){
	case 1: 
		printf("Usted selecciono la tasa de 5 pociento\n");
		printf("%4s %21s\n", "anio", "Monto del deposito");
		
		for(anio = 1; anio <= 10; anio++){
			monto = principal * pow (1.0 + tasa[0], anio);
			printf("%4d %21.2f\n", anio, monto);
		}
		break;
		
		
	case 2: 
		printf("Usted selecciono la tasa de 6 pociento\n");
		printf("%4s %21s\n", "anio", "Monto del deposito");
		
		for(anio = 1; anio <= 10; anio++){
			monto = principal * pow (1.0 + tasa[1], anio);
			printf("%4d %21.2f\n", anio, monto);
		}
		break;
	
	case 3: 
		printf("Usted selecciono la tasa de 8 pociento\n");
		printf("%4s %21s\n", "anio", "Monto del deposito");
		
		for(anio = 1; anio <= 10; anio++){
			monto = principal * pow (1.0 + tasa[2], anio);
			printf("%4d %21.2f\n", anio, monto);
		}
		break;
		
	
	case 4: 
		printf("Usted selecciono la tasa de 9 pociento\n");
		printf("%4s %21s\n", "anio", "Monto del deposito");
		
		for(anio = 1; anio <= 10; anio++){
			monto = principal * pow (1.0 + tasa[3], anio);
			printf("%4d %21.2f\n", anio, monto);
		}
		break;
		
		
	case 5: 
		printf("Usted selecciono la tasa de 10 pociento\n");
		printf("%4s %21s\n", "anio", "Monto del deposito");
		
		for(anio = 1; anio <= 10; anio++){
			monto = principal * pow (1.0 + tasa[4], anio);
			printf("%4d %21.2f\n", anio, monto);
		}
		break;
		
	}
	if(opcion > 5){
		printf("Error al ingresar una opcion\n");
	}
		
	return 0;
}
	
