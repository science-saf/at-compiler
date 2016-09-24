#pragma once

#include "stdafx.h"
#include "BaseAST.h"
#include "enums.h"

class BinaryExprAST : public BaseAST
{
private:
	MathOperator m_operator;
	std::unique_ptr<BaseAST> m_lhs;
	std::unique_ptr<BaseAST> m_rhs;

public:
	BinaryExprAST(MathOperator op, std::unique_ptr<BaseAST> lhs, std::unique_ptr<BaseAST> rhs)
		: m_operator(op)
		, m_lhs(std::move(lhs))
		, m_rhs(std::move(rhs))
	{
	}

	~BinaryExprAST();
};

