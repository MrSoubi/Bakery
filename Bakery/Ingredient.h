#pragma once

#include <string>

#include "Ingredient.h"

class Ingredient
{
private:
	
	float price;

public:
	void SetPrice();
	float GetPrice();
	Ingredient(std::string name);
	void Print();
	bool operator== (const Ingredient& i) const {
		return (name == i.name && price == i.price);
	}

	constexpr bool operator<(const Ingredient& l) const {
		return (l.price > price);
	}

	std::string name;
};