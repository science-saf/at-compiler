#pragma once

#include "stdafx.h"

struct Token
{
	double value;
	std::string toString()
	{
		return std::to_string(value);
	}
};

struct Expr
{
	double value;
	std::string toString()
	{
		return std::to_string(value);
	}
};