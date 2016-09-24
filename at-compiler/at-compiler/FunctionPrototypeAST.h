#pragma once

#include "stdafx.h"
#include "BaseAST.h"

class FunctionPrototypeAST : public BaseAST
{
private:
	std::string m_name;
	std::vector<std::string> m_argv;

public:
	FunctionPrototypeAST(const std::string& name, std::vector<std::string> argv)
		: m_name(name)
		, m_argv(std::move(argv))
	{
	}

	~FunctionPrototypeAST();
};

