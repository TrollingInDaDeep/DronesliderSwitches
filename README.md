# DronesliderSwitches
Addon PCB for FlipFloaters Hex Drone Slider

# About
FlipFloater, great DIY Synth builder (https://flipfloater.net/) created an awesome small DIY Synthesizer. It´s a 6-Tone Touch sensitive drone synth with 7 octaves per tone. The basis are six Schmitt-Triggers (Squarewaves). The pitch of each tone is adjustable and has a 4070 ring modulation and a distortion. Great Kit he offered to build at Circuit Control Festival in Dresden (https://www.circuit-control.de/)
The Synth is great and motivated me to continue building electronic projects. However my brain is never satisfied, so immediately I started thinking about how to mod this beautiful machine and render it possibly even more useful for making Music.
The Idea was, that, like an actual drone synth, you don´t need to play it, instead you can fade in and out each of the 6 Voices. This should make the sounds much more spheric and ambient. With switches I wanted to be able to toggle each of the 7 Voice Octaves. 
As it should be quite an easy project I thought it was time to design this as my first PCB.

# Circuit
The DroneSlider has 6 Pads, one for each Voice. The pads consist of Metal plates, that you touch with your finger. The flowing Electricity enables every Octave: Small pad means +Voltage, Large Pad connects to each octave. the Circuit has Solder Pads, that are soldered onto the Original DroneSlider to connect to. These Pads are then connected again to DIP Switches, with which you can switch every Octave on and off. Between the +Voltage and each "Receiver Pad" I added a Potentiometer, to gradually fade in each voice.
Also added in the Circuit is a CD4051BE Multiplexer, Which could be used to make this thing a 6 step multiplexer! Insane, right?


# Design
The Circuit and PCB were designed using EasyEDA, an online tool to create these things and order them directly for manufacturing. Both export files are in the EasyEDA/ folder in this repo. You can simply import these .JSON files into the EasyEDA designer (free account needed) and modify them as you wish.
At the end, you have to create Gerber files, they contain all the PCB Traces, drill holes, solder pads and writing. These you can then upload to EasyEDA and order them.
If you edit the .JSON files, you need to create the Gerber files again and upload them. Of course, you can use any design tool and PCB manufacturing service you want, as long as the files are compatible.
![3D Render](/3D_Render.png)

# Assembly
