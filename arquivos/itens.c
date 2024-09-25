#include <stdio.h>
#include <string.h>
#include "itens.h"

void cadastrar_item(Item produtos[], int *num_produtos) {
    if (*num_produtos < limite_ITENS) {
        printf("Nome do item: ");
        scanf("%s", produtos[*num_produtos].nome);
        printf("Preço: ");
        scanf("%f", &produtos[*num_produtos].preco);
        (*num_produtos)++;
    } else {
        printf("Limite de itens atingido.\n");
    }
}

void listar_itens(Item produtos[], int num_produtos) {
    for (int i = 0; i < num_produtos; i++) {
        printf("Item %d: %s - Preço: %.2f\n", i + 1, produtos[i].nome, produtos[i].preco);
    }
}

void salvar_itens(Item produtos[], int num_produtos) {
    FILE *file = fopen("data/itens.dat", "wb");
    if (file != NULL) {
        fwrite(&num_produtos, sizeof(int), 1, file);
        fwrite(produtos, sizeof(Item), num_produtos, file);
        fclose(file);
    } else {
        printf("Erro ao abrir arquivo para salvar itens.\n");
    }
}

void carregar_itens(Item produtos[], int *num_produtos) {
    FILE *file = fopen("data/itens.dat", "rb");
    if (file != NULL) {
        fread(num_produtos, sizeof(int), 1, file);
        fread(produtos, sizeof(Item), *num_produtos, file);
        fclose(file);
    } else {
        *num_produtos = 0;
    }
}

int busca_binaria(Item produtos[], int inicio, int fim, const char *nome) {
    if (fim >= inicio) {
        int meio = inicio + (fim - inicio) / 2;

        if (strcmp(produtos[meio].nome, nome) == 0) {
            return meio;
        }

        if (strcmp(produtos[meio].nome, nome) > 0) {
            return busca_binaria(produtos, inicio, meio - 1, nome);
        } else {
            return busca_binaria(produtos, meio + 1, fim, nome);
        }
    }
    return -1;
}

void editar_item(Item produtos[], int num_produtos) {
    char nome[50];
    printf("Nome do item a editar: ");
    scanf("%s", nome);
    
    int index = busca_binaria(produtos, 0, num_produtos - 1, nome);
    if (index != -1) {
        printf("Novo preço: ");
        scanf("%f", &produtos[index].preco);
        printf("Item editado com sucesso!\n");
    } else {
        printf("Item não encontrado.\n");
    }
}

void excluir_item(Item produtos[], int *num_produtos) {
    char nome[50];
    printf("Nome do item a excluir: ");
    scanf("%s", nome);
    
    int index = busca_binaria(produtos, 0, *num_produtos - 1, nome);
    if (index != -1) {
        for (int i = index; i < *num_produtos - 1; i++) {
            produtos[i] = produtos[i + 1];
        }
        (*num_produtos)--;
        printf("Item excluído com sucesso!\n");
    } else {
        printf("Item não encontrado.\n");
    }
}

void buscar_item(Item produtos[], int num_produtos) {
    char nome[50];
    printf("Nome do item a buscar: ");
    scanf("%s", nome);
    
    int index = busca_binaria(produtos, 0, num_produtos - 1, nome);
    if (index != -1) {
        printf("Item encontrado: %s - Preço: %.2f\n", produtos[index].nome, produtos[index].preco);
    } else {
        printf("Item não encontrado.\n");
    }
}