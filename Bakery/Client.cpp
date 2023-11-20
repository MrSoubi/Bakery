#include "Client.h"

Client::Client(vector<Product> products)
{
	for (int i = 0; i < products.size(); i++) {
		needs.insert(make_pair(products.at(i), 0));
	}
}

void Client::SetNewNeeds()
{
	for (auto it = needs.begin(); it != needs.end(); it++) {
		it->second = 1 + rand() % 2;
	}
}

map<Product, int> Client::GetNeeds()
{
	return map<Product, int>();
}
