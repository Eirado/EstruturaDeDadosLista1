#include <stdio.h>
#include <string.h>

#define maxLivros 100

struct Livro {
    char titulo[100];
    char autor[100];
    int anoPublicacao;
};

void adicionarLivro(struct Livro livros[], int *numLivros) {
    if (*numLivros < maxLivros) {
        printf("Digite o título do livro: ");
        scanf("%s", livros[*numLivros].titulo);

        printf("Digite o nome do autor: ");
        scanf("%s", livros[*numLivros].autor);

        printf("Digite o ano de publicação: ");
        scanf("%d", &livros[*numLivros].anoPublicacao);

        (*numLivros)++;
        printf("Livro adicionado com sucesso!\n");
    } else {
        printf("Limite de livros alcançado.\n");
    }
}

void listarLivros(struct Livro livros[], int numLivros) {
    int i = 0;
    printf("Lista de livros:\n");
    for (i = 0; i < numLivros; i++) {
        printf("Título: %s, Autor: %s, Ano: %d\n", livros[i].titulo, livros[i].autor, livros[i].anoPublicacao);
    }
}

void buscarLivroPorAutor(struct Livro livros[], int numLivros, const char *autorBusca) {
    int encontrado = 0;
    int i = 0;
    printf("Livros do autor %s:\n", autorBusca);
    for (i = 0; i < numLivros; i++) {
        if (strcmp(livros[i].autor, autorBusca) == 0) {
            printf("Título: %s, Ano: %d\n", livros[i].titulo, livros[i].anoPublicacao);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("Nenhum livro encontrado para o autor %s.\n", autorBusca);
    }
}

int main() {
    struct Livro livros[maxLivros];
    int numLivros = 0;

    int opcao;
    char autorBusca[100];

    do {
        printf("\nEscolha uma opcao:\n");
        printf("1. Adicionar Livro\n");
        printf("2. Listar Livros\n");
        printf("3. Buscar Livro por Autor\n");
        printf("4. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarLivro(livros, &numLivros);
                break;
            case 2:
                listarLivros(livros, numLivros);
                break;
            case 3:
                printf("Digite o nome do autor a buscar: ");
                scanf("%s", autorBusca);
                buscarLivroPorAutor(livros, numLivros, autorBusca);
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
