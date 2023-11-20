#include "Ingredient.h"

// Sets the price between 0.20 and 1.00€
void Ingredient::SetPrice() {
	price = 0.2f + (rand() % 80) / 100;
}

float Ingredient::GetPrice() {
	return price;
}

Ingredient::Ingredient(string name) {
	this->name = name;
	this->price = 0.2f;
}

void Ingredient::Print()
{
	cout << "Ingredient : " << this->name << " : " << this->price << endl;
}