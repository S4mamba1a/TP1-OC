#include "instrucoes.h"

Instrucao* IIdentificaInstrucao(const char *nome) {
    for (int i = 0; i < TAM_DICIONARIO; i++) {
        if (strcmp(nome, dicionario[i].nome) == 0) {
            return &dicionario[i]; // Retorna o endereço da instrução encontrada
        }
    }
    return NULL; // Instrução não pertence ao grupo ou não existe
}

void IdentificaInstrucao(const char *nome) {
    Instrucao *inst = IIdentificaInstrucao(nome);
    if (inst == NULL) {
        fprintf(stderr, "Erro: Instrução '%s' não reconhecida.\n", nome);
    } else {
        switch (inst->tipo) {
        case 'R':
            // processar_tipo_R(inst->opcode, inst->funct3, inst->funct7, ...);
            break;
        case 'I':
            // processar_tipo_I(inst->opcode, inst->funct3, ...);
            break;
        case 'S':
            // processar_tipo_S(inst->opcode, inst->funct3, ...);
            break;
        case 'B':
            // processar_tipo_B(inst->opcode, inst->funct3, ...);
            break;
        }
    }
}


uint32_t montar_tipo_R(int opcode, int rd, int funct3, int rs1, int rs2, int funct7) {
    uint32_t instrucao = 0;

    // Encaixando cada campo em sua posição específica (padrão RISC-V)
    instrucao |= (opcode & 0x7F);          // Bits 0 a 6
    instrucao |= ((rd & 0x1F) << 7);       // Bits 7 a 11
    instrucao |= ((funct3 & 0x07) << 12);  // Bits 12 a 14
    instrucao |= ((rs1 & 0x1F) << 15);     // Bits 15 a 19
    instrucao |= ((rs2 & 0x1F) << 20);     // Bits 20 a 24
    instrucao |= ((funct7 & 0x7F) << 25);  // Bits 25 a 31

    return instrucao;
}