/*===================================================================*\
* Copyright mr.m.dudek@gmail.com
*--------------------------------------------------------------------
* Module Name:     ESP8266_wifi.ino
* Created By:      mr.m.dudek@gmail.com
* Created Date:    13-10-2021
* Tested Date:		13-10-2021
*--------------------------------------------------------------------
*
* Description:
* This module is used to wifi connection handle
\*===================================================================*/

#include <ESP8266WiFi.h>

const char* ssid     = "yyy";
const char* password = "xxx";

void ESP8266_wifi_reconnect_wifi()
{
  // reconnect wifi
  if ((WiFi.status() != WL_CONNECTED))
  {
    ESP8266_wifi_setup_wifi();
  }
}

void ESP8266_wifi_setup_wifi()
{
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}
