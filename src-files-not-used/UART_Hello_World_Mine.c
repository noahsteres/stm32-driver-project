#include "my_stm32446xx.h"
#include <stdbool.h>


static void delay(volatile uint32_t x)
{
    // 'volatile' tells the compiler not to optimize away this loop.
    // Without 'volatile', the compiler might realize the loop has no
    // side effects and remove it completely during optimization.
    while (x--)  // loop until x reaches 0
    {
        // 'nop' = "no operation" assembly instruction.
        // It literally does nothing but consumes 1 CPU cycle.
        // This ensures the loop takes a predictable amount of time.
        __asm("nop");
    }
}

void gpio_init(){
    RCC_AHB1ENR |= (1U << 0);

    // LED
    GPIOA_MODER &= ~(0x3U << (5 * 2));
    GPIOA_MODER |= (0x1U << 5 * 2);


    // Button
    GPIOA_MODER &= ~(0x3U << (13 * 2));
    GPIOA_PUPDR &= ~(0x3U << (13 * 2));
    GPIOA_PUPDR |= (0x2U << 13 * 2);
}

void LED_ON(){
    GPIOA_ODR |= (0x1U << 5);
}

void LED_OFF(){
    GPIOA_ODR &= ~(1 << 5);
}

bool button_press(){
    if(GPIOA_IDR & (1 << 13) != 0){
        return true;
    }
    return false;
}

int main(void)
{
    gpio_init();
    bool buttonPressed = false;
    // uart_init();

    while(1){
        buttonPressed = button_press();
        if(button_press == true){
            LED_ON();
            delay(500000);
            LED_OFF();
        }
    }


    return 0;



}