#pragma once

#include "enums.h"

class BaseAST
{
protected:
	ExprType m_exprType;

public:
	BaseAST();
	virtual ~BaseAST();
};

