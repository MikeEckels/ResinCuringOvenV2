#include "Encoder.h"

Encoder* encoderPointerA;
//Encoder* encoderPointerB;

static void globalISRa() {
	encoderPointerA->PinAISR();
}

/*
static void globalISRb() {
	encoderPointerB->PinBISR();
}
*/

Encoder::Encoder(const unsigned char pinA, const unsigned char pinB, const unsigned char encoderBtn) : pinA(pinA), pinB(pinB), encoderBtn(encoderBtn) {}

void Encoder::Begin() {
	encoderPointerA = this;
	//encoderPointerB = this;

	pinMode(pinA, INPUT_PULLUP);
	pinMode(pinB, INPUT_PULLUP);
	pinMode(encoderBtn, INPUT_PULLUP);

	attachInterrupt(digitalPinToInterrupt(this->pinA), globalISRa, CHANGE);
	//attachInterrupt(digitalPinToInterrupt(this->pinB), globalISRb, CHANGE);
}

void Encoder::End() {
	detachInterrupt(digitalPinToInterrupt(this->pinA));
	//detachInterrupt(digitalPinToInterrupt(this->pinB));
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
	/*static unsigned int index = 0;
	this->rotating = true;

	if (this->lastPos != this->encoderPos) {
		index = this->encoderPos;
	}

	this->lastPos = this->encoderPos;
	return index;*/
	return this->encoderPos;
}

void Encoder::Reset() {
	SetIndex(0);
}

void Encoder::PinAISR() {
	/*if (this->rotating) delay(1);

	if (digitalRead(this->pinA) != this->A_set) {
		this->A_set = !this->A_set;

		if (this->A_set && !this->B_set) {
			this->encoderPos = (this->encoderPos + this->minVal > this->maxVal) ? this->maxVal : this->encoderPos + this->stepVal;
		}

		this->rotating = false;
	}*/

	if (digitalRead(this->pinA)) digitalRead(this->pinB) ? this->encoderPos++ : this->encoderPos--;
	else digitalRead(this->pinB) ? this->encoderPos-- : this->encoderPos++;
}

//void encoder::pinbisr() {
//	if (this->rotating) delay(1);
//
//	if (digitalread(this->pinb) != this->b_set) {
//		this->b_set = !this->b_set;
//
//		if (this->b_set && !this->a_set && ((int)this->encoderpos - (int)this->stepval) > 0) {
//			this->encoderpos = (this->encoderpos - this->minval < this->minval) ? this->minval : this->encoderpos - this->stepval;
//		}
//
//		this->rotating = false;
//	}
//}

void Encoder::SetMinVal(unsigned int min) {
	this->minVal = min;
}

void Encoder::SetMaxVal(unsigned int max) {
	this->maxVal = max;
}

void Encoder::SetStepVal(unsigned int step) {
	this->stepVal = step;
}

void Encoder::SetIndex(unsigned int pos) {
	this->encoderPos = pos;
}