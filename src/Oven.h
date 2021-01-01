#pragma once

class Oven {
private:
	void SetMotorState(bool state);
	void SetCuringLedState(bool state);
	void SetFanState(bool state);
	void SetHeaterVal(unsigned char val);

	void Reset();

public:
	
	void Begin();
	void End();

	void Preheat();
	void Cure();
	void Cool();
};