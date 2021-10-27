/*===================================================================*\
* Copyright mr.m.dudek@gmail.com
*--------------------------------------------------------------------
* Module Name:     ESP8266_Watchdog.ino
* Created By:      mr.m.dudek@gmail.com
* Created Date:    13-10-2021
* Tested Date:		-
*--------------------------------------------------------------------
*
* Description:
* This module is used to handle watchdog
\*===================================================================*/

#include <Ticker.h> // timer and ticker library

// SETUP
int reset_time = 20; // reset time in seconds (if device not respond)

// error detect and variable used for reset
volatile uint8_t ESP8266_Watchdog_count = 0; // watchdog count
Ticker TIMER; // Ticker TIMER

void ESP8266_Watchdog_setup(int time_base_ms)
{
  TIMER.attach_ms(time_base_ms, ESP8266_Watchdog_TIMER_ISR); // TIMER 1st argument is in seconds
  ESP8266_Watchdog_set_reset_time_ms(10000);
}

void ESP8266_Watchdog_set_reset_time_ms(int time_to_reset_ms)
{
  reset_time = time_to_reset_ms;
  ESP8266_Watchdog_clear();
}

void ESP8266_Watchdog_clear()
{
  ESP8266_Watchdog_count = 0;
}

// ISR TIMER TICKER
void ESP8266_Watchdog_TIMER_ISR()
{
  // watchdog function
  // every used function clear WatchDogCount, if program stuck this function reset ESP
  // ESP8266_GPIO_LED_toogle();
  ESP8266_Watchdog_count++;
  if (ESP8266_Watchdog_count >= reset_time) // if main program didn't reset WatchDogCount reset
  {
    ESP8266_Watchdog_reset_func();
  }
}

void ESP8266_Watchdog_reset_func()
{
  //reset_ESP8266++;
  //ESP8266_EEPROM_save_EEPROM();
  Serial.print("Wathdog RESET ");
  ESP.reset();
}

void ESP8266_Watchdog_watchdog_clear()
{
  ESP8266_Watchdog_count = 0; // clear watchdog
}
