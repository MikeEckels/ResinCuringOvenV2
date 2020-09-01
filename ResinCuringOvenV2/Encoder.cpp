#include "Encoder.h"

//Encoder* encoderPinPointer;

//static void globalPinISR() {
//	encoderPinPointer->PinISR();
//}

Encoder::Encoder(const unsigned char pinA, const unsigned char pinB, const unsigned char encoderBtn) : pinA(pinA), pinB(pinB), encoderBtn(encoderBtn) {}

void Encoder::Begin() {
	//encoderPinPointer = this;

	pinMode(pinA, INPUT_PULLUP);
	pinMode(pinB, INPUT_PULLUP);
	pinMode(encoderBtn, INPUT_PULLUP);

	//attachInterrupt(digitalPinToInterrupt(this->pinA), globalPinISR, CHANGE);
	Reset();
}

void Encoder::End() {
	//detachInterrupt(digitalPinToInterrupt(this->pinA));
}

void Encoder::Reset() {
	SetIndex(0);
}

void Encoder::Update() {
    this->encoderPos = (digitalRead(this->pinB) * 2) + digitalRead(this->pinA);;

    if (this->encoderPos != this->encoderLastPos) {
        this->encoderDir = ((this->encoderLastPos == 0) && (this->encoderPos == 1)) || ((this->encoderLastPos == 1) && (this->encoderPos == 3)) ||
            ((this->encoderLastPos == 3) && (this->encoderPos == 2)) || ((this->encoderLastPos == 2) && (this->encoderPos == 0));

		if (this->encoderDir) this->encoderPos++;
		else this->encoderPos--;
    }
    this->encoderPos = this->encoderLastPos;
	CheckBounds();
}

//void Encoder::PinISR() {
//	noInterrupts();
//
//	if (digitalRead(this->pinA)) digitalRead(this->pinB) ? this->encoderPos++ : this->encoderPos--;
//	else digitalRead(this->pinB) ? this->encoderPos-- : this->encoderPos++;
//
//	/*if (digitalRead(this->pinA)) {
//		if (digitalRead(this->pinB)) {
//			this->encoderPos = (this->encoderPos + this->minVal > this->maxVal) ? this->maxVal : this->encoderPos + this->stepVal;
//		}
//		else {
//				this->encoderPos = (this->encoderPos - this->minVal < this->minVal) ? this->minVal : this->encoderPos - this->stepVal;
//		}
//		this->encoderDir = false;
//	}
//	else {
//		if (digitalRead(this->pinB)) {
//				this->encoderPos = (this->encoderPos - this->minVal < this->minVal) ? this->minVal : this->encoderPos - this->stepVal;
//		}
//		else {
//			this->encoderPos = (this->encoderPos + this->minVal > this->maxVal) ? this->maxVal : this->encoderPos + this->stepVal;
//		}
//		this->encoderDir = true;
//	}*/
//
//	interrupts();
//}

bool Encoder::GetBtnState() {
	return digitalRead(this->encoderBtn);
}

bool Encoder::GetDirection() {
	return this->encoderDir;
}

long int Encoder::GetIndex() {
	return this->encoderPos;
}

void Encoder::SetMinVal(long int min) {
	this->minVal = min;
	CheckBounds();
}

void Encoder::SetMaxVal(long int max) {
	this->maxVal = max;
	CheckBounds();
}

void Encoder::SetStepVal(unsigned int step) {
	this->stepVal = step;
}

void Encoder::SetIndex(long int pos) {
	this->encoderPos = pos;
}

void Encoder::CheckBounds() {
	if (this->encoderPos < this->minVal) this->encoderPos = this->minVal;
	if (this->encoderPos > this->maxVal) this->encoderPos = this->maxVal;
}