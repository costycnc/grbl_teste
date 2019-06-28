/*
Serial.write is more down to earth , it is simple and fast, it is made to talk binary, one byte at a time. example:

Serial.write(0x45);   // will write 0100 0101 to the cable
Serial.print in the other hand is more versatile , it will do the conversion for you from ASCII to binary it also can convert to BIN/ HEX/OCT/DEC but you need to specify a second argument like so

Serial.print(76, BIN) gives "0100 1100"
Serial.print(76, OCT) gives "114"
Serial.print("L", DEC) gives "76"
Serial.print(76, HEX) gives "4C" 
*/

// the setup function runs once when you press reset or power the board
void setup() {
 Serial.begin(9600);
}

void loop() {
  Serial.write("Hello1\n");   
  delay(1000);                       
  Serial.print("Hello\n");    
  delay(1000);                       
}
