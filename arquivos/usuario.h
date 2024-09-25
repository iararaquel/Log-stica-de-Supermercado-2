#ifndef USUARIOS_H
#define USUARIOS_H

#define limite_USUARIOS 100

typedef struct {
    char nome[50];
    char senha[50];
} Usuario;

void cadastrar_usuario(Usuario usuarios[], int *num_usuarios);
void salvar_usuarios(Usuario usuarios[], int num_usuarios);
void carregar_usuarios(Usuario usuarios[], int *num_usuarios);
void login(Usuario usuarios[], int num_usuarios);

#endif