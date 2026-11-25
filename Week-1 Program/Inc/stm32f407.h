#ifndef STM32F407_H_
#define STM32F407_H_

#include <stdint.h>



/******************************************************************************/
/*                          1. Peripheral Registers                           */
/******************************************************************************/

/* Reset and Clock Control (RCC) Register Structure */
typedef struct {
    volatile uint32_t CR;          /* RCC clock control register,                Address offset: 0x00 */
    volatile uint32_t PLLCFGR;     /* RCC PLL configuration register,            Address offset: 0x04 */
    volatile uint32_t CFGR;        /* RCC clock configuration register,          Address offset: 0x08 */
    volatile uint32_t CIR;         /* RCC clock interrupt register,              Address offset: 0x0C */
    volatile uint32_t AHB1RSTR;    /* RCC AHB1 peripheral reset register,        Address offset: 0x10 */
    volatile uint32_t AHB2RSTR;    /* RCC AHB2 peripheral reset register,        Address offset: 0x14 */
    volatile uint32_t AHB3RSTR;    /* RCC AHB3 peripheral reset register,        Address offset: 0x18 */
    uint32_t          RESERVED0;   /* Reserved memory block,                     Address offset: 0x1C */
    volatile uint32_t APB1RSTR;    /* RCC APB1 peripheral reset register,        Address offset: 0x20 */
    volatile uint32_t APB2RSTR;    /* RCC APB2 peripheral reset register,        Address offset: 0x24 */
    uint32_t          RESERVED1[2];/* Reserved memory blocks,                    Address offset: 0x28-0x2C */
    volatile uint32_t AHB1ENR;     /* RCC AHB1 peripheral clock enable register, Address offset: 0x30 */
    /* Note: We stopped at 0x30 for now because this is all we need to blink the LED */
} RCC_TypeDef;

/* General Purpose I/O (GPIO) Register Structure */
typedef struct {
    volatile uint32_t MODER;   /* GPIO port mode register,               Address offset: 0x00 */
    volatile uint32_t OTYPER;  /* GPIO port output type register,        Address offset: 0x04 */
    volatile uint32_t OSPEEDR; /* GPIO port output speed register,       Address offset: 0x08 */
    volatile uint32_t PUPDR;   /* GPIO port pull-up/pull-down register,  Address offset: 0x0C */
    volatile uint32_t IDR;     /* GPIO port input data register,         Address offset: 0x10 */
    volatile uint32_t ODR;     /* GPIO port output data register,        Address offset: 0x14 */
    volatile uint32_t BSRR;    /* GPIO port bit set/reset register,      Address offset: 0x18 */
    volatile uint32_t LCKR;    /* GPIO port configuration lock register, Address offset: 0x1C */
    volatile uint32_t AFR[2];  /* GPIO alternate function registers,     Address offset: 0x20-0x24 */
} GPIO_TypeDef;


/******************************************************************************/
/*                          2. Peripheral Base Addresses                      */
/******************************************************************************/
#define PERIPH_BASE           (0x40000000UL)                      /* Base address of all peripherals */
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000UL)        /* AHB1 bus base address */

#define RCC_BASE              (AHB1PERIPH_BASE + 0x00003800UL)    /* RCC base address: 0x40023800 */
#define GPIOD_BASE            (AHB1PERIPH_BASE + 0x00000C00UL)    /* GPIOD base address: 0x40020C00 */


/******************************************************************************/
/*                          3. Peripheral Pointers                            */
/******************************************************************************/
#define RCC                   ((RCC_TypeDef *) RCC_BASE)
#define GPIOD                 ((GPIO_TypeDef *) GPIOD_BASE)
#endif /* STM32F407_H_ */
