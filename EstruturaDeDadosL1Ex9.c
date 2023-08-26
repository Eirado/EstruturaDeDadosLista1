#include <stdio.h>
#include <string.h>

struct Funcionario {
    char nome[50];
    char cargo[50];
    float salario;
    int anoAdmissao;
};

void darAumento(struct Funcionario *funcionario, float aumento) {
    funcionario->salario += aumento;
}

int calcularTempoTrabalho(struct Funcionario *funcionario, int anoAtual) {
    return anoAtual - funcionario->anoAdmissao;
}

int main() {
    struct Funcionario funcionario = {
        "Joao da Silva",
        "Analista",
        3000.0,
        2020
    };

    int anoAtual = 2023;

    printf("Nome: %s\n", funcionario.nome);
    printf("Cargo: %s\n", funcionario.cargo);
    printf("Salario: R$%.2f\n", funcionario.salario);

    int anosTrabalho = calcularTempoTrabalho(&funcionario, anoAtual);
    printf("Tempo de trabalho: %d anos\n", anosTrabalho);

    darAumento(&funcionario, 500.0);
    printf("Salario apos aumento: R$%.2f\n", funcionario.salario);

    return 0;
}
