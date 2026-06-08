#include "lsm6dso.h"
#include "main.h"

extern I2C_HandleTypeDef hi2c1; // Mapeado no CubeMX (PB6, PB7)

#define LSM6DSO_I2C_ADDR (0x6A << 1)

void LSM6DSO_Init(void) {
    uint8_t who_am_i = 0;
    // Tenta ler o register WHO_AM_I (0x0F)
    HAL_I2C_Mem_Read(&hi2c1, LSM6DSO_I2C_ADDR, 0x0F, I2C_MEMADD_SIZE_8BIT, &who_am_i, 1, 100);
    
    // Adicionar logica real de setup aqui...
}

void LSM6DSO_Read(void) {
    uint8_t data[6];
    // Exemplo: leitura dos eixos (registrador 0x28 em diante)
    HAL_I2C_Mem_Read(&hi2c1, LSM6DSO_I2C_ADDR, 0x28, I2C_MEMADD_SIZE_8BIT, data, 6, 100);
}
