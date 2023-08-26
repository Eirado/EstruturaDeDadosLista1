#include <stdio.h>
#include <string.h>

#define numDisciplinas 3
#define notaAprovacao 7.0

struct Estudante {
    char nome[100];
    int matricula;
    float notas[numDisciplinas];
};

float calcularMedia(struct Estudante estudante) {
    float somaNotas = 0.0;
    int i;
    for (i = 0; i < numDisciplinas; i++) {
        somaNotas += estudante.notas[i];
    }
    return somaNotas / numDisciplinas;
}

int estaAprovado(struct Estudante estudante) {
    float media = calcularMedia(estudante);
    return media >= notaAprovacao;
}

int main() {
    struct Estudante aluno;

    printf("Digite o nome do aluno: ");
    scanf("%s", aluno.nome);

    printf("Digite a matricula do aluno: ");
    scanf("%d", &aluno.matricula);

    printf("Digite as notas do aluno nas %d disciplinas:\n", numDisciplinas);
    int i;
    for (i = 0; i < numDisciplinas; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &aluno.notas[i]);
    }

    printf("\nInformacoes do aluno:\n");
    printf("Nome: %s\n", aluno.nome);
    printf("Matricula: %d\n", aluno.matricula);
    for (i = 0; i < numDisciplinas; i++) {
        printf("Nota %d: %.2f\n", i + 1, aluno.notas[i]);
    }

    float media = calcularMedia(aluno);
    printf("Media: %.2f\n", media);

    if (estaAprovado(aluno)) {
        printf("Situacao: Aprovado\n");
    } else {
        printf("Situacao: Reprovado\n");
    }

    return 0;
}
