#include <stdio.h>
#include <string.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidadeEmEstoque;
};

int main() {
    struct Produto produtos[3] = {
        {"Produto A", 10.0, 5},
        {"Produto B", 15.0, 8},
        {"Produto C", 20.0, 3}
    };

    printf("Bem-vindo(a) a loja virtual!\n");

    int i;
    while (1) {
        printf("Produtos disponiveis:\n");
        for (i = 0; i < 3; i++) {
            printf("%s - R$%.2f - Estoque: %d\n", produtos[i].nome, produtos[i].preco, produtos[i].quantidadeEmEstoque);
        }

        char nomeProduto[50];
        printf("Digite o nome do produto que deseja comprar (ou 'sair' para encerrar): ");
        scanf("%s", nomeProduto);

        if (strcmp(nomeProduto, "sair") == 0) {
            break;
        }

        int quantidadeCompra;
        printf("Digite a quantidade que deseja comprar: ");
        scanf("%d", &quantidadeCompra);

        int produtoEncontrado = 0;
        for (i = 0; i < 3; i++) {
            if (strcmp(produtos[i].nome, nomeProduto) == 0) {
                if (produtos[i].quantidadeEmEstoque >= quantidadeCompra) {
                    float totalCompra = produtos[i].preco * quantidadeCompra;
                    printf("Compra realizada: %s - Quantidade: %d - Total: R$%.2f\n", produtos[i].nome, quantidadeCompra, totalCompra);
                    produtos[i].quantidadeEmEstoque -= quantidadeCompra;
                } else {
                    printf("Estoque insuficiente.\n");
                }
                produtoEncontrado = 1;
                break;
            }
        }

        if (!produtoEncontrado) {
            printf("Produto nao encontrado.\n");
        }
    }

    printf("Obrigado por comprar conosco!\n");

    return 0;
}
