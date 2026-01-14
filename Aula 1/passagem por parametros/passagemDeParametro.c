#include <stdio.h>

void dobra(int x){
    x = x * 2;

    printf("O valor dentro da função é de: %d\n", x);
}

int main(){
    int numero = 5;

    dobra(numero);

    printf("Fora da função o valor é de: %d\n", numero);
}