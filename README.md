https://github.com/natevw/js-cnc

# grbl_teste

grbl is inspired from this Arduino GCode Interpreter by Mike Ellery https://github.com/alx/reprap-arduino-firmware/tree/master/GCode_Interpreter

first grbl 2009 https://github.com/grbl/grbl/tree/9df29ad3b3fb769317d9c5560c54e89c92a71680

grbl tat i use in my cnc grbl 0.8c


GcodeCNCDemo2Axis original not workimg https://github.com/MarginallyClever/GcodeCNCDemo
I adjust some errors and now working but only same as G1 X10 working --- G90,G91,G21 is blocking

     WiFi.begin(ssid, password);
      while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
     }
 
       Serial.println("");
       Serial.println("WiFi connected");
       Serial.print("Camera Stream Ready! Go to: http://");
       Serial.print(WiFi.localIP());
     ----------------------------------connect direct to module esp32-----------------------------------------------------

     WiFi.softAP(ssid,password); // or  WiFi.softAP(ssid); if want connect without password

      IPAddress IP = WiFi.softAPIP();
      Serial.print("AP IP address: ");
      Serial.println(IP);
