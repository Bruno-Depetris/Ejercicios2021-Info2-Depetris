#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	int opcion;
	float  suma, f[100] = {65.574 , 57.388 , 122.254 , 125.031 , 93.333 , 58.756 , 26.659 , 61.442 , 193.866 , 22.583 , 90.063 , 30.59 , 178.051 , 132.947 , 56.168 , 105.465 , 170.727 , 131.126 , 189.356 , 151.147 , 73.463 , 128.722 , 121.068 , 99.299 , 26.194 , 113.62 , 157.893 , 4.868 , 72.796 , 183.768 , 5.851 , 117.763 , 113.042 , 137.811 , 101.363 , 26.506 , 155.136 , 24.942 , 36.723 , 62.811 , 130.78 , 147.643 , 45.546 , 143.456 , 98.08 , 60.049 , 149.959 , 167.616 , 138.691 , 33.946 , 92.02 , 188.238 , 61.952 , 40.788 , 126.364 , 117.987 , 179.427 , 17.191 , 165.159 , 46.429 , 102.312 , 14.36 , 128.332 , 19.75 , 163.666 , 60.039 , 19.347 , 103.815 , 86.972 , 188.315 , 148.61 , 197.525 , 43.585 , 70.877 , 142.141 , 92.303 , 149.834 , 196.792 , 79.886 , 123.251 , 38.902 , 116.568 , 38.76 , 94.23 , 77.061 , 85.171 , 158.494 , 117.181 , 63.715 , 175.603 , 191.389 , 165.563 , 33.47 , 17.659 , 196.029 , 30.995 , 25.94 , 132.603 , 60.566 , 7.238} ;
	int e[100] = {63 , 37 , 170 , 68 , 17 , 57 , 106 , 131 , 47 , 190 , 88 , 96 , 199 , 158 , 129 , 98 , 62 , 119 , 85 , 162 , 13 , 175 , 73 , 84 , 173 , 179 , 129 , 140 , 42 , 21 , 197 , 168 , 70 , 63 , 196 , 18 , 125 , 80 , 197 , 125 , 194 , 75 , 132 , 176 , 146 , 164 , 147 , 79 , 181 , 125 , 179 , 34 , 81 , 155 , 77 , 140 , 186 , 114 , 40 , 28 , 87 , 145 , 38 , 64 , 46 , 105 , 139 , 87 , 154 , 149 , 70 , 118 , 135 , 129 , 83 , 88 , 195 , 127 , 174 , 191 , 133 , 118 , 33 , 89 , 188 , 102 , 149 , 143 , 133 , 12 , 104 , 138 , 10 , 84 , 45 , 22 , 57 , 106 , 3 , 44};
	
	printf("Seleccione una OPCION\n"
		   "Despliegue el valor del s�ptimo elemento del arreglo de caracteres f.......................(OPCION 1)\n"
		   "Introduzca un valor en el elemento 4 del arreglo de punto flotante con un solo sub�ndice,b..(OPCION 2)\n"
		   "Inicialice en 8 cada uno de los 5 elementos del arreglo entero g............................(OPCION 3)\n"
		   "Sume los elementos del arreglo de punto flotante c, el cual contiene 100 elementos..........(OPCION 4)\n"
		   "Copie el arreglo a en la primera porci�n del arreglo b. Suponga que double a[11], b[34]....(OPCION 5)\n");
	scanf("%i", &opcion);
				
	switch(opcion){
	case 1:
		printf("Usted selecciono la opcion 1\n"
			   "El valor del septimo elemento es:%f\n",  f[6] );
		break;
		
	case 2:
		printf("Usted selecciono la opcion 2\n"
			   "Introdusca un valor tipo float para colocar al elemento 4 del arreglo\n"
			   ":");
		scanf("%f", &f[3]);
		break;
		
	case 3:
		printf("Usted selecciono la opcion 3\n");
		break;
		
	case 4:
		for(int i = 0;i <= 100; i++){
			suma +=f[i];
		}
		printf("Usted selecciono la opcion 4\n"
			  "La suma de los elementos de tipo float es = %f", suma);
		break;
		
	case 5:
		printf("Usted selecciono la opcion 5\n");
	}
}
