#pragma once
#include "GlobalHeader.h"

#include "Product.h"

class Bakery
{

public:
	Bakery(float cash);
	bool Bankrupt();
	float cashFlow;
	std::map<Ingredient, int> stock;
	std::map<Product, int> store;
};

