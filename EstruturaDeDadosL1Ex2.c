#include <stdio.h>

struct Tipo {
    int valorInteiro;
    float valorFlutuante;
    char letra;
};

int main() {
    struct Tipo meuTipo;
    meuTipo.valorInteiro = 42;
    meuTipo.valorFlutuante = 3.14;
    meuTipo.letra = 'A';

    printf("Valor Inteiro: %d\n", meuTipo.valorInteiro);
    printf("Valor Flutuante: %.2f\n", meuTipo.valorFlutuante);
    printf("Letra: %c\n", meuTipo.letra);

    return 0;
}
