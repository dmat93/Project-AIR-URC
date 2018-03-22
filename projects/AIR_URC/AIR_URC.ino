#include <IRremote.h>
#include <IRremoteInt.h> 

int RECV_PIN = 11; //In my case, for Nano Clone it's D11, you can change this
//Use DigitalPIN 3 for Nano/Uno; in my case Nano Clone it's D3, depends on the library (if I'm not wrong)

IRrecv irrecv(RECV_PIN); //receiver linked to D11
IRsend irsend; //sender linked to D3
decode_results results; //received decoded signal
int code_bits = 32;
unsigned long code_value = 0;

void setup()
{
  Serial.begin(9600);
  Serial.println("Booting..."); //Debug Message
  Serial.println("============================");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Ready! v1.01");
}

void loop() {
  if (irrecv.decode(&results)) { //if you decoded something
    Serial.println(results.value, HEX); //results.value get the value (unsigned long) of the recorded signal (in bits), 
    code_value = results.value;
    code_bits = results.bits;
    irrecv.resume(); // Receive the next value
  }
  if(Serial.read()!=-1){ //open serial monitor and send a character in input, x1 character = x1 transmission
    irsend.sendNEC(code_value,code_bits); //send the signal with that length in bits; 
  }
  delay(500);
}
