#include "stm32f407.h"

void delay(void) {
    volatile uint32_t i;
    for(i = 0; i < 200000; i++) {
        /* Waste CPU cycles safely using the volatile keyword */
    }
}

int main(void) {
    /* 1. Enable the clock for GPIOD (Set Bit 3 of the AHB1 Enable Register) */
    RCC->AHB1ENR |= (1UL << 3);

    /* 2. Configure GPIOD Pin 12 as an Output */
    /* First, clear bits 24 and 25 to safely wipe any existing configurations */
    GPIOD->MODER &= ~(3UL << 24);
    /* Set bit 24 to high (01 = General purpose output mode) */
    GPIOD->MODER |= (1UL << 24);

    /* 3. The Super-Loop */
    while(1) {
        /* Toggle Pin 12 using the bitwise XOR operator */
        GPIOD->ODR ^= (1UL << 12);

        delay();
    }
}
