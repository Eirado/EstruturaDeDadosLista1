#include <stdio.h>
#include <string.h>

#define MaxContatos 100

struct Contato {
    char nome[50];
    char telefone[15];
};

void adicionarContato(struct Contato contatos[], int *numContatos) {
    if (*numContatos < MaxContatos) {
        printf("Digite o nome do contato: ");
        scanf("%s", contatos[*numContatos].nome);

        printf("Digite o número de telefone: ");
        scanf("%s", contatos[*numContatos].telefone);

        (*numContatos)++;
        printf("Contato adicionado com sucesso!\n");
    } else {
        printf("Limite de contatos alcancado.\n");
    }
}

void listarContatos(struct Contato contatos[], int numContatos) {
    int i = 0;
    printf("Lista de contatos:\n");
    for (i = 0; i < numContatos; i++) {
        printf("Nome: %s, Telefone: %s\n", contatos[i].nome, contatos[i].telefone);
    }
}

void buscarContato(struct Contato contatos[], int numContatos, const char *nomeBusca) {
    int encontrado = 0;
    int i = 0;
    for (i = 0; i < numContatos; i++) {
        if (strcmp(contatos[i].nome, nomeBusca) == 0) {
            printf("Contato encontrado:\n");
            printf("Nome: %s, Telefone: %s\n", contatos[i].nome, contatos[i].telefone);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Contato nao encontrado.\n");
    }
}

int main() {
    struct Contato contatos[MaxContatos];
    int numContatos = 0;

    int opcao;
    char nomeBusca[50];

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1. Adicionar Contato\n");
        printf("2. Listar Contatos\n");
        printf("3. Buscar Contato por Nome\n");
        printf("4. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato(contatos, &numContatos);
                break;
            case 2:
                listarContatos(contatos, numContatos);
                break;
            case 3:
                printf("Digite o nome do contato a buscar: ");
                scanf("%s", nomeBusca);
                buscarContato(contatos, numContatos, nomeBusca);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opcao inválida. Escolha novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}
