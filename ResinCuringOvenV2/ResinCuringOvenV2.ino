#include "PID.h"
#include <Wire.h>
#include "Menu.h"
#include "Oven.h"
#include "Encoder.h"
#include "PinDefs.h"
#include "WatchDog.h"
#include "KalmanFilter.h"
#include "Adafruit_MCP9808.h"
#include "LiquidCrystal_I2C.h"

long int maxEncoderVal = 120;
long int minEncoderVal = 15;
long int encoderStepVal = 15;

Menu menu;
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
