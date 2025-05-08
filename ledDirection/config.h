#ifndef CONFIG_H
    // Configuration Bits
#pragma config FOSC = HSPLL_HS  // High-Speed Crystal with PLL
#pragma config PLLDIV = 5       // Divide by 5 (20 MHz crystal)
#pragma config CPUDIV = OSC1_PLL2 // Divide by 2
#pragma config USBDIV = 1       // USB clock source from PLL
#pragma config FCMEN = OFF
#pragma config IESO = OFF
#pragma config PWRT = OFF
#pragma config BOR = OFF
#pragma config VREGEN = OFF
#pragma config WDT = OFF
#pragma config MCLRE = ON
#pragma config LPT1OSC = OFF
#pragma config PBADEN = OFF
#pragma config STVREN = OFF
#pragma config LVP = OFF
#pragma config XINST = OFF
#pragma config DEBUG = OFF

#define _XTAL_FREQ 48000000  // 48MHz for __delay_ms()
#endif	/* CONFIG_H */