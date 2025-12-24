#ifndef MY_STM32F446XX_H
#define MY_STM32F446XX_H

#include <stdint.h> 

//*****************************
//***********GPIO**************
//*****************************

// 1) Base addresses (from RM0390 memory map) 
#define PERIPH_BASE        0x40000000U
#define AHB1PERIPH_BASE    0x40020000U
#define APB2PERIPH_BASE    0x40010000U

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
#define RCC_APB1ENR        (*(volatile uint32_t *)(RCC_BASE + 0x40U))
#define RCC_APB2ENR        (*(volatile uint32_t *)(RCC_BASE + 0x44U))      

//GPIO Pins A
#define GPIOA_MODER        (*(volatile uint32_t *)(GPIOA_BASE + 0x00U))
#define GPIOA_OTYPER       (*(volatile uint32_t *)(GPIOA_BASE + 0x04U))
#define GPIOA_OSPEEDR      (*(volatile uint32_t *)(GPIOA_BASE + 0x08U))
#define GPIOA_PUPDR        (*(volatile uint32_t *)(GPIOA_BASE + 0x0CU))
#define GPIOA_IDR          (*(volatile uint32_t *)(GPIOA_BASE + 0x10U))
#define GPIOA_ODR          (*(volatile uint32_t *)(GPIOA_BASE + 0x14U))
#define GPIOA_BSRR         (*(volatile uint32_t *)(GPIOA_BASE + 0x18U))
#define GPIOA_LCKR         (*(volatile uint32_t *)(GPIOA_BASE + 0x1CU))
#define GPIOA_AFRL         (*(volatile uint32_t *)(GPIOA_BASE + 0x20U))
#define GPIOA_AFRH         (*(volatile uint32_t *)(GPIOA_BASE + 0x24U))

//GPIO Pins B
#define GPIOB_MODER        (*(volatile uint32_t *)(GPIOB_BASE + 0x00U))
#define GPIOB_OTYPER       (*(volatile uint32_t *)(GPIOB_BASE + 0x04U))
#define GPIOB_OSPEEDR      (*(volatile uint32_t *)(GPIOB_BASE + 0x08U))
#define GPIOB_PUPDR        (*(volatile uint32_t *)(GPIOB_BASE + 0x0CU))
#define GPIOB_IDR          (*(volatile uint32_t *)(GPIOB_BASE + 0x10U))
#define GPIOB_ODR          (*(volatile uint32_t *)(GPIOB_BASE + 0x14U))
#define GPIOB_BSRR         (*(volatile uint32_t *)(GPIOB_BASE + 0x18U)) 
#define GPIOB_LCKR         (*(volatile uint32_t *)(GPIOA_BASE + 0x1CU))
#define GPIOB_AFRL         (*(volatile uint32_t *)(GPIOA_BASE + 0x20U))
#define GPIOB_AFRH         (*(volatile uint32_t *)(GPIOA_BASE + 0x24U))

//GPIO Pins C
#define GPIOC_MODER        (*(volatile uint32_t *)(GPIOC_BASE + 0x00U))
#define GPIOC_OTYPER       (*(volatile uint32_t *)(GPIOC_BASE + 0x04U))
#define GPIOC_OSPEEDR      (*(volatile uint32_t *)(GPIOC_BASE + 0x08U))
#define GPIOC_PUPDR        (*(volatile uint32_t *)(GPIOC_BASE + 0x0CU))
#define GPIOC_IDR          (*(volatile uint32_t *)(GPIOC_BASE + 0x10U))
#define GPIOC_ODR          (*(volatile uint32_t *)(GPIOC_BASE + 0x14U))
#define GPIOC_BSRR         (*(volatile uint32_t *)(GPIOC_BASE + 0x18U)) 
#define GPIOC_LCKR         (*(volatile uint32_t *)(GPIOA_BASE + 0x1CU))
#define GPIOC_AFRL         (*(volatile uint32_t *)(GPIOA_BASE + 0x20U))
#define GPIOC_AFRH         (*(volatile uint32_t *)(GPIOA_BASE + 0x24U))


//*****************************
//***********UART**************
//*****************************

// Base adresses for UART
#define USART1_BASE      (APB2PERIPH_BASE + 0x1000U)
#define USART6_BASE      (APB2PERIPH_BASE + 0x4000U)
#define USART2_BASE      (PERIPH_BASE + 0x4400U)
#define USART3_BASE      (PERIPH_BASE + 0x4800U)
#define UART4_BASE       (PERIPH_BASE + 0x4C00U)
#define UART5_BASE       (PERIPH_BASE + 0x5000U)

// 2) Register offsets

//USART1
#define USART1_SR         (*(volatile uint32_t *)(USART1_BASE + 0x00U))
#define USART1_DR         (*(volatile uint32_t *)(USART1_BASE + 0x04U))
#define USART1_BRR        (*(volatile uint32_t *)(USART1_BASE + 0x08U))
#define USART1_CR1        (*(volatile uint32_t *)(USART1_BASE + 0x0CU))
#define USART1_CR2        (*(volatile uint32_t *)(USART1_BASE + 0x10U))
#define USART1_CR3        (*(volatile uint32_t *)(USART1_BASE + 0x14U))
#define USART1_GTPR       (*(volatile uint32_t *)(USART1_BASE + 0x18U))

//USART1
#define USART6_SR         (*(volatile uint32_t *)(USART6_BASE + 0x00U))
#define USART6_DR         (*(volatile uint32_t *)(USART6_BASE + 0x04U))
#define USART6_BRR        (*(volatile uint32_t *)(USART6_BASE + 0x08U))
#define USART6_CR1        (*(volatile uint32_t *)(USART6_BASE + 0x0CU))
#define USART6_CR2        (*(volatile uint32_t *)(USART6_BASE + 0x10U))
#define USART6_CR3        (*(volatile uint32_t *)(USART6_BASE + 0x14U))
#define USART6_GTPR       (*(volatile uint32_t *)(USART6_BASE + 0x18U))

//USART2
#define USART2_SR         (*(volatile uint32_t *)(USART2_BASE + 0x00U))
#define USART2_DR         (*(volatile uint32_t *)(USART2_BASE + 0x04U))
#define USART2_BRR        (*(volatile uint32_t *)(USART2_BASE + 0x08U))
#define USART2_CR1        (*(volatile uint32_t *)(USART2_BASE + 0x0CU))
#define USART2_CR2        (*(volatile uint32_t *)(USART2_BASE + 0x10U))
#define USART2_CR3        (*(volatile uint32_t *)(USART2_BASE + 0x14U))
#define USART2_GTPR       (*(volatile uint32_t *)(USART2_BASE + 0x18U))

//USART3
#define USART3_SR         (*(volatile uint32_t *)(USART3_BASE + 0x00U))
#define USART3_DR         (*(volatile uint32_t *)(USART3_BASE + 0x04U))
#define USART3_BRR        (*(volatile uint32_t *)(USART3_BASE + 0x08U))
#define USART3_CR1        (*(volatile uint32_t *)(USART3_BASE + 0x0CU))
#define USART3_CR2        (*(volatile uint32_t *)(USART3_BASE + 0x10U))
#define USART3_CR3        (*(volatile uint32_t *)(USART3_BASE + 0x14U))
#define USART3_GTPR       (*(volatile uint32_t *)(USART3_BASE + 0x18U))

#endif