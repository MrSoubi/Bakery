#pragma once

#include <vector>
#include <string>


#include "Product.h"
#include "Ingredient.h"
#include "Bakery.h"

class Utils
{
public:
	static float StrToFloat(std::string s);
	static std::vector<Product> ReadXML(char path[]);
	static std::vector<Ingredient> ReadXML_Ingredients(char path[]);
	static bool Contains(std::vector<Ingredient> vec, Ingredient value);
	static void AnalyzeBuyingOrder(std::string buyingOrder, std::vector<Ingredient>, Bakery player);
};