/*
 * main.c
 *
 * Created: 15.05.2015 22:35:11
 *  Author: Makerboost
 */ 



/*
	INCLUDES
*/
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "main.h"



/*
	PORTS
*/

// TODO: Set step output pin
// TODO: Set direction output pin



/*
	TIMERS
*/

// TODO: Set up timer for step output. 16 bit timer, to allow for longer pause when ramping up or down.
//pgm_read_byte(&delayTable[0]);


/*
	SPI SETUP
	Listen on MOSI port for commands and then act on them
	Commands are a subset of G-Code
*/






int main(void)
{
	// Initialize
	
	// Set state machine initial state to STOPPED
	volatile State machine = STOPPED;
	
	// Infinite loop
    while(1)
    {
        
		switch (machine)
		{
			case STOPPED:
					// Machine in stopped state. 
					// TODO: Listen to SPI communications for commands.
					// TODO: When command received, calculate total steps and direction.
			
					break;
					
			case ACCELERATING:
					// Machine accelerating.
					// TODO: Run through delayTable array, using the values as milliseconds to delay between each step pulse.
					// TODO: When reached end of array, go to running state.
			
			
					break;			
					
			case RUNNING:
					// Machine is running at top speed.
					// TODO: Maintain steps at lowest delay specified.
			
			
					break;
					
			case DECELERATING:
					// Machine is decelerating.
					// TODO: Run through delayTable in reverse. When reached end, go to stopped state.
			
					break;
					
		}
		
		
		// TODO: 
		pgm_read_byte(&delayTable[0]);
		
		
		
    }
}


/*
	DELAY TABLE
*/
unsigned char const delayTable[DELAY_MAX_VALUES] PROGMEM = {
	 0x01,0x03,0x07,0x0a,0x0d,0x11,0x14,0x17,0x1a,0x1c,0x1f,0x22,0x25,0x28,
	 0x2a,0x2d,0x2f,0x32,0x34,0x37,0x39,0x3c,0x3e,0x40,0x43,0x45,0x47,0x49,
	 0x4b,0x4e,0x50,0x52,0x54,0x56,0x58,0x5a,0x5c,0x5e,0x60,0x62,0x64,0x66,
	 0x67,0x69,0x6b,0x6d,0x6f,0x70,0x72,0x74,0x76,0x77,0x79,0x7b,0x7c,0x7e,
	 0x80,0x81,0x83,0x84,0x86,0x87,0x89,0x8a,0x8c,0x8d,0x8f,0x90,0x92,0x93,
	 0x94,0x96,0x97,0x99,0x9a,0x9b,0x9d,0x9e,0x9f,0xa0,0xa2,0xa3,0xa4,0xa5,
	 0xa7,0xa8,0xa9,0xaa,0xab,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,0xb6,
	 0xb7,0xb8,0xb9,0xba,0xbb,0xbc,0xbd,0xbe,0xbf,0xc0,0xc1,0xc2,0xc3,0xc4,
	 0xc5,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xcd,0xce,0xcf,0xd0,
	 0xd1,0xd1,0xd2,0xd3,0xd4,0xd5,0xd5,0xd6,0xd7,0xd8,0xd8,0xd9,0xda,0xda,
	 0xdb,0xdc,0xdc,0xdd,0xde,0xde,0xdf,0xe0,0xe0,0xe1,0xe2,0xe2,0xe3,0xe3,
	 0xe4,0xe5,0xe5,0xe6,0xe6,0xe7,0xe7,0xe8,0xe8,0xe9,0xe9,0xea,0xea,0xeb,
	 0xeb,0xec,0xec,0xed,0xed,0xee,0xee,0xef,0xef,0xf0,0xf0,0xf0,0xf1,0xf1,
	 0xf2,0xf2,0xf2,0xf3,0xf3,0xf3,0xf4,0xf4,0xf5,0xf5,0xf5,0xf6,0xf6,0xf6,
	 0xf7,0xf7,0xf7,0xf7,0xf8,0xf8,0xf8,0xf9,0xf9,0xf9,0xf9,0xfa,0xfa,0xfa,
	 0xfa,0xfb,0xfb,0xfb,0xfb,0xfb,0xfc,0xfc,0xfc,0xfc,0xfc,0xfd,0xfd,0xfd,
	 0xfd,0xfd,0xfd,0xfd,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xfe,0xff,0xff,
	 0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,
     0xff,0xff,0xff,0xff};