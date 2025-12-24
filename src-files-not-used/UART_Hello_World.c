#include "my_stm32446xx.h"


// Simple software delay loop
static void delay(volatile uint32_t x)
{
    while (x--)  // loop until x reaches 0
    {
        __asm("nop");
    }
}

void gpio_init(void)
{
    // Enable GPIOA and GPIOC clocks
    RCC_AHB1ENR |= (1U << 0) | (1U << 2);

    // PA5 -> output (LED)
    GPIOA_MODER &= ~(0x3U << (5 * 2));
    GPIOA_MODER |=  (0x1U << (5 * 2));

    // PC13 -> input (button)
    GPIOC_MODER &= ~(0x3U << (13 * 2));
    GPIOC_PUPDR &= ~(0x3U << (13 * 2)); // no pull
}

void led_on(void) {
    GPIOA_BSRR = (1U << 5);
}

void led_off(void) {
    GPIOA_BSRR = (1U << (5 + 16));
}

uint8_t button_pressed(void)
{
    return (GPIOC_IDR & (1U << 13)) ? 0 : 1;
}

void uart_init()
{
    // Enable GPIOA and USART2 clocks
    RCC_APB1ENR |= (1U << 17);

    // Alternat Function Mode for PA2 and PA3
    GPIOA_MODER &= ~(0x3U << (2 * 2));
    GPIOA_MODER |=  (0x2U << (2 * 2));
    GPIOA_MODER &= ~(0x3U << (3 * 2));
    GPIOA_MODER |=  (0x2U << (3 * 2));

    /*  - high speed on pins
        - pull-up on RX (PA3)
    */
    GPIOA_OSPEEDR |=  ((3U << (2*2)) | (3U << (3*2))); // very high speed
    GPIOA_PUPDR   &= ~((3U << (2*2)) | (3U << (3*2)));
    GPIOA_PUPDR   |=  (1U << (3*2));                  // PA3 pull-up

    GPIOA_AFRL &= ~(0xFU << (2 * 4));  // clear 4 bits for PA2 AF
    GPIOA_AFRL |=  (0x7U << (2 * 4));  // set AF7

    GPIOA_AFRL &= ~(0xFU << (3 * 4));  // clear 4 bits for PA3 AF
    GPIOA_AFRL |=  (0x7U << (3 * 4));  // set AF7

    USART2_BRR
}

int main(void)
{
    gpio_init();
    uart_init();


}