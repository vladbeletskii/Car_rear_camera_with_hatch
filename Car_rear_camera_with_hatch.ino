#include <ServoSmooth.h>                    //Include the servo control library.
                  
ServoSmooth servo;                          //Add a new servo to the servo class to reference it later (this will become clear on line 12).

int sign = 5;                               //Set the variable 'sign' which will be used to store the pin number to which the servo is connected.

int sign_state = 0;                         //Create a variable initialized to 0 to represent the state of the signal (initially 0).
                  
void setup() {                              //The code inside the 'setup' function runs once at the start.
              
  servo.attach(A4);                         //Set the pin to which the servo signal is connected, referencing the servo class created earlier.
  servo.setSpeed(500);                      //Set the rotation speed in arbitrary units using the servo class.
  servo.setAccel(0);                        //Set the acceleration of the servo's movement in arbitrary units using the servo class.
  pinMode(sign, INPUT);                     //Set the actual pin specified by the 'sign' variable as an input.
  pinMode(LED_BUILTIN, OUTPUT);             //Set the actual pin specified by 'LED_BUILTIN' (the built-in LED pin, typically 13) as an output.

}

void loop() {                               //The code inside the 'loop' function runs in a continuous loop, executing line by line at intervals of a few milliseconds.
 
                                            //  /Load the servo (after changing its angle, it starts moving, and there's a timer that pushes it every few milliseconds;
  servo.tick();                             // | this needs to be loaded). This line is placed at the beginning,
                                            //  \and after changes in the target angle, the code continues, and the loop restarts to load the servo again.
  
  sign_state = digitalRead(sign);           //Set the 'sign_state' variable to the value read from the pin specified by the 'sign' variable. Since this is DIGITAL read, it can only be 0 or 1.


  if (sign_state == 1) {                    //Now that we've just read the variable, if it's equal to 1,
    servo.setTargetDeg(80);                 //Set a target angle for the servo to move to (in degrees); here, it's 80 (this opens the shutter).
    digitalWrite(LED_BUILTIN, HIGH);        //In the same condition, turn on the LED by sending a HIGH signal to the LED pin.
  } else {                                  //If it's not equal to 1,
    servo.setTargetDeg(20);                 //Set a different target angle for the servo, here it's 20 (this closes the shutter).
    digitalWrite(LED_BUILTIN, LOW);         //In the same condition, turn off the LED by sending a LOW signal to the LED pin.
  }                                         //The 'loop' function of the program is complete, and it will start again from line 23.

}
