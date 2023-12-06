#pragma once

#include <ctime>
#include <string>
#include <vector>
#include <iostream>

#include "Bakery.h"
#include "Utils.h"
#include "main.h"

std::vector<Product> products;
std::vector<Ingredient> ingredients;
Bakery player;

int main() {
	// Initialize random seed
	srand(time(0));

	char path[] = "Cookbook.xml";
	products = Utils::ReadXML(path);
	ingredients = Utils::ReadXML_Ingredients(path);
	int day = 1;

	player = Bakery(50.0f);

	while (!player.Bankrupt()) {
		// Set ingredients prices
		for (int i = 0; i < ingredients.size(); i++) {
			ingredients[i].SetPrice();
		}

		// Buy ingredients
		// ENTERING FULL TRASH MODE

		// Needs to be changed, I should use class methods instead and keep only the logic here.
		bool isBuyingIngredients = true;

		int buyIndex;
		int quantity;

		while (isBuyingIngredients) {
			std::cout << player.cashFlow << std::endl;
			std::cout << "BUYING TIME" << std::endl << std::endl;

			// Display the ingredients the player can buy
			for (int i = 0; i < ingredients.size(); i++) {
				std::cout << i + 1 << ". " << ingredients[i].name << " " << ingredients[i].GetPrice() << "euros/u" << std::endl;
			}

			// Get the player choice
			std::cout << "Select the ingredient you want to buy" << std::endl;
			std::cin >> buyIndex;

			// Apply the player's choice
			if (buyIndex == 0) {
				isBuyingIngredients = false;
			}else if (buyIndex <= ingredients.size()) {
				std::cout << "Choose a quantity (max " << (int)(player.cashFlow / ingredients[buyIndex-1].GetPrice()) << ") :" << std::endl;
				std::cin >> quantity;
				if (quantity < (player.cashFlow / ingredients[buyIndex-1].GetPrice())) {
					player.cashFlow -= ingredients[buyIndex-1].GetPrice() * quantity;
					player.stock.insert(std::make_pair(ingredients[buyIndex-1], quantity));
					std::cout << player.stock[ingredients[buyIndex-1]];
				}
			}
			system("cls");
		}

		bool isCookingProducts = true;
		int cookingIndex;

		// Cook products
		while (isCookingProducts) {
			std::cout << player.cashFlow << std::endl;
			std::cout << "COOKING TIME" << std::endl << std::endl;

			// Display the products the player can cook
			for (int i = 0; i < products.size(); i++) {
				std::cout << i+1 << ". " << products[i].name << " " << products[i].price << "euros/u" << std::endl;
			}

			// Get the player choice
			std::cout << "Select the products you want to cook" << std::endl;
			std::cin >> cookingIndex;

			// Apply the player's choice
			if (cookingIndex == 0) {
				isCookingProducts = false;
			}
			else if (cookingIndex <= products.size()) {
				std::cout << "Choose a quantity (max : " << QuantityCookable(products[cookingIndex-1]) << ")" << std::endl;
				std::cin >> quantity;
				if (quantity < (player.cashFlow / ingredients[cookingIndex - 1].GetPrice())) {
					player.cashFlow -= ingredients[cookingIndex - 1].GetPrice() * quantity;
					player.stock.insert(std::make_pair(ingredients[cookingIndex - 1], quantity));
					std::cout << player.stock[ingredients[cookingIndex - 1]];
				}
			}
			system("cls");
		}

		// Create clients

		// Sell items
	}
}

int QuantityCookable(Product p) {
	int result = 0;

	for (int i = 0; i < p.recipe.size(); i++) {
		if (result < player.stock[p.recipe[i]]) result = player.stock[p.recipe[i]];
	}

	return result;
}