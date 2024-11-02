#include "Mux.h" // Multiplexer library called "Analog-Digital Multiplexers" https://github.com/stechio/arduino-ad-mux-lib
#include "time.h"
using namespace admux;


/*
  Code written by trollingInDaDeep
  November 2024
  DroneSliderSwitches Addon PCB for flipfloater's DroneSlider
  Code controls the optional Sequencer that can be added to the drone.
  
*/

// Connect  Multiplexer select lines to Pins 7, 8 and 9
Mux seqMux(Pinset(7, 8, 9));

int tempo = 200; //time in ms between seq steps
int numSteps = 6; //number of steps
int gateLength = 50; // how long a note is played
long stepStart = 0; //time in ms when the step starts
long noteStart = 0; // time in ms when a note is started
byte step = 0; //which step are we at currently

void setup() {
  Serial.begin(9600);
}

void loop() {

  // if tempo ms time has passed
  if ((millis() - stepStart) > tempo) {
    stepStart = millis(); //initialize the start time
    seqMux.channel(step); //select which output the mux input is connected to
    noteStart = millis(); //initialize note start time
    Serial.println(step); //For debugging, print out number
    step = (step+1) % numSteps; //increase step pointer by 1, wrap and start at 0 when numSteps reached
  }

  //if gate ms time has passed since note start
  if ((millis() - noteStart) > gateLength) {
    //Select mux pin 7, will not produce sound by default
    seqMux.channel(7);
  }
}
