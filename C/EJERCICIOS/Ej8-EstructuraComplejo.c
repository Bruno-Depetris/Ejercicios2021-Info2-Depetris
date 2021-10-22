#include<stdio.h>


int main (){
struct complejo{
    float real;
    float imaginario;
}x, *px, cx[100];
x.real = 1.3;
x.imaginario = -2.2;
px = &x;

printf("\ningrese un valor para el espacio decimoctavo de cx:\t");
scanf("%f",&cx[17]);
for(int i=0;i>=100;i++){
    printf("los valores de cx son:%.2f",cx[i]);
}
    


}

