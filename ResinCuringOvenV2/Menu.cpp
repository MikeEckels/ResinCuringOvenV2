#include "Menu.h"

Menu::Menu() {
	this->desiredTemp = 60;
	this->desiredTime = 15;
};

void Menu::SetDesiredTemp(unsigned int temp) {
	this->desiredTemp = temp;
}

void Menu::SetDesiredTime(unsigned int time) {
	this->desiredTime = time;
}

unsigned int Menu::GetDesiredTemp() {
	return desiredTemp;
}

unsigned int Menu::GetDesiredTime() {
	return desiredTime;
}