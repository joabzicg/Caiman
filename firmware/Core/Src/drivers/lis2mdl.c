#include "lis2mdl.h"
#include "main.h"

extern I2C_HandleTypeDef hi2c1; // Verifique se ele está no I2C1 ou I2C2!

// O endereço I2C do LIS2MDL é 0x1E (7 bits). Para a HAL STM32, deslocamos 1 bit para a esquerda: 0x3C
#define LIS2MDL_I2C_ADDR (0x1E << 1)
#define LIS2MDL_WHO_AM_I 0x4F

void LIS2MDL_Init(void) {
    uint8_t who_am_i = 0;
    
    // Tenta ler o registrador WHO_AM_I (0x4F). O valor esperado é 0x40.
    if (HAL_I2C_Mem_Read(&hi2c1, LIS2MDL_I2C_ADDR, LIS2MDL_WHO_AM_I, I2C_MEMADD_SIZE_8BIT, &who_am_i, 1, 100) == HAL_OK) {
        if (who_am_i == 0x40) {
            // Sensor encontrado!
            // Aqui futuramente enviaremos os comandos para CFG_REG_A, CFG_REG_B, etc, para ligá-lo.
        }
    }
}

void LIS2MDL_Read(void) {
    uint8_t raw_data[6];
    // O registrador de saída X começa no 0x68 (OUTX_L_REG) 
    // Futura implementação da leitura X, Y e Z
    // HAL_I2C_Mem_Read(&hi2c1, LIS2MDL_I2C_ADDR, 0x68, I2C_MEMADD_SIZE_8BIT, raw_data, 6, 100);
}
