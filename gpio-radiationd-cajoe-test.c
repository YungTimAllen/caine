/* RadiationD-Cajoe GPIO Test Script
 * yung_tim_allen#1918, 20221008
 * 
 * Prerequisites: WiringPi 
 * 
 *     $ git clone https://github.com/WiringPi/WiringPi
 *     $ ./build
 * 
 * Compile: gcc pi_gpio.c -lwiringPi
 */
#include <stdio.h>
#include <wiringPi.h>
 
#define PIN 7 // GPIO digital pin (Pin #7 is BCM pin #4)

char FLAG = 0;

void myInterrupt() {
    FLAG++;
}
 
int main() {
	printf("RadiationD-Cajoe Test Program\n");
	
    if(wiringPiSetup() < 0) return 1;

    if(wiringPiISR(PIN, INT_EDGE_FALLING, myInterrupt) < 0) {
        printf("Cant create WiringPi ISR\n");
        return 0;
	}

    for(;;) { // blocks
        if(FLAG) {  
            while(digitalRead(PIN) == 0);
            printf("Croak\n");
            FLAG = 0;
        }  
    }
}
