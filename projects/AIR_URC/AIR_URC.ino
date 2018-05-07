#include <IRremote.h>
#include <IRremoteInt.h> 

int RECV_PIN = 11; //In my case, for Nano Clone it's D11, you can change this
//Use DigitalPIN 3 for Nano/Uno; in my case Nano Clone it's D3, depends on the library (if I'm not wrong)

IRrecv irrecv(RECV_PIN); //receiver linked to D11
IRsend irsend; //sender linked to D3
decode_results results; //received decoded signal
int code_bits = 32;
unsigned long code_value = 0;
int code_type;
String type[] = {"UNKNOW", "RC5", "RC6", "NEC", "SONY", "PANASONIC", 
                 "JVC", "SAMSUNG", "WHYNTER", "AIWA_RC_T501", 
                 "LG", "SANYO", "MITSUBISHI", "DISH", "SHARP", 
                 "DENON", "PRONTO", "LEGO_PF"};

void setup()
{
  Serial.begin(9600);
  Serial.print(">Booting."); //Debug Message
  delay(1000);
  Serial.print(".");
  delay(1000);
  Serial.println(".");
  delay(1000);
  Serial.println(">AIR - URC");         
  Serial.println("========================================================");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println(">Ready! v1.024");
  Serial.println("========================================================");

  pinMode(2, OUTPUT); //Debug LED
  digitalWrite(2, LOW); //Led OFF
}

void loop() {
  if (irrecv.decode(&results)) { //if you decoded something
    Serial.print("HEX Value: ");
    Serial.println(results.value,HEX); //results.value get the value (unsigned long) of the recorded signal (in bits), 
    digitalWrite(2, HIGH);
    delay(250);
    digitalWrite(2, LOW);
    code_value = results.value;
    code_bits = results.bits;
    code_type = (int)((char)results.decode_type);
    Serial.println("Results Value: " + (String)results.value);
    Serial.println("Results Bit: " + (String)results.bits);
    Serial.println("Results Type: " + type[(int)((char)results.decode_type)]);
    irrecv.resume(); // Receive the next value
  }
  if(Serial.read()!=-1){ //open serial monitor and send a character in input, x1 character = x1 transmission
    if(code_type==0){
      irsend.sendNEC(code_value,code_bits); //send the signal with that length in bits
      delay(100);
      irrecv.resume(); 
    }
    if(code_type==1){
      irsend.sendRC5(code_value,code_bits); //send the signal with that length in bits
      delay(100);
      irrecv.resume();
    }
    if(code_type==2){
      irsend.sendRC6(code_value,code_bits); //send the signal with that length in bits
      delay(100);
      irrecv.resume();
    }
    if(code_type==3){
      irsend.sendNEC(code_value,code_bits); //send the signal with that length in bits
      delay(100);
      irrecv.resume();
    }
    if(code_type==4){
      irsend.sendSony(code_value,code_bits); //send the signal with that length in bits
      delay(100);
      irrecv.resume();
    }
    if(code_type==5){
      irsend.sendPanasonic(code_value,code_bits); //send the signal with that length in bits
      delay(100);
      irrecv.resume();
    }
    if(code_type==6){
      irsend.sendJVC(code_value,code_bits, false); //send the signal with that length in bits
      delay(100);
      irrecv.resume();
    }
    if(code_type==7){
      irsend.sendSAMSUNG(code_value,code_bits); //send the signal with that length in bits
      delay(100);
      irrecv.resume();
    }
    if(code_type==8){
      irsend.sendWhynter(code_value,code_bits); //send the signal with that length in bits
      delay(100);
      irrecv.resume();
    }
    if(code_type==9){
      irsend.sendAiwaRCT501(code_value); //send the signal with that length in bits
      delay(100);
      irrecv.resume();
    }
    if(code_type==10){
      irsend.sendLG(code_value,code_bits); //send the signal with that length in bits
      delay(100);
      irrecv.resume();
    }
    if(code_type==11){
      Serial.println("Not Supported yet");
    }
    if(code_type==12){
      Serial.println("Not Supported yet");
    }
    if(code_type==13){
      irsend.sendDISH(code_value,code_bits); //send the signal with that length in bits
      delay(100);
      irrecv.resume();
    }
    if(code_type==14){
      irsend.sendSharpRaw(code_value,code_bits); //send the signal with that length in bits
      delay(100);
      irrecv.resume();
    }
    if(code_type==15){
      irsend.sendDenon(code_value,code_bits); //send the signal with that length in bits
      delay(100);
      irrecv.resume();
    }
    if(code_type==16){
      Serial.println("Not Supported yet");
    }
    if(code_type==17){
      irsend.sendLegoPowerFunctions(code_value,code_bits); //send the signal with that length in bits
      delay(100);
      irrecv.resume();
    }
  }
}
