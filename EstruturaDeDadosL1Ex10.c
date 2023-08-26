#include <stdio.h>

struct Moeda {
    float dolares;
    float euros;
};

int main() {
    struct Moeda moeda;
    moeda.dolares = 0.0;
    moeda.euros = 0.0;

    float taxaCambioDolarParaEuro = 0.85;

    int opcao;
    printf("Escolha uma opcao:\n");
    printf("1 - Converter de dolares para euros\n");
    printf("2 - Converter de euros para dolares\n");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite o valor em dolares: ");
            scanf("%f", &moeda.dolares);
            moeda.euros = moeda.dolares * taxaCambioDolarParaEuro;
            printf("Valor em euros: %.2f\n", moeda.euros);
            break;
        case 2:
            printf("Digite o valor em euros: ");
            scanf("%f", &moeda.euros);
            moeda.dolares = moeda.euros / taxaCambioDolarParaEuro;
            printf("Valor em dolares: %.2f\n", moeda.dolares);
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }

    return 0;
}
