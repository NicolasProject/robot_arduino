#ifndef FONCTIONS_H
#define FONCTIONS_H

//#include <Arduino.h> // is included by Temporisation.h
#include <avr/wdt.h>
#include <avr/delay.h>
#include "Temporisation.h"

/*#define BIT0 0x01
#define BIT1 0x02
#define BIT2 0x04
#define BIT3 0x08
#define BIT4 0x10
#define BIT5 0x20
#define BIT6 0x40
#define BIT7 0x80*/

extern const uint8_t BIT0;
extern const uint8_t BIT1;
extern const uint8_t BIT2;
extern const uint8_t BIT3;
extern const uint8_t BIT4;
extern const uint8_t BIT5;
extern const uint8_t BIT6;
extern const uint8_t BIT7;


#define BLUETOOTH Serial1

#define TOP_TIMER1 5000 - 1


// vitesse max qu'il est possible d'envoyer au robot
#define VITESSE_PRECISION 10

#define POS_SERVO_DEG_MAX 90
#define POS_SERVO_DEG_MIN 0


#define DEBUG
#undef DEBUG // remove DEBUG

#ifdef DEBUG
#define PRINTD Serial.println
#else
inline int PRINTD(char*, ...)
{
	return 0;
}
inline int PRINTD(const char*, ...)
{
	return 0;
}
inline int PRINTD(char, ...)
{
	return 0;
}
inline int PRINTD(int, ...)
{
	return 0;
}
#endif


void resetPortDir();

// Read Tram Bluetooth
bool readTBluetooth(char trame[], const int iTaille);
// Send Tram Bluetooth in 1 time
void sendTBluetooth(char trame[], const int iTaille);

// blocant
void blinkLedBlock(const int pin, const int times, const int speedMS);


void WDT_start();
void WDT_stop();


#endif
