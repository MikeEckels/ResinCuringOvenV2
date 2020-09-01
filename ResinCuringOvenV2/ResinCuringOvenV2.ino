#include "PID.h"
#include <Wire.h>
#include "Encoder.h"
#include "WatchDog.h"
#include "KalmanFilter.h"
#include "Adafruit_MCP9808.h"
#include "LiquidCrystal_I2C.h"

const unsigned char encoderPinA = 2;
const unsigned char encoderPinB = 3;
const unsigned char encoderBtnPin = 4;

long int maxEncoderVal = 120;
long int minEncoderVal = 15;
long int encoderStepVal = 15;

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
	encoder.Update();
	//Serial.println(encoder.GetIndex());
	delay(100);
}
