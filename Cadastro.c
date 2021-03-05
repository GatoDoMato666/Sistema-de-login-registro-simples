#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
	char nome[16];
	char senha[9];
}User;

void login(){
	User *usuario = (User*)malloc(sizeof(User));

	char lnome[16];
	char lsenha[9];

	FILE *arq = fopen("User/sys.txt", "r");
	if(arq == NULL){
		printf("Erro ao encontrar usuarios cadastrados!\n\n");
		exit(0);
	}

	fscanf(arq, "%s %s", usuario->nome, usuario->senha);
	fclose(arq);

	printf("Digite o nome de usuario: ");
	scanf("%s", lnome);

	printf("Digite a senha: ");
	scanf("%s", lsenha);

	if(strcmp(lnome, usuario->nome) == 0 && strcmp(lsenha, usuario->senha) == 0){
		printf("Login efetuado com sucesso!\n");
	}else{
		printf("Usuario e/ou senha errado!\n");
	}

}

void cadastro(){
	User usuario;

	FILE *arq = fopen("User/sys.txt", "w");

	printf("Digite o nome de usuario (max. 15 caracteres): ");
	scanf("%s", usuario.nome);
	if(strlen(usuario.nome) > 15){
		printf("Nome de usuario muito grande!\n");
		exit(0);
	}

	printf("Digite a senha (max. 8 caracteres): ");
	scanf("%s", usuario.senha);
	if(strlen(usuario.senha) > 8){
		printf("Senha muito grande!\n");
		exit(0);
	}

	fprintf(arq, "%s ", usuario.nome);
	fprintf(arq, "%s", usuario.senha);

	printf("Cadastro concluido!\n\n");
	fclose(arq);
}


int main(){

	int esc;

	while(1){
	printf("SISTEMA DE LOGIN/CADASTRO\n");

	printf("1 - Login\n");
	printf("2 - Cadastro\n");
	scanf("%d", &esc);

	switch(esc){
		case 1:
		login();
		break;

		case 2:
		cadastro();
		break;

		default:
		printf("Escolha invalida!");
		break;
	}
}

	return 0;
}