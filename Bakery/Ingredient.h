#pragma once
#include "GlobalHeader.h"

class Ingredient
{
private:
	string name;
	float price;

public:
	void SetPrice();
	float GetPrice();
	Ingredient(string name);
	void Print();
};