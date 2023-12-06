#pragma once

#include <map>

#include "Product.h"
#include "Ingredient.h"

class Bakery
{

public:
	Bakery();
	Bakery(float cash);
	bool Bankrupt();
	float cashFlow;
	std::map<Ingredient, int> stock;
	std::map<Product, int> store;
};