/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/*
  gps
  by Vicente Abarca
*/

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Serial.h" 
#include "GPS.h" 

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

void iniGPS()
{
  uint32_t init_speed[5] = {9600,19200,38400,57600,115200};
  SerialEnd();
  
  for(uint8_t i=0;i<5;i++)
  {
    SerialOpen(init_speed[i]);                // switch UART speed for sending SET BAUDRATE command
    delay(1000);
    SerialPrintPROGMEM(MTK_BAUD);  
    while(!SerialTXfree());
    delay(500);
    SerialEnd();
  }

  // at this point we have GPS working at selected (via #define GPS_BAUD) baudrate
  // So now we have to set the desired mode and update rate (which depends on the NMEA or MTK_BINARYxx settings)
  SerialOpen(DATA_BAUD);
  delay(1000);

  SerialPrintPROGMEM(MTK_NAVTHRES_OFF);
  while(!SerialTXfree());
  delay(500);
  SerialPrintPROGMEM(MTK_NMEA_OUTPUT);
  while(!SerialTXfree());
  delay(500);
  SerialPrintPROGMEM(MTK_SET_DATUM);
  while(!SerialTXfree());
  delay(500);
  SerialPrintPROGMEM(MTK_OUTPUT_1HZ);           // 1 Hz update rate
  while(!SerialTXfree());
  delay(500);
  SerialPrintPROGMEM(MTK_TEST);                 // 1 Hz update rate
  while(!SerialTXfree());
  
  SerialRxPurge();
  delay(500);
}

/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

