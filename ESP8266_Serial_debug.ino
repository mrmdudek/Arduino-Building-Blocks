/*===================================================================*\
* Copyright mr.m.dudek@gmail.com
*--------------------------------------------------------------------
* Module Name:     ESP8266_Serial_debug.ino
* Created By:      mr.m.dudek@gmail.com
* Created Date:    13-10-2021
* Tested Date:		13-10-2021
*--------------------------------------------------------------------
*
* Description:
* This module is used to print debug info, If debug is not needed change
* DEBUG value
\*===================================================================*/

#define DEBUG 1

#ifdef DEBUG
# define Debug_print(x) Serial.print(x)
#else
# define Debug_print(x) do {} while (0)
#endif

#ifdef DEBUG
# define Debug_println(x) Serial.println(x)
#else
# define Debug_println(x) do {} while (0)
#endif
