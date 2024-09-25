#ifndef ITENS_H
#define ITENS_H

#define limite_ITENS 100

typedef struct {
    char nome[50];
    float preco;
} Item;

void cadastrar_item(Item produtos[], int *num_produtos);
void listar_itens(Item produtos[], int num_produtos);
void salvar_itens(Item produtos[], int num_produtos);
void carregar_itens(Item produtos[], int *num_produtos);
void editar_item(Item produtos[], int num_produtos);
void excluir_item(Item produtos[], int *num_produtos);
void buscar_item(Item produtos[], int num_produtos);

#endif