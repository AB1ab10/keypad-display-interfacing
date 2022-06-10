/*
 * File:   kewpadDisplay.c
 * Author: Alex
 *
 * Created on March 30, 2022, 11:02 AM
 */


#include <xc.h>

#define SEG_ON 1

#define C1 PORTBbits.RB0
#define C2 PORTBbits.RB1
#define C3 PORTBbits.RB2
#define R1 PORTBbits.RB3
#define R2 PORTBbits.RB4
#define R3 PORTBbits.RB5
#define R4 PORTBbits.RB6

unsigned char seg[] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};

void display(int n){
    PORTC = seg[n];
}

void keypad(){
    C1 = 1 ; C2 = 0 ; C3 = 0;
    if(R1 == 1){
        display(1);
        while(R1 == 1);
    }
    if(R2 == 1){
        display(4);
        while(R2 == 1);
    }
    if(R3 == 1){
        display(7);
        while(R3 == 1);
    }
    C1 = 0 ; C2 = 1 ; C3 = 0;
    if(R1 == 1){
        display(2);
        while(R1 == 1);
    }
    if(R2 == 1){
        display(5);
        while(R2 == 1);
    }
    if(R3 == 1){
        display(8);
        while(R3 == 1);
    }
    if(R4 == 1){
        display(0);
        while(R4 == 1);
    }
    C1 = 0 ; C2 = 0 ; C3 = 1;
    if(R1 == 1){
        display(3);
        while(R1 == 1);
    }
    if(R2 == 1){
        display(6);
        while(R2 == 1);
    }
    if(R3 == 1){
        display(7);
        while(R3 == 1);
    }    
    
}

void main(void) {
    
    TRISE = 0x00;
    TRISC = 0x00;
    TRISB = 0xF0;
    
    while(1){
        PORTEbits.RE2 = SEG_ON;
        keypad();
    }
    
    return;
}
