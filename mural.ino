#include <Adafruit_CircuitPlayground.h> 
// Declare global objects and call up additional files the program needs to use.  Declare variables and 
// assign/them to CP pin values.
int mySwitch = 21;
int wristy=10;
int leftButton=4;
int rightButton = 19;
int pin1;
int pin2;
int pin3;
int pin4;


// Things that only need to be done once at the beginning of the program. Setting up the CP device.
void setup() {
  pinMode(wristy, OUTPUT);
  pinMode(mySwitch, INPUT);
  pinMode(leftButton,INPUT);
  pinMode(rightButton,INPUT);
  Serial.begin(9600); //starts serial communication through the USB, the value is how fast the data is to be sent
  //CircuitPlayground.begin();
}


 /* Things that happen repeatedly in the program loop while the program is running. The code is executed in the order coded. */
void loop() {
  //look at (read) the current state of the switch and assign its value to a variable
  int switchValue = digitalRead(mySwitch);
  setPins(switchValue);
  
  int lbuttonValue = digitalRead(leftButton);
  int rbuttonValue = digitalRead(rightButton);
  
  // determine if the variable is HIGH, and make the wristband LED’s blink
  if (lbuttonValue == HIGH && rbuttonValue == HIGH) {
    sequenceOne();
  } 
  if (lbuttonValue == HIGH && rbuttonValue == LOW) {
    sequenceTwo();
  }
  if (lbuttonValue == LOW && rbuttonValue == HIGH) {
    sequenceThree();
  }
  if (lbuttonValue == LOW && rbuttonValue == LOW) {
    sequenceFour();
  }
}

          
// The fourth section is for functions that are called up by the third section.          
// determine if the variable is LOW, and make the wristband LED’s turn off

//Wristband Code
 void blinkWristy(){
    //CircuitPlayground.clearPixels();
    digitalWrite(wristy, HIGH);
    //CircuitPlayground.setPixelColor(0, 255,   0,   0);
    delay(500);
    digitalWrite(wristy, LOW);
    //CircuitPlayground.setPixelColor(0, 0,   0,   0);
    delay(500);
  }

  void quietWristy(){
    digitalWrite(wristy,LOW);
  }

//Mural Code

void setPins(int mode){
  if (mode == HIGH){
    //Patrick's Pins
    pin1 = 2;
    pin2 = 3;
    pin3 = 6;
    pin4 = 7;
  }else{
    pin1 = 2;
    pin2 = 3;
    pin3 = 8;
    pin4 = 11;
  }
}

void sequenceOne(){
  digitalWrite(pin1,1);
  digitalWrite(pin2,1);
  digitalWrite(pin3,1);
  digitalWrite(pin4,1);
  delay(random(100,1000));
  digitalWrite(pin1,1);
  digitalWrite(pin2,1);
  digitalWrite(pin3,1);
  digitalWrite(pin4,1);
  delay(random(100,1000));

  
}

void sequenceTwo(){
  int myLEDs[]={pin1,pin2,pin3,pin4};
  int i = 0;
  while(i < 20){
    int choice = random(4);
    digitalWrite(myLEDs[choice],1);
    delay(100);
    digitalWrite(myLEDs[choice],0);
    delay(1000);
    i++;
  }
  
}

void sequenceThree(){
  
}

void sequenceFour(){
  
}
 
