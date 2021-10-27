/*===================================================================*\
* Copyright mr.m.dudek@gmail.com
*--------------------------------------------------------------------
* Module Name:     ESP8266_ping.ino
* Created By:      mr.m.dudek@gmail.com
* Created Date:    13-10-2021
* Tested Date:		13-10-2021
*--------------------------------------------------------------------
*
* Description:
* This module is used to IP device ping
\*===================================================================*/

#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>

const char* remote_host = "192.168.0.2";

int ESP8266_ping_ping()
{
  Serial.print("Pinging host ");
  Serial.println(remote_host);

  if (Ping.ping(remote_host))
  {
    Serial.println("Success!!");
    return 1;
  }
  else
  {
    Serial.println("Error :(");
    return 0;
  }
}
