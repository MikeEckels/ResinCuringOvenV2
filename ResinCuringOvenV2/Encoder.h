#pragma once
#include <Arduino.h>

class Encoder {
private:
	const unsigned char pinA, pinB, encoderBtn;

	bool A_set = false;
	bool B_set = false;
	bool rotating;
	unsigned int lastPos = 1;
	volatile unsigned int encoderPos = 0;

	unsigned int minVal;
	unsigned int maxVal;
	unsigned int stepVal;

public:
	Encoder(const unsigned char pinA, const unsigned char pinB, const unsigned char encoderBtn);

	void Begin();
	void End();
	void SetMinVal(unsigned int min);
	void SetMaxVal(unsigned int max);
	void SetStepVal(unsigned int step);
	void SetIndex(unsigned int pos);
	bool GetDirection();
	unsigned int GetIndex();
	void Reset();
	void PinAISR();
	void PinBISR();
};
