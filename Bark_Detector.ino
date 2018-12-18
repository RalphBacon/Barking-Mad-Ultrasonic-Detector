/*
 * Bark detector. Detects noise peaks (barks) that must last for a minimum time and also occur within a
 * minimum time together.
 *
 * A bark occurs for the minimum amount of time. Green.
 * Another bark occurs within X milliseconds of the first. Amber. Sound the ultrasonic for 1/2 second. (A warning).
 * A third bark occurs within X milliseconds of second bark. Red. Sound the ultrasonic for 2 seconds.
 * A fourth bark.... Start the ultrasonic sound for X seconds.
 *
 * A gap in barks occur. The barks are removed from the list as they expire.
 *
 * Rinse. Wash. Repeat.
 */

#include "Arduino.h"

// Microphone input put A0 / GPIO 14
#define mic 14

// Voltage on pin that determines a bark
#define barkTriggerLevel 100

// Bark noise in this time period considered same bark
#define barkDuration 700

// Period that defines no barking detected, in mseconds
#define quietPeriod 15000

// Have we detected a bark - stays true until reset
bool barkDetected;

// -------------------------------------------------------------------
// SETUP    SETUP     SETUP    SETUP    SETUP    SETUP    SETUP
// -------------------------------------------------------------------
void setup() {
	Serial.begin(9600);

	Serial.println("Setup Completed.");
}

// -------------------------------------------------------------------
// LOOP     LOOP     LOOP     LOOP     LOOP     LOOP     LOOP     LOOP
// -------------------------------------------------------------------
void loop() {

	// Scope of this time variable limited to this function (it is STATIC so doesn't get reinitialised every iteration)
	static unsigned long barkStarts;
	static unsigned long barkQuietPeriod = millis();

	// Continuously poll for a bark noise
	int barkLevel = analogRead(mic);

	// If noise level has exceeded trigger level, consider this a bark
	if (barkLevel > barkTriggerLevel) {
		Serial.print(barkLevel);

		// If we're not already detecting a bark period, start a new one else just continue one
		if (barkDetected) {
			Serial.println("\tBark continues");
		}
		else {
			Serial.println("New Bark detected.");
			barkStarts = millis();
		}

		// Whatever, we're still in bark-has-been-detected mode
		barkDetected = true;
	}

	// If we're in bark mode but the noise level has fallen to below trigger level check the duration of the bark
	// as we assume a bark will continue for a minimum period of time
	if (barkDetected && barkLevel < barkTriggerLevel && millis() > barkStarts + barkDuration) {
		// Barking has completed
		Serial.println("Bark completed.");
		barkDetected = false;
		barkStarts = 0;
		barkQuietPeriod = millis();
	}

	// If we haven't had a bark for X seconds reset all counters etc
	if (millis() > barkQuietPeriod + quietPeriod) {
		Serial.println("Quiet period detected - reset everything.");
		barkQuietPeriod = millis();
		//barkDetected = false;
		//barkStarts = 0;
	}

}
