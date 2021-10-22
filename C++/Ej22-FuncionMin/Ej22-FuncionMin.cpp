#include <iostream>
using namespace std;
int min(int *x, int *y);
int main(){
    int n1 = 5;
    int n2 = 3;

    min(&n1,&n2);

}
int min(int *x, int *y){
    if(*x > *y){
        cout << *x << ":es mayor";
    }
    if(*x < *y){
        cout << *y << ":es mayor";
    }

    return(0);
}