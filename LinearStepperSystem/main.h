/*
 * main.h
 *
 * Created: 15.05.2015 22:59:56
 *  Author: Makerboost
 */ 


#ifndef MAIN_H_
#define MAIN_H_



/*
	CONSTANTS
*/
#define F_CPU                   16000000UL;             // 16Mhz crystal (unsigned long)

// ** Target of rotational motion
#define TARGET_RADIUS           20                      // Target radius, in millimeters. TODO - add ability to set radius in G-code
#define PI                      3.14159
#define TARGET_CIRCUMFERENCE    (2 * PI) * TARGET_RADIUS

// ** Stepper motor specifics
#define DEGREES_PER_STEP        1.8                     // TODO - add ability to set degrees per step in G-code
#define MICROSTEPPING           16                      // TODO - add ability to set micro stepping in G-code
#define STEPS_IN_360_DEGREES    (360 / DEGREES_PER_STEP) * MICROSTEPPING

// ** 
#define MM_PER_STEP             TARGET_CIRCUMFERENCE / STEPS_IN_360_DEGREES


/*
	DELAY TABLE 

Lookup table for acceleration/deceleration. 
Each value corresponds to delay between each step pulse, expressed in a 8 bit format. 
Calculated from a cubic ease-in formula with the following arguments: (0,0,0.25,1)
*/
unsigned char const delayTable[256] PROGMEM;


#endif /* MAIN_H_ */