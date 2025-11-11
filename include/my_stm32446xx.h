#ifndef MY_STM32F446XX_H
#define MY_STM32F446XX_H

#include <stdint.h> 

// 1) Base addresses (from RM0390 memory map) 
#define PERIPH_BASE        0x40000000U
#define AHB1PERIPH_BASE    0x40020000U

// GPIO base addresses (RM0390, GPIO section) 
#define GPIOA_BASE         (AHB1PERIPH_BASE + 0x0000U)  // 0x40020000
#define GPIOB_BASE         (AHB1PERIPH_BASE + 0x0400U)
#define GPIOC_BASE         (AHB1PERIPH_BASE + 0x0800U)
#define GPIOD_BASE         (AHB1PERIPH_BASE + 0x0C00U)
#define GPIOE_BASE         (AHB1PERIPH_BASE + 0x1000U)
#define GPIOF_BASE         (AHB1PERIPH_BASE + 0x1400U)
#define GPIOG_BASE         (AHB1PERIPH_BASE + 0x1800U)
#define GPIOH_BASE         (AHB1PERIPH_BASE + 0x1C00U)

// RCC base address (RM0390, RCC chapter)
#define RCC_BASE           (AHB1PERIPH_BASE + 0x3800U)

// 2) Register offsets (from the RCC and GPIO register maps) 

// RCC registers 
#define RCC_AHB1ENR        (*(volatile uint32_t *)(RCC_BASE + 0x30U))

//GPIO Pins
#define GPIOA_MODER        (*(volatile uint32_t *)(GPIOA_BASE + 0x00U))
#define GPIOA_OTYPER       (*(volatile uint32_t *)(GPIOA_BASE + 0x04U))
#define GPIOA_OSPEEDR      (*(volatile uint32_t *)(GPIOA_BASE + 0x08U))
#define GPIOA_PUPDR        (*(volatile uint32_t *)(GPIOA_BASE + 0x0CU))
#define GPIOA_IDR          (*(volatile uint32_t *)(GPIOA_BASE + 0x10U))
#define GPIOA_ODR          (*(volatile uint32_t *)(GPIOA_BASE + 0x14U))
#define GPIOA_BSRR         (*(volatile uint32_t *)(GPIOA_BASE + 0x18U)) 

#endif