#include "PID.h"
#include <Wire.h>
#include "Encoder.h"
#include "WatchDog.h"
#include "KalmanFilter.h"
#include "Adafruit_MCP9808.h"
#include "LiquidCrystal_I2C.h"

const unsigned char encoderPinA = 2;
const unsigned char encoderPinB = 3;
const unsigned char encoderBtnPin = 7;

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

	Serial.begin(115200);
}


void loop() {
	Serial.println(encoder.GetIndex());
	delay(50);
}