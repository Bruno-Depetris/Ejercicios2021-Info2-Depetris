#include <iostream>
#include <math.h>
using namespace std;
int tripleLlamadaPorValor(int x);
int  triplePorReferencia(int *y);
int main (){
    int numero;
    cout << "ingrese un numero:";
    cin >> numero;
    tripleLlamadaPorValor(numero);
    triplePorReferencia(&numero); 
    cout << "\n" << "llamada por valor:" << tripleLlamadaPorValor(numero);
    cout << "\n" << "Llamada por referencia:" << triplePorReferencia(&numero);

}

int tripleLlamadaPorValor(int x){

    int new_valor;

    new_valor = x * 3;

    return 1;

}
int  triplePorReferencia(int *y){
    int new_valor2;

    new_valor2 = *y * 3;

    return 1;

}