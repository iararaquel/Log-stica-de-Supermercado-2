#include <stdio.h>
#include <string.h>
#include "usuarios.h"

void cadastrar_usuario(Usuario usuarios[], int *num_usuarios) {
    if (*num_usuarios < limite_USUARIOS) {
        printf("Nome: ");
        scanf("%s", usuarios[*num_usuarios].nome);
        printf("Senha: ");
        scanf("%s", usuarios[*num_usuarios].senha);
        (*num_usuarios)++;
    } else {
        printf("Limite de usuários atingido.\n");
    }
}

void salvar_usuarios(Usuario usuarios[], int num_usuarios) {
    FILE *file = fopen("data/usuarios.dat", "wb");
    if (file != NULL) {
        fwrite(&num_usuarios, sizeof(int), 1, file);
        fwrite(usuarios, sizeof(Usuario), num_usuarios, file);
        fclose(file);
    } else {
        printf("Erro ao abrir arquivo para salvar usuários.\n");
    }
}

void carregar_usuarios(Usuario usuarios[], int *num_usuarios) {
    FILE *file = fopen("data/usuarios.dat", "rb");
    if (file != NULL) {
        fread(num_usuarios, sizeof(int), 1, file);
        fread(usuarios, sizeof(Usuario), *num_usuarios, file);
        fclose(file);
    } else {
        *num_usuarios = 0;
    }
}

void login(Usuario usuarios[], int num_usuarios) {
    char nome[50], senha[50];
    printf("Nome: ");
    scanf("%s", nome);
    printf("Senha: ");
    scanf("%s", senha);
    
    for (int i = 0; i < num_usuarios; i++) {
        if (strcmp(usuarios[i].nome, nome) == 0 && strcmp(usuarios[i].senha, senha) == 0) {
            printf("Login bem-sucedido!\n");
            return;
        }
    }
    printf("Nome ou senha inválidos.\n");
}