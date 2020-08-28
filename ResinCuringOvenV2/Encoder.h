#pragma once

class Encoder {
private:
	const unsigned char pinA, pinB, encoderBtn;

	bool A_set = false;
	bool B_set = false;
	static bool rotating;
	unsigned int lastPos = 1;
	volatile unsigned int encoderPos = 0;

	unsigned int minVal;
	unsigned int maxVal;
	unsigned int stepVal;

	void PinA();
	void PinB();

public:
	Encoder(const unsigned char pinA, const unsigned char pinB, const unsigned char encoderBtn);

	void Begin();
	void End();
	void SetMinVal(unsigned int min);
	void SetMaxVal(unsigned int max);
	void SetStepVal(unsigned int step);
	bool GetDirection();
	unsigned int GetIndex();
	void Reset();
};
