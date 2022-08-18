int pot0 = 0; //Define Pots 0,1 and array LEDs to be used in loop
int pot1 = 0;
int leds[] = {9,8,7,6,5,4,3,2};
void setup() {
  Serial.begin(9600); //Set baud rate 
  for(int i = 2; i <= 9; i++) // Set all Pins 2-9 as an output so it can use digitWrite()
  {
    pinMode(i, OUTPUT);
  }
  
}

void loop() {
  // put your main code here, to run repeatedly:
  pot0 = analogRead(A0); //Assign pot0 and pot 1 to the bit value from 0-1023
  pot1 = analogRead(A1);
  Serial.println(pot0);
   
 if (pot0 < 341) { //Runs when pot0 is in its first third of 1024 bits
    allOff();
    digitalWrite(leds[ledAssign(pot1)], HIGH);   //After calling allOff, we call ledAssign and tuen on that specifc LED
  } 
   else if(pot0<682){  //Runs when pot0 is in its second third of 1024 bits
    digitalWrite(leds[ledAssign(pot1)], HIGH);
    
  }
  else{ //runs when pot0 is in its last third of 1024 bits
  allOff();
    if (1 < ledAssign(pot1) <  6) {     //Middle Cases
      for (int i = 0; i < 3; i++) {
        digitalWrite(leds[ledAssign(pot1) - i], HIGH);
        
      }
    }
    else if (ledAssign(pot1) == 0) {    //First Edge Case
      digitalWrite(leds[ledAssign(pot1)], HIGH);
      digitalWrite(leds[ledAssign(pot1) + 1], HIGH);
      digitalWrite(4,LOW);
    }
    else{                              //Second Edge Case
      digitalWrite(leds[ledAssign(pot1)], HIGH);
      digitalWrite(leds[ledAssign(pot1) - 1], HIGH);
      
    }
    
    }
   }
   
//Helper Functions
int ledAssign(int pot1) { //Assigns pot1s each eighth a single value for LEDs 0-7
  return floor(pot1 / 128);
}
void allOff() { //Iterates through array and turns off all previous lit LEDs
  for (int i = 0; i < 8; i++)
  {
    digitalWrite(leds[i], LOW);
  }
}
