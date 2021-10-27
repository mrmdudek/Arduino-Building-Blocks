/*===================================================================*\
* Copyright mr.m.dudek@gmail.com
*--------------------------------------------------------------------
* Module Name:     ESP8266_http_request.ino
* Created By:      mr.m.dudek@gmail.com
* Created Date:    13-10-2021
* Tested Date:		-
*--------------------------------------------------------------------
*
* Description:
* This module is used to connect to send and receive http get request
\*===================================================================*/

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>

#define LINK ""

// HTTP req
int ESP8266_http_request_connect()
{     
    std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);

    client->setInsecure();

    HTTPClient https;

    Serial.print("[HTTPS] begin...\n");
    if (https.begin(*client, LINK)) {  // HTTPS
      
      request_state = 2;
      
      Serial.print("[HTTPS] GET...\n");
      // start connection and send HTTP header
      int httpCode = https.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {

        request_state = 3;
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTPS] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = https.getString();
          Serial.println(payload);
		 }
      } else {
        Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
      }

      https.end();
    } else {
      Serial.printf("[HTTPS] Unable to connect\n");
    }
}
