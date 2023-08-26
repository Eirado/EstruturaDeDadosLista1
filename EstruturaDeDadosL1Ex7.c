#include <stdio.h>
#include <string.h>

struct ContaBancaria {
    char nomeTitular[100];
    int numeroConta;
    float saldo;
};

void depositar(struct ContaBancaria *conta, float valor) {
    conta->saldo += valor;
    printf("Deposito realizado com sucesso. Novo saldo: %.2f\n", conta->saldo);
}

void sacar(struct ContaBancaria *conta, float valor) {
    if (conta->saldo >= valor) {
        conta->saldo -= valor;
        printf("Saque realizado com sucesso. Novo saldo: %.2f\n", conta->saldo);
    } else {
        printf("Saldo insuficiente para saque.\n");
    }
}

void verificarSaldo(struct ContaBancaria conta) {
    printf("Saldo atual: %.2f\n", conta.saldo);
}

int main() {
    struct ContaBancaria conta;
    
    printf("Digite o nome do titular da conta: ");
    scanf("%s", conta.nomeTitular);
    
    printf("Digite o numero da conta: ");
    scanf("%d", &conta.numeroConta);
    
    conta.saldo = 0.0;
    
    int opcao;
    float valor;
    
    do {
        printf("\nEscolha uma opcao:\n");
        printf("1. Depositar\n");
        printf("2. Sacar\n");
        printf("3. Verificar Saldo\n");
        printf("4. Sair\n");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                printf("Digite o valor a depositar: ");
                scanf("%f", &valor);
                depositar(&conta, valor);
                break;
            case 2:
                printf("Digite o valor a sacar: ");
                scanf("%f", &valor);
                sacar(&conta, valor);
                break;
            case 3:
                verificarSaldo(conta);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao invalida. Escolha novamente.\n");
        }
    } while (opcao != 4);
    
    return 0;
}
