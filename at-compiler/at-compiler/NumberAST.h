#pragma once

#include "BaseAST.h"

class NumberAST : public BaseAST
{
	double m_value;

public:
	NumberAST(double value)
		: m_value(value)
	{
	}

	~NumberAST();
};

