#include "my_stm32446xx.h"

static void delay(volatile uint32_t x)
{
    while(x--)
    {
        __asm("nop");
    }
}

int main(void)
{
    RCC_AHB1ENR |= (1U << 0); //Enable bit 0 to 1 for enable clock
    
    
    //First clear the two bits for Port A, Pin 5.
    //Then OR for the Green LED
    GPIOA_MODER &= ~(0x3U << (5 * 2)); 
    GPIOA_MODER |=  (0x1U << (5 * 2)); 

    // optional: no pull-up/down 
    GPIOA_PUPDR &= ~(0x3U << (5 * 2));

    while(1)
    {
        // LED on: write to BSRR lower 16 bits
        GPIOA_BSRR |= (1U << 5);
        delay(500000);

        // LED off: write to BSRR upper 16 bits (pin+16)
        GPIOA_BSRR = (1U << (5 + 16));
        delay(500000);
    }
}