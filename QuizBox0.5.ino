
#include <Adafruit_TLC5947.h>

#define NUM_TLC5974 1
#define data   MOSI
#define clock   SCK
#define latch   SS
#define oe  -1  // set to -1 to not use the enable pin (its optional)
// Init TLC5947
Adafruit_TLC5947 tlc = Adafruit_TLC5947(NUM_TLC5974, clock, data, latch);

int R = 150;
int G = 150;
int B = 150;



struct Quizzer
{
	int seat; // pin number to read
	int slide; // disable switch to read
	int led; // in the name

	bool standing; // last read seat
	bool enabled; // last read slide

	bool softDisabled;

	Quizzer(int seatIn, int slideIn, int ledIn) {
		seat = seatIn;
		slide = slideIn;
		led = ledIn;

		standing = readSeat();
		enabled = readSlide();
		softDisabled = false;
	}
	Quizzer() {
		seat = 0;
		slide = 0;
	}

	// returns if changed NOT what the value is
	bool readSeat() {
		bool reading = !digitalRead(seat);
		if (reading != standing) {
			standing = reading;
			return true;
		};
		return false;

	}
	
	// returns if changed NOT what the value is
	bool readSlide() {
		bool reading = !digitalRead(slide);
		if (reading != enabled) {
			enabled = reading;
			return true;
		}
		return false;
	}
	
};

Quizzer quizzers[5] = {
	{3, 8 , 1},
	{4, 9 , 2},
	{5, 14, 3},
	{6, 15, 4},
	{7, 16, 5},
};

int activeQuizzer = -1;

// 0: Unlocked
// 1: armed
// 2: triggered
int boxState = 0;

bool tlcFlag = false;

void setup() {
	Serial.begin(9600);
	delay(2000);

	// set buzzer to off
	// initilize leds

	// Serial.println(quizzers[2].seat);

}

void loop() {
	switch (boxState) {
		case 0: // Box is unlocked.
			for (int quizzer = 0; quizzer < 5; quizzer ++) {
				quizzers[quizzer].readSlide();

				if (quizzers[quizzer].enabled) {

					// if quizzer.standing changed, tlcFlag = true
					tlcFlag = quizzers[quizzer].readSeat();

					if (quizzers[quizzer].standing) {
						tlc.setLED(quizzers[quizzer].led, R,G,B);
					} else {
						tlc.setLED(quizzers[quizzer].led, 0,0,0);
					}

				} else {

					tlc.setLED(quizzers[quizzer].led, 0,0,0); 

				};
				
				
			}
			break;
		
		case 1: // Box is armed
			for (int quizzer = 0; quizzer < 5; quizzer ++) {
				quizzers[quizzer].readSlide();
				if (quizzers[quizzer].enabled) {
					// if quizzer.standing changed, tlcFlag = true
					tlcFlag = quizzers[quizzer].readSeat();

					if (quizzers[quizzer].standing) {
						tlc.setLED(quizzers[quizzer].led, R,G,B);
						// Beep
						// Start Timer
						// enable light
						boxState = 2;
						break;
					}
				}
			}
			break;

		case 2:
			break;

		default:
			break;
	}
	if (tlcFlag) {tlc.write();};
}