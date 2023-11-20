#pragma once

#include "GlobalHeader.h"

//#include "Product.h"
#include "Bakery.h"

class Utils
{
public:
	static float StrToFloat(string s);
	static vector<Product> ReadXML(char path[]);
	static vector<Ingredient> ReadXML_Ingredients(char path[]);
	static bool Contains(vector<Ingredient> vec, Ingredient value);
	static void AnalyzeBuyingOrder(string buyingOrder, vector<Ingredient>, Bakery player);
};