/*
 * File:   string_select.c
 * Author: Justin Andreotti
 *
 * Created on October 13, 2026, 3:22 PM
 */

//check
#include <xc.h>

void main(void) {
    init();

    TrafficState state = ELow;

    while (1)
    {
	switch (state)
        {
            case ELow:
    
                if (PORTDbits.RD6 == 0){
                state = A;
              
                }else if (PORTDbits.RD7 == 0){
                state = EHigh;
                 } 
                Break;

            case A:
                
                if (PORTDbits.RD6 == 0){
                state = D;
              
                }else if (PORTDbits.RD7 == 0){
                state = ELow;
                } 
                Break;

            case D:
                
                if (PORTDbits.RD6 == 0){
                state = G;
              
                }else if (PORTDbits.RD7 == 0){
                state = A;
                } 
                Break;

            case G:
                
                if (PORTDbits.RD6 == 0){
                state = B;
              
                }else if (PORTDbits.RD7 == 0){
                state = D;
                } 
                Break;

            case B:

                if (PORTDbits.RD6 == 0){
                state = EHigh;
              
                }else if (PORTDbits.RD7 == 0){
                state = G;
                } 
                Break;

            case EHigh:
                
                if (PORTDbits.RD6 == 0){
                state = ELow;
              
                }else if (PORTDbits.RD7 == 0){
                state = B;
                } 
                Break;
        }
	}

}
