#include "GlobalHeader.h"

#include "Bakery.h"
#include "Utils.h"

int main() {
	// Initialize random seed
	srand(time(0));

	vector<Product> products;

	TiXmlDocument doc("Cookbook.xml");
	if (doc.LoadFile()) {
		TiXmlElement* currentRecipe = doc.RootElement()->FirstChildElement("recipe");

		while (currentRecipe != NULL) {
			string name = currentRecipe->FirstChildElement("name")->GetText();
			float price = Utils::StrToFloat(currentRecipe->FirstChildElement("price")->GetText());

			// This part doesn't work. I changed the XML format, I need to change this part now.
			vector<Ingredient> ingredients;
			/*
				
			TiXmlElement* currentIngredient = currentRecipe->FirstChildElement("ingredient");
			while (currentIngredient != NULL) {
				cout << "ingredient non null" << endl;
				ingredients.push_back(Ingredient(doc.NextSiblingElement("ingredient")->GetText()));
				currentIngredient = currentIngredient->NextSiblingElement("ingredient");
			}*/

			Product p = Product(name, price, ingredients);
			products.push_back(p);

			currentRecipe = currentRecipe->NextSiblingElement("recipe");
		}
	}

	products[0].Print();
}