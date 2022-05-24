#include <stdio.h>
#include <stdlib.h>
#include <xc.h>

#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#define _XTAL_FREQ 4000000

int sayac;

void main(void) {
    
    INTCON |= 0xA0;     // GIE ve T0IE bitleri aktif.
    TRISB = (0 << 0);   // RB0 set output
    OPTION_REG = 0x07;
    
    TMR0 = 217;
    PORTB &= ~(1 << 0); // RB0 = 0
    while(1)
    {
        
    }
}
void __interrupt() TMR0_KESME(void) //10ms'de bir gir
{
    if(T0IF) // TMR0 ta?mas? kontrolü
    {
        sayac += 1;
       
        if(sayac == 50)
        {
            sayac = 0;
            RB0 = RB0 ^ 1;
        }
        TMR0 = 217;
        T0IF = 0;
    }

}