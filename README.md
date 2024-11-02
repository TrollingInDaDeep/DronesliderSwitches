##### Table of Contents  
[About](#About)

[Sound Examples](#Sound-Examples)

[Circuit](#Circuit)

[Design](#Design)

[How it works](#How-it-works)

[Assembly](#Assembly)

[Sequencer](#Sequencer)

[Issues](#Issues)

# DronesliderSwitches
Addon PCB for FlipFloaters Hex Drone Slider

# About
FlipFloater, great DIY Synth builder (https://flipfloater.net/) created an awesome small DIY Synthesizer. It´s a 6-Tone Touch sensitive drone synth with 7 octaves per tone. The basis are six Schmitt-Triggers (Squarewaves). The pitch of each tone is adjustable and has a 4070 ring modulation and a distortion. Great Kit he offered to build at Circuit Control Festival in Dresden (https://www.circuit-control.de/).
The Synth is genius and motivated me to continue building electronic projects. However my brain is never satisfied, so immediately I started thinking about how to mod this beautiful machine and render it possibly even more useful for making Music.
The Idea was, that, like an actual drone synth, you don´t need to play it, instead you can fade in and out each of the 6 Voices. This should make the sounds much more spheric and ambient. With switches I wanted to be able to toggle each of the 7 Voice Octaves. 
As it should be quite an easy project I thought it was time to design this as my first PCB.

# Sound examples:

Drone without effects
https://github.com/TrollingInDaDeep/DronesliderSwitches/raw/refs/heads/main/Audio/drone_raw.wav

Drone with effects
https://github.com/TrollingInDaDeep/DronesliderSwitches/raw/refs/heads/main/Audio/drone_with_effects.wav

Just the sequencer switching through the voices
https://github.com/TrollingInDaDeep/DronesliderSwitches/raw/refs/heads/main/Audio/SEQ_raw.mov

Sequencer switching through, but disabling the note after 50ms gate time. Bit more musical
https://github.com/TrollingInDaDeep/DronesliderSwitches/raw/refs/heads/main/Audio/SEQ_with_gate_raw.mov

Now with added effects (Filter and Reverb/Delay)
https://github.com/TrollingInDaDeep/DronesliderSwitches/raw/refs/heads/main/Audio/SEQ_with_effects.mov

# Circuit
The DroneSlider has 6 Pads, one for each Voice. The pads consist of Metal plates, that you touch with your finger. The flowing Electricity enables every Octave: Small pad means +Voltage, Large Pad connects to each octave. the Circuit has Solder Pads, that are soldered onto the Original DroneSlider to connect to. These Pads are then connected again to DIP Switches, with which you can switch every Octave on and off. Between the +Voltage and each "Receiver Pad" I added a Potentiometer, to gradually fade in each voice.
Also added in the Circuit is a CD4051BE Multiplexer, Which could be used to make this thing a 6 step multiplexer! Insane, right?


# Design
The Circuit and PCB were designed using EasyEDA, an online tool to create these things and order them directly for manufacturing. Both export files are in the EasyEDA/ folder in this repo. You can simply import these .JSON files into the EasyEDA designer (free account needed) and modify them as you wish.
At the end, you have to create Gerber files, they contain all the PCB Traces, drill holes, solder pads and writing. These you can then upload to EasyEDA and order them.
If you edit the .JSON files, you need to create the Gerber files again and upload them. Of course, you can use any design tool and PCB manufacturing service you want, as long as the files are compatible.
![3D Render](/3D_Render.png)

# How it works
Here´s the Pinout of the DroneSlider. Each voice has 7 Octaves. The Thin pads are all connected to the + Voltage, the Thick pads when receiving voltage, will play the dialed tone for that voice in 7 different octaves (voltage is always halved to get one octave lower).
![PCB_Comparison](./images/pinout.jpg)

The addon board features for each voice 1 Potentiometer to dial the volume of the voice and a DIP switch. The DIP switch 1 enables or disables the voice. The other 2-7 switches will enable / disable each octave of the voice.
Like this you can enable and disable each voice, set which octaves are played and mix the volume of each voice. This gives you a drone-y sound. Best coupled with a few effects (filters, delays, reverbs) to get crazy and awesome sounds.

There is a 3 pin header to switch between 2 modes: Drone and SEQ. If connecting the lower 2 Pins with a jumper, you are in Drone mode, where the 1st voice and all others act as drone voices. By selecting SEQ mode, the sequencer is activated. More on that below: [Sequencer](#Sequencer)


# Assembly
The blank PCB arrived and looked beautiful. Inspect it for errors and admire your work!
![PCB_Comparison](./images/blank_pcb.jpg)

Start with attaching the PCBs to each other first. I did the mistake to first populate the PCB with the potentiometers and well, what can I say, I burned them with my solder iron.

1. Align the pins of the addon board with the Main DroneSlider board. Make the lowest Pad match.
   Blue: connect the Thick pads (and the lowest thin pad)
   Red: Don´t connect he other thin pads
   Red dotted: The uppermost thin pad on the main board will not be seen (and not connected)
   
![PCB_Comparison](./images/align.jpg)

3. Clamp the boards in place so they don´t slip and you can solder in peace. Solder upper left and lower right corner first for stability.
   
![PCB_Comparison](./images/clamp.jpg)

5. Solder the Pads together. This is a Pain I tell you. I first tried to bridge by just using a lot of solder, this worked sometimes but not very convenient and fiddly.
   I then tried to make small wires (2mm or so) and bend them in a 90° angle. Then, using pliers, solder one end to the upper pad first, keep holding the wire and also solder to the lower pad.
   The solder joints look absolutely horrible and I don´t know if the connections are good, but it´s the best I could get to work. For easier installation it´s probably needed to find a different solution for connecting the pads.

   ![PCB_Comparison](./images/bridges_1.jpg)
   ![PCB_Comparison](./images/Bridges_2.jpg)

6. Solder a Wire from the GND pad to a GND on the main board. I soldered it to the GND ring on the backside.
   
   ![PCB_Comparison](./images/GND_Wire_1.jpg)
   ![PCB_Comparison](./images/GND_Wire_2.jpg)
   ![PCB_Comparison](./images/GND_Wire_side.jpg)

8. Solder the parts in, from smallest to tallest. First the IC socket, then the DIP switch and lastly the potentiometers. Always solder one pin, so the part holds in place, then reheat the solder and push it in straight position.
   Then continue to solder all pins. Lastly solder the 3 Pin header in.

   ![PCB_Comparison](./images/parts_order.jpg)
   ![PCB_Comparison](./images/Header.jpg)

10. Modify the jack socket (optional)
   I found, that I usually only have stereo jack cables laying around. By connecting them to the socket of the droneslider you will only get sound on one channel. To simply "clone" the audio signal to both channels, just add a small bridging wire.
   Be careful to not melt the jack socked, as this would suck.

   ![PCB_Comparison](./images/Jack_Mod.jpg)

11. Backplate
    Add a Backplate for stability. I don't know how good the connection between the two boards is, electrically and physically. Adding a backplate makes it more rigid and you're not afraid of breaking something off.
![PCB_Comparison](./images/backplate1.jpg)

![PCB_Comparison](./images/backplate1.jpg)

12. Additional tips:
   - Clean the surface with some nail polish or alcohol cleaner, but don´t spill it all over your desk
   - Don´t burn the potentiometers with your solder iron
   - when desoldering your previous modifications, don´t rip off one of the pads like I did
   - It´s a fiddly job, don´t loose patience and take breaks if needed
   - The Mixing potentiometers behave a bit strange. When a voice is enabled, you should turn up the pot at least a little bit, otherwise none of the voices will be heard. I used linear pots, which are sub-optimal for audio usage, but they work quite okay with this strange behavior.

# Sequencer
Using a CD4051BE Multiplexer, this thing can be turned into a fresh 6-step Sequencer! You just need a microcontroller like an arduino. It needs 3 digital pins to select one of the Multiplexer's outputs.
1. Solder cables to the pads on the PCB and connect them to the Microcontroller. I used an arduino UNO for testing.
Connect the Pads E#, VE, VSS, GND and Y7 together. These will all be connected to GND of the Microcontroller. Why, you ask?
The E#, VE and VSS make sure the Multiplexer is grounded and enabled.
The GND pad connects it to the GND of the DroneSlider, maybe this is a mistake, it could also work without this and it could even prevent noise.
The Y7 Pin is not used, as we only have 6 steps. By connecting it to GND, we get an additional "silent" step. So if you want to implement silence, a gate time (after which a note stops) etc. just select this pin. -> See example in the code.
![PCB_Comparison](./images/seqConnect_arduino.jpg)

Would've been more convenient to connect with a connector if I had not gone with solder pads but just a pin header instead. Can be easily changed in the PCB schematics though.

3. Upload the code to your microcontroller. Example can be found in the repo. You could add potentiometers to control the tempo and gate length of your sequencer. Or just do all kinds of wonky things.
4. Connect the SEQ pins together with the jumper to activate it.
5. Switch off all voices exept the 1st one in SEQ mode. Or you will have a constant sidetone... hmm, might give us interesting results.
6. To keep track of which step is currently active, you could add some LEDs


# Issues
- On Voice 4, the octaves 5 and 6 are reversed. Probably connection error in the schematic. Blame me if you want.
- The synth gets louder when connecting the Microcontroller. I gues this might be caused by the additional voltage of the Microcontroller. I'm not sure if this is irrelevant, bad practice or plain out stupid and doing damage. Smelled no smoke yet.
