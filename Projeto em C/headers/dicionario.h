#ifndef DICIONARIO_H
#define DICIONARIO_H

// Definições de opcodes para as instruções
#define OP_R    0x33  // 0110011
#define OP_I    0x13  // 0010011 (addi)
#define OP_LW   0x03  // 0000011
#define OP_SW   0x23  // 0100011
#define OP_B    0x63  // 1100011 (bne)

// Definições de funct3 para as instruções
#define F3_ADD  0x0
#define F3_XOR  0x4
#define F3_SLL  0x1
#define F3_ADDI 0x0
#define F3_LW   0x2
#define F3_SW   0x2
#define F3_BNE  0x1

// Definição de funct7 para as instruções R-type
#define F7_STD  0x00

// Estrutura para armazenar as informações de cada instrução
typedef struct {
    char *nome;
    char tipo; // 'R', 'I', 'S', 'B'
    int opcode;
    int funct3;
    int funct7;
} Instrucao;

// Declaração do dicionário de instruções
extern Instrucao dicionario[];
extern const int TAM_DICIONARIO;

#endif // DICIONARIO_H
