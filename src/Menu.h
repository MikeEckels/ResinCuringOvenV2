#pragma once

class Menu {
private:

public:
	unsigned int desiredTemp;
	unsigned int desiredTime;

	Menu();
	void SetDesiredTemp(unsigned int);
	void SetDesiredTime(unsigned int);

	unsigned int GetDesiredTemp();
	unsigned int GetDesiredTime();
};
