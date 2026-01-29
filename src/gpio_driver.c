// #include "my_stm32446xx.h"

// // Simple software delay loop
// // This function creates a small delay by looping 'x' times.
// // It doesn't use any hardware timer — it just burns CPU cycles.
// // The longer 'x' is, the longer the delay.
// //
// // Note: This delay is not accurate because the duration depends
// // on CPU clock speed, compiler optimization, and pipeline effects.
// // It’s fine for LED blinking or testing, but not for real timing.
// static void delay(volatile uint32_t x)
// {
//     // 'volatile' tells the compiler not to optimize away this loop.
//     // Without 'volatile', the compiler might realize the loop has no
//     // side effects and remove it completely during optimization.
//     while (x--)  // loop until x reaches 0
//     {
//         // 'nop' = "no operation" assembly instruction.
//         // It literally does nothing but consumes 1 CPU cycle.
//         // This ensures the loop takes a predictable amount of time.
//         __asm("nop");
//     }
// }

// void gpio_init(void)
// {
//     // Enable GPIOA and GPIOC clocks
//     RCC_AHB1ENR |= (1U << 0) | (1U << 2);

//     // PA5 -> output (LED)
//     GPIOA_MODER &= ~(0x3U << (5 * 2));
//     GPIOA_MODER |=  (0x1U << (5 * 2));

//     // PC13 -> input (button)
//     GPIOC_MODER &= ~(0x3U << (13 * 2));
//     GPIOC_PUPDR &= ~(0x3U << (13 * 2)); // no pull
// }

// void led_on(void) {
//     GPIOA_BSRR = (1U << 5);
// }

// void led_off(void) {
//     GPIOA_BSRR = (1U << (5 + 16));
// }

// uint8_t button_pressed(void)
// {
//     return (GPIOC_IDR & (1U << 13)) ? 0 : 1;
// }


// int main(void)
// {
//     gpio_init();

//     volatile uint32_t delaySpeed = 250000;
//     int counter = 0;

//     while (1)
//     {
//         if (button_pressed()) {
//             if (counter < 5) {
//                 counter++;
//                 delaySpeed >>= 1; // faster
//             } else {
//                 counter = 0;
//                 delaySpeed = 2500000; // reset
//             }
//             delay(200000); // debounce delay
//         }

//         led_on();
//         delay(delaySpeed);
//         led_off();
//         delay(delaySpeed);
//     }
// }

#include "my_stm32446xx.h"
#include <stdbool.h>
// #include <stdio.h>


// static void delay(volatile uint32_t x)
// {
//     while (x--)  // loop until x reaches 0
//     {
//         __asm("nop");
//     }
// }
 
void gpio_init()
{
    RCC_AHB1ENR |= (1U << 0) | (1U << 1) |(1U << 2);
    RCC_APB1ENR |= (1U << 14);
    RCC_APB2ENR |= (1U << 12);

    // LED
    GPIOA_MODER &= ~(0x3U << (5 * 2));
    GPIOA_MODER |= (0x1U << (5 * 2));


    // Button
    GPIOC_MODER &= ~(0x3U << (13 * 2));
    GPIOC_PUPDR &= ~(0x3U << (13 * 2));
    GPIOC_PUPDR |= (0x1U << (13 * 2));
}

void LED_ON(void)
{
    GPIOA_BSRR |= (0x1U << 5);
}

void LED_OFF(void)
{
    GPIOA_BSRR |= (0x1U << (16 + 5));
}

bool button_press()
{
    if((GPIOC_IDR & (1 << 13)) == 0){
        return true;
    }
    return false;
}

void uart_init()
{
    RCC_APB1ENR |= (0x1U << 17);

    // PA2 is TX and PA3 is RX
    GPIOA_MODER &= ~((0x3U << (2 * 2)) | (0x3U << (3 * 2)));
    GPIOA_MODER |= ((0x2U << (2 * 2)) | (0x2U << (3 * 2)));

    GPIOA_OSPEEDR |= ((0x1U << (2 * 2)) | (0x1U << (3 * 2)));

    GPIOA_PUPDR &= ~((0x3U << (2 * 2)) | (0x3U << (3 * 2)));
    GPIOA_PUPDR |=  (1U << (3 * 2));

    GPIOA_AFRL &= ~((0xFU << (2 * 4)) | (0xFU << (3 * 4)));
    GPIOA_AFRL |= ((0x7U << (2 * 4)) | (0x7U << (3 * 4)));

    USART2_BRR = 0x8B; //The PCLKJ1 is 16 MHz
    // USART2_BRR = 0x16D; //22 * 16 = 0x16 and 0.8125 * 16 = 0xD
    // USART2_BRR = 0x2D9;  // 84MHz @ 115200, OVER8=0
    USART2_CR1 |= (1 << 13);
    USART2_CR1 |= (1 << 3);
    USART2_CR1 |= (1 << 2);
    // USART2_CR1 |= (1 << 3 | 1 << 4)
}

void spi_init()
{
    //CS - PB6 || SCK - PB13 || MISO - PB14 || MOSI - PB15
    GPIOB_MODER &= ~((0x3U << (6 * 2)) | (0x3U << (13 * 2)) | (0x3U << (14 * 2)) | (0x3U << (15 * 2)));
    GPIOB_MODER |= ((0x1U << (6 * 2)) | (0x2U << (13 * 2)) | (0x2U << (14 * 2)) | (0x2U << (15 * 2)));

    GPIOB_AFRH &= ~((0xFU << ((13 - 8) * 4)) | (0xFU << ((14 - 8) * 4)) | (0xFU << ((15  - 8) * 4)));
    GPIOB_AFRH |=  ((5U << ((13 - 8) * 4))   | (5U << ((14 - 8) * 4))   | (5U << ((15 - 8) * 4)));


    SPI2_CR1 |= (0x1U << 2);   // MSTR
    SPI2_CR1 |= (0x3U << 3);   // BR prescaler (example /16)   
    SPI2_CR1 |= (0x1U << 6);   // SPE
    SPI2_CR1 |= (0x1U << 8);   // SSI
    SPI2_CR1 |= (0x1U << 9);   // SSM

}

void spi_send_char(char c)
{
    while(!(SPI2_SR & (1U << 1)));
    SPI1_DR = (uint8_t)c;
}

void spi_send_string(char* str)
{
    while(*str)
    {
        spi_send_char(*str++);
    }
}

void uart_send_char(char c)
{
    while(!(USART2_SR & (1<<7))); // wait TXE
    USART2_DR = (uint8_t)c;
}

void uart_send_string(char* str)
{
    while(*str)
    {
        uart_send_char(*str++);
    }
}

int main(void)
{
    gpio_init();
    uart_init();
    spi_init();
    bool buttonPressed = false;
    
    int count = 0;
    // char helloWorld = "Hello World";

    while(1)
    {
        buttonPressed = button_press();
        if(buttonPressed == true && count == 0){
            LED_ON();
            uart_send_string("Hello World UART\r\n");
            spi_send_string("Hello World SPI\r\n");
            // uart_send_char(0x55);
            count++;
        }
        if(buttonPressed == true && count != 0){
        }
        else{
            LED_OFF();
            count = 0;
        }
    }

    return 0;

}