  /*
  This Sketch opens a Door via a DC Motor using an Arduino Uno and the adafruit Motor shield. 
  It only opens the door, if the coorect pin code is entered in a code panel
  */

  //Includes
    #include <Wire.h>
    #include <Adafruit_MotorShield.h>
    #include "utility/Adafruit_MS_PWMServoDriver.h"
    
//Global Variables
boolean pinCorrect = false; 
boolean doorOpen = false; 
unsigned int code = 0000; // This is the pin code. It´s an u_int so theres a fuckton of possible numbers 
unsigned int enteredNum = 0000; 

    Adafruit_MotorShield motorShield =  Adafruit_MotorShield(); //Create a MS-Object
    Adafruit_DCMotor *motor = motorShield.getMotor(1); //Create a Motor Object (Connected to M1) 

void setup() {
  // put your setup code here, to run once:
    motor -> setSpeed(255); //Full Speed; Range: 0-255; 
    Serial.begin(9600); // for debuging purposes 
}

void loop() {
  // put your main code here, to run repeatedly:
pinCorrect = checkPin(); //set the global variable; 
if(pinCorrect == true && doorOpen == false)
{
  Serial.println("Opening the Door..."); // debugging
  openDoor(); 
}else if (pinCorrect == true && doorOpen == true)
{
  Serial.println("Closing the Door..."); 
  closeDoor(); 
}
 
}

bool checkPin()
{
 if(enteredNum == code) // if the entered pin == the pin
 {
  return(true);   //return a YES
 }else{
  return(false); //return a FUCK OFF
 }
}
void openDoor() //This method opens the door via the DC Motor (Cpt. Obvious strikes again) 
{

  motor ->run(FORWARD); // if the motor moves backwards, switch the wires on the board(obvioulsy...) 
  delay(10000); //10 sec, change to wanted intevall
  motor->run(RELEASE); //Stop the motor again

  Serial.println("Door opened"); 
  
}

void closeDoor() //This method closes the door via the DC Motor (No, i did not just caopy an paste openDoor. Or did i...) 
{

  motor ->run(BACKWARD); // if the motor moves forward, switch the wires on the board(obvioulsy...) 
  delay(10000); //10 sec, change to wanted intevall
  motor->run(RELEASE); //Stop the motor again

  
  Serial.println("Door closed"); 
  
}


