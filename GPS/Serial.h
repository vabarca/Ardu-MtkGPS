/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/*
  
  by Vicente Abarca
*/

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

#ifndef SERIAL_H_
#define SERIAL_H_

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

void    SerialOpen(uint32_t baud);
uint8_t SerialRead();
void    SerialWrite(uint8_t c);
uint8_t SerialAvailable();
void    SerialEnd();
bool    SerialTXfree();
uint8_t SerialUsedTXBuff();
void    SerialPrintPROGMEM(const char PROGMEM * str);
void    SerialRxPurge();

uint8_t parseHex(char c);
char    char2hex(char c);

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

#endif /* SERIAL_H_ */

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
