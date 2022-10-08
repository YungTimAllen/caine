# caine
### *RadiationD-Cajoe for TRNG on Raspian* [**WIP**]

## Notes 
* RadiationD-Cajoe board doesnt need a voltage divider - the VIN pin outputs 3.3v, confirmed with multimeter.
* The VIN pin is the pulse pin. Naming isnt intuitive. 
* This project uses Pin #7 (BCM2835 pin #4) for GPIO reading - connect the VIN pin on the board to this.
* Have also got Pin read working in C with bcm2835.h, but WiringPi is cleaner and supports events.
* Pretty much every WiringPi event example uses an address operator on the callback function pointer given in parameter 3 of `wiringPiISR()`. I removed the operator and the callback function started working.
* The C code is inspired by [this example](https://www.waveshare.com/wiki/Raspberry_Pi_Tutorial_Series:_External_Button).
* Existing examples of writing a kernel module to ingest measurements from a geiger on a Pi [[kRad](https://github.com/brendan-w/kRad)] used a different board to the RadiationD-Cajoe.

## Progress
* GPIO event POC in Python3 and C

## Next-Steps
* Acquire a source of beta radiation - Stronium 90 (like kRad uses) is hard to acquire in the UK, so I'll probably smash up some Radium glass or dismantle a smoke detector.
* Kernel Module for hardware rng sources to feed /dev/random
* Make files and other QoL stuff.
