#include "dicionario.h"

// Dicionário preenchido com as instruções suportadas pelo projeto
Instrucao dicionario[] = {
    {"add",  'R', OP_R,  F3_ADD,  F7_STD},
    {"xor",  'R', OP_R,  F3_XOR,  F7_STD},
    {"sll",  'R', OP_R,  F3_SLL,  F7_STD},
    {"addi", 'I', OP_I,  F3_ADDI, 0},
    {"lw",   'I', OP_LW, F3_LW,   0},
    {"sw",   'S', OP_SW, F3_SW,   0},
    {"bne",  'B', OP_B,  F3_BNE,  0}
};

const int TAM_DICIONARIO = 7;