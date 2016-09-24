#pragma once

#include "stdafx.h"
#include "BaseAST.h"

class FunctionCallAST : public BaseAST
{
private:
	std::string m_callee;
	std::vector<std::unique_ptr<BaseAST>> m_argv;

public:
	FunctionCallAST(const std::string& callee, std::vector<std::unique_ptr<BaseAST>> argv)
		: m_callee(callee)
		, m_argv(std::move(argv))
	{
	}

	~FunctionCallAST();
};

