#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PB5  // Define the LED pin (Port B, Pin 5)

void setup() {
    // Set LED_PIN as an output
    DDRB |= (1 << LED_PIN);
}

void loop() {
    // Turn the LED on
    PORTB |= (1 << LED_PIN);
    _delay_ms(1000);  // Wait for 1 second

    // Turn the LED off
    PORTB &= ~(1 << LED_PIN);
    _delay_ms(1000);  // Wait for 1 second
}

int main(void) {
    setup();

    while (1) {
        loop();  // Continuously execute the loop function
    }

    return 0;
}
