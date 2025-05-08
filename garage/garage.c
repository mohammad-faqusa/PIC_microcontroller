#include <p18f4550.h>
#include <delays.h>

// CONFIGURATION BITS
#pragma config FOSC = HS     // High-speed oscillator
#pragma config WDT = OFF     // Watchdog Timer off
#pragma config LVP = OFF     // Low-voltage programming off

// Declare ISR function prototype before using
void isr(void);
void increment();
int right = 5; 
int left = 9; 

int is_max = 0;

const unsigned char seven_seg_digits[10] = {
    0b00111111, // 0 → A B C D E F
    0b00000110, // 1 → B C
    0b01011011, // 2 → A B D E G
    0b01001111, // 3 → A B C D G
    0b01100110, // 4 → B C F G
    0b01101101, // 5 → A C D F G
    0b01111101, // 6 → A C D E F G
    0b00000111, // 7 → A B C
    0b01111111, // 8 → All segments
    0b01101111  // 9 → A B C D F G
};
// High-priority interrupt vector
#pragma code high_vector=0x08
void high_interrupt(void) {
    _asm GOTO isr _endasm
}
#pragma code

// Mark the ISR as high-priority
#pragma interrupt isr
void isr(void) {
    if (INTCONbits.INT0IF) {
        INTCONbits.INT0IF = 0;  // Clear the interrupt flag!
        if(left <= 9 && right < 9) {
            
            right++;
            if (right > 9) {
                right = 0;
                left++;
                if (left > 9)
                    left = 0;
            }
        } 
        
    }

    if (INTCON3bits.INT1IF) {
        INTCON3bits.INT1IF = 0;
        if(left >= 0 && right > 0) {
            
            right--;
            if (right < 0 ) {
                right = 9;
                left--;
            }
        } 
    }
}

void main(void) {
    // Setup
    ADCON1 = 15; 
    TRISB = 3;   // RB0 as input (button)
    TRISD  = 0;   // RD0 as output (LED)
    LATD  = 0;
    TRISC = 0;
    PORTC = 0;
	PORTCbits.RC2 = 1; // available
    PORTCbits.RC4 = 0; // full 

    // INT0 Setup (RB0)
    INTCON2bits.INTEDG0 = 1;     // Rising edge
    INTCONbits.INT0IF = 0;
    INTCONbits.INT0IE = 1;

    // INT1 Setup (RB1)
    INTCON2bits.INTEDG1 = 1;     // Rising edge
    INTCON3bits.INT1IF = 0;
    INTCON3bits.INT1IE = 1;

    // Enable global interrupts
    RCONbits.IPEN = 0;           // Disable priority levels (both high)
    INTCONbits.GIE = 1;
    

    while (1) {
        PORTCbits.RC1 = 1; 
        PORTD = seven_seg_digits[right];
        Delay1KTCYx(0.1); // Small delay (~5ms depending on clock)
        PORTCbits.RC1 = 0;
        PORTCbits.RC0 = 1; 
        PORTD = seven_seg_digits[left];
        Delay1KTCYx(0.1); // Small delay (~5ms depending on clock)
        PORTCbits.RC0 = 0;
        if(left <= 9 && right < 9){
            PORTCbits.RC2 = 1;
            PORTCbits.RC4 = 0;
        } else {
            PORTCbits.RC2 = 0;
            PORTCbits.RC4 = 1;
        }
        
        
    }
}
