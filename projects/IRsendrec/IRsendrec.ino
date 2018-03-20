/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>
#include <IRremoteInt.h> 

int RECV_PIN = 11;

IRrecv irrecv(RECV_PIN);
IRsend irsend;
decode_results results;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin151");
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX); //results.value get the value of the recorded signal (bits)
    irrecv.resume(); // Receive the next value
  }
  if(Serial.read()!=-1){
    irsend.sendLG(results.value,32); //from feedback on serial monitor we can find the length in bits (every HEX value = 4bits)
  }
  delay(500);
}
