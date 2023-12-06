#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Product.h"

Product::Product(std::string name, float price, std::vector<Ingredient> recipe) {
	this->name = name;
	this->price = price;
	this->recipe = recipe;
}

void Product::Print()
{
	std::cout << "Product : " << this->name << std::endl;
	std::cout << "Price : " << this->price << std::endl;
	for (int i = 0; i < this->recipe.size(); i++) {
		recipe[i].Print();
	}
}