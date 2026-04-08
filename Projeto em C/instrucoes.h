#ifndef INSTRUCOES_H
#define INSTRUCOES_H

#include <stdint.h>
#include "dicionario.h"

// Formato R: [funct7][rs2][rs1][funct3][rd][opcode]
uint32_t montar_tipo_R(int opcode, int rd, int funct3, int rs1, int rs2, int funct7);

// Formato I: [imm][rs1][funct3][rd][opcode]
uint32_t montar_tipo_I(int opcode, int rd, int funct3, int rs1, int imediato);

// Formato S: [imm[11:5]][rs2][rs1][funct3][imm[4:0]][opcode]
uint32_t montar_tipo_S(int opcode, int funct3, int rs1, int rs2, int imediato);

// Formato B: Lógica especial para saltos (bne)
uint32_t montar_tipo_B(int opcode, int funct3, int rs1, int rs2, int imediato);

#endif // INSTRUCOES_H