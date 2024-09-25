#include <stdio.h>
#include "usuarios.h"
#include "itens.h"

int main() {
    Usuario usuarios[limite_USUARIOS];
    Item produtos[limite_ITENS];
    int num_usuarios = 0;
    int num_produtos = 0;
    int opcao;

    carregar_usuarios(usuarios, &num_usuarios);
    carregar_itens(produtos, &num_produtos);

    do {
        printf("\n1. Cadastrar Usuário\n");
        printf("2. Login\n");
        printf("3. Cadastrar Item\n");
        printf("4. Listar Itens\n");
        printf("5. Editar Item\n");
        printf("6. Excluir Item\n");
        printf("7. Buscar Item\n");
        printf("8. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrar_usuario(usuarios, &num_usuarios);
                salvar_usuarios(usuarios, num_usuarios);
                break;
            case 2:
                login(usuarios, num_usuarios);
                break;
            case 3:
                cadastrar_item(produtos, &num_produtos);
                salvar_itens(produtos, num_produtos);
                break;
            case 4:
                listar_itens(produtos, num_produtos);
                break;
            case 5:
                editar_item(produtos, num_produtos);
                salvar_itens(produtos, num_produtos);
                break;
            case 6:
                excluir_item(produtos, &num_produtos);
                salvar_itens(produtos, num_produtos);
                break;
            case 7:
                buscar_item(produtos, num_produtos);
                break;
            case 8:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }
    } while (opcao != 8);

    return 0;
}