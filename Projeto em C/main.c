#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "instrucoes.h"

int main(int num_args, char *args[]) {
    // Verifica se o usuário passou pelo menos o arquivo de entrada
    if (num_args < 2) {
        printf("Erro: Voce esqueceu de digitar o nome do arquivo .asm no terminal!\n");
        return 1;
    }
    // Abre o arquivo passado como primeiro argumento em modo de leitura
    FILE *arquivo = fopen(args[1], "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo: %s\n", args[1]);
        return 1;
    }
    char linha[256];
    // Lê o arquivo linha por linha
    while (fgets(linha, sizeof(linha), arquivo)) {
        // Ignora linhas vazias ou que só tem quebra de linha
        if (linha[0] == '\n' || linha[0] == '\r') {
            continue;
        }
        // Separa a string usando strtok
        char *nome_instrucao = strtok(linha, " ,\n\r");
        // Se a linha tava em branco (só espaços), ignora
        if (nome_instrucao == NULL) {
            continue;
        }
        // Pega os próximos argumentos da mesma linha
        char *arg1 = strtok(NULL, " ,\n\r");
        char *arg2 = strtok(NULL, " ,\n\r");
        char *arg3 = strtok(NULL, " ,\n\r");
    }
    fclose(arquivo);
    return 0; 
}