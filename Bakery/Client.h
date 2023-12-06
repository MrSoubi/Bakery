#pragma once

#include <map>
#include <vector>

#include "Product.h"

class Client
{
private:
	std::map<Product, int> needs;

public:
	Client(std::vector<Product> products);
	void SetNewNeeds();
	std::map<Product, int> GetNeeds();
};