#include<p18f4550.h>




void main(){
	ADCON1=15;
	PORTD=0;
	PORTB=0;
	TRISD=0;
	TRISB=255;
	while(1){
		PORTD=PORTB; 
	}
}
	