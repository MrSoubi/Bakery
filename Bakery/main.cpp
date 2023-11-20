#include "GlobalHeader.h"

#include "Bakery.h"
#include "Utils.h"
#include "main.h"

int main() {
	// Initialize random seed
	srand(time(0));

	char path[] = "Cookbook.xml";
	vector<Product> products = Utils::ReadXML(path);
	vector<Ingredient> ingredients = Utils::ReadXML_Ingredients(path);
	int day = 1;

	Bakery player = Bakery(50.0f);

	while (!player.Bankrupt()) {
		// Set ingredients prices
		for (int i = 0; i < ingredients.size(); i++) {
			ingredients[i].SetPrice();
		}

		// Buy ingredients
		// ENTERING FULL TRASH MODE

		// Needs to be changed, I should use class methods instead and keep only the logic here.
		bool isBuyingIngredients = true;
		string buySentence;
		int quantity;
		while (isBuyingIngredients) {
			cout << "Choose the ingredients you want to buy :" << endl << endl;
			for (int i = 0; i < ingredients.size(); i++) {
				ingredients[i].Print();
			}
			cout << "Type the ingredient you want to buy (example : \"Flour\")" << endl;
			cin >> buySentence;

			for (int i = 0; i < ingredients.size(); i++) {
				if (buySentence == ingredients[i].name) {
					cout << "Choose a quantity (max " << player.cashFlow / ingredients[i].GetPrice() << ") :" << endl;
					string str;
					cin >> str;
					quantity = stof(str);
					if (quantity < (player.cashFlow / ingredients[i].GetPrice())) {
						player.stock.insert(make_pair(ingredients[i], quantity)); // CANT DO THIS !!! Use a comparator and add it to each map in the classes, see : https://stackoverflow.com/questions/5733254/how-can-i-create-my-own-comparator-for-a-map
					}
					break;
				}
			}


			Utils::AnalyzeBuyingOrder(buySentence, ingredients, player);
		}


		// Cook products



		// Create clients

		// Sell items
	}
}