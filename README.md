# STM32F407 Bare-Metal Embedded Systems Journey

A structured 12-week embedded systems learning roadmap built on the STM32F407 Discovery Board using register-level programming, peripheral driver development, automotive communication protocols, and real-time operating systems.

The goal of this project is to develop a strong foundation in embedded software engineering while building a portfolio that demonstrates practical firmware development skills relevant to automotive, industrial control, and embedded systems roles.

---

# Hardware Platform

| Item | Description |
|--------|------------|
| MCU | STM32F407VGT6 |
| Core | ARM Cortex-M4 |
| Board | STM32F4 Discovery |
| Language | Embedded C |
| IDE | STM32CubeIDE |
| Debugger | ST-Link |
| UART | USART2 |
| SPI | SPI1 |
| CAN | CAN1 (bxCAN) |
| RTOS | FreeRTOS |

---

# Project Roadmap

## Phase 1 - Foundation & Low-Level Abstraction

### Week 1 - Register Mapping via C Structs

**Objective**

Replace raw memory addresses with structured peripheral register mappings.

**Topics**

- Memory-Mapped I/O
- Peripheral Base Addresses
- GPIO Register Layout
- RCC Register Layout
- C Structures
- Volatile Keyword

**Deliverables**

- GPIO register structure
- RCC register structure
- Multi-LED control application

---

### Week 2 - Advanced Bit Manipulation & Code Portability

**Objective**

Safely modify individual hardware register bits using reusable macros.

**Topics**

- Bitwise Operations
- Register Masking
- Code Reusability
- GPIO Driver Foundations

**Deliverables**

- SET_BIT()
- CLEAR_BIT()
- TOGGLE_BIT()
- READ_BIT()
- Button-controlled LED toggle

---

### Week 3 - Clock Architecture & System Performance

**Objective**

Configure the STM32F407 clock system to operate at 168 MHz.

**Topics**

- HSE Oscillator
- PLL Configuration
- Flash Latency
- Clock Trees
- RCC Configuration

**Deliverables**

- HSE initialization
- PLL setup
- 168 MHz system clock

---

# Phase 2 - Time, Interrupts & Determinism

### Week 4 - Hardware Timers & Periodic Events

**Objective**

Implement accurate timing using dedicated hardware timers.

**Topics**

- TIM2 Peripheral
- Prescalers
- Auto Reload Registers
- Update Events

**Deliverables**

- Millisecond timer
- delay_ms() function
- Hardware-timed LED blinking

---

### Week 5 - Nested Vectored Interrupt Controller (NVIC)

**Objective**

Handle external events using interrupts instead of polling.

**Topics**

- NVIC
- EXTI
- ISR Design
- Event Handling

**Deliverables**

- EXTI0 Button Interrupt
- NVIC Configuration
- Software Trigger Verification

---

### Week 6 - Pulse Width Modulation (PWM)

**Objective**

Generate PWM signals using hardware timers.

**Topics**

- Alternate Function Routing
- TIM4
- PWM Mode 1
- Duty Cycle Control

**Deliverables**

- 1 kHz PWM
- LED Brightness Control
- Breathing LED Effect

---

# Phase 3 - Communication & Automotive Networking

### Week 7 - UART Communication

**Objective**

Establish serial communication with a workstation.

**Topics**

- USART2
- Baud Rate Generation
- TX/RX Drivers
- printf Redirection

**Deliverables**

- UART Driver
- Terminal Communication
- Console Logging

---

### Week 8 - SPI Communication

**Objective**

Communicate with the onboard accelerometer using SPI.

**Topics**

- SPI Master Mode
- CPOL
- CPHA
- Chip Select Control
- Full Duplex Communication

**Deliverables**

- SPI Driver
- Register Read Function
- WHO_AM_I Verification

---

### Week 9 - CAN Bus Fundamentals

**Objective**

Implement automotive-grade network communication.

**Topics**

- bxCAN
- Mailboxes
- Arbitration
- Message Identifiers
- Loopback Testing

**Deliverables**

- 500 kbps CAN Configuration
- CAN Transmission Function
- CAN Loopback Verification

---

# Phase 4 - Production Standards & Portfolio Assembly

### Week 10 - Memory Management & Defensive Programming

**Objective**

Implement safe memory-management practices.

**Topics**

- Circular Buffers
- Static Allocation
- MISRA Concepts
- Interrupt-Driven Systems

**Deliverables**

- UART Circular Buffer
- Interrupt-Based Reception
- Code Review and Cleanup

---

### Week 11 - Real-Time Operating Systems (RTOS)

**Objective**

Introduce task scheduling and concurrency.

**Topics**

- FreeRTOS
- Tasks
- Queues
- Mutexes
- Scheduler Operation

**Deliverables**

- Sensor Task
- Telemetry Task
- Protected SPI Access

---

### Week 12 - Documentation & Portfolio Launch

**Objective**

Publish a professional GitHub repository demonstrating embedded development skills.

**Topics**

- Technical Documentation
- System Architecture
- Project Verification
- GitHub Portfolio Building

**Deliverables**

- Complete Documentation
- Verification Screenshots
- Portfolio Repository

---

# Repository Structure

```text
STM32F407-BareMetal/
│
├── README.md
│
├── Week01_Register_Mapping/
├── Week02_Bit_Manipulation/
├── Week03_Clock_System/
├── Week04_Hardware_Timers/
├── Week05_NVIC_Interrupts/
├── Week06_PWM/
├── Week07_UART/
├── Week08_SPI/
├── Week09_CAN/
├── Week10_Defensive_Programming/
├── Week11_FreeRTOS/
├── Week12_Portfolio/
│
└── Docs/
    ├── Images/
    └── Notes/
```

---

# Example Peripheral Mapping

typedef struct
{
    volatile uint32_t MODER;
    volatile uint32_t OTYPER;
    volatile uint32_t OSPEEDR;
    volatile uint32_t PUPDR;
    volatile uint32_t IDR;
    volatile uint32_t ODR;

} GPIO_Reg_TypeDef;

#define GPIOD_BASE (0x40020C00UL)

#define GPIOD ((GPIO_Reg_TypeDef*)GPIOD_BASE)
```

---

# Clock Configuration

| Domain | Frequency |
*----------|----------|
| HSE | 8 MHz |
| SYSCLK | 168 MHz |
| AHB | 18 MHz |
| APB1 | 42 MHz |
| APB2 | 84 MHz |
| TIM2 Clock | 84 MHz |
| SPI1 Clock Source | APB2 |
| USART Clock Source | APB1 |
| CAN1 Clock Source | APB1 |

---

# Skills Demonstrated

- Embedded C
- Register*Level Programming
- ARM Cortex-M4 Architecture
- GPIO Driver Development
- RCC Configuration
- Hardware Timers
- Interrupt Systems
- PWM Generation
- UART Communication
- SPI Communication
- CAN Networking
- FreeRTOS
- Circular Buffers
- MISRA-Oriented Design
- Embedded Debugging
- Git Version Control

---

# Future Improvements

- ADC Driver Development
- DMA Transfers
- I2C Communication
- CAN-FD
- Bootloaders
- ECU Simulation- AUTOSAR Concepts
- Embedded Linux

---

# Author

Arun Babu

Controls Service Technician transitioning into Embedded Software and Automotive Firmware Development.

STMM32F407 | Embedded C | ARM Cortex-M | UART | SPI | CAN | FreeRTOS
```*