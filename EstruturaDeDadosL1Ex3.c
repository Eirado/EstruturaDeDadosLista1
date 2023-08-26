#include <stdio.h>
#include <math.h>

struct Ponto {
    float x;
    float y;
};

float calcularDistancia(struct Ponto p1, struct Ponto p2) {
    float distancia = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
    return distancia;
}

float calcularInclinacao(struct Ponto p1, struct Ponto p2) {
    float inclinacao = (p2.y - p1.y) / (p2.x - p1.x);
    return inclinacao;
}

int main() {
    struct Ponto ponto1 = {1.0, 2.0};
    struct Ponto ponto2 = {4.0, 6.0};

    printf("Coordenadas do Ponto 1: (%.2f, %.2f)\n", ponto1.x, ponto1.y);
    printf("Coordenadas do Ponto 2: (%.2f, %.2f)\n", ponto2.x, ponto2.y);

    float distancia = calcularDistancia(ponto1, ponto2);
    printf("Distancia entre os pontos: %.2f\n", distancia);

    float inclinacao = calcularInclinacao(ponto1, ponto2);
    printf("Inclinacao da reta: %.2f\n", inclinacao);

    return 0;
}
