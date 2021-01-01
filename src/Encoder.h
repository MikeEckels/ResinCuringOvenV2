#pragma once
#include <Arduino.h>

class Encoder {
private:
	const unsigned char pinA, pinB, encoderBtn;

	volatile bool encoderDir;
	volatile long int encoderPos;
	volatile long int encoderLastPos;

	long int minVal;
	long int maxVal;
	unsigned int stepVal;

	void CheckBounds();

public:
	Encoder(const unsigned char pinA, const unsigned char pinB, const unsigned char encoderBtn);

	void Begin();
	void End();
	void Reset();
	void Update();
	//void PinISR();

	void SetMinVal(long int min);
	void SetMaxVal(long int max);
	void SetStepVal(unsigned int step);
	void SetIndex(long int pos);

	bool GetBtnState();
	bool GetDirection();
	long int GetIndex();
};
