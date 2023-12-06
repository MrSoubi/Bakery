#pragma once

#include <vector>
#include <map>

#include "Client.h"

Client::Client(std::vector<Product> products)
{
	for (int i = 0; i < products.size(); i++) {
		needs.insert(std::make_pair(products.at(i), 0));
	}
}

void Client::SetNewNeeds()
{
	for (auto it = needs.begin(); it != needs.end(); it++) {
		it->second = 1 + rand() % 2;
	}
}

std::map<Product, int> Client::GetNeeds()
{
	return std::map<Product, int>();
}