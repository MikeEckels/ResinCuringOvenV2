#include "Encoder.h"

const unsigned char encoderPinA = 2;
const unsigned char encoderPinB = 3;
const unsigned char encoderBtnPin = 4;

unsigned int maxEncoderVal = 120;
unsigned int minEncoderVal = 15;
unsigned int encoderStepVal = 15;

Encoder encoder(encoderPinA, encoderPinB, encoderBtnPin);

void setup() {
	encoder.Begin();
	encoder.SetMinVal(minEncoderVal);
	encoder.SetMaxVal(maxEncoderVal);
	encoder.SetStepVal(encoderStepVal);

	encoder.Reset();
}


void loop() {
  
}
