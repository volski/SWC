#include <SPI.h>
#include <IRremote.h>

// remote control commands from IR_remote
const long VOL_UP=0xFFA857;
const long VOL_DN=0xFFE01F;
const long PREV_TR=0xFF22DD;
const long NEXT_TR=0xFF02FD;
const long MODE=0xFF9867; //on ir remote label 100+
const long MUTE=0xFF6897; //on ir remote label 0
const long BAND=0xFFB04F; //on ir remote label 200+
const long EQ=0xFF906F;
const long PLAY=0xFFC23D;
const long CH_UP=0xFFE21D;
const long CH_DN=0xFFA25D;
const long CH=0xFF629D;

const long ONE=0xFF30CF;
const long TWO=0xFF18E7;
const long THREE=0xFF7A85;
const long FOUR=0xFF10EF;
const long FIVE=0xFF38C7;
const long SIX=0xFF5AA5;
const long SEVEN=0xFF42BD;
const long EIGHT=0xFF4AB5;
const long NINE=0xFF52AD;


const int POT_PIN = 3;
// Set digital pin 6 for IR data:
const int RECV_PIN = 6;

IRrecv irrecv(RECV_PIN);
decode_results results;

int currButton;

void setup() {                
  pinMode(POT_PIN, OUTPUT);  
  SPI.begin();
  Serial.begin(9600);
  irrecv.enableIRIn();
}

void loop() {
  delay(50);
 while(irrecv.decode(&results)) {
  if(results.value!=0xFFFFFFFF){
    currButton=results.value;
  }
    Serial.println(currButton,HEX);
     switch(currButton) {
       case VOL_UP: digitalPotWrite(20); break;  
       case VOL_DN: digitalPotWrite(15); break;    
       case PREV_TR: digitalPotWrite(10); break;  
       case NEXT_TR: digitalPotWrite(5); break;  
       case MODE: digitalPotWrite(25); break;  
       case MUTE: digitalPotWrite(30); break;  
       case BAND: digitalPotWrite(60); break;
       case EQ: digitalPotWrite(62); break;
       case PLAY: digitalPotWrite(64); break;
       case CH_UP: digitalPotWrite(66); break;
       case CH_DN: digitalPotWrite(68); break;
       case CH: digitalPotWrite(70); break;
       case ONE: digitalPotWrite(40); break;  
       case TWO: digitalPotWrite(42); break;    
       case THREE: digitalPotWrite(44); break;  
       case FOUR: digitalPotWrite(46); break;  
       case FIVE: digitalPotWrite(48); break;  
       case SIX: digitalPotWrite(50); break;  
       case SEVEN: digitalPotWrite(52); break;  
       case EIGHT: digitalPotWrite(54); break;  
       case NINE: digitalPotWrite(56); break;
       default: break; 
     }
     
    irrecv.resume();
    }
    digitalPotWrite(0);
}
int digitalPotWrite(int value)
{
  // Take the SS/CS pin low to select the chip:
  digitalWrite(POT_PIN, LOW);
 // Serial.println(value,HEX);
  // Send in the address and value via SPI:
  SPI.transfer(0);
  SPI.transfer(value);
  delay(150);
  // Take the SS/CS pin high to de-select the chip:
  digitalWrite(POT_PIN, HIGH); 
} 
