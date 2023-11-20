#pragma once
#include "GlobalHeader.h"

#include "Product.h"

class Bakery
{
private:
	float cashFlow;
	std::map<Ingredient, int> stock;
	std::map<Product, int> store;
};

