#include "rgb_led.h"
#include "main.h"

extern TIM_HandleTypeDef htim3; // Mapeado no PC6 via TIM3_CH1

void RGB_LED_Init(void) {
    // Inicia geracao do PWM
    HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
}

void RGB_LED_SetColor(int r, int g, int b) {
    // No caso do NeoPixel (WS2812), isso chama HAL_TIM_PWM_Start_DMA
    // Se for PWM comum via TIM3:
    __HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, g); // Ajustar canal de acordo
}
