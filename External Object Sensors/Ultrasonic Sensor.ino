
/*
 * This is code for an HC-SR04 ultrasoinic sensor useing an arduino.
 */


// define variables and set up pins (do not have to be PWM)
int trigger = 10; 
int echo = 9; 

// define variables to hold distance 
int duration = 0; 
float distance = 0.0; 


void setup() {
  
Serial.begin(9600); // set up ther serial monitor

// setup utrasonic sensor pin types
pinMode(trigger, OUTPUT); 
pinMode(echo, INPUT); 

}

void loop() {

  //turn off sensor 
  digitalWrite(trigger, LOW);         // turn off ping    
  delayMicroseconds(2);              // wait 2 microseconds 

  //send trigger ping 
  digitalWrite(trigger ,HIGH);        // send ping 
  delayMicroseconds(10);             // wait 10 microseconds 
  digitalWrite(trigger, LOW);         // turn off ping 

  //get data and calculate distance 
  duration = pulseIn(echo, HIGH);       // receive ping 
  distance = ((float)(duration))/58.2;  // calculate ping 

  //display distance on serial monitor when the Arduino is plugged in 
  Serial.print("distance = ");       //tell the serial monitor to say distance = 
  Serial.print(distance);            //print the distance on the same line
  Serial.println(" cm");             //print the label: cm and make a new line 

}
