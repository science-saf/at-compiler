#pragma once

#include "stdafx.h"
#include "BaseAST.h"

class VariableAST : public BaseAST
{
	std::string m_name;

public:
	VariableAST(const std::string& name)
		: m_name(name)
	{
	}

	~VariableAST();
};

