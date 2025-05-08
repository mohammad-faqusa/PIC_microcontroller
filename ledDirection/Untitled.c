/* Compile options:  -ml (Large code model) */
#include <p18F4550.h>
#include <delays.h>
#pragma config FOSC = INTOSCIO_EC 
#pragma config PWRT = OFF
#pragma config BOR = OFF
#pragma config MCLRE = ON
#pragma config PBADEN = OFF
#pragma config ICPRT = OFF
#pragma config LVP = OFF
#pragma config WDT = OFF,DEBUG=OFF

void main (void){
	char leds[] = {0b00000000,0b10000000,0b11000000,0b11100000,0b11110000,0b11111000,0b11111100,0b11111110,0b11111111};
    int i;
    int turn_on = 0; 
    int turn_off = 0; 

    TRISD = 0x00; 
    TRISB = 0x03;

    while (1)
    {
    
        if(PORTBbits.RB0==1){
            for(i ; i <= 8 && PORTBbits.RB0==1; i++){
                PORTD = leds[i];
                Delay10KTCYx(25);
            }

        } else if(PORTBbits.RB1==1){
            for(i ; i >= 0 && PORTBbits.RB1==1; i--){
                PORTD = leds[i];
                Delay10KTCYx(25);
            }

        }
		

    }
}