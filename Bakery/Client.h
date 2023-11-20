#pragma once
#include "GlobalHeader.h"

#include "Product.h"

class Client
{
private:
	map<Product, int> needs;

public:
	Client(vector<Product> products);
	void SetNewNeeds();
	map<Product, int> GetNeeds();
};

