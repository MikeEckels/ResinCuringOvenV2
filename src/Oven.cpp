#include "Oven.h"
#include "PinDefs.h"
#include "Arduino.h"

void Oven::Begin() {
	pinMode(sensorPin, INPUT);
	pinMode(heaterPin, OUTPUT);
	pinMode(curingLedPin, OUTPUT);
	pinMode(fanPin, OUTPUT);
	pinMode(motorPin, OUTPUT);
	pinMode(panelLed, OUTPUT);
	pinMode(unusedRelay, OUTPUT);

	Reset();
}

void Oven::End() {
	Reset();
}

void Oven::Reset() {
	SetFanState(0);
	SetHeaterVal(0);
	SetMotorState(0);
	SetCuringLedState(0);
}

void Oven::Preheat() {

}

void Oven::Cure() {

}

void Oven::Cool() {

}

void Oven::SetMotorState(bool state) {
	digitalWrite(motorPin, !state);
}

void Oven::SetCuringLedState(bool state) {
	digitalWrite(curingLedPin, !state);
}

void Oven::SetFanState(bool state) {
	digitalWrite(fanPin, !state);
}

void Oven::SetHeaterVal(unsigned char val) {
	analogWrite(heaterPin, val);
}