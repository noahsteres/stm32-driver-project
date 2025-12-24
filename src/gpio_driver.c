#include "my_stm32446xx.h"

// Simple software delay loop
// This function creates a small delay by looping 'x' times.
// It doesn't use any hardware timer — it just burns CPU cycles.
// The longer 'x' is, the longer the delay.
//
// Note: This delay is not accurate because the duration depends
// on CPU clock speed, compiler optimization, and pipeline effects.
// It’s fine for LED blinking or testing, but not for real timing.
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


int main(void)
{
    gpio_init();

    volatile uint32_t delaySpeed = 250000;
    int counter = 0;

    while (1)
    {
        if (button_pressed()) {
            if (counter < 5) {
                counter++;
                delaySpeed >>= 1; // faster
            } else {
                counter = 0;
                delaySpeed = 2500000; // reset
            }
            delay(200000); // debounce delay
        }

        led_on();
        delay(delaySpeed);
        led_off();
        delay(delaySpeed);
    }
}