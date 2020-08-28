#include "Encoder.h"

Encoder::Encoder(const unsigned char pinA, const unsigned char pinB, const unsigned char encoderBtn) : pinA(pinA), pinB(pinB), encoderBtn(encoderBtn) {}

void Encoder::Begin() {
	pinMode(pinA, INPUT_PULLUP);
	pinMode(pinB, INPUT_PULLUP);
	pinMode(encoderBtn, INPUT_PULLUP);

	attachInterrupt(digitalPinToInterrupt(pinA), PinA, CHANGE);
	attachInterrupt(digitalPinToInterrupt(pinB), PinB, CHANGE);
}

void Encoder::End() {

}

bool Encoder::GetDirection() {
	bool direction;

	if (this->encoderPos > this->lastPos) {
		direction = 1;
	}
	else if (this->encoderPos < this->lastPos) {
		direction = 0;
	}

	this->lastPos = this->encoderPos;
	return direction;
}

unsigned int Encoder::GetIndex() {
	static unsigned int index = 0;
	this->rotating = true;

	if (this->lastPos != this->encoderPos) {
		index = this->encoderPos;
	}

	this->lastPos = this->encoderPos;
	return index;
}

void Encoder::Reset() {
	this->encoderPos = 0;
}

void Encoder::PinA() {
	if (this->rotating) delay(1);

	if (digitalRead(this->pinA) != this->A_set) {
		this->A_set = !this->A_set;

		if (this->A_set && !this->B_set) {
			this->encoderPos = (this->encoderPos + this->minVal > this->maxVal) ? this->maxVal : this->encoderPos + this->stepVal;
		}

		this->rotating = false;
	}
}

void Encoder::PinB() {
	if (this->rotating) delay(1);

	if (digitalRead(this->pinB) != this->B_set) {
		this->B_set = !this->B_set;

		if (this->B_set && !this->A_set && ((int)this->encoderPos - (int)this->stepVal) > 0) {
			this->encoderPos = (this->encoderPos - this->minVal < this->minVal) ? this->minVal : this->encoderPos - this->stepVal;
		}

		this->rotating = false;
	}
}

void Encoder::SetMinVal(unsigned int min) {
	this->minVal = min;
}

void Encoder::SetMaxVal(unsigned int max) {
	this->maxVal = max;
}

void Encoder::SetStepVal(unsigned int step) {
	this->stepVal = step;
}