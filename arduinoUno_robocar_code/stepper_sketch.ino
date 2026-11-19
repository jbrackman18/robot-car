#include <Stepper.h>


const int stepsPerRev = 2048; // total steps per revolution
const int rpm = 10; // top speed for the stepper motors; any higher causes a stall
Stepper leftWheel (stepsPerRev, 4, 6, 5, 7);
Stepper rightWheel (stepsPerRev, A0, A2, A1, A3);

void setup() {
  leftWheel.setSpeed(rpm);
  rightWheel.setSpeed(rpm);

}

void loop() {
  
  // if button gets pressed, start moving forward; 'true' placeholder until we get the remote set up
  if (true) {
    leftWheel.step(1); // replace 1 with stepsPerRev? or a smaller number
    rightWheel.step(-1);
  }

}
