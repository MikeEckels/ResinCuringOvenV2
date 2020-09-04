#pragma once

class Menu {
private:

public:
	void SetDesiredTemp(unsigned int);
	void SetDesiredTime(unsigned int);

	unsigned int GetDesiredTemp();
	unsigned int GetDesiredTime();
};
