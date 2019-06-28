/*
Serial.write is more down to earth , it is simple and fast, it is made to talk binary, one byte at a time. example:

Serial.write(0x45);   // will write 0100 0101 to the cable
Serial.print in the other hand is more versatile , it will do the conversion for you from ASCII to binary it also can convert to BIN/ HEX/OCT/DEC but you need to specify a second argument like so

Serial.print(76, BIN) gives "0100 1100"
Serial.print(76, OCT) gives "114"
Serial.print("L", DEC) gives "76"
Serial.print(76, HEX) gives "4C" 
*/

#define MAX_BUF        (64)

char  buffer1[MAX_BUF];  // where we store the message until we get a newline
int   sofar;            // how much is in the buffer

// the setup function runs once when you press reset or power the board
void setup() {
 Serial.begin(9600);
}

void loop() {
  
  while(Serial.available() > 0) {  // if something is available
    char c=Serial.read();  // get it
    //Serial.print(c);  // repeat it back so I know you got the message
    if(sofar<MAX_BUF-1) buffer1[sofar++]=c;  // store it
    if((c=='\n') || (c == '\r')) {
      // entire message received
      buffer1[sofar]=0;  // end the buffer so string functions work right
      Serial.println("received=");  // echo a return character for humans
      Serial.print(buffer1);
     
    }
  }                      
}
