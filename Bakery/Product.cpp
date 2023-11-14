#include "Product.h"

Product::Product(string name, float price, vector<Ingredient> recipe) {
	this->name = name;
	this->price = price;
	this->recipe = recipe;
}

void Product::Print()
{
	cout << "Product : " << this->name << endl;
	cout << "Price : " << this->price << endl;
	for (int i = 0; i < this->recipe.size(); i++) {
		recipe[i].Print();
	}
}
