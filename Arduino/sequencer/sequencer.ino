#include "Mux.h"
#include "time.h"
using namespace admux;


/*
  Code written by trollingInDaDeep
  November 2024
  DroneSliderSwitches Addon PCB for flipfloater's DroneSlider
  Code controls the optional Sequencer that can be added to the drone.
  
*/

Mux seqMux(Pinset(7, 8, 9));
int tempo = 200; //time in ms between seq steps
int numSteps = 6;
int gateLength = 50;
long stepStart = 0;
long noteStart = 0;
byte step = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {

  

  if ((millis() - stepStart) > tempo) {
    stepStart = millis();
    seqMux.channel(step);
    noteStart = millis();
    Serial.println(step);
    step = (step+1) % numSteps;
  }

  if ((millis() - noteStart) > gateLength) {
    //todo disable mux to implement gate
    seqMux.channel(7);
  }
}
