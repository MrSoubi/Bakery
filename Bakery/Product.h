#pragma once
#include "GlobalHeader.h"

#include "Ingredient.h"

class Product
{
	friend bool operator<(const Product& l, const Product& r) {
		return l.price < r.price;
	}

private:
	string name;
	float price;
	vector<Ingredient> recipe;

public:
	Product(string name, float price, vector<Ingredient> recipe);
	void Print();
};