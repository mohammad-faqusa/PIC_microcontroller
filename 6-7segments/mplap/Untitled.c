#include <p18f4550.h>
#include <delays.h>

// CONFIGURATION BITS
#pragma config FOSC = HS
#pragma config WDT = OFF
#pragma config LVP = OFF
#pragma config PBADEN = OFF

#define SEGMENT_PORT PORTD
#define DIGIT_PORT PORTB

void main(void) {
    // Setup
    TRISD = 0x00;    // PORTD as output (segments)
    TRISB &= 0xC0;   // PORTB<5:0> as output (digits)
    SEGMENT_PORT = 0x00;
    DIGIT_PORT = 0x00;

    while (1) {
        // First digit: show 1
        SEGMENT_PORT = 0b00000110;  // Display "1"
        DIGIT_PORT = 0b00000001;    // Activate digit 0 (RB0)
        Delay1KTCYx(10);            // Delay ~few ms
        DIGIT_PORT = 0x00;          // Deactivate digits

        // Second digit: show 2
        SEGMENT_PORT = 0b01011011;  // Display "2"
        DIGIT_PORT = 0b00000010;    // Activate digit 1 (RB1)
        Delay1KTCYx(10);
        DIGIT_PORT = 0x00;

        // Third digit: show 3
        SEGMENT_PORT = 0b01001111;  // Display "3"
        DIGIT_PORT = 0b00000100;    // Activate digit 2 (RB2)
        Delay1KTCYx(10);
        DIGIT_PORT = 0x00;

        // Fourth digit: show 4
        SEGMENT_PORT = 0b01100110;  // Display "4"
        DIGIT_PORT = 0b00001000;    // Activate digit 3 (RB3)
        Delay1KTCYx(10);
        DIGIT_PORT = 0x00;

        // Fifth digit: show 5
        SEGMENT_PORT = 0b01101101;  // Display "5"
        DIGIT_PORT = 0b00010000;    // Activate digit 4 (RB4)
        Delay1KTCYx(10);
        DIGIT_PORT = 0x00;

        // Sixth digit: show 6
        SEGMENT_PORT = 0b01111101;  // Display "6"
        DIGIT_PORT = 0b00100000;    // Activate digit 5 (RB5)
        Delay1KTCYx(10);
        DIGIT_PORT = 0x00;
    }
}
