/*
 * WebSocketServer.ino
 *
 *  Created on: 22.05.2015
 *
 */

#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WebSocketsServer.h>
#include <Hash.h>

ESP8266WiFiMulti WiFiMulti;

WebSocketsServer webSocket = WebSocketsServer(81);

//#define Serial Serial1

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t length) {

    switch(type) {
        case WStype_DISCONNECTED:
            Serial.printf("[%u] Disconnected!\n", num);
            break;
        case WStype_CONNECTED:
            {
                IPAddress ip = webSocket.remoteIP(num);
                //Serial.printf("[%u] Connected from %d.%d.%d.%d url: %s\n", num, i, payload);
				
				// send message to client
				webSocket.sendTXT(num, "Grbl 1.1# ['$' for help]\n");
       break;
            }
            
        case WStype_TEXT:
        {
            Serial.printf("[%u] get Text: %s\n", num, payload);

            // send message to client
             
             
webSocket.sendTXT(num,"<Idle,MPos:100.500,200.000,0.000,WPos:100.500,150.000,0.000>\r\n");

            // send data to all connected clients
             //webSocket.broadcastTXT("OK\n");
            break;
            }
        case WStype_BIN:
        {
            Serial.printf("[%u] get binary length: %u\n", num, length);
            hexdump(payload, length);

            // send message to client
             webSocket.sendBIN(num, payload, length);
            break;
            }
    }

}

void setup() {
    // Serial.begin(921600);
    Serial.begin(115200);

    //Serial.setDebugOutput(true);
    Serial.setDebugOutput(true);

    Serial.println();
    Serial.println();
    Serial.println();

    for(uint8_t t = 4; t > 0; t--) {
        Serial.printf("[SETUP] BOOT WAIT %d...\n", t);
        Serial.flush();
        delay(1000);
    }

    WiFiMulti.addAP("Infostrada-2.4GHz-02C3F6", "costycnccostycnc");

    while(WiFiMulti.run() != WL_CONNECTED) {
        delay(100);
    }

    webSocket.begin();
    webSocket.onEvent(webSocketEvent);
}

void loop() {
    webSocket.loop();
}
