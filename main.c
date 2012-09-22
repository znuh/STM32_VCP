/*
 * A skeleton main.c
 * Add your own code!
 */

// Load CMSIS and peripheral library and configuration
#include "stm32f10x.h"

// Peripheral configuration functions
void GPIO_Config();

// A simple busy wait loop
void Delay(volatile unsigned long delay);

int main(void) {
    // Setup STM32 system (clock, PLL and Flash configuration)
    SystemInit();

    // Setup the GPIOs
    GPIO_Config();

    for(;;) {
        GPIO_SetBits(GPIOD, GPIO_Pin_7);
        Delay(0xAFFFF);

        GPIO_ResetBits(GPIOD, GPIO_Pin_7);
        Delay(0xAFFFF);
    }
}


void Delay(volatile unsigned long delay) {
    for(; delay; --delay ) { asm("nop"); }
}

void GPIO_Config() {
    GPIO_InitTypeDef	GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_10MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_Init(GPIOD, &GPIO_InitStructure);
}
