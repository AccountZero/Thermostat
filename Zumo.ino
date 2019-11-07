
/*This is the zumo robot code*/
#include <Wire.h>
#include <Zumo32U4.h>

// This might need to be tuned for different lighting conditions,
// surfaces, etc.
#define QTR_THRESHOLD     1000  // microseconds

// These might need to be tuned for different motor types.
#define REVERSE_SPEED     350  // 0 is stopped, 400 is full speed
#define TURN_SPEED        300
#define FORWARD_SPEED     400
#define REVERSE_DURATION  200  // ms
#define TURN_DURATION     500  // ms
#define BATTLE_DURATION   96000   // s

Zumo32U4LCD lcd;
Zumo32U4ButtonA buttonA;
Zumo32U4Buzzer buzzer;
Zumo32U4Motors motors;
Zumo32U4LineSensors lineSensors;


 
 

#define NUM_SENSORS 3
unsigned int lineSensorValues[NUM_SENSORS];

void waitForButtonAndCountDown()
{
  ledYellow(1);
  lcd.clear();
  lcd.print(F("Press A"));

  buttonA.waitForButton();

  ledYellow(0);
  lcd.clear();

  // Play audible countdown.
  for (int i = 0; i < 5; i++)
  {
    delay(1000);
    buzzer.play(">c7");
  }
}

void setup()
{
  // Uncomment if necessary to correct motor directions:
  //motors.flipLeftMotor(true);
  //motors.flipRightMotor(true);

  lineSensors.initThreeSensors();

  waitForButtonAndCountDown();

}


void loop()
 
{
  for(int i=0; i>1170000; i++){
 

 
    if (buttonA.isPressed())
    {
   

       
     
      // If button is pressed, stop and wait for another press to
      // go again.
      motors.setSpeeds(0, 0);
      buttonA.waitForRelease();
      waitForButtonAndCountDown();

   
    }

 
   
    lineSensors.read(lineSensorValues);
 
    if (lineSensorValues[0] < QTR_THRESHOLD)
    {
      // If leftmost sensor detects line, reverse and turn to the
      // right.
      motors.setSpeeds(-REVERSE_SPEED, -REVERSE_SPEED);
      delay(REVERSE_DURATION);
      motors.setSpeeds(TURN_SPEED, -TURN_SPEED);
      delay(TURN_DURATION);
      motors.setSpeeds(FORWARD_SPEED, FORWARD_SPEED);
    }
    else if (lineSensorValues[NUM_SENSORS - 1] < QTR_THRESHOLD)
    {
      // If rightmost sensor detects line, reverse and turn to the
      // left.
      motors.setSpeeds(-REVERSE_SPEED, -REVERSE_SPEED);
      delay(REVERSE_DURATION);
      motors.setSpeeds(-TURN_SPEED, TURN_SPEED);
      delay(TURN_DURATION);
      motors.setSpeeds(FORWARD_SPEED, FORWARD_SPEED);
    }
    else
    {
      // Otherwise, go straight.
      motors.setSpeeds(FORWARD_SPEED, FORWARD_SPEED);
    }
 
  }
  shutdown;
}

void shutdown(){
  Serial.print("Stopped");
  while(1);
}
