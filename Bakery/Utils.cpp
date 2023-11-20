#include "Utils.h"

float Utils::StrToFloat(string s) {
	return 1.0f;
}

vector<Product> Utils::ReadXML(char path[])
{
	vector<Product> products;
	vector<Ingredient> ingredients;

	TiXmlDocument doc(path);
	if (doc.LoadFile()) {
		TiXmlElement* currentRecipe = doc.RootElement()->FirstChildElement("recipe");

		while (currentRecipe != NULL) {
			string name = currentRecipe->FirstChildElement("name")->GetText();
			float price = Utils::StrToFloat(currentRecipe->FirstChildElement("price")->GetText());

			TiXmlElement* currentIngredient = currentRecipe->FirstChildElement("ingredients")->FirstChildElement("name");

			while (currentIngredient != NULL) {
				Ingredient tmpIngredient = Ingredient(currentIngredient->GetText());
				ingredients.push_back(tmpIngredient);
				currentIngredient = currentIngredient->NextSiblingElement("name");
			}

			Product p = Product(name, price, ingredients);
			products.push_back(p);

			currentRecipe = currentRecipe->NextSiblingElement("recipe");
			ingredients.clear();
		}
	}
	return products;
}

vector<Ingredient> Utils::ReadXML_Ingredients(char path[])
{
	vector<Product> products;
	vector<Ingredient> ingredients;

	TiXmlDocument doc(path);
	if (doc.LoadFile()) {
		TiXmlElement* currentRecipe = doc.RootElement()->FirstChildElement("recipe");

		while (currentRecipe != NULL) {

			TiXmlElement* currentIngredient = currentRecipe->FirstChildElement("ingredients")->FirstChildElement("name");

			while (currentIngredient != NULL) {
				Ingredient tmpIngredient = Ingredient(currentIngredient->GetText());
				if (!Contains(ingredients, tmpIngredient))
				{
					ingredients.push_back(tmpIngredient);
				}
				currentIngredient = currentIngredient->NextSiblingElement("name");
			}
			currentRecipe = currentRecipe->NextSiblingElement("recipe");
		}
	}

	return ingredients;
}

bool Utils::Contains(vector<Ingredient> vec, Ingredient value)
{
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == value) {
			return true;
		}
	}
	return false;
}

void Utils::AnalyzeBuyingOrder(string buyingOrder, vector<Ingredient> ingredients, Bakery player)
{
	for (int i = 0; i < ingredients.size(); i++) {
		if (buyingOrder.find(ingredients[i].name) != -1) {
			Ingredient tmpIngredient = ingredients[i];
			break;
		}
	}

	for (int i = 0; i < buyingOrder.size(); i++) {

	}
}
