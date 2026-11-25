# Week 1 - Register Mapping via C Structs

## Objective

The goal of Week 1 is to move away from using raw memory addresses throughout the code and begin representing STM32 peripherals as C structures that mirror the hardware layout described in the STM32F407 Reference Manual.

By mapping hardware registers into structures, the code becomes easier to read, maintain, and scale as additional peripherals are introduced.

---

## Documentation Used

- RM0090 Reference Manual
  - Chapter 2: Memory Map
  - Chapter 7: General-Purpose I/O (GPIO)

---

## Concepts Covered

### Memory-Mapped I/O

STM32 peripherals are controlled through memory-mapped registers.

Example:

```c
0x40020C00
```

is the base address of the GPIOD peripheral.

Instead of directly using addresses throughout the code, a structured approach is used.

---

### Register Mapping with Structures

A GPIO register map was represented using a C structure:

```c
typedef struct
{
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;

} GPIO_Reg_TypeDef;
```

The `volatile` keyword ensures the compiler always accesses the physical hardware register and does not optimize register reads or writes.

---

## Exercise 1.1 – GPIO Structure Definition

Created a custom peripheral structure to represent the GPIO register block.

### Registers Added

| Register | Purpose |
|-----------|----------|
| MODER | Pin mode selection |
| OTYPER | Output type selection |
| OSPEEDR | Output speed configuration |
| PUPDR | Pull-up/Pull-down configuration |
| IDR | Input Data Register |
| ODR | Output Data Register |

---

## Exercise 1.2 – Peripheral Base Address Mapping

Created base address macros and peripheral pointers.

### GPIOD

```c
#define GPIOD_BASE (0x40020C00UL)

#define GPIOD ((GPIO_Reg_TypeDef*)GPIOD_BASE)
```

### RCC

*``c
#define RCC_BASE *0x40023800UL)

#define RCC ((RCC_R*g_TypeDef*)RCC_BASE)
```

This allows peripheral access using readable syntax:

```c
GPIOD->MODER
RCC->AHB1ENR
```

instead of:

```c
*(volatile uint32_t*)0x40023830
```

---

## Exercise 1.3 – Multi-LED Control

Configured the four onboard LEDs connected to GPIOD:

| LED | Pin |
|-------|------|
| Green | PD12 |
| Orange | PD13 |
| Red | PD14 |
| Blue | PD15 |

### Steps

1. Enabled the GPIOD peripheral clock through RCC.
2. Configured Pins 12–15 as outputs.
3. Turned all LEDs on simultaneously using a single write to ODR.

### Clock Enable

```c
RCC->AHB1ENR |= (1U << 3);
```

### Pin Configuration

```c
GPIOD->MODER |= (1U << (12 * 2));
GPIOD->MODER |= (1U << (13 * 2));
GPIOD->MODER |= (1U << (14 * 2));
GPIOD->MODER |= (1U << (15 * 2));
```

### LED Activation

```c
GPIOD->ODR = (1U << 12) |
             (1U << 13) |
             (1U << 14) |
             (1U << 15);
```

---

## Project Structure

```text
Week01_Register_Mapping/
│
├── main.c
├── stm32f407xx.h
├── gpio.h
├── gpio.c
└── README.md
```

---

## Key Takeaways

- STM32 peripherals are memory-mapped hardware devices.
- C structures can directly mirror peripheral register layouts.
- The `volatile` keyword is essential when accessing hardware registers.
- Peripheral base addresses can be converted into typed pointers.
- Register mapping significantly improves readability compared to raw address manipulation.
- Multiple GPIO pins can be controlled simultaneously through a single register write.

---

## Result

Successfully mapped GPIO and RCC peripherals into C structures and controlled all four STM32F4 Discovery board LEDs using structure-based register access instead of raw hexadecimal memory addresses.

### Verification

Expected board state:

```text
PD12 -> ON
PD13 -> ON
PD14 -> ON
PD15 -> ON
```

All four onboard LEDs illuminate simultaneously after program execution.