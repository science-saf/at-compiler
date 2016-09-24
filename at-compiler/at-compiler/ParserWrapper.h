#pragma once

#include "structs.h"

class ParserWrapper
{
public:
	ParserWrapper();
	~ParserWrapper();

	void Parse(int tokenId, Token& token);
	void log(Token token);
	void log(Expr expr);
	void log(double str);
	void log(std::string d);
private:
	void* m_parserPtr;
};