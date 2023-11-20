#pragma once
#include "GlobalHeader.h"

class Ingredient
{
private:
	
	float price;

public:
	void SetPrice();
	float GetPrice();
	Ingredient(string name);
	void Print();
	bool operator== (const Ingredient& i) const {
		return (name == i.name && price == i.price);
	}
	string name;
};