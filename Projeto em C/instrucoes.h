#ifndef INSTRUCOES_H
#define INSTRUCOES_H

#include <stdint.h>
#include <string.h>
#include "dicionario.h"

// Função de busca interna
Instrucao* IIdentificaInstrucao(const char *nome);

// Retorna o caractere do tipo da instrução ('R', 'I', 'S' ou 'B') ou '\0' se não encontrar
char IdentificaInstrucao(const char *nome);

// Formato R
uint32_t montar_tipo_R(int opcode, int rd, int funct3, int rs1, int rs2, int funct7);

// Formato I
uint32_t montar_tipo_I(int opcode, int rd, int funct3, int rs1, int imediato);

// Formato S
uint32_t montar_tipo_S(int opcode, int funct3, int rs1, int rs2, int imediato);

// Formato B
uint32_t montar_tipo_B(int opcode, int funct3, int rs1, int rs2, int imediato);

#endif // INSTRUCOES_H