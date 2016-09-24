#pragma once

#include "stdafx.h"
#include "BaseAST.h"
#include "FunctionPrototypeAST.h"

class FunctionAST : public BaseAST
{
private:
	std::unique_ptr<FunctionPrototypeAST> m_prototype;
	std::unique_ptr<BaseAST> m_body;

public:
	FunctionAST(std::unique_ptr<FunctionPrototypeAST> prototype, std::unique_ptr<BaseAST> body)
		: m_prototype(std::move(prototype))
		, m_body(std::move(body))
	{
	}

	~FunctionAST();
};

