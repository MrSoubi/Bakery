#pragma once

#include "Bakery.h"

Bakery::Bakery()
{
	cashFlow = 0;
}

Bakery::Bakery(float cash)
{
	cashFlow = cash;
}

bool Bakery::Bankrupt()
{
	return cashFlow <= 0.0f;
}