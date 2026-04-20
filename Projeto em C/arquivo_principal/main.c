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

    // Lógica do arquivo de saída
    FILE *arquivo_saida = NULL;
    
    // Se o usuário passou 4 argumentos
    if (num_args == 4 && strcmp(args[2], "-o") == 0) {
        arquivo_saida = fopen(args[3], "w");
        if (arquivo_saida == NULL) {
            printf("Erro ao criar o arquivo de saida: %s\n", args[3]);
            fclose(arquivo); // Fecha o de entrada antes de sair
            return 1;
        }
    }

    char linha[256];
    // Lê o arquivo linha por linha
    while (fgets(linha, sizeof(linha), arquivo)) {
        // Ignora linhas vazias ou que só tem quebra de linha
        if (linha[0] == '\n' || linha[0] == '\r') {
            continue;
        }
        // Corta a linha se achar um comentário 
        char *comentario = strchr(linha, '#');
        if (comentario != NULL) {
            *comentario = '\0'; // Substitui o # pelo fim da string
        }
        // Separa a string usando strtok
        char *nome_instrucao = strtok(linha, " ,\n\r()");

        // Se a linha tava em branco (só espaços), ignora
        if (nome_instrucao == NULL) {
            continue;
        }

        // Pega os próximos argumentos da mesma linha
        char *arg1 = strtok(NULL, " ,\n\r()");
        char *arg2 = strtok(NULL, " ,\n\r()");
        char *arg3 = strtok(NULL, " ,\n\r()");
    
        // Busca a instrução no dicionário
        Instrucao *inst = IIdentificaInstrucao(nome_instrucao);
        
        // Se não achou a instrução no dicionário, pula pra próxima linha
        if (inst == NULL) {
            continue;
        }

        // Variável que vai guardar a instrução final montada
        uint32_t binario_final = 0;

        // Verifica o tipo da instrução e chama a função de montagem
        if (inst->tipo == 'R') {
            int rd = extrair_numero(arg1);
            int rs1 = extrair_numero(arg2);
            int rs2 = extrair_numero(arg3);
            binario_final = montar_tipo_R(inst->opcode, rd, inst->funct3, rs1, rs2, inst->funct7);
        } 
        else if (inst->tipo == 'I') {
            int rd = extrair_numero(arg1);
            
            // O lw tem os argumentos em uma ordem diferente
            if (strcmp(inst->nome, "lw") == 0) {
                int imm = extrair_numero(arg2);
                int rs1 = extrair_numero(arg3);
                binario_final = montar_tipo_I(inst->opcode, rd, inst->funct3, rs1, imm);
            } else {
                int rs1 = extrair_numero(arg2);
                int imm = extrair_numero(arg3);
                binario_final = montar_tipo_I(inst->opcode, rd, inst->funct3, rs1, imm);
            }
        } 
        else if (inst->tipo == 'S') {
            int rs2 = extrair_numero(arg1);
            int imm = extrair_numero(arg2);
            int rs1 = extrair_numero(arg3);
            binario_final = montar_tipo_S(inst->opcode, inst->funct3, rs1, rs2, imm);
        } 
        else if (inst->tipo == 'B') {
            int rs1 = extrair_numero(arg1);
            int rs2 = extrair_numero(arg2);
            int imm = extrair_numero(arg3);
            binario_final = montar_tipo_B(inst->opcode, inst->funct3, rs1, rs2, imm);
        }

        // Imprime no arquivo ou no terminal 
        for (int i = 31; i >= 0; i--) {
            uint32_t bit = (binario_final >> i) & 1;
            if (arquivo_saida != NULL) {
                fprintf(arquivo_saida, "%u", bit); 
            } else {
                printf("%u", bit); 
            }
        }
        
        // Quebra de linha no final de cada instrução
        if (arquivo_saida != NULL) {
            fprintf(arquivo_saida, "\n"); 
        } else {
            printf("\n"); 
        }
    }

    fclose(arquivo);
    
    // Se abriu um arquivo de saída, fecha ele
    if (arquivo_saida != NULL) {
        fclose(arquivo_saida);
    }
    
    return 0; 
}