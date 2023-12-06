#pragma once

#include <vector>
#include <string>

#include "Product.h"
#include "Ingredient.h"

class Product
{
	friend bool operator<(const Product& l, const Product& r) {
		return l.price < r.price;
	}

public:
	std::string name;
	float price;
	std::vector<Ingredient> recipe;
	Product(std::string name, float price, std::vector<Ingredient> recipe);
	void Print();
};